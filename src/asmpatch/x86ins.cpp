// X86 instruction table
// probably has many errors

struct X86InsInfo {
	const char* name; const char* opcode;
	struct ArgInfo { int type; int size; } args[3];
	int nOps() { return !!args[0].type 
		+ !!args[1].type + !!args[2].type; }
	
	enum { TYPE_NONE, TYPE_REGMEM, TYPE_REG, TYPE_MEM, 
		TYPE_REGFIX, TYPE_IMM, TYPE_IMMFIX };
	enum { SIZE_NONE, SIZE_BYTE, SIZE_WORD, SIZE_LONG };
} x86InsInfo[] = 
{{"AAA", "37", 0, 0, 0, 0, 0, 0 }, 
{"AAS", "3F", 0, 0, 0, 0, 0, 0 }, 
{"AAD", "D50A", 0, 0, 0, 0, 0, 0 }, 
{"AAD", "D5ib", 5, 3, 0, 0, 0, 0 }, 
{"AAM", "D40A", 0, 0, 0, 0, 0, 0 }, 
{"AAM", "D4ib", 5, 3, 0, 0, 0, 0 }, 
{"ADC", "10/r", 1, 1, 2, 1, 0, 0 }, 
{"ADC", "po11/r", 1, 2, 2, 2, 0, 0 }, 
{"ADC", "po11/r", 1, 3, 2, 3, 0, 0 }, 
{"ADC", "12/r", 2, 1, 1, 1, 0, 0 }, 
{"ADC", "po13/r", 2, 2, 1, 2, 0, 0 }, 
{"ADC", "po13/r", 2, 3, 1, 3, 0, 0 }, 
{"ADC", "80/2ib", 1, 1, 5, 1, 0, 0 }, 
{"ADC", "po81/2iw", 1, 2, 5, 2, 0, 0 }, 
{"ADC", "po81/2id", 1, 3, 5, 3, 0, 0 }, 
{"ADC", "po83/2ib", 1, 2, 5, 1, 0, 0 }, 
{"ADC", "po83/2ib", 1, 3, 5, 1, 0, 0 }, 
{"ADC", "14ib", 4, 0, 5, 1, 0, 0 }, 
{"ADC", "po15iw", 4, 8, 5, 2, 0, 0 }, 
{"ADC", "po15id", 4, 16, 5, 3, 0, 0 }, 
{"ADD", "00/r", 1, 1, 2, 1, 0, 0 }, 
{"ADD", "po01/r", 1, 2, 2, 2, 0, 0 }, 
{"ADD", "po01/r", 1, 3, 2, 3, 0, 0 }, 
{"ADD", "02/r", 2, 1, 1, 1, 0, 0 }, 
{"ADD", "po03/r", 2, 2, 1, 2, 0, 0 }, 
{"ADD", "po03/r", 2, 3, 1, 3, 0, 0 }, 
{"ADD", "80/0ib", 1, 1, 5, 1, 0, 0 }, 
{"ADD", "po81/0iw", 1, 2, 5, 2, 0, 0 }, 
{"ADD", "po81/0id", 1, 3, 5, 3, 0, 0 }, 
{"ADD", "po83/0ib", 1, 2, 5, 1, 0, 0 }, 
{"ADD", "po83/0ib", 1, 3, 5, 1, 0, 0 }, 
{"ADD", "04ib", 4, 0, 5, 1, 0, 0 }, 
{"ADD", "po05iw", 4, 8, 5, 2, 0, 0 }, 
{"ADD", "po05id", 4, 16, 5, 3, 0, 0 }, 
{"AND", "20/r", 1, 1, 2, 1, 0, 0 }, 
{"AND", "po21/r", 1, 2, 2, 2, 0, 0 }, 
{"AND", "po21/r", 1, 3, 2, 3, 0, 0 }, 
{"AND", "22/r", 2, 1, 1, 1, 0, 0 }, 
{"AND", "po23/r", 2, 2, 1, 2, 0, 0 }, 
{"AND", "po23/r", 2, 3, 1, 3, 0, 0 }, 
{"AND", "80/4ib", 1, 1, 5, 1, 0, 0 }, 
{"AND", "po81/4iw", 1, 2, 5, 2, 0, 0 }, 
{"AND", "po81/4id", 1, 3, 5, 3, 0, 0 }, 
{"AND", "po83/4ib", 1, 2, 5, 1, 0, 0 }, 
{"AND", "po83/4ib", 1, 3, 5, 1, 0, 0 }, 
{"AND", "24ib", 4, 0, 5, 1, 0, 0 }, 
{"AND", "po25iw", 4, 8, 5, 2, 0, 0 }, 
{"AND", "po25id", 4, 16, 5, 3, 0, 0 }, 
{"BOUND", "po62/r", 2, 2, 3, 0, 0, 0 }, 
{"BOUND", "po62/r", 2, 3, 3, 0, 0, 0 }, 
{"BSF", "po0FBC/r", 2, 2, 1, 2, 0, 0 }, 
{"BSF", "po0FBC/r", 2, 3, 1, 3, 0, 0 }, 
{"BSR", "po0FBD/r", 2, 2, 1, 2, 0, 0 }, 
{"BSR", "po0FBD/r", 2, 3, 1, 3, 0, 0 }, 
{"BSWAP", "po0FC8+r", 2, 3, 0, 0, 0, 0 }, 
{"BT", "po0FA3/r", 1, 2, 2, 2, 0, 0 }, 
{"BT", "po0FA3/r", 1, 3, 2, 3, 0, 0 }, 
{"BT", "po0FBA/4ib", 1, 2, 5, 1, 0, 0 }, 
{"BT", "po0FBA/4ib", 1, 3, 5, 1, 0, 0 }, 
{"BTC", "po0FBB/r", 1, 2, 2, 2, 0, 0 }, 
{"BTC", "po0FBB/r", 1, 3, 2, 3, 0, 0 }, 
{"BTC", "po0FBA/7ib", 1, 2, 5, 1, 0, 0 }, 
{"BTC", "po0FBA/7ib", 1, 3, 5, 1, 0, 0 }, 
{"BTR", "po0FB3/r", 1, 2, 2, 2, 0, 0 }, 
{"BTR", "po0FB3/r", 1, 3, 2, 3, 0, 0 }, 
{"BTR", "po0FBA/6ib", 1, 2, 5, 1, 0, 0 }, 
{"BTR", "po0FBA/6ib", 1, 3, 5, 1, 0, 0 }, 
{"BTS", "po0FAB/r", 1, 2, 2, 2, 0, 0 }, 
{"BTS", "po0FAB/r", 1, 3, 2, 3, 0, 0 }, 
{"BTS", "po0FBA/5ib", 1, 2, 5, 3, 0, 0 }, 
{"BTS", "po0FBA/5ib", 1, 3, 5, 3, 0, 0 }, 
{"CALL", "E8-i", 5, 3, 0, 0, 0, 0 }, 
{"CALL", "poFF/2", 1, 2, 0, 0, 0, 0 }, 
{"CALL", "poFF/2", 1, 3, 0, 0, 0, 0 }, 
{"CBW", "pw98", 0, 0, 0, 0, 0, 0 }, 
{"CWD", "pw99", 0, 0, 0, 0, 0, 0 }, 
{"CDQ", "po99", 0, 0, 0, 0, 0, 0 }, 
{"CWDE", "po98", 0, 0, 0, 0, 0, 0 }, 
{"CLC", "F8", 0, 0, 0, 0, 0, 0 }, 
{"CLD", "FC", 0, 0, 0, 0, 0, 0 }, 
{"CLI", "FA", 0, 0, 0, 0, 0, 0 }, 
{"CMC", "F5", 0, 0, 0, 0, 0, 0 }, 
{"CMOVO", "po0F40/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVNO", "po0F41/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVB", "po0F42/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVC", "po0F42/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVNEA", "po0F42/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVAE", "po0F43/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVNB", "po0F43/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVNC", "po0F43/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVE", "po0F44/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVZ", "po0F44/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVNE", "po0F45/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVNZ", "po0F45/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVBE", "po0F46/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVNA", "po0F46/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVA", "po0F47/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVNBE", "po0F47/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVS", "po0F48/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVNS", "po0F49/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVP", "po0F4A/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVPE", "po0F4A/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVNP", "po0F4B/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVPO", "po0F4B/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVL", "po0F4C/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVNGE", "po0F4C/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVGE", "po0F4D/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVNL", "po0F4D/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVLE", "po0F4E/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVNG", "po0F4E/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVG", "po0F4F/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVNLE", "po0F4F/r", 2, 2, 1, 2, 0, 0 }, 
{"CMOVO", "po0F40/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVNO", "po0F41/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVB", "po0F42/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVC", "po0F42/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVNEA", "po0F42/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVAE", "po0F43/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVNB", "po0F43/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVNC", "po0F43/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVE", "po0F44/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVZ", "po0F44/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVNE", "po0F45/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVNZ", "po0F45/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVBE", "po0F46/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVNA", "po0F46/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVA", "po0F47/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVNBE", "po0F47/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVS", "po0F48/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVNS", "po0F49/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVP", "po0F4A/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVPE", "po0F4A/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVNP", "po0F4B/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVPO", "po0F4B/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVL", "po0F4C/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVNGE", "po0F4C/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVGE", "po0F4D/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVNL", "po0F4D/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVLE", "po0F4E/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVNG", "po0F4E/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVG", "po0F4F/r", 2, 3, 1, 3, 0, 0 }, 
{"CMOVNLE", "po0F4F/r", 2, 3, 1, 3, 0, 0 }, 
{"CMP", "38/r", 1, 1, 2, 1, 0, 0 }, 
{"CMP", "po39/r", 1, 2, 2, 2, 0, 0 }, 
{"CMP", "po39/r", 1, 3, 2, 3, 0, 0 }, 
{"CMP", "3A/r", 2, 1, 1, 1, 0, 0 }, 
{"CMP", "po3B/r", 2, 2, 1, 2, 0, 0 }, 
{"CMP", "po3B/r", 2, 3, 1, 3, 0, 0 }, 
{"CMP", "80/7ib", 1, 1, 5, 1, 0, 0 }, 
{"CMP", "po81/7iw", 1, 2, 5, 2, 0, 0 }, 
{"CMP", "po81/7id", 1, 3, 5, 3, 0, 0 }, 
{"CMP", "po83/7ib", 1, 2, 5, 1, 0, 0 }, 
{"CMP", "po83/7ib", 1, 3, 5, 1, 0, 0 }, 
{"CMP", "3Cib", 4, 0, 5, 1, 0, 0 }, 
{"CMP", "po3Diw", 4, 8, 5, 2, 0, 0 }, 
{"CMP", "po3Did", 4, 16, 5, 3, 0, 0 }, 
{"CMPSB", "A6", 0, 0, 0, 0, 0, 0 }, 
{"CMPSW", "pwA7", 0, 0, 0, 0, 0, 0 }, 
{"CMPSD", "poA7", 0, 0, 0, 0, 0, 0 }, 
{"CMPXCHG", "0FB0/r", 1, 1, 2, 1, 0, 0 }, 
{"CMPXCHG", "po0FB1/r", 1, 2, 2, 2, 0, 0 }, 
{"CMPXCHG", "po0FB1/r", 1, 3, 2, 3, 0, 0 }, 
{"CMPXCHG8B", "0FC7/1", 3, 0, 0, 0, 0, 0 }, 
{"CPUID", "0FA2", 0, 0, 0, 0, 0, 0 }, 
{"DAA", "27", 0, 0, 0, 0, 0, 0 }, 
{"DAS", "2F", 0, 0, 0, 0, 0, 0 }, 
{"DEC", "po48+r", 2, 2, 0, 0, 0, 0 }, 
{"DEC", "po48+r", 2, 3, 0, 0, 0, 0 }, 
{"DEC", "FE/1", 1, 1, 0, 0, 0, 0 }, 
{"DEC", "poFF/1", 1, 2, 0, 0, 0, 0 }, 
{"DEC", "poFF/1", 1, 3, 0, 0, 0, 0 }, 
{"DIV", "F6/6", 1, 1, 0, 0, 0, 0 }, 
{"DIV", "poF7/6", 1, 2, 0, 0, 0, 0 }, 
{"DIV", "poF7/6", 1, 3, 0, 0, 0, 0 }, 
{"EMMS", "0F77", 0, 0, 0, 0, 0, 0 }, 
{"F2XM1", "D9F0", 0, 0, 0, 0, 0, 0 }, 
{"FABS", "D9E1", 0, 0, 0, 0, 0, 0 }, 
{"FADD", "D8/0", 3, 3, 0, 0, 0, 0 }, 
{"FCHS", "D9E0", 0, 0, 0, 0, 0, 0 }, 
{"FCLEX", "9BDBE2", 0, 0, 0, 0, 0, 0 }, 
{"FNCLEX", "DBE2", 0, 0, 0, 0, 0, 0 }, 
{"FCOM", "D8/2", 3, 3, 0, 0, 0, 0 }, 
{"FCOMP", "D8/3", 3, 3, 0, 0, 0, 0 }, 
{"FCOMPP", "DED9", 0, 0, 0, 0, 0, 0 }, 
{"FCOS", "D9FF", 0, 0, 0, 0, 0, 0 }, 
{"FDECSTP", "D9F6", 0, 0, 0, 0, 0, 0 }, 
{"FDISI", "9BDBE1", 0, 0, 0, 0, 0, 0 }, 
{"FNDISI", "DBE1", 0, 0, 0, 0, 0, 0 }, 
{"FENI", "9BDBE0", 0, 0, 0, 0, 0, 0 }, 
{"FNENI", "DBE0", 0, 0, 0, 0, 0, 0 }, 
{"FDIV", "D8/6", 3, 3, 0, 0, 0, 0 }, 
{"FDIVR", "D8/7", 3, 3, 0, 0, 0, 0 }, 
{"FEMMS", "0F0E", 0, 0, 0, 0, 0, 0 }, 
{"FIADD", "DE/0", 3, 2, 0, 0, 0, 0 }, 
{"FIADD", "DA/0", 3, 3, 0, 0, 0, 0 }, 
{"FICOM", "DE/2", 3, 2, 0, 0, 0, 0 }, 
{"FICOM", "DA/2", 3, 3, 0, 0, 0, 0 }, 
{"FICOMP", "DE/3", 3, 2, 0, 0, 0, 0 }, 
{"FICOMP", "DA/3", 3, 3, 0, 0, 0, 0 }, 
{"FIDIV", "DE/6", 3, 2, 0, 0, 0, 0 }, 
{"FIDIV", "DA/6", 3, 3, 0, 0, 0, 0 }, 
{"FIDIVR", "DE/7", 3, 2, 0, 0, 0, 0 }, 
{"FIDIVR", "DA/7", 3, 3, 0, 0, 0, 0 }, 
{"FILD", "DF/0", 3, 2, 0, 0, 0, 0 }, 
{"FILD", "DB/0", 3, 3, 0, 0, 0, 0 }, 
{"FIST", "DF/2", 3, 2, 0, 0, 0, 0 }, 
{"FIST", "DB/2", 3, 3, 0, 0, 0, 0 }, 
{"FISTP", "DF/3", 3, 2, 0, 0, 0, 0 }, 
{"FISTP", "DB/3", 3, 3, 0, 0, 0, 0 }, 
{"FIMUL", "DE/1", 3, 2, 0, 0, 0, 0 }, 
{"FIMUL", "DA/1", 3, 3, 0, 0, 0, 0 }, 
{"FINCSTP", "D9F7", 0, 0, 0, 0, 0, 0 }, 
{"FINIT", "9BDBE3", 0, 0, 0, 0, 0, 0 }, 
{"FNINIT", "DBE3", 0, 0, 0, 0, 0, 0 }, 
{"FISUB", "DE/4", 3, 2, 0, 0, 0, 0 }, 
{"FISUB", "DA/4", 3, 3, 0, 0, 0, 0 }, 
{"FISUBR", "DE/5", 3, 2, 0, 0, 0, 0 }, 
{"FISUBR", "DA/5", 3, 3, 0, 0, 0, 0 }, 
{"FLD", "D9/0", 3, 3, 0, 0, 0, 0 }, 
{"FLD1", "D9E8", 0, 0, 0, 0, 0, 0 }, 
{"FLDL2E", "D9EA", 0, 0, 0, 0, 0, 0 }, 
{"FLDL2T", "D9E9", 0, 0, 0, 0, 0, 0 }, 
{"FLDLG2", "D9EC", 0, 0, 0, 0, 0, 0 }, 
{"FLDLN2", "D9ED", 0, 0, 0, 0, 0, 0 }, 
{"FLDPI", "D9EB", 0, 0, 0, 0, 0, 0 }, 
{"FLDZ", "D9EE", 0, 0, 0, 0, 0, 0 }, 
{"FLDCW", "D9/5", 3, 2, 0, 0, 0, 0 }, 
{"FLDENV", "D9/4", 3, 0, 0, 0, 0, 0 }, 
{"FMUL", "D8/1", 3, 3, 0, 0, 0, 0 }, 
{"FNOP", "D9D0", 0, 0, 0, 0, 0, 0 }, 
{"FPATAN", "D9F3", 0, 0, 0, 0, 0, 0 }, 
{"FPTAN", "D9F2", 0, 0, 0, 0, 0, 0 }, 
{"FPREM", "D9F8", 0, 0, 0, 0, 0, 0 }, 
{"FPREM1", "D9F5", 0, 0, 0, 0, 0, 0 }, 
{"FRNDINT", "D9FC", 0, 0, 0, 0, 0, 0 }, 
{"FSAVE", "9BDD/6", 3, 0, 0, 0, 0, 0 }, 
{"FNSAVE", "DD/6", 3, 0, 0, 0, 0, 0 }, 
{"FRSTOR", "DD/4", 3, 0, 0, 0, 0, 0 }, 
{"FSCALE", "D9FD", 0, 0, 0, 0, 0, 0 }, 
{"FSETPM", "DBE4", 0, 0, 0, 0, 0, 0 }, 
{"FSIN", "D9FE", 0, 0, 0, 0, 0, 0 }, 
{"FSINCOS", "D9FB", 0, 0, 0, 0, 0, 0 }, 
{"FSQRT", "D9FA", 0, 0, 0, 0, 0, 0 }, 
{"FST", "D9/2", 3, 3, 0, 0, 0, 0 }, 
{"FSTP", "D9/3", 3, 3, 0, 0, 0, 0 }, 
{"FSTCW", "9BD9/0", 3, 2, 0, 0, 0, 0 }, 
{"FNSTCW", "D9/0", 3, 2, 0, 0, 0, 0 }, 
{"FSTENV", "9BD9/6", 3, 0, 0, 0, 0, 0 }, 
{"FNSTENV", "D9/6", 3, 0, 0, 0, 0, 0 }, 
{"FSTSW", "9BDD/0", 3, 2, 0, 0, 0, 0 }, 
{"FSTSW", "9BDFE0", 4, 8, 0, 0, 0, 0 }, 
{"FNSTSW", "DD/0", 3, 2, 0, 0, 0, 0 }, 
{"FNSTSW", "DFE0", 4, 8, 0, 0, 0, 0 }, 
{"FSUB", "D8/4", 3, 3, 0, 0, 0, 0 }, 
{"FSUBR", "D8/5", 3, 3, 0, 0, 0, 0 }, 
{"FTST", "D9E4", 0, 0, 0, 0, 0, 0 }, 
{"FUCOMPP", "DAE9", 0, 0, 0, 0, 0, 0 }, 
{"FWAIT", "9B", 0, 0, 0, 0, 0, 0 }, 
{"FXAM", "D9E5", 0, 0, 0, 0, 0, 0 }, 
{"FXCH", "D9C9", 0, 0, 0, 0, 0, 0 }, 
{"FXTRACT", "D9F4", 0, 0, 0, 0, 0, 0 }, 
{"FYL2X", "D9F1", 0, 0, 0, 0, 0, 0 }, 
{"FYL2XP1", "D9F9", 0, 0, 0, 0, 0, 0 }, 
{"HLT", "F4", 0, 0, 0, 0, 0, 0 }, 
{"IDIV", "F6/7", 1, 1, 0, 0, 0, 0 }, 
{"IDIV", "poF7/7", 1, 2, 0, 0, 0, 0 }, 
{"IDIV", "poF7/7", 1, 3, 0, 0, 0, 0 }, 
{"IMUL", "F6/5", 1, 1, 0, 0, 0, 0 }, 
{"IMUL", "poF7/5", 1, 2, 0, 0, 0, 0 }, 
{"IMUL", "poF7/5", 1, 3, 0, 0, 0, 0 }, 
{"IMUL", "po0FAF/r", 2, 2, 1, 2, 0, 0 }, 
{"IMUL", "po0FAF/r", 2, 3, 1, 3, 0, 0 }, 
{"IMUL", "po6B/rib", 2, 2, 5, 1, 0, 0 }, 
{"IMUL", "po69/riw", 2, 2, 5, 2, 0, 0 }, 
{"IMUL", "po6B/rib", 2, 3, 5, 1, 0, 0 }, 
{"IMUL", "po69/rid", 2, 3, 5, 3, 0, 0 }, 
{"IMUL", "po6B/rib", 2, 2, 1, 2, 5, 1 }, 
{"IMUL", "po69/riw", 2, 2, 1, 2, 5, 2 }, 
{"IMUL", "po6B/rib", 2, 3, 1, 3, 5, 1 }, 
{"IMUL", "po69/rid", 2, 3, 1, 3, 5, 3 }, 
{"IN", "E4ib", 4, 0, 5, 1, 0, 0 }, 
{"IN", "poE5ib", 4, 8, 5, 1, 0, 0 }, 
{"IN", "poE5ib", 4, 16, 5, 1, 0, 0 }, 
{"IN", "EC", 4, 0, 4, 10, 0, 0 }, 
{"IN", "poED", 4, 8, 4, 10, 0, 0 }, 
{"IN", "poED", 4, 16, 4, 10, 0, 0 }, 
{"INC", "po40+r", 2, 2, 0, 0, 0, 0 }, 
{"INC", "po40+r", 2, 3, 0, 0, 0, 0 }, 
{"INC", "FE/0", 1, 1, 0, 0, 0, 0 }, 
{"INC", "poFF/0", 1, 2, 0, 0, 0, 0 }, 
{"INC", "poFF/0", 1, 3, 0, 0, 0, 0 }, 
{"INSB", "6C", 0, 0, 0, 0, 0, 0 }, 
{"INSW", "po6D", 0, 0, 0, 0, 0, 0 }, 
{"INSD", "po6D", 0, 0, 0, 0, 0, 0 }, 
{"INT", "CDib", 5, 1, 0, 0, 0, 0 }, 
{"INT1", "F1", 0, 0, 0, 0, 0, 0 }, 
{"ICEBP", "F1", 0, 0, 0, 0, 0, 0 }, 
{"INT01", "F1", 0, 0, 0, 0, 0, 0 }, 
{"INT3", "CC", 0, 0, 0, 0, 0, 0 }, 
{"INT03", "CC", 0, 0, 0, 0, 0, 0 }, 
{"INTO", "CE", 0, 0, 0, 0, 0, 0 }, 
{"INVD", "0F08", 0, 0, 0, 0, 0, 0 }, 
{"INVLPG", "0F01/0", 3, 0, 0, 0, 0, 0 }, 
{"IRET", "CF", 0, 0, 0, 0, 0, 0 }, 
{"IRETW", "pwCF", 0, 0, 0, 0, 0, 0 }, 
{"IRETD", "poCF", 0, 0, 0, 0, 0, 0 }, 
{"JCXZ", "poE3-b", 5, 3, 0, 0, 0, 0 }, 
{"JECXZ", "poE3-b", 5, 3, 0, 0, 0, 0 }, 
{"JMP", "E9-i", 5, 3, 0, 0, 0, 0 }, 
{"JMP", "EB-b", 5, 3, 0, 0, 0, 0 }, 
{"JMP", "poFF/5", 3, 0, 0, 0, 0, 0 }, 
{"JMP", "poFF/4", 1, 2, 0, 0, 0, 0 }, 
{"JMP", "poFF/4", 1, 3, 0, 0, 0, 0 }, 
{"JO", "70-b", 5, 3, 0, 0, 0, 0 }, 
{"JNO", "71-b", 5, 3, 0, 0, 0, 0 }, 
{"JB", "72-b", 5, 3, 0, 0, 0, 0 }, 
{"JC", "72-b", 5, 3, 0, 0, 0, 0 }, 
{"JNEA", "72-b", 5, 3, 0, 0, 0, 0 }, 
{"JAE", "73-b", 5, 3, 0, 0, 0, 0 }, 
{"JNB", "73-b", 5, 3, 0, 0, 0, 0 }, 
{"JNC", "73-b", 5, 3, 0, 0, 0, 0 }, 
{"JE", "74-b", 5, 3, 0, 0, 0, 0 }, 
{"JZ", "74-b", 5, 3, 0, 0, 0, 0 }, 
{"JNE", "75-b", 5, 3, 0, 0, 0, 0 }, 
{"JNZ", "75-b", 5, 3, 0, 0, 0, 0 }, 
{"JBE", "76-b", 5, 3, 0, 0, 0, 0 }, 
{"JNA", "76-b", 5, 3, 0, 0, 0, 0 }, 
{"JA", "77-b", 5, 3, 0, 0, 0, 0 }, 
{"JNBE", "77-b", 5, 3, 0, 0, 0, 0 }, 
{"JS", "78-b", 5, 3, 0, 0, 0, 0 }, 
{"JP", "7A-b", 5, 3, 0, 0, 0, 0 }, 
{"JPE", "7A-b", 5, 3, 0, 0, 0, 0 }, 
{"JNP", "7B-b", 5, 3, 0, 0, 0, 0 }, 
{"JPO", "7B-b", 5, 3, 0, 0, 0, 0 }, 
{"JL", "7C-b", 5, 3, 0, 0, 0, 0 }, 
{"JNGE", "7C-b", 5, 3, 0, 0, 0, 0 }, 
{"JGE", "7D-b", 5, 3, 0, 0, 0, 0 }, 
{"JNL", "7D-b", 5, 3, 0, 0, 0, 0 }, 
{"JLE", "7E-b", 5, 3, 0, 0, 0, 0 }, 
{"JNG", "7E-b", 5, 3, 0, 0, 0, 0 }, 
{"JG", "7F-b", 5, 3, 0, 0, 0, 0 }, 
{"JNLE", "7F-b", 5, 3, 0, 0, 0, 0 }, 
{"JO", "0F80-i", 5, 3, 0, 0, 0, 0 }, 
{"JNO", "0F81-i", 5, 3, 0, 0, 0, 0 }, 
{"JB", "0F82-i", 5, 3, 0, 0, 0, 0 }, 
{"JC", "0F82-i", 5, 3, 0, 0, 0, 0 }, 
{"JNEA", "0F82-i", 5, 3, 0, 0, 0, 0 }, 
{"JAE", "0F83-i", 5, 3, 0, 0, 0, 0 }, 
{"JNB", "0F83-i", 5, 3, 0, 0, 0, 0 }, 
{"JNC", "0F83-i", 5, 3, 0, 0, 0, 0 }, 
{"JE", "0F84-i", 5, 3, 0, 0, 0, 0 }, 
{"JZ", "0F84-i", 5, 3, 0, 0, 0, 0 }, 
{"JNE", "0F85-i", 5, 3, 0, 0, 0, 0 }, 
{"JNZ", "0F85-i", 5, 3, 0, 0, 0, 0 }, 
{"JBE", "0F86-i", 5, 3, 0, 0, 0, 0 }, 
{"JNA", "0F86-i", 5, 3, 0, 0, 0, 0 }, 
{"JA", "0F87-i", 5, 3, 0, 0, 0, 0 }, 
{"JNBE", "0F87-i", 5, 3, 0, 0, 0, 0 }, 
{"JS", "0F88-i", 5, 3, 0, 0, 0, 0 }, 
{"JNS", "0F89-i", 5, 3, 0, 0, 0, 0 }, 
{"JP", "0F8A-i", 5, 3, 0, 0, 0, 0 }, 
{"JPE", "0F8A-i", 5, 3, 0, 0, 0, 0 }, 
{"JNP", "0F8B-i", 5, 3, 0, 0, 0, 0 }, 
{"JPO", "0F8B-i", 5, 3, 0, 0, 0, 0 }, 
{"JL", "0F8C-i", 5, 3, 0, 0, 0, 0 }, 
{"JNGE", "0F8C-i", 5, 3, 0, 0, 0, 0 }, 
{"JGE", "0F8D-i", 5, 3, 0, 0, 0, 0 }, 
{"JNL", "0F8D-i", 5, 3, 0, 0, 0, 0 }, 
{"JLE", "0F8E-i", 5, 3, 0, 0, 0, 0 }, 
{"JNG", "0F8E-i", 5, 3, 0, 0, 0, 0 }, 
{"JG", "0F8F-i", 5, 3, 0, 0, 0, 0 }, 
{"JNLE", "0F8F-i", 5, 3, 0, 0, 0, 0 }, 
{"LAHF", "9F", 0, 0, 0, 0, 0, 0 }, 
{"LDS", "poC5/r", 2, 2, 3, 0, 0, 0 }, 
{"LDS", "poC5/r", 2, 3, 3, 0, 0, 0 }, 
{"LES", "poC4/r", 2, 2, 3, 0, 0, 0 }, 
{"LES", "poC4/r", 2, 3, 3, 0, 0, 0 }, 
{"LFS", "po0FB4/r", 2, 2, 3, 0, 0, 0 }, 
{"LFS", "po0FB4/r", 2, 3, 3, 0, 0, 0 }, 
{"LGS", "po0FB5/r", 2, 2, 3, 0, 0, 0 }, 
{"LGS", "po0FB5/r", 2, 3, 3, 0, 0, 0 }, 
{"LSS", "po0FB2/r", 2, 2, 3, 0, 0, 0 }, 
{"LSS", "po0FB2/r", 2, 3, 3, 0, 0, 0 }, 
{"LDMXCSR", "0FAE/2", 3, 3, 0, 0, 0, 0 }, 
{"LEA", "po8D/r", 2, 2, 3, 0, 0, 0 }, 
{"LEA", "po8D/r", 2, 3, 3, 0, 0, 0 }, 
{"LEAVE", "C9", 0, 0, 0, 0, 0, 0 }, 
{"LODSB", "AC", 0, 0, 0, 0, 0, 0 }, 
{"LODSW", "pwAD", 0, 0, 0, 0, 0, 0 }, 
{"LODSD", "poAD", 0, 0, 0, 0, 0, 0 }, 
{"LOOP", "E2-b", 5, 3, 0, 0, 0, 0 }, 
{"LOOP", "paE2-b", 5, 3, 4, 9, 0, 0 }, 
{"LOOP", "paE2-b", 5, 3, 4, 17, 0, 0 }, 
{"LOOPE", "E1-b", 5, 3, 0, 0, 0, 0 }, 
{"LOOPE", "paE1-b", 5, 3, 4, 9, 0, 0 }, 
{"LOOPE", "paE1-b", 5, 3, 4, 17, 0, 0 }, 
{"LOOPZ", "E1-b", 5, 3, 0, 0, 0, 0 }, 
{"LOOPZ", "paE1-b", 5, 3, 4, 9, 0, 0 }, 
{"LOOPZ", "paE1-b", 5, 3, 4, 17, 0, 0 }, 
{"LOOPNE", "E0-b", 5, 3, 0, 0, 0, 0 }, 
{"LOOPNE", "paE0-b", 5, 3, 4, 9, 0, 0 }, 
{"LOOPNE", "paE0-b", 5, 3, 4, 17, 0, 0 }, 
{"LOOPNZ", "E0-b", 5, 3, 0, 0, 0, 0 }, 
{"LOOPNZ", "paE0-b", 5, 3, 4, 9, 0, 0 }, 
{"LOOPNZ", "paE0-b", 5, 3, 4, 17, 0, 0 }, 
{"MOV", "88/r", 1, 1, 2, 1, 0, 0 }, 
{"MOV", "po89/r", 1, 2, 2, 2, 0, 0 }, 
{"MOV", "po89/r", 1, 3, 2, 3, 0, 0 }, 
{"MOV", "8A/r", 2, 1, 1, 1, 0, 0 }, 
{"MOV", "po8B/r", 2, 2, 1, 2, 0, 0 }, 
{"MOV", "po8B/r", 2, 3, 1, 3, 0, 0 }, 
{"MOV", "B0+rib", 2, 1, 5, 1, 0, 0 }, 
{"MOV", "poB8+riw", 2, 2, 5, 2, 0, 0 }, 
{"MOV", "poB8+rid", 2, 3, 5, 3, 0, 0 }, 
{"MOV", "C6/0ib", 1, 1, 5, 1, 0, 0 }, 
{"MOV", "poC7/0iw", 1, 2, 5, 2, 0, 0 }, 
{"MOV", "poC7/0id", 1, 3, 5, 3, 0, 0 }, 
{"MOVSB", "A4", 0, 0, 0, 0, 0, 0 }, 
{"MOVSW", "pwA5", 0, 0, 0, 0, 0, 0 }, 
{"MOVSD", "poA5", 0, 0, 0, 0, 0, 0 }, 
{"MOVSX", "po0FBE/r", 2, 2, 1, 1, 0, 0 }, 
{"MOVSX", "po0FBE/r", 2, 3, 1, 1, 0, 0 }, 
{"MOVSX", "po0FBF/r", 2, 3, 1, 2, 0, 0 }, 
{"MOVZX", "po0FB6/r", 2, 2, 1, 1, 0, 0 }, 
{"MOVZX", "po0FB6/r", 2, 3, 1, 1, 0, 0 }, 
{"MOVZX", "po0FB7/r", 2, 3, 1, 2, 0, 0 }, 
{"MUL", "F6/4", 1, 1, 0, 0, 0, 0 }, 
{"MUL", "poF7/4", 1, 2, 0, 0, 0, 0 }, 
{"MUL", "poF7/4", 1, 3, 0, 0, 0, 0 }, 
{"NEG", "F6/3", 1, 1, 0, 0, 0, 0 }, 
{"NEG", "poF7/3", 1, 2, 0, 0, 0, 0 }, 
{"NEG", "poF7/3", 1, 3, 0, 0, 0, 0 }, 
{"NOT", "F6/2", 1, 1, 0, 0, 0, 0 }, 
{"NOT", "poF7/2", 1, 2, 0, 0, 0, 0 }, 
{"NOT", "poF7/2", 1, 3, 0, 0, 0, 0 }, 
{"NOP", "90", 0, 0, 0, 0, 0, 0 }, 
{"OR", "08/r", 1, 1, 2, 1, 0, 0 }, 
{"OR", "po09/r", 1, 2, 2, 2, 0, 0 }, 
{"OR", "po09/r", 1, 3, 2, 3, 0, 0 }, 
{"OR", "0A/r", 2, 1, 1, 1, 0, 0 }, 
{"OR", "po0B/r", 2, 2, 1, 2, 0, 0 }, 
{"OR", "po0B/r", 2, 3, 1, 3, 0, 0 }, 
{"OR", "80/1ib", 1, 1, 5, 1, 0, 0 }, 
{"OR", "po81/1iw", 1, 2, 5, 2, 0, 0 }, 
{"OR", "po81/1id", 1, 3, 5, 3, 0, 0 }, 
{"OR", "po83/1ib", 1, 2, 5, 1, 0, 0 }, 
{"OR", "po83/1ib", 1, 3, 5, 1, 0, 0 }, 
{"OR", "0Cib", 4, 0, 5, 1, 0, 0 }, 
{"OR", "po0Diw", 4, 8, 5, 2, 0, 0 }, 
{"OR", "po0Did", 4, 16, 5, 3, 0, 0 }, 
{"OUT", "E6ib", 5, 1, 4, 0, 0, 0 }, 
{"OUT", "poE7ib", 5, 1, 4, 8, 0, 0 }, 
{"OUT", "poE7ib", 5, 1, 4, 16, 0, 0 }, 
{"OUT", "EE", 4, 10, 4, 0, 0, 0 }, 
{"OUT", "poEF", 4, 10, 4, 8, 0, 0 }, 
{"OUT", "poEF", 4, 10, 4, 16, 0, 0 }, 
{"OUTSB", "6E", 0, 0, 0, 0, 0, 0 }, 
{"OUTSW", "po6F", 0, 0, 0, 0, 0, 0 }, 
{"OUTSD", "po6F", 0, 0, 0, 0, 0, 0 }, 
{"POP", "po58+r", 2, 2, 0, 0, 0, 0 }, 
{"POP", "po58+r", 2, 3, 0, 0, 0, 0 }, 
{"POP", "po8F/0", 1, 2, 0, 0, 0, 0 }, 
{"POP", "po8F/0", 1, 3, 0, 0, 0, 0 }, 
{"POPA", "61", 0, 0, 0, 0, 0, 0 }, 
{"POPAW", "po61", 0, 0, 0, 0, 0, 0 }, 
{"POPAD", "po61", 0, 0, 0, 0, 0, 0 }, 
{"POPF", "9D", 0, 0, 0, 0, 0, 0 }, 
{"POPFW", "po9D", 0, 0, 0, 0, 0, 0 }, 
{"POPFD", "po9D", 0, 0, 0, 0, 0, 0 }, 
{"PREFETCH", "0F0D/0", 3, 0, 0, 0, 0, 0 }, 
{"PREFETCHW", "0F0D/1", 3, 0, 0, 0, 0, 0 }, 
{"PREFETCHNTA", "0F18/0", 3, 0, 0, 0, 0, 0 }, 
{"PREFETCHT0", "0F18/1", 3, 0, 0, 0, 0, 0 }, 
{"PREFETCHT1", "0F18/2", 3, 0, 0, 0, 0, 0 }, 
{"PREFETCHT2", "0F18/3", 3, 0, 0, 0, 0, 0 }, 
{"PUSH", "po50+r", 2, 2, 0, 0, 0, 0 }, 
{"PUSH", "po50+r", 2, 3, 0, 0, 0, 0 }, 
{"PUSH", "poFF/6", 1, 2, 0, 0, 0, 0 }, 
{"PUSH", "poFF/6", 1, 3, 0, 0, 0, 0 }, 
{"PUSH", "6Aib", 5, 1, 0, 0, 0, 0 }, 
{"PUSH", "po68iw", 5, 2, 0, 0, 0, 0 }, 
{"PUSH", "po68id", 5, 3, 0, 0, 0, 0 }, 
{"PUSHA", "60", 0, 0, 0, 0, 0, 0 }, 
{"PUSHAD", "po60", 0, 0, 0, 0, 0, 0 }, 
{"PUSHAW", "po60", 0, 0, 0, 0, 0, 0 }, 
{"PUSHF", "9C", 0, 0, 0, 0, 0, 0 }, 
{"PUSHFD", "po9C", 0, 0, 0, 0, 0, 0 }, 
{"PUSHFW", "po9C", 0, 0, 0, 0, 0, 0 }, 
{"RCL", "D0/2", 1, 1, 5, 1, 0, 0 }, 
{"RCL", "D2/2", 1, 1, 4, 1, 0, 0 }, 
{"RCL", "C0/2ib", 1, 1, 5, 1, 0, 0 }, 
{"RCL", "poD1/2", 1, 2, 5, 1, 0, 0 }, 
{"RCL", "poD3/2", 1, 2, 4, 1, 0, 0 }, 
{"RCL", "poC1/2ib", 1, 2, 5, 1, 0, 0 }, 
{"RCL", "poD1/2", 1, 3, 5, 1, 0, 0 }, 
{"RCL", "poD3/2", 1, 3, 4, 1, 0, 0 }, 
{"RCL", "poC1/2ib", 1, 3, 5, 1, 0, 0 }, 
{"RCR", "D0/3", 1, 1, 5, 1, 0, 0 }, 
{"RCR", "D2/3", 1, 1, 4, 1, 0, 0 }, 
{"RCR", "C0/3ib", 1, 1, 5, 1, 0, 0 }, 
{"RCR", "poD1/3", 1, 2, 5, 1, 0, 0 }, 
{"RCR", "poD3/3", 1, 2, 4, 1, 0, 0 }, 
{"RCR", "poC1/3ib", 1, 2, 5, 1, 0, 0 }, 
{"RCR", "poD1/3", 1, 3, 5, 1, 0, 0 }, 
{"RCR", "poD3/3", 1, 3, 4, 1, 0, 0 }, 
{"RCR", "poC1/3ib", 1, 3, 5, 1, 0, 0 }, 
{"RDMSR", "0F32", 0, 0, 0, 0, 0, 0 }, 
{"RDPMC", "0F33", 0, 0, 0, 0, 0, 0 }, 
{"RDTSC", "0F31", 0, 0, 0, 0, 0, 0 }, 
{"RET", "C3", 0, 0, 0, 0, 0, 0 }, 
{"RET", "C2iw", 5, 2, 0, 0, 0, 0 }, 
{"RETF", "CB", 0, 0, 0, 0, 0, 0 }, 
{"RETF", "CAiw", 5, 2, 0, 0, 0, 0 }, 
{"RETN", "C3", 0, 0, 0, 0, 0, 0 }, 
{"RETN", "C2iw", 5, 2, 0, 0, 0, 0 }, 
{"ROL", "D0/0", 1, 1, 5, 1, 0, 0 }, 
{"ROL", "D2/0", 1, 1, 4, 1, 0, 0 }, 
{"ROL", "C0/0ib", 1, 1, 5, 1, 0, 0 }, 
{"ROL", "poD1/0", 1, 2, 5, 1, 0, 0 }, 
{"ROL", "poD3/0", 1, 2, 4, 1, 0, 0 }, 
{"ROL", "poC1/0ib", 1, 2, 5, 1, 0, 0 }, 
{"ROL", "poD1/0", 1, 3, 5, 1, 0, 0 }, 
{"ROL", "poD3/0", 1, 3, 4, 1, 0, 0 }, 
{"ROL", "poC1/0ib", 1, 3, 5, 1, 0, 0 }, 
{"ROR", "D0/1", 1, 1, 5, 1, 0, 0 }, 
{"ROR", "D2/1", 1, 1, 4, 1, 0, 0 }, 
{"ROR", "C0/1ib", 1, 1, 5, 1, 0, 0 }, 
{"ROR", "poD1/1", 1, 2, 5, 1, 0, 0 }, 
{"ROR", "poD3/1", 1, 2, 4, 1, 0, 0 }, 
{"ROR", "poC1/1ib", 1, 2, 5, 1, 0, 0 }, 
{"ROR", "poD1/1", 1, 3, 5, 1, 0, 0 }, 
{"ROR", "poD3/1", 1, 3, 4, 1, 0, 0 }, 
{"ROR", "poC1/1ib", 1, 3, 5, 1, 0, 0 }, 
{"RSM", "0FAA", 0, 0, 0, 0, 0, 0 }, 
{"SAHF", "9E", 0, 0, 0, 0, 0, 0 }, 
{"SAL", "D0/4", 1, 1, 5, 1, 0, 0 }, 
{"SAL", "D2/4", 1, 1, 4, 1, 0, 0 }, 
{"SAL", "C0/4ib", 1, 1, 5, 1, 0, 0 }, 
{"SAL", "poD1/4", 1, 2, 5, 1, 0, 0 }, 
{"SAL", "poD3/4", 1, 2, 4, 1, 0, 0 }, 
{"SAL", "poC1/4ib", 1, 2, 5, 1, 0, 0 }, 
{"SAL", "poD1/4", 1, 3, 5, 1, 0, 0 }, 
{"SAL", "poD3/4", 1, 3, 4, 1, 0, 0 }, 
{"SAL", "poC1/4ib", 1, 3, 5, 1, 0, 0 }, 
{"SAR", "D0/7", 1, 1, 5, 1, 0, 0 }, 
{"SAR", "D2/7", 1, 1, 4, 1, 0, 0 }, 
{"SAR", "C0/7ib", 1, 1, 5, 1, 0, 0 }, 
{"SAR", "poD1/7", 1, 2, 5, 1, 0, 0 }, 
{"SAR", "poD3/7", 1, 2, 4, 1, 0, 0 }, 
{"SAR", "poC1/7ib", 1, 2, 5, 1, 0, 0 }, 
{"SAR", "poD1/7", 1, 3, 5, 1, 0, 0 }, 
{"SAR", "poD3/7", 1, 3, 4, 1, 0, 0 }, 
{"SAR", "poC1/7ib", 1, 3, 5, 1, 0, 0 }, 
{"SBB", "18/r", 1, 1, 2, 1, 0, 0 }, 
{"SBB", "po19/r", 1, 2, 2, 2, 0, 0 }, 
{"SBB", "po19/r", 1, 3, 2, 3, 0, 0 }, 
{"SBB", "1A/r", 2, 1, 1, 1, 0, 0 }, 
{"SBB", "po1B/r", 2, 2, 1, 2, 0, 0 }, 
{"SBB", "po1B/r", 2, 3, 1, 3, 0, 0 }, 
{"SBB", "80/3ib", 1, 1, 5, 1, 0, 0 }, 
{"SBB", "po81/3iw", 1, 2, 5, 2, 0, 0 }, 
{"SBB", "po81/3id", 1, 3, 5, 3, 0, 0 }, 
{"SBB", "po83/3ib", 1, 2, 5, 1, 0, 0 }, 
{"SBB", "po83/3ib", 1, 3, 5, 1, 0, 0 }, 
{"SBB", "1Cib", 4, 0, 5, 1, 0, 0 }, 
{"SBB", "po1Diw", 4, 8, 5, 2, 0, 0 }, 
{"SBB", "po1Did", 4, 16, 5, 3, 0, 0 }, 
{"SCASB", "AE", 0, 0, 0, 0, 0, 0 }, 
{"SCASW", "pwAF", 0, 0, 0, 0, 0, 0 }, 
{"SCASD", "poAF", 0, 0, 0, 0, 0, 0 }, 
{"SETO", "0F90/2", 1, 1, 0, 0, 0, 0 }, 
{"SETNO", "0F91/2", 1, 1, 0, 0, 0, 0 }, 
{"SETB", "0F92/2", 1, 1, 0, 0, 0, 0 }, 
{"SETC", "0F92/2", 1, 1, 0, 0, 0, 0 }, 
{"SETNEA", "0F92/2", 1, 1, 0, 0, 0, 0 }, 
{"SETAE", "0F93/2", 1, 1, 0, 0, 0, 0 }, 
{"SETNB", "0F93/2", 1, 1, 0, 0, 0, 0 }, 
{"SETNC", "0F93/2", 1, 1, 0, 0, 0, 0 }, 
{"SETE", "0F94/2", 1, 1, 0, 0, 0, 0 }, 
{"SETZ", "0F94/2", 1, 1, 0, 0, 0, 0 }, 
{"SETNE", "0F95/2", 1, 1, 0, 0, 0, 0 }, 
{"SETNZ", "0F95/2", 1, 1, 0, 0, 0, 0 }, 
{"SETBE", "0F96/2", 1, 1, 0, 0, 0, 0 }, 
{"SETNA", "0F96/2", 1, 1, 0, 0, 0, 0 }, 
{"SETA", "0F97/2", 1, 1, 0, 0, 0, 0 }, 
{"SETNBE", "0F97/2", 1, 1, 0, 0, 0, 0 }, 
{"SETS", "0F98/2", 1, 1, 0, 0, 0, 0 }, 
{"SETNS", "0F99/2", 1, 1, 0, 0, 0, 0 }, 
{"SETP", "0F9A/2", 1, 1, 0, 0, 0, 0 }, 
{"SETPE", "0F9A/2", 1, 1, 0, 0, 0, 0 }, 
{"SETNP", "0F9B/2", 1, 1, 0, 0, 0, 0 }, 
{"SETPO", "0F9B/2", 1, 1, 0, 0, 0, 0 }, 
{"SETL", "0F9C/2", 1, 1, 0, 0, 0, 0 }, 
{"SETNGE", "0F9C/2", 1, 1, 0, 0, 0, 0 }, 
{"SETGE", "0F9D/2", 1, 1, 0, 0, 0, 0 }, 
{"SETNL", "0F9D/2", 1, 1, 0, 0, 0, 0 }, 
{"SETLE", "0F9E/2", 1, 1, 0, 0, 0, 0 }, 
{"SETNG", "0F9E/2", 1, 1, 0, 0, 0, 0 }, 
{"SETG", "0F9F/2", 1, 1, 0, 0, 0, 0 }, 
{"SETNLE", "0F9F/2", 1, 1, 0, 0, 0, 0 }, 
{"SFENCE", "0FAE/7", 0, 0, 0, 0, 0, 0 }, 
{"SHL", "D0/4", 1, 1, 5, 1, 0, 0 }, 
{"SHL", "D2/4", 1, 1, 4, 1, 0, 0 }, 
{"SHL", "C0/4ib", 1, 1, 5, 1, 0, 0 }, 
{"SHL", "poD1/4", 1, 2, 5, 1, 0, 0 }, 
{"SHL", "poD3/4", 1, 2, 4, 1, 0, 0 }, 
{"SHL", "poC1/4ib", 1, 2, 5, 1, 0, 0 }, 
{"SHL", "poD1/4", 1, 3, 5, 1, 0, 0 }, 
{"SHL", "poD3/4", 1, 3, 4, 1, 0, 0 }, 
{"SHL", "poC1/4ib", 1, 3, 5, 1, 0, 0 }, 
{"SHR", "D0/5", 1, 1, 5, 1, 0, 0 }, 
{"SHR", "D2/5", 1, 1, 4, 1, 0, 0 }, 
{"SHR", "C0/5ib", 1, 1, 5, 1, 0, 0 }, 
{"SHR", "poD1/5", 1, 2, 5, 1, 0, 0 }, 
{"SHR", "poD3/5", 1, 2, 4, 1, 0, 0 }, 
{"SHR", "poC1/5ib", 1, 2, 5, 1, 0, 0 }, 
{"SHR", "poD1/5", 1, 3, 5, 1, 0, 0 }, 
{"SHR", "poD3/5", 1, 3, 4, 1, 0, 0 }, 
{"SHR", "poC1/5ib", 1, 3, 5, 1, 0, 0 }, 
{"SHLD", "po0FA4/rib", 1, 2, 2, 2, 5, 1 }, 
{"SHLD", "po0FA4/rib", 1, 3, 2, 3, 5, 1 }, 
{"SHLD", "po0FA5/r", 1, 2, 2, 2, 4, 1 }, 
{"SHLD", "po0FA5/r", 1, 3, 2, 3, 4, 1 }, 
{"SHRD", "po0FAC/rib", 1, 2, 2, 2, 5, 1 }, 
{"SHRD", "po0FAC/rib", 1, 3, 2, 3, 5, 1 }, 
{"SHRD", "po0FAD/r", 1, 2, 2, 2, 4, 1 }, 
{"SHRD", "po0FAD/r", 1, 3, 2, 3, 4, 1 }, 
{"SMINT", "0F38", 0, 0, 0, 0, 0, 0 }, 
{"SMINTOLD", "0F7E", 0, 0, 0, 0, 0, 0 }, 
{"STC", "F9", 0, 0, 0, 0, 0, 0 }, 
{"STD", "FD", 0, 0, 0, 0, 0, 0 }, 
{"STI", "FB", 0, 0, 0, 0, 0, 0 }, 
{"STMXCSR", "0FAE/3", 3, 3, 0, 0, 0, 0 }, 
{"STOSB", "AA", 0, 0, 0, 0, 0, 0 }, 
{"STOSW", "pwAB", 0, 0, 0, 0, 0, 0 }, 
{"STOSD", "poAB", 0, 0, 0, 0, 0, 0 }, 
{"SUB", "28/r", 1, 1, 2, 1, 0, 0 }, 
{"SUB", "po29/r", 1, 2, 2, 2, 0, 0 }, 
{"SUB", "po29/r", 1, 3, 2, 3, 0, 0 }, 
{"SUB", "2A/r", 2, 1, 1, 1, 0, 0 }, 
{"SUB", "po2B/r", 2, 2, 1, 2, 0, 0 }, 
{"SUB", "po2B/r", 2, 3, 1, 3, 0, 0 }, 
{"SUB", "80/5ib", 1, 1, 5, 1, 0, 0 }, 
{"SUB", "po81/5iw", 1, 2, 5, 2, 0, 0 }, 
{"SUB", "po81/5id", 1, 3, 5, 3, 0, 0 }, 
{"SUB", "po83/5ib", 1, 2, 5, 1, 0, 0 }, 
{"SUB", "po83/5ib", 1, 3, 5, 1, 0, 0 }, 
{"SUB", "2Cib", 4, 0, 5, 1, 0, 0 }, 
{"SUB", "po2Diw", 4, 8, 5, 2, 0, 0 }, 
{"SUB", "po2Did", 4, 16, 5, 3, 0, 0 }, 
{"SYSENTER", "0F34", 0, 0, 0, 0, 0, 0 }, 
{"TEST", "84/r", 1, 1, 2, 1, 0, 0 }, 
{"TEST", "po85/r", 1, 2, 2, 2, 0, 0 }, 
{"TEST", "po85/r", 1, 3, 2, 3, 0, 0 }, 
{"TEST", "F6/7ib", 1, 1, 5, 1, 0, 0 }, 
{"TEST", "poF7/7iw", 1, 2, 5, 2, 0, 0 }, 
{"TEST", "poF7/7id", 1, 3, 5, 3, 0, 0 }, 
{"TEST", "A8ib", 4, 0, 5, 1, 0, 0 }, 
{"TEST", "poA9iw", 4, 8, 5, 2, 0, 0 }, 
{"TEST", "poA9id", 4, 16, 5, 3, 0, 0 }, 
{"UD2", "0F0B", 0, 0, 0, 0, 0, 0 }, 
{"WAIT", "9B", 0, 0, 0, 0, 0, 0 }, 
{"WBINVD", "0F09", 0, 0, 0, 0, 0, 0 }, 
{"WRMSR", "0F30", 0, 0, 0, 0, 0, 0 }, 
{"XADD", "0FC0/r", 1, 1, 2, 1, 0, 0 }, 
{"XADD", "po0FC1/r", 1, 2, 2, 2, 0, 0 }, 
{"XADD", "po0FC1/r", 1, 3, 2, 3, 0, 0 }, 
{"XCHG", "86/r", 2, 1, 1, 1, 0, 0 }, 
{"XCHG", "po87/r", 2, 2, 1, 1, 0, 0 }, 
{"XCHG", "po87/r", 2, 3, 1, 3, 0, 0 }, 
{"XCHG", "86/r", 1, 1, 2, 1, 0, 0 }, 
{"XCHG", "po87/r", 1, 2, 2, 2, 0, 0 }, 
{"XCHG", "po87/r", 1, 3, 2, 3, 0, 0 }, 
{"XCHG", "po90+r", 4, 8, 2, 2, 0, 0 }, 
{"XCHG", "po90+r", 4, 16, 2, 3, 0, 0 }, 
{"XCHG", "po90+r", 2, 2, 4, 8, 0, 0 }, 
{"XCHG", "po90+r", 2, 3, 4, 16, 0, 0 }, 
{"XLATB", "D7", 0, 0, 0, 0, 0, 0 }, 
{"XOR", "30/r", 1, 1, 2, 1, 0, 0 }, 
{"XOR", "po31/r", 1, 2, 2, 2, 0, 0 }, 
{"XOR", "po31/r", 1, 3, 2, 3, 0, 0 }, 
{"XOR", "32/r", 2, 1, 1, 1, 0, 0 }, 
{"XOR", "po33/r", 2, 2, 1, 2, 0, 0 }, 
{"XOR", "po33/r", 2, 3, 1, 3, 0, 0 }, 
{"XOR", "80/6ib", 1, 1, 5, 1, 0, 0 }, 
{"XOR", "po81/6iw", 1, 2, 5, 2, 0, 0 }, 
{"XOR", "po81/6id", 1, 3, 5, 3, 0, 0 }, 
{"XOR", "po83/6ib", 1, 2, 5, 1, 0, 0 }, 
{"XOR", "po83/6ib", 1, 3, 5, 1, 0, 0 }, 
{"XOR", "34ib", 4, 0, 5, 1, 0, 0 }, 
{"XOR", "po35iw", 4, 8, 5, 2, 0, 0 }, 
{"XOR", "po35id", 4, 16, 5, 3, 0, 0 }};