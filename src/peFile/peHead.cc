#include "stdafx.h"
#include "peHead.h"

#define FOR_FI(s,r,i, ...) for(size_t i = 0; i < s.size(); i++)  \
	{ auto& r = s[i]; __VA_ARGS__; }

void PeOptHead_::update(IMAGE_SECTION_HEADER* ish)
{
	SizeOfImage += sectAlign(ish->Misc.VirtualSize);
	u32 vSzFA = fileAlign(ish->Misc.VirtualSize);
	if(ish->Characteristics & IMAGE_SCN_CNT_CODE) { SizeOfCode += vSzFA; 
		if(!BaseOfCode) BaseOfCode = ish->VirtualAddress;		
	} ei(ish->Characteristics & IMAGE_SCN_CNT_INITIALIZED_DATA) {
		SizeOfInitializedData += vSzFA; goto L1;
	} ei(ish->Characteristics & IMAGE_SCN_CNT_UNINITIALIZED_DATA) {
		SizeOfUninitializedData += vSzFA; L1:  
		if(!PE64() && !BaseOfData32) BaseOfData32 = ish->VirtualAddress;	
	}
}

TMPL2(T, U) void pack_common(T* __restrict__ dst, U* __restrict__ src)
{
	#define MV(N) dst->N = src->N;
	MV(Magic) MV(MajorLinkerVersion) MV(MinorLinkerVersion) 
	MV(AddressOfEntryPoint) MV(SectionAlignment) MV(FileAlignment) 
	MV(MajorOperatingSystemVersion) MV(MinorOperatingSystemVersion)
	MV(MajorImageVersion) MV(MinorImageVersion) MV(MajorSubsystemVersion)
	MV(MinorSubsystemVersion) MV(Win32VersionValue) MV(CheckSum)
	MV(Subsystem) MV(DllCharacteristics)
}

TMPL2(T, U) PeOptHead_::DataDirX* pack_extra(
	T* __restrict__ dst, U* __restrict__ src)
{
	MV(ImageBase)
	MV(SizeOfStackReserve) MV(SizeOfStackCommit)
	MV(SizeOfHeapReserve) MV(SizeOfHeapCommit)
	
	// c++ is a piece of utter shit
	if constexpr(!std::is_same_v<T,PeOptHead>)
		return Void(&dst->LoaderFlags);
	else return Void(&src->LoaderFlags);
}

void* PeOptHead::ioh_unpack(void* ioh)
{
	pack_common(this, (IMAGE_OPTIONAL_HEADER64*)ioh);
	
	PeOptHead_::DataDirX* dd = PE64() ?
		pack_extra(this, (IMAGE_OPTIONAL_HEADER64*)ioh):
		pack_extra(this, (IMAGE_OPTIONAL_HEADER32*)ioh);
		
	LoaderFlags = dd->LoaderFlags;
	return memcpyY(dataDir_, 
		dd->dataDir, dd->dataDirSize);
}


void* PeOptHead::ioh_pack(void* ioh)
{
	pack_common((IMAGE_OPTIONAL_HEADER64*)ioh, this);
	ARGFIX(*this); 
	
	PeOptHead_::DataDirX* dd = PE64() ?
		pack_extra((IMAGE_OPTIONAL_HEADER64*)ioh, this):
		pack_extra((IMAGE_OPTIONAL_HEADER32*)ioh, this);
	
	dd->LoaderFlags = LoaderFlags;
	dd->dataDirSize = 0x10;
	return memcpyX(dd->dataDir, dataDir_, 16);
}

int peMzChk(void* data, u32 size)
{
	IMAGE_DOS_HEADER* idh = Void(data);
	if((size < 0x1C)||(idh->e_magic != 'ZM')
	||(size < idh->e_lfarlc)) return -1;
	if(idh->e_lfarlc < 0x40) return 0;
	if(idh->e_lfanew <= 0) return -1;
	return idh->e_lfanew;
}

int peHeadChk(IMAGE_NT_HEADERS64* inh, u32 e_lfanew, u32 size)
{
	// check header
	if((size < 4)||(inh->Signature != 'EP')) return 0;
	u32 sectOfs = offsetof(IMAGE_NT_HEADERS, OptionalHeader);
	if((size < sectOfs)||(size < (sectOfs += inh->FileHeader.SizeOfOptionalHeader))
	||(inh->FileHeader.SizeOfOptionalHeader < 2)) { ERR: nothing();	return -1; }
	
	// check optional header magic
	u32 dataDirOffset;
	if(inh->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR32_MAGIC) { 
		dataDirOffset = offsetof(IMAGE_NT_HEADERS32, OptionalHeader.DataDirectory); }
	ei(inh->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR64_MAGIC) { 
		dataDirOffset = offsetof(IMAGE_NT_HEADERS64, OptionalHeader.DataDirectory); }
	else { goto ERR; }

	// check optional header size
	if(sectOfs < dataDirOffset) goto ERR;
	u32 dataDirSize = sectOfs-dataDirOffset;
	dataDirSize /= sizeof(IMAGE_DATA_DIRECTORY);
	if((RI(inh, dataDirOffset-4) != dataDirSize)
	||(RI(inh, dataDirOffset-4) > 0x10)) goto ERR;
	
	// check SizeOfHeaders
	sectOfs += sizeof(IMAGE_SECTION_HEADER)*inh->FileHeader.NumberOfSections;
	u32 headSize = inh->OptionalHeader.SizeOfHeaders;
	if(headSize % inh->OptionalHeader.FileAlignment) goto ERR;
	if(ovf_sub(headSize, e_lfanew)) { goto ERR; } nothing();
	if(headSize < sectOfs) goto ERR; return headSize;
}

static inline 
bool peHead64(IMAGE_NT_HEADERS64* inh) {
	return u8(inh->OptionalHeader.Magic>>8) == 2; };
	
static inline 
xarray<PeOptHead_::DataDir> peHeadDataDir(IMAGE_NT_HEADERS64* inh) 
{
	void* dd = peHead64(inh) ?
		&((IMAGE_NT_HEADERS64*)inh)->OptionalHeader.DataDirectory:
		&((IMAGE_NT_HEADERS32*)inh)->OptionalHeader.DataDirectory;
	return {(PeOptHead_::DataDir*)dd, RI(dd,-4)};
}

static inline
xarray<IMAGE_SECTION_HEADER> peHeadSect(IMAGE_NT_HEADERS64* inh) 
{
	u32 sectOfs = offsetof(IMAGE_NT_HEADERS, OptionalHeader);
	sectOfs += inh->FileHeader.SizeOfOptionalHeader;
	return {(IMAGE_SECTION_HEADER*) Void(inh, 
		sectOfs), inh->FileHeader.NumberOfSections};
}

int peHeadChkRva(IMAGE_NT_HEADERS64* inh, u32 rva, u32 len)
{
	auto sects = peHeadSect(inh);
	FOR_FI(sects,sect,i, u32 tmp;
		if(ovf_sub(tmp, rva, sect.VirtualAddress)) continue;
		if(ovf_add(tmp, len)) continue; nothing();
		if(tmp <= sect.Misc.VirtualSize) return i;		
	);
	
	return -1;
}

static inline
DWORD peHead_sectAlign(IMAGE_NT_HEADERS64* inh, DWORD v) {
	return ALIGN(v, inh->OptionalHeader.SectionAlignment-1); }

int peHeadChk2(IMAGE_NT_HEADERS64* inh, u32 e_lfanew)
{
	// validate sections
	u32 filePos = inh->OptionalHeader.SizeOfHeaders;
	u32 virtPos = peHead_sectAlign(inh, filePos);
	for(auto& sect : peHeadSect(inh)) {
		DWORD vSize = peHead_sectAlign(inh, sect.Misc.VirtualSize);
		if(virtPos != sect.VirtualAddress) return 1; virtPos += vSize;
		if(sect.PointerToRawData) {
			if((filePos != sect.PointerToRawData)
			||(vSize < sect.SizeOfRawData)) return 1;
			filePos += sect.SizeOfRawData;
		}
	}
	
	// validate entry point
	DWORD aoep = inh->OptionalHeader.AddressOfEntryPoint;
	if((aoep)&&(peHeadChkRva(inh, aoep, 0) < 0))
		return 2;

	// validate DataDirectory
	auto dd = peHeadDataDir(inh);
	FOR_FI(dd,d,i, if(d.rva == 0) continue;
		if(i != IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT) {
			if(peHeadChkRva(inh, d.rva, d.size) < 0) return 2; }
			
		// validate bound import
		else { if(d.rva < e_lfanew) return 2; u32 tmp; 
			if(ovf_add(tmp, d.rva, d.size)||(tmp>inh
			->OptionalHeader.SizeOfHeaders)) return 2; }
	)

	return 0;
}