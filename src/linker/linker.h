#ifndef _LINKER_H_
#define _LINKER_H_

namespace Linker {

// section interface	
struct Section {
	const char* fileName;
	char* name; Void rawData;
	DWORD iReloc, nReloc;
	WORD type; WORD align;
	DWORD baseRva, length;

	Void endPtr() {
		return rawData+length; }
};
extern Section* sections;
extern DWORD nSections;
DWORD addSection(const char* fileName, const char* Name,
	void* rawData, DWORD iReloc, DWORD nReloc,
	WORD type, WORD align, DWORD baseRva, DWORD length);
void destroy_section(Section& sect);
Section* findSection(const char* name);

// symbol interface
enum : DWORD {
	Type_Undefined = DWORD(-1),
	Type_Relocate = DWORD(-2),
	Type_Absolute = DWORD(-3),
	Type_Import	= DWORD(-4) };
struct Symbol {
	char* Name;
	DWORD section;
	DWORD weakSym;
	DWORD value; 
	DWORD getAddr(void); };
extern Symbol* symbols;
extern DWORD nSymbols;
int findSymbol(const char* name); int symbolRva(int symbol);
int addSymbol(const char* name, DWORD section, DWORD weakSym, DWORD value);
int addImport(const char* Name, const char* dllName, const char* importName);

// reloc interace
enum {
	Type_DIR32 = 0,
	Type_REL32 = 1, 
	Type_DIR32NB = 2};
struct Reloc {
	WORD type;
	WORD section;
	DWORD offset;
	DWORD symbol; };
extern Reloc* relocs;
extern DWORD nRelocs;
void addReloc(WORD type, WORD section, DWORD offset, DWORD symbol);
void relocs_fixup(void);

// object functions
void library_load(const char* fileName);
void library_load(const char* fileName,
	Void fileData, int fileSize);
void object_load(const char* fileName);
void object_load(const char* fileName, 
	Void objData, DWORD objSize);
void imports_parse(void);
void imports_resolve(void);
const char* nullchk(const char* str, const char* limit);
void gc_sections(void);

}
#endif