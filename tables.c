/************************************************************************
*  MyBB(r) - My Business Basic Interpreter                              *
*  -------------------------------------------------------------------  *
*  Program:    tables.c                                                 *
************************************************************************/

#include "mybb.h"

struct errors errortable[] = 
{
	// System
	{ "Directive or Function Not Available", ERR_DIRECTIVE_NOT_AVAILABLE },
	// Input/Output
	{ "File, Record, or Device Busy/Timeout Error", ERR_TIMEOUT },
	{ "End of Record",                      ERR_END_OF_RECORD },
	{ "End of File",                        ERR_END_OF_FILE },
	{ "Key Field Not Found",                ERR_KEY_FIELD_NOT_FOUND },
	{ "",                                   ERR_BAD1 },
	{ "",                                   ERR_BAD2 },
	{ "",                                   ERR_BAD3 },
	{ "File Corruption Detected",           ERR_FILE_CORRUPTION },
	{ "",                                   ERR_BAD4 },
	{ "",                                   ERR_BAD5 },

	// File Usage
	{ "File ID Size of Key Usage",          ERR_FILEID_SIZE_KEY_USAGE },
	{ "Missing or Duplicate Key",           ERR_MISSING_DUPLICATE_KEY },
	{ "Undefined or Duplicate File ID",     ERR_BAD_FILEID },
	{ "File/Device Access",                 ERR_FILE_DEVICE_BUSY },
	{ "File/Device Usage",                  ERR_FILE_DEVICE_USAGE },
	{ "Out of Disk Space",                  ERR_OUT_OF_DISK_SPACE },
	{ "Disk Directory Capacity",            ERR_DISK_DIRECTORY_CAPACITY },
	{ "Invalid Parameter",                  ERR_INVALID_PARAMETER },
	{ "Illegal Program Encryption Error",   ERR_ILLEGAL_PROG_ENCRYPTION },
	{ "Program Format or Size Incorrect",   ERR_PROGRAM_FORMAT_INCORRECT },

	// Structure
	{ "Statement Structure (Syntax)",       ERR_SYNTAX },
	{ "Statement Number Error",             ERR_STATEMENT_NUMBER },
	{ "Uninitialized Variable",             ERR_UNINITIALIZED_VARIABLE },
	{ "Function Name Definition Already Exists", ERR_FUNC_NAME_ALREADY_EXISTS },
	{ "Undefined Function",                 ERR_UNDEFINED_FUNC },
	{ "Variable Usage",                     ERR_VARIABLE_USAGE },
	{ "Return Without GOSUB",               ERR_RETURN_WITHOUT_GOSUB },
	{ "NEXT Without FOR",                   ERR_NEXT_WITHOUT_FOR },
	{ "Undefined Mnemonic Constant",        ERR_UNDEFINED_MNEMONIC },

	// Limit
	{ "Program Checksum Error",             ERR_PROGRAM_CHECKSUM },
	{ "Internal Stack Overflow",            ERR_INTERNAL_STACK_OVERFLOW },
	{ "Record Too Large for Buffer",        ERR_RECORD_TOO_LARGE },
	{ "Memory Capacity",                    ERR_MEMORY_CAPACITY },
	{ "FOR/NEXT GOSUB/RETURN Stack Overflow", ERR_FOR_GOSUB_STACK_OVERFLOW },
	{ "LISTer Stack Overflow",              ERR_LISTER_STACK_OVERFLOW },
	{ "CALL/ENTER Mismatch",                ERR_CALL_ENTER_MISMATCH },
	{ "Format Structure/Locate Table Overflow", ERR_FORMAT_TABLE_OVERFLOW },
	{ "Illegal Command in a Public Program",ERR_ILLEGAL_COMMAND },
	{ "Escape in a Public Program",         ERR_ESCAPE },

	// Execution
	{ "Numeric Value Overflow",             ERR_NUM_VALUE_OVERFLOW },
	{ "Integer Range",                      ERR_INTEGER_RANGE },
	{ "Nonexistent Subscript",              ERR_NONEXISTENT_SUBSCRIPT },
	{ "Numeric Format Mask Overflow",       ERR_NUM_FORMAT_MASK_OVERFLOW },
	{ "Step Size Zero",                     ERR_STEP_SIZE_ZERO },
	{ "Statement Usage",                    ERR_STATEMENT_USAGE },
	{ "String Size",                        ERR_STRING_SIZE },
	{ "Invalid Substring Reference",        ERR_INVALID_SUBSTRING_REF },
	{ "Input Verification",                 ERR_INPUT_VERIFICATION },
	{ "Global Variable Error",              ERR_GLOBAL_VARIABLE },
	{ "Cannot Remove Primary Sort",         ERR_CANNOT_REMOVE_PRIMARY_SORT },
	{ "Cannot Have More than 16 Sorts for an MSORT File", ERR_SORTS_IN_MSORT },
	{ "Cannot Have More than 8 Sorts for a TISAM File", ERR_SORTS_IN_TISAM },
	{ "Too Many Segment Definitions",       ERR_TOO_MANY_SEGMENT_DEFS },
	{ "Primary Key Must Be Unique",         ERR_PRIMARY_KEY_MUST_BE_UNIQUE },
	{ "Sort Name Too Long",                 ERR_SORT_NAME_TOO_LONG },
	{ "Field Number Greater than 255",      ERR_FIELD_NUMBER },
	{ "Undefined Mode",                     ERR_UNDEFINED_MODE },
	{ "Field Does Not Exist",               ERR_FIELD_DOES_NOT_EXIST },
	{ "",                                   ERR_BAD6 },

	// Transaction Processing
	{ "Transaction Log File Not Open",      ERR_TRANS_LOG_NOT_FOUND },
	{ "Transaction in Progress",            ERR_TRANS_IN_PROGRESS },
	{ "Transaction Not Started",            ERR_TRANS_NOT_STARTED },
	{ "Transaction Log Already Opened",     ERR_TRANS_LOG_ALREADY_OPENED },
	{ "Channel Not Opened For Transaction Modification", ERR_TRANS_CHANNEL_NOT_OPENED },
	{ "Transaction \"IN PROGRESS\" File Exists", ERR_TRANS_PROGRESS_FILE_EXISTS}
};

struct operators optable[] = 
{
	{ "OPT",	OP_OPT,			6 },
	{ "SEP",	OP_SEP,			6 },
	{ "SRT",	OP_SRT,			6 },
	{ "BNK",	OP_BNK,			6 },
	{ "DOM",	OP_DOM,			6 },
	{ "END",	OP_END,			6 },
	{ "IND",	OP_IND,			6 },
	{ "IOL",	OP_IOL,			6 },
	{ "ISZ",	OP_ISZ,			6 },
	{ "KEY",	OP_KEY,			6 },
	{ "SIZ",	OP_SIZ,			6 },
	{ "TBL",	OP_TBL,			6 },
	{ "TIM",	OP_TIM,			6 },
	{ "ERR",	OP_ERR,			6 },
	{ "LEN",	OP_LEN,			6 },
	{ "PWD",	OP_PWD,			6 },
	{ "ATR",	OP_ATR,			6 },
	{ "AND",	OP_AND,			6 },
	{ "XOR",	OP_XOR,			6 },
	{ "OR",		OP_OR,			6 },
	{ "<>",		OP_NOTEQUAL,	5 },
	{ "><",		OP_NOTEQUAL,	5 },
	{ "<=",		OP_LTEQ,		5 },
	{ "=<",		OP_LTEQ,		5 },
	{ ">=",		OP_GTEQ,		5 },
	{ "=>",		OP_GTEQ,		5 },
	{ "**",		OP_EXPONENT,	1 },
	{ "<",		OP_LESSTHAN,	5 },
	{ ">",		OP_GREATTHAN,	5 },
	{ "(",		OP_PAREN,		6 },
	{ "=",		OP_EQUALS,		5 },
	{ "+",		OP_ADD,			4 },
	{ "-",		OP_SUBTRACT,	4 },
	{ "_",		OP_NEGATE,		3 },
	{ "*",		OP_MULTIPLY,	2 },
	{ "/",		OP_DIVIDE,		2 },
	{ "^",		OP_EXPONENT,	1 }
};

//  NAME        OPCODE          AVAILABLE IO OPTIONS
struct commands cmdtable[] = 
{
	{ "<TEMP>", 		0, 					0 },
	{ "DUMPSTMT",		CMD_DUMPSTMT,		IO_CHANNEL },
	{ "START", 			CMD_START, 			IO_ERR + IO_BNK },
	{ "BYE", 			CMD_RELEASE,		0 },
	{ "RELEASE", 		CMD_RELEASE,		0 },
	{ "RUN", 			CMD_RUN,			IO_ERR },
	{ "CALL", 			CMD_CALL, 			IO_ERR },
	{ "ENTER", 			CMD_ENTER, 			0 },
	{ "EXIT", 			CMD_EXIT, 			0 },
	{ "SETTRACE",		CMD_SETTRACE, 		IO_CHANNEL },
	{ "ENDTRACE",		CMD_ENDTRACE, 		IO_CHANNEL },
	{ "ESCAPE", 		CMD_ESCAPE, 		0 },
	{ "LOAD", 			CMD_LOAD, 			0 },
	{ "LAOD", 			CMD_LOAD, 			0 },
	{ "DELETE", 		CMD_DELETE,			0 },
	{ "EDIT", 			CMD_EDIT,			0 },
	{ "MERGE", 			CMD_MERGE, 			IO_CHANNEL + IO_ERR + IO_IND + IO_TBL },
	{ "LIST", 			CMD_LIST, 			IO_CHANNEL + IO_ERR + IO_IND + IO_TBL },
	{ "LSIT", 			CMD_LIST, 			IO_CHANNEL + IO_ERR + IO_IND + IO_TBL },
	//{ "/", 			CMD_LIST, 			IO_CHANNEL + IO_ERR + IO_IND + IO_TBL },
	{ "\\", 			CMD_LIST, 			IO_CHANNEL + IO_ERR + IO_IND + IO_TBL },
	{ "SAVE", 			CMD_SAVE, 			IO_ERR },
	{ "PROGRAM", 		CMD_PROGRAM,		IO_ERR },
	{ "INDEXED", 		CMD_INDEXED,		IO_ERR },
	{ "SERIAL", 		CMD_SERIAL,			IO_ERR },
	{ "SORT", 			CMD_SORT, 			IO_ERR },
	{ "DIRECT", 		CMD_DIRECT,			IO_ERR },
	{ "SYSTEM", 		CMD_SYSTEM,			0 },
	{ "FILE", 			CMD_FILE, 			0 },
	{ "ERASE", 			CMD_ERASE, 			IO_ERR },
	{ "ADD", 			CMD_ADD, 			IO_ERR },
	{ "ADDR", 			CMD_ADDR, 			IO_ERR + IO_BNK },
	{ "DROP", 			CMD_DROP, 			IO_ERR },
	{ "ENABLE", 		CMD_ENABLE,			IO_ERR },
	{ "DISABLE", 		CMD_DISABLE,		IO_ERR },
	{ "RESERVE", 		CMD_RESERVE,		IO_ERR },
	{ "OPEN", 			CMD_OPEN, 			IO_ERR + IO_OPT + IO_ISZ + IO_SEP + IO_DEV + IO_CHANNEL },
	{ "CLOSE",			CMD_CLOSE, 			IO_CHANNEL + IO_ERR },
	{ "LOCK", 			CMD_LOCK, 			IO_CHANNEL + IO_ERR },
	{ "UNLOCK", 		CMD_UNLOCK,			IO_CHANNEL + IO_ERR },
	{ "PUT", 			CMD_PUT, 			IO_ERR },
	{ "PRINT", 			CMD_PRINT, 			IO_CHANNEL + IO_ERR + IO_DOM + IO_END + IO_TBL + IO_IND + IO_KEY + IO_IOL },
	{ "WRITE", 			CMD_WRITE,			IO_CHANNEL + IO_ERR + IO_DOM + IO_END + IO_TBL + IO_IND + IO_KEY + IO_IOL },
	{ "REMOVE", 		CMD_REMOVE,			IO_CHANNEL + IO_KEY + IO_DOM + IO_ERR },
	{ "GET", 			CMD_GET, 			IO_ERR },
	{ "INPUT", 			CMD_INPUT, 			IO_CHANNEL + IO_ERR + IO_DOM + IO_END + IO_TBL + IO_SIZ + IO_TIM + IO_LEN + IO_IND + IO_KEY + IO_IOL },
	{ "READ", 			CMD_READ, 			IO_CHANNEL + IO_IOL + IO_IND + IO_KEY + IO_SRT + IO_ERR + IO_DOM + IO_END + IO_TBL },
	{ "EXTRACT", 		CMD_EXTRACT,		IO_CHANNEL + IO_IOL + IO_IND + IO_KEY + IO_SRT + IO_ERR + IO_DOM + IO_END + IO_TBL },
	{ "FIND", 			CMD_FIND, 			IO_CHANNEL + IO_IOL + IO_IND + IO_KEY + IO_SRT + IO_ERR + IO_DOM + IO_END + IO_TBL },
	{ "RENAME", 		CMD_RENAME,			IO_ERR,  },
	{ "FLOATINGPOINT",	CMD_FLOATPT,		0 },
	{ "PRECISION",		CMD_PRECISION,		0 },
	{ "RESET", 			CMD_RESET, 			0 },
	{ "CLEAR", 			CMD_CLEAR, 			0 },
	{ "BEGIN", 			CMD_BEGIN, 			0 },
	{ "STOP", 			CMD_STOP, 			0 },
	{ "END", 			CMD_END, 			0 },
	{ "ON", 			CMD_ON, 			0 },
	{ "GOTO", 			CMD_GOTO, 			0 },
	{ "GOSUB",			CMD_GOSUB, 			0 },
	{ "SETERR", 		CMD_SETERR,			0 },
	{ "SETERR ON",		CMD_SETERRON,		0 },
	{ "SETERR OFF",		CMD_SETERROFF,		0 },
	{ "SETESC", 		CMD_SETESC, 		0 },
	{ "FOR", 			CMD_FOR, 			0 },
	{ "EXITTO", 		CMD_EXITTO, 		0 },
	{ "RETURN", 		CMD_RETURN, 		0 },
	{ "NEXT", 			CMD_NEXT, 			0 },
	{ "RETRY", 			CMD_RETRY, 			0 },
	{ "EXECUTE", 		CMD_EXECUTE, 		0 },
	{ "REM", 			CMD_REM, 			0 },
	{ "!", 				CMD_REM2, 			0 },  
	{ "DIM", 			CMD_DIM, 			0 },
	{ "TABLE", 			CMD_TABLE, 			0 },
	{ "IOLIST", 		CMD_IOLIST, 		IO_IOL },
	{ "DEF", 			CMD_DEFFN, 			0 },
	{ "SETTIME", 		CMD_SETTIME,		0 },
	{ "SETDAY", 		CMD_SETDAY, 		0 },
	{ "WAIT", 			CMD_WAIT, 			0 },
	{ "LET", 			CMD_LET, 			0 },  
	{ "INPUTRECORD",	CMD_INPUTRECORD,	IO_CHANNEL + IO_ERR + IO_DOM +
											IO_END + IO_TBL + IO_SIZ + IO_TIM + 
											IO_LEN + IO_IND + IO_KEY + IO_IOL },
	{ "READRECORD",		CMD_READRECORD,		IO_CHANNEL + IO_IOL + IO_IND +
											IO_SRT + IO_ERR + IO_DOM + IO_END + 
											IO_TBL + IO_KEY + IO_SIZ },
	{ "EXTRACTRECORD",	CMD_EXTRACTRECORD,	IO_CHANNEL + IO_IOL + IO_IND +
											IO_SRT + IO_ERR + IO_DOM + IO_END + 
											IO_TBL + IO_KEY },
	{ "FINDRECORD",		CMD_FINDRECORD,		IO_CHANNEL + IO_IOL + IO_IND +
											IO_SRT + IO_ERR + IO_DOM + IO_END + 
											IO_TBL + IO_KEY },
	{ "PRINTRECORD",	CMD_PRINTRECORD,	IO_CHANNEL + IO_ERR + IO_DOM+IO_END +
											IO_TBL + IO_IND + IO_KEY + IO_IOL },
	{ "WRITERECORD",	CMD_WRITERECORD,	IO_CHANNEL + IO_ERR + IO_DOM+IO_END +
											IO_TBL + IO_IND + IO_KEY + IO_IOL },
	{ "ENCRYPT", 		CMD_ENCRYPT, 		IO_ERR },
	{ "PSAVE", 			CMD_PSAVE, 			IO_ERR },
	{ "PREAD", 			CMD_PREAD, 			1 },
	{ "PREADRECORD",	CMD_PREADRECORD,	1 },
	{ "PEXTRACT",		CMD_PEXTRACT, 		1 },
	{ "PEXTRACTRECORD", CMD_PEXTRACTRECORD, 1 },
	{ "IF", 			CMD_IF, 			0 },
	{ "FINPUT", 		CMD_FINPUT, 		IO_CHANNEL + IO_ATR + IO_EDT + IO_TIM +
											IO_ERR },
	{ "INITFILE",		CMD_INITFILE, 		IO_ERR },
	{ "SHORTVAR",		CMD_SHORTVAR,		0 },
	{ "LONGVAR", 		CMD_LONGVAR,		0 },
	{ "INPUT EDT",		CMD_INPUTEDT,		0 },
	//{ "INPUT EDT RECORD", CMD_INPUTEDTRECORD, 0 },
	{ "WINDOW", 		CMD_WINDOW, 		0 },
	{ "MSORT", 			CMD_MSORT, 			IO_ERR },
	{ "ADDSORT", 		CMD_ADDSORT,		IO_ERR },
	{ "REMSORT", 		CMD_REMSORT,		IO_ERR + IO_SRT },
	{ "DROP ALL",		CMD_DROPALL, 		IO_ERR },
	{ "WHILE", 			CMD_WHILE, 			0 },
	{ "WEND", 			CMD_WEND, 			0 },
	{ "ESCON", 			CMD_ESCON, 			0 },
	{ "ESCOFF", 		CMD_ESCOFF, 		0 },
	{ "TISAM", 			CMD_TISAM, 			IO_ERR },
	{ "EDITF", 			CMD_EDITF, 			0 },
	{ "SET PREFIX",		CMD_SETPREFIX,		IO_ERR },
	{ "SET DIR", 		CMD_SETDIR, 		IO_ERR },
	{ "TEXT", 			CMD_TEXT, 			IO_ERR },
	//{ "SET DATE STRINGS",			CMD_SETDATESTR, 0 },
	{ "FIXUP",			CMD_FIXUP,			IO_ERR },
	{ "SYMTAB", 		CMD_SYMTAB,			IO_ERR },
	{ "DUMP",			CMD_DUMP,			IO_CHANNEL + IO_ERR },
	{ "SET DRIVE",		CMD_SETDRIVE, 		IO_ERR },
	{ "SET TRACEMODE",	CMD_SETTRACEMODE,	IO_ERR },
	{ "ESCAPE WHEN",	CMD_ESCAPEWHEN,		0 },
	{ "XCALL", 			CMD_XCALL, 			IO_ERR },
	{ "FORMAT", 		CMD_FORMAT, 		0 },
	{ "SET PRM", 		CMD_SETPRM, 		IO_ERR },
	{ "LOG OPEN",		CMD_LOGOPEN,		IO_ERR },
	{ "LOG CLOSE",		CMD_LOGCLOSE,		IO_ERR },
	//{ "TRANSACTION BEGIN", CMD_TRANSBEGIN, IO_ERR },
	{ "COMMIT", 		CMD_COMMIT, 		IO_ERR },
	{ "ROLLBACK",		CMD_ROLLBACK, 		IO_ERR },
	//{ "LET FMD", 		CMD_LETFMD, 		0 },
	{ "SET DATEMASK",	CMD_SETDATEMASK,	IO_ERR },
	{ "SET CMASK",		CMD_SETCMASK, 		IO_ERR },
	{ "SET HOTKEY",		CMD_SETHOTKEY,		0 },
	{ "SET ERR ON",		CMD_SETERRON,		0 },
	{ "SET ERR OFF",	CMD_SETERROFF,		0 },
	//{ "LET FMT",		CMD_LETFMT, 		0 },
	{ "PACK ARRAY",		CMD_PACKARRAY,		IO_ERR },
	{ "UNPACK ARRAY",	CMD_UNPACKARRAY,	IO_ERR },
	//{ "END ESCAPE WHEN",CMD_ENDESCAPEWHEN, 0 },
	//{ "GLOBAL ESCAPE WHEN", CMD_GLOBALESCAPEWHEN, 0 },
	{ "SET ERC",		CMD_SETERC, 		0 },
	{ "CLEAR ERC",		CMD_CLEARERC, 		0 }
};

struct reserved resvtable[] = 
{
	{ "TO",		RESV_TO },
	{ "STEP",	RESV_STEP },
	{ "THEN",	RESV_THEN },
	{ "ELSE",	RESV_ELSE }
};

// mnemonics
struct mnemonics mnemtable[] =
{
	{ "XX",			"" },
	{ "CS",			"\x1B[2J\x1B[0;0H\x1B[1m" },
	{ "CL",			"\x1B[0K" },
	{ "CR",			"\x0A\x0D" },
	{ "BV",			"\x1B[5;7m" },
	{ "RB",			"\x1B[0m" },
	{ "BB",			"\x1B[5m" },
	{ "BF",			"\x1B[7m" },
	{ "ER",			"\x1B[0m" },
	{ "BR",			"\x1B[7m" },
	{ "EB",			"\x1B[0m" },
	{ "BU",			"\x1B[4m" },
	{ "EU",			"\x1B[0m" },
	{ "CH",			"\x1B[0;0H\x1B[1m" },
	{ "CE",			"\x1B[J" },
	{ "ES",			"\x1B" },
	{ "LD",			"\x1B[0M\x1B[1m" },
	{ "LI",			"\x1B[0L\x1B[1m" },
	{ "VT",			"\x1B[1A" }, 
	{ "LF",			"\x0A\x0D" },
	{ "BLACK",		"\x1B[1;30m" },
	{ "BGBLACK",	"\x1B[40m" },
	{ "BLUE",		"\x1B[1;34m" },
	{ "BGBLUE",		"\x1B[44m" },
	{ "BROWN",		"\x1B[1;33m" },
	{ "BGBROWN",	"\x1B[43m" },
	{ "CYAN",		"\x1B[1;36m" },
	{ "BGCYAN",		"\x1B[46m" },
	{ "GREEN",		"\x1B[1;32m" },
	{ "BGGREEN",	"\x1B[42m" },
	{ "RED",		"\x1B[1;31m" },
	{ "BGRED",		"\x1B[41m" },
	{ "WHITE",		"\x1B[1;37m" },
	{ "BGWHITE",	"\x1B[47m" },
	{ "MAGENTA",	"\x1B[1;35m" },
	{ "BGMAGENTA",	"\x1B[45m" },
	{ "G0",			"\x1B[12mD\x1B[10m" },
	{ "G1",			"\x1B[12m3\x1B[10m" },
	{ "G2",			"\x1B[12mZ\x1B[10m" },
	{ "G3",			"\x1B[12m?\x1B[10m" },
	{ "G4",			"\x1B[12m2\x1B[10m" },
	{ "G5",			"\x1B[12mY\x1B[10m" },
	{ "G6",			"\x1B[12m4\x1B[10m" },
	{ "G7",			"\x1B[12mC\x1B[10m" },
	{ "G8",			"\x1B[12mA\x1B[10m" },
	{ "G9",			"\x1B[12mB\x1B[10m" },
	{ "GA",			"\x1B[12mE\x1B[10m" },
	{ "GB",			"\x1B[12m0\x1B[10m" },
	{ "GC",			"\x1B[12m1\x1B[10m" },
	{ "GD",			"\x1B[12m2\x1B[10m" },
	{ "GE",			"\x1B[12m:\x1B[10m" },
	{ "GF",			"\x1B[12mM\x1B[10m" }
};

struct functions fnctable[] =
{
	// FN Name Opcode #arg ret. type
	{ "ABS", FNC_ABS,	1,	1 },
	{ "ACS", FNC_ACS,	1,	1 },
	{ "AND", FNC_AND,	2,	2 },
	{ "ARG", FNC_ARG,	2,	2 },
	{ "ASC", FNC_ASC,	1,	1 },
	{ "ASN", FNC_ASN,	1,	1 },
	{ "ATH", FNC_ATH,	1,	2 },
	{ "ATN", FNC_ATN,	1,	1 },
	{ "ATQ", FNC_ATQ,	2,	1 },
	{ "ATR", FNC_ATR,	3,	2 },
	{ "BIN", FNC_BIN,	2,	2 },
	{ "CGV", FNC_CGV,	99,	2 },
	{ "CHR", FNC_CHR,	1,	2 },
	{ "COS", FNC_COS,	1,	1 },
	{ "CPL", FNC_CPL,	1,	2 },
	{ "CPP", FNC_CPP,	1,	2 },
	{ "CRC", FNC_CRC,	99,	2 },
	{ "CVT", FNC_CVT,	2,	2 },
	{ "DCM", FNC_DCM,	1,	2 },
	{ "DEC", FNC_DEC,	1,	1 },
	{ "DIM", FNC_DIM,	99,	2 },
	{ "DSD", FNC_DSD,	1,	2 },
	{ "DSK", FNC_DSK,	1,	2 },
	{ "DTN", FNC_DTN,	99,	1 },
	{ "DTR", FNC_DTR,	2,	2 },
	{ "EPT", FNC_EPT,	1,	1 },
	{ "ERM", FNC_ERM,	1,	2 },
	{ "ERR", FNC_ERR,	99,	1 },
	{ "EXP", FNC_EXP,	1,	1 },
	{ "FID", FNC_FID,	1,	2 },
	{ "FIX", FNC_FIX,	1,	1 },
	{ "FKY", FNC_FKY,	1,	2 },
	{ "FMD", FNC_FMD,	99,	2 },
	{ "FMT", FNC_FMT,	99,	2 },
	{ "FPT", FNC_FPT,	1,	1 },
	{ "FST", FNC_FST,	2,	2 },
	{ "GAP", FNC_GAP,	1,	2 },
	{ "HSH", FNC_HSH,	99,	2 },
	{ "HTA", FNC_HTA,	1,	2 },
	{ "IND", FNC_IND,	1,	1 },
	{ "INF", FNC_INF,	2,	2 },
	{ "INT", FNC_INT,	1,	1 },
	{ "IOR", FNC_IOR,	2,	2 },
	{ "KEY", FNC_KEY,	1,	2 },
	{ "LCS", FNC_LCS,	1,	2 },
	{ "LEN", FNC_LEN,	1,	1 },
	{ "LKY", FNC_LKY,	1,	2 },
	{ "LOG", FNC_LOG,	1,	1 },
	{ "LRC", FNC_LRC,	1,	2 },
	{ "LST", FNC_LST,	1,	2 },
	{ "MAX", FNC_MAX,	99,	1 },
	{ "MIN", FNC_MIN,	99,	1 },
	{ "MNE", FNC_MNE,	99,	2 },
	{ "MOD", FNC_MOD,	2,	1 },
	{ "NEA", FNC_NEA,	2,	1 },
	{ "NLG", FNC_NLG,	1,	1 },
	{ "NMV", FNC_NMV,	1,	1 },
	{ "NOT", FNC_NOT,	1,	2 },
	{ "NTD", FNC_NTD,	1,	2 },
	{ "NUM", FNC_NUM,	99,	1 },
	{ "PAD", FNC_PAD,	99,	2 },
	{ "PCK", FNC_PCK,	2,	2 },
	{ "PFL", FNC_PFL,	2,	2 },
	{ "PFP", FNC_PFP,	2,	2 },
	{ "PGM", FNC_PGM,	2,	2 },
	{ "PKY", FNC_PKY,	1,	2 },
	{ "POS", FNC_POS,	99,	1 },
	{ "PUB", FNC_PUB,	1,	2 },
	{ "REV", FNC_REV,	1,	2 },
	{ "RND", FNC_RND,	1,	1 },
	{ "RTD", FNC_RTD,	2,	2 },
	{ "RTI", FNC_RTI,	1,	1 },
	{ "SDX", FNC_SDX,	1,	2 },
	{ "SGN", FNC_SGN,	1,	1 },
	{ "SIN", FNC_SIN,	1,	1 },
	{ "SQR", FNC_SQR,	1,	1 },
	{ "SSZ", FNC_SSZ,	1,	1 },
	{ "STL", FNC_STL,	1,	1 },
	{ "STP", FNC_STP,	2,	2 },
	{ "STR", FNC_STR,	1,	2 },
	{ "SWP", FNC_SWP,	99,	2 },
	{ "TAN", FNC_TAN,	1,	1 },
	{ "TBL", FNC_TBL,	2,	2 },
	{ "TCB", FNC_TCB,	1,	1 },
	{ "TSK", FNC_TSK,	1,	2 },
	{ "UCM", FNC_UCM,	1,	2 },
	{ "UCS", FNC_UCS,	1,	2 },
	{ "UPK", FNC_UPK,	1,	2 },
	{ "XFD", FNC_XFD,	2,	2 },
	{ "XOR", FNC_XOR,	2,	2 },
	{ "",	 0,			0,	0 }
};

struct sysvars sysvartbl[] = 
{
	{ "NIL",			0, 0 },
	{ "ARGC",			VAR_ARGC,		1 },
	{ "CDN",			VAR_CDN,		1 },
	{ "CDS",			VAR_CDS,		2 },
	{ "CMASK",			VAR_CMASK,		2 },
	{ "CTL",			VAR_CTL,		1 },
	{ "DATEMASK",		VAR_DATEMASK,	2 },
	{ "DATESTRINGS",	VAR_DATESTRINGS,2 },
	{ "DAY",			VAR_DAY,		2 },
	{ "DIR",			VAR_DIR,		2 },
	{ "DLM",			VAR_DLM,		2 },
	{ "DNE",			VAR_DNE,		2 },
	{ "DSZ",			VAR_DSZ,		1 },
	{ "EOM",			VAR_EOM,		2 },	
	{ "ERC",			VAR_ERC,		1 },
	{ "ERS",			VAR_ERS,		1 },
	{ "ERR",			VAR_ERR,		1 },
	{ "ERRBUF",			VAR_ERRBUF,		2 },
	{ "ESC",			VAR_ESC,		2 },
	{ "FDT",			VAR_FDT,		2 },
	{ "FMTNL",			VAR_FMTNL,		2 },
	{ "OCH",			VAR_OCH,		2 },
	{ "PGN",			VAR_PGN,		2 },
	{ "PRC",			VAR_PRC,		1 },
	{ "PREFIX",			VAR_PREFIX,		2 },
	{ "PRM",			VAR_PRM,		2 },
	{ "PSZ",			VAR_PSZ,		1 },
	{ "PTN",			VAR_PTN,		1 },
	{ "QUO",			VAR_QUO,		2 },
	{ "SEP",			VAR_SEP,		2 },
	{ "SSN",			VAR_SSN,		2 },
	{ "SYS",			VAR_SYS,		2 },
	{ "TIM",			VAR_TIM,		1 },
	{ "TME",			VAR_TIM,		1 },
	{ "TMS",			VAR_TMS,		1 },
	{ "TRACEMODE",		VAR_TRACEMODE,	2 },
	{ "TSM",			VAR_TSM,		2 },
	{ "UNT",			VAR_UNT,		1 },
	{ "",				0,				0 }
};
