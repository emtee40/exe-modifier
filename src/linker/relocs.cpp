// relocation fixups
// included by linker.cc
// DeadFish Shitware, 2014

char* getSectionName(Section* sect, int offset)
{
	return (sect == NULL) ? xstrfmt("@image:%X", offset) : xstrfmt(
		"%s:%s:%X", sect->fileName, sect->name, offset);
}

bool undef_symbol_flag;
void undef_symbol(Symbol* symb, Section* sect, int offset)
{
	undef_symbol_flag = true;
	char* sectName = getSectionName(sect, offset);
	error_msg("undefined symbol: %s, referenced by: %s\n",
		symb->getName(), sectName); free(sectName);
}

void Reloc::fixup(Section* sect)
{
	// check symbol
	if(this->type == (WORD)-1) return;
	auto& symb = symbols[this->symbol];
	const char* symbName = symb.Name ? 
		symb.Name : "##NO NAME##";
		if(symb.section == Type_Undefined)
			undef_symbol(&symb, sect, this->offset);
			
	// resolve fixup
	DWORD baseRva = sect ? sect->baseRva : 0;
	DWORD relocRva = baseRva + this->offset;
	DWORD& addr = PeFILE::rvaToPtr(relocRva).dword();
	DWORD symbAddr = symb.getAddr();
	if(this->type == Type_DIR32) {
		addr += symbAddr;
		if(symb.section != Type_Absolute)
			PeFILE::Relocs_Add( relocRva );
	} else {
		addr += symbAddr;
		addr -= PeFILE::rvaToAddr(relocRva) + 4;
	}
}

void Section::addReloc(WORD type, 
	DWORD offset, DWORD symbol)
{
	auto& reloc = xNextAlloc(relocs, nReloc);
	reloc.type = type;
	reloc.offset = offset;
	reloc.symbol = symbol;	
}

void addReloc(WORD type, 
	DWORD offset, DWORD symbol)
{
	auto& reloc = xNextAlloc(relocs, nRelocs);
	reloc.type = type;
	reloc.offset = offset;
	reloc.symbol = symbol;	
}

void relocs_fixup(void)
{
	for(auto& sect : Range(sections, nSections)) {
	  for(auto& reloc : Range(sect.relocs, sect.nReloc))
		reloc.fixup(&sect); }
	for(auto& reloc : Range(relocs, nRelocs))
		reloc.fixup(NULL);
	if(undef_symbol_flag) exit(1);
	
	if(undef_symbol_flag) exit(1);
}
