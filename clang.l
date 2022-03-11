%{

#include <stdio.h>
#include <stdlib.h>
/* 标识符 */ 
#define ID              1
/* 关键字 */
#define AUTO            2
#define BREAK           3
#define CASE            4
#define CHAR            5
#define CONST           6
#define CONTINUE        7
#define DEFAULT         8
#define DO              9
#define DOUBLE         10
#define ELSE           11
#define ENUM           12
#define EXTERN         13
#define FLOAT          14
#define FOR            15
#define GOTO           16
#define IF             17
#define INLINE         18
#define INT            19
#define LONG           20
#define REGISTER       21
#define RESTRICT       22
#define RETURN         23
#define SHORT          24
#define SIGNED         25
#define SIZEOF         26
#define STATIC         27
#define STRUCT         28
#define SWITCH         29
#define TYPEDEF        30
#define UNION          31
#define UNSIGNED       32
#define VOID           33
#define VOLATILE       34
#define WHILE          35
#define _ALIGNAS       36
#define _ALIGNOF       37
#define _ATOMIC        38
#define _BOOL          39
#define _COMPLEX       40
#define _GENERIC       41
#define _IMAGINARY     42
#define _NORETURN      43
#define _STATIC_ASSERT 44
#define _THREAD_LOCAL  45
#define __FUNC__       46
/* 运算符 */
// 算术运算符
#define PLUS           47
#define MINUS          48
#define STAR           49
#define DIV            50
#define MOD            51
#define INC            52
#define DEC            53
// 关系运算符
#define LANGLE         54
#define RANGLE         55
#define EQ	           56		
#define	NE	           57
#define	GE	           58
#define LE             59
// 逻辑运算符
#define NOT            60
#define AND            61                    
#define OR             62
 // &,既可作位运算符也可作取地址符
#define ESPERLUETTE    63
// 位运算符
#define BNOT           64
#define BOR            65
#define XOR            66
#define LS             67 
#define RS             68
// 赋值运算符
#define DIRECTASSIGN   69 
#define ADDASSIGN      70
#define SUBASSIGN      71
#define MULASSIGN      72
#define DIVASSIGN      73
#define MODASSIGN      74             
#define BANDASSIGN     75
#define XORASSIGN      76
#define BORASSIGN      77
#define LSASSIGN       78
#define RSASSIGN       79
// 间接结构成员访问
#define ARROW          80
// 直接访问结构成员
#define PERIOD         81

/* 界符 */
#define COMMA          82
// 省略号
#define ELLIPSIS       83
// 问号
#define QUESTION       84
#define COLON          85
#define SEMICOLON      86
#define LPARENTHESE    87
#define RPARENTHESE    88 
#define LBRACE         89
#define RBRACE         90
#define LBRACKET       91
#define RBRACKET       92
/* 常量 */
// 数字常量
#define INT_CONSTANT   93
#define FLOAT_CONSTANT 94         
// 字符常量
#define CHARACTER      95
// 字符串常量
#define STRING         96
// 非法字符
#define ERRORCHAR      97

void terminationCheck(); 
void writeOut(int ch);
%}

whiteSpace     [ \t\v\f\n] 
whiteSpaces    {whiteSpace}+
letter_	       [A-Za-z_]  
/* 转义符 */
escape         (\\(['"?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+)) 
/* 十进制数位 */  
decDigit	   [0-9]  
/* 不包括0的十进制数位 */ 
nzDecDigit     [1-9]
/* 十六进制数位 */ 
hexDigit       ([A-Fa-f]|{decDigit})
/* 八进制数位 */ 
octDigit       [0-7]
/* 字符常量前缀 */ 
charPrefix     (u8|u|U|L)
/* 十六进制前缀 */ 
hexPrefix      (0[xX])
/* 整数后缀 */ 
intPostfix   (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
/* 浮点数后缀*/
floatPostfix (f|F|l|L)  
/* 字符常量 */  
character      ({charPrefix}?'([^'\\\n]|{escape})+')
/* 十进制整数 */
decInt	   {nzDecDigit}{decDigit}*{intPostfix}?
/* 十六进制整数 */
hex            {hexPrefix}{hexDigit}+{intPostfix}?
/* 八进制整数 */
octal          0{octDigit}*{intPostfix}?
/* 整数 */
integer        {decInt}|{hex}|{octal}
/* 浮点数 */
float      ({decDigit}*\.{decDigit}+([Ee][+-]?{decDigit}+)?{floatPostfix}?|{decDigit}+"."([Ee][+-]?{decDigit}+)?{floatPostfix}?|{decDigit}+([Ee][+-]?{decDigit}+){floatPostfix}?)     
/* 标识符 */
id	       	   {letter_}({letter_}|{decDigit})* 

string         ({charPrefix}?\"([^"\\\n]|{escape})*\"{whiteSpace}*)+

%s COMMENT2
%%
 /* 过滤注释 */
<INITIAL>"/*"                {terminationCheck();}
<INITIAL>"//"                {BEGIN COMMENT2;}
<COMMENT2>\n                 {BEGIN INITIAL;}
<COMMENT2>.                  {;}


 /* 过滤空白符 */
<INITIAL>{whiteSpaces}	     {;}

 /* 匹配关键字 */
<INITIAL>auto                {return (AUTO);}
<INITIAL>break               {return (BREAK);}
<INITIAL>case                {return (CASE);}
<INITIAL>char                {return (CHAR);}
<INITIAL>const               {return (CONST);}
<INITIAL>continue            {return (CONTINUE);}
<INITIAL>default             {return (DEFAULT);}
<INITIAL>do                  {return (DO);}
<INITIAL>double              {return (DOUBLE);}
<INITIAL>else                {return (ELSE);}
<INITIAL>enum                {return (ENUM);}
<INITIAL>extern              {return (EXTERN);}
<INITIAL>float               {return (FLOAT);}
<INITIAL>for                 {return (FOR);}
<INITIAL>goto                {return (GOTO);}
<INITIAL>if                  {return (IF);}
<INITIAL>inline              {return (INLINE);}
<INITIAL>int                 {return (INT);}
<INITIAL>long                {return (LONG);}
<INITIAL>register            {return (REGISTER);}
<INITIAL>restrict            {return (RESTRICT);}
<INITIAL>return              {return (RETURN);}
<INITIAL>short               {return (SHORT);}
<INITIAL>signed              {return (SIGNED);}
<INITIAL>sizeof              {return (SIZEOF);}
<INITIAL>static              {return (STATIC);}
<INITIAL>struct              {return (STRUCT);}
<INITIAL>switch              {return (SWITCH);}
<INITIAL>typedef             {return (TYPEDEF);}
<INITIAL>union               {return (UNION);}
<INITIAL>unsigned            {return (UNSIGNED);}
<INITIAL>void                {return (VOID);}
<INITIAL>volatile            {return (VOLATILE);}
<INITIAL>while               {return (WHILE);}
<INITIAL>_Alignas            {return (_ALIGNAS);}
<INITIAL>_Alignof            {return (_ALIGNOF);}
<INITIAL>_Atomic             {return (_ATOMIC);}
<INITIAL>_Bool               {return (_BOOL);}
<INITIAL>_Complex            {return (_COMPLEX);}
<INITIAL>_Generic            {return (_GENERIC);}
<INITIAL>_Imaginary          {return (_IMAGINARY);}
<INITIAL>_Noreturn           {return (_NORETURN);}
<INITIAL>_Static_assert      {return (_STATIC_ASSERT);}
<INITIAL>_Thread_local       {return (_THREAD_LOCAL);}
<INITIAL>__func__            {return (__FUNC__);}
 /* 匹配标识符 */
<INITIAL>{id}	             {return (ID);}

 /* 匹配数字常量 */
 /* 匹配整数  */
<INITIAL>{integer}	     	 {return (INT_CONSTANT);}
 /* 匹配浮点数常量 */
<INITIAL>{float}             {return (FLOAT_CONSTANT);}
 /* 匹配字符常量 */
<INITIAL>{character}         {return (CHARACTER);}
 /* 匹配字符串常量 */
<INITIAL>{string}            {return (STRING);}

 /* 匹配运算符 */
 /* 匹配算术运算符 */
<INITIAL>"+"	             {return (PLUS);}
<INITIAL>"-"	             {return (MINUS);}
<INITIAL>"*" 	             {return (STAR);}
<INITIAL>"/"	             {return (DIV);}
<INITIAL>"%"	             {return (MOD);}
<INITIAL>"++"                {return (INC);}
<INITIAL>"--"                {return (DEC);}
 /* 匹配关系运算符 */
<INITIAL>"=="                {return (EQ);}
<INITIAL>"!="                {return (NE);}
 /* >,<既是关系运算符也是界符 */
<INITIAL>"<"                 {return (LANGLE);}
<INITIAL>">"                 {return (RANGLE);}
<INITIAL>">="                {return (GE);}
<INITIAL>"<="                {return (LE);}
 /* 匹配逻辑运算符 */
<INITIAL>"!"                 {return (NOT);}
<INITIAL>"&&"                {return (AND);}
<INITIAL>"||"                {return (OR);}
 /* 匹配&运算符 */
<INITIAL>"&"                 {return (ESPERLUETTE);}
 /* 匹配位运算符 */
<INITIAL>"~"                 {return (BNOT);}
<INITIAL>"|"                 {return (BOR);}
<INITIAL>"^"                 {return (XOR);}
<INITIAL>"<<"                {return (LS);}
<INITIAL>">>"                {return (RS);}
 /* 匹配赋值运算符 */
<INITIAL>"="                 {return (DIRECTASSIGN);}
<INITIAL>"+="                {return (ADDASSIGN);}
<INITIAL>"-="                {return (SUBASSIGN);}
<INITIAL>"*="                {return (MULASSIGN);}
<INITIAL>"/="                {return (DIVASSIGN);}
<INITIAL>"%="                {return (MODASSIGN);}
<INITIAL>"&="                {return (BANDASSIGN);}
<INITIAL>"^="                {return (XORASSIGN);}
<INITIAL>"|="                {return (BORASSIGN);}
<INITIAL>"<<="               {return (LSASSIGN);}
<INITIAL>">>="               {return (RSASSIGN);}
 /* 匹配成员访问运算符 */
<INITIAL>"->"                {return (ARROW);}
<INITIAL>"."                 {return (PERIOD);}
 /* 匹配界符(某些界符也同时作为运算符，如?和：搭配是条件运算符) */
<INITIAL>","                 {return (COMMA);}
<INITIAL>"..."               {return (ELLIPSIS);}
<INITIAL>"?"                 {return (QUESTION);}
<INITIAL>":"                 {return (COLON);}
<INITIAL>";"                 {return (SEMICOLON);}
<INITIAL>"("                 {return (LPARENTHESE);}
<INITIAL>")"                 {return (RPARENTHESE);}
<INITIAL>"{"                 {return (LBRACE);}
<INITIAL>"}"                 {return (RBRACE);}
<INITIAL>"["                 {return (LBRACKET);}
<INITIAL>"]"                 {return (RBRACKET);}

<INITIAL>.	                 {return (ERRORCHAR);}

 
%%

int yywrap() {
  return 1;
}

int fileNum;

void terminationCheck() {
	char current, prev;
	prev = 0;
  
	while ((current = input()))      
	{
		if (prev == '*' && current == '/') return;
		prev = current;
	}
	fprintf(stderr, "unterminated comment\n");
	fclose(yyin);
	if (fileNum > 1) fclose(yyout);
	exit(-1);
}

void writeOut(int ch) {
  switch(ch) {
	case AUTO:           fprintf(yyout, "(AUTO, %s)\n", yytext);          break;
	case BREAK:          fprintf(yyout, "(BREAK, %s)\n", yytext);         break;
	case CASE:           fprintf(yyout, "(CASE, %s)\n", yytext);          break;
	case CHAR:           fprintf(yyout, "(CHAR, %s)\n", yytext);          break;
	case CONST:          fprintf(yyout, "(CONST, %s)\n", yytext);         break;
	case CONTINUE:       fprintf(yyout, "(BREAK, %s)\n", yytext);         break;
	case DEFAULT:        fprintf(yyout, "(DEFAULT, %s)\n", yytext);       break;
	case DO:             fprintf(yyout, "(DO, %s)\n", yytext);            break;
	case DOUBLE:         fprintf(yyout, "(DOUBLE, %s)\n", yytext);        break;
	case ELSE:           fprintf(yyout, "(ELSE, %s)\n", yytext);          break;
	case ENUM:           fprintf(yyout, "(ENUM, %s)\n", yytext);          break;
	case EXTERN:         fprintf(yyout, "(EXTERN, %s)\n", yytext);        break;
	case FLOAT:          fprintf(yyout, "(FLOAT, %s)\n", yytext);         break;
	case FOR:            fprintf(yyout, "(FOR, %s)\n", yytext);           break;
	case GOTO:           fprintf(yyout, "(GOTO, %s)\n", yytext);          break;
	case IF:             fprintf(yyout, "(IF, %s)\n", yytext);            break;
	case INLINE:         fprintf(yyout, "(INLINE, %s)\n", yytext);        break;
	case INT:            fprintf(yyout, "(INT, %s)\n", yytext);           break;
	case LONG:           fprintf(yyout, "(LONG, %s)\n", yytext);          break;
	case REGISTER:       fprintf(yyout, "(REGISTER, %s)\n", yytext);      break;
	case RESTRICT:       fprintf(yyout, "(RESTRICT, %s)\n", yytext);      break;
	case RETURN:         fprintf(yyout, "(RETURN, %s)\n", yytext);        break;
	case SHORT:          fprintf(yyout, "(SHORT, %s)\n", yytext);         break;
	case SIGNED:         fprintf(yyout, "(SIGNED, %s)\n", yytext);        break;
	case SIZEOF:         fprintf(yyout, "(SIZEOF, %s)\n", yytext);        break;
	case STATIC:         fprintf(yyout, "(STATIC, %s)\n", yytext);        break;
	case STRUCT:         fprintf(yyout, "(STRUCT, %s)\n", yytext);        break;
	case SWITCH:         fprintf(yyout, "(SWITCH, %s)\n", yytext);        break;
	case TYPEDEF:        fprintf(yyout, "(TYPEDEF, %s)\n", yytext);       break;
	case UNION:          fprintf(yyout, "(UNION, %s)\n", yytext);         break; 
	case UNSIGNED:       fprintf(yyout, "(UNSIGNED, %s)\n", yytext);      break;
	case VOID:           fprintf(yyout, "(VOID, %s)\n", yytext);          break;
	case VOLATILE:       fprintf(yyout, "(VOLATILE, %s)\n", yytext);      break;
	case WHILE:          fprintf(yyout, "(WHILE, %s)\n", yytext);         break;
	case _ALIGNAS:       fprintf(yyout, "(ALIGNAS, %s)\n", yytext);       break;
	case _ALIGNOF:       fprintf(yyout, "(ALIGNOF, %s)\n", yytext);       break;
	case _ATOMIC:        fprintf(yyout, "(ATOMIC, %s)\n", yytext);        break;
	case _BOOL:          fprintf(yyout, "(BOOL, %s)\n", yytext);          break;
	case _COMPLEX:       fprintf(yyout, "(COMPLEX, %s)\n", yytext);       break;
	case _GENERIC:       fprintf(yyout, "(GENERIC, %s)\n", yytext);       break;
	case _IMAGINARY:     fprintf(yyout, "(IMAGINARY, %s)\n", yytext);     break;
	case _NORETURN:      fprintf(yyout, "(NORETURN, %s)\n", yytext);      break;
	case _STATIC_ASSERT: fprintf(yyout, "(STATIC_ASSERT, %s)\n", yytext); break;
	case _THREAD_LOCAL:  fprintf(yyout, "(THREAD_LOCAL, %s)\n", yytext);  break;
	case __FUNC__:       fprintf(yyout, "(FUNC, %s)\n", yytext);          break;
	
	case ID:             fprintf(yyout, "(ID, %s)\n", yytext);            break;

	case INT_CONSTANT:   fprintf(yyout, "(INT_CONSTANT, %s)\n", yytext);  break;
	case FLOAT_CONSTANT: fprintf(yyout, "(FLOAT_CONSTANT, %s)\n", yytext);break;
	case CHARACTER:      fprintf(yyout, "(CHARACTER, %s)\n", yytext);     break;
	case STRING:         fprintf(yyout, "(STRING, %s)\n", yytext);        break;

	case PLUS:           fprintf(yyout, "(PLUS, %s)\n", yytext);          break;
	case MINUS:          fprintf(yyout, "(MINUS, %s)\n", yytext);         break;
	case STAR:           fprintf(yyout, "(STAR, %s)\n", yytext);          break;
	case DIV:            fprintf(yyout, "(DIV, %s)\n", yytext);           break;
	case MOD:            fprintf(yyout, "(MOD, %s)\n", yytext);           break;
	case INC:            fprintf(yyout, "(INC, %s)\n", yytext);           break;
	case DEC:            fprintf(yyout, "(DEC, %s)\n", yytext);           break;
	case EQ:             fprintf(yyout, "(EQ, %s)\n", yytext);            break;
	case NE:             fprintf(yyout, "(NE, %s)\n", yytext);            break;
	case LANGLE:         fprintf(yyout, "(LANGLE, %s)\n", yytext);        break;
	case RANGLE:         fprintf(yyout, "(RANGLE, %s)\n", yytext);        break;
	case GE:             fprintf(yyout, "(GE, %s)\n", yytext);            break;
	case LE:             fprintf(yyout, "(LE, %s)\n", yytext);            break;
	case NOT:            fprintf(yyout, "(NOT, %s)\n", yytext);           break;
	case AND:            fprintf(yyout, "(AND, %s)\n", yytext);           break;
	case OR:             fprintf(yyout, "(OR, %s)\n", yytext);            break;
	case ESPERLUETTE:    fprintf(yyout, "(ESPERLUETTE, %s)\n", yytext);   break;
	case BNOT:           fprintf(yyout, "(BNOT, %s)\n", yytext);          break;
	case BOR:            fprintf(yyout, "(BOR, %s)\n", yytext);           break;
	case XOR:            fprintf(yyout, "(XOR, %s)\n", yytext);           break;
	case LS:             fprintf(yyout, "(LS, %s)\n", yytext);            break;
	case RS:             fprintf(yyout, "(RS, %s)\n", yytext);            break;
	case DIRECTASSIGN:   fprintf(yyout, "(DIRECTASSIGN, %s)\n", yytext);  break;
	case ADDASSIGN:      fprintf(yyout, "(ADDASSIGN, %s)\n", yytext);     break;
	case SUBASSIGN:      fprintf(yyout, "(SUBASSIGN, %s)\n", yytext);     break;
	case MULASSIGN:      fprintf(yyout, "(MULASSIGN, %s)\n", yytext);     break;
	case DIVASSIGN:      fprintf(yyout, "(DIVASSIGN, %s)\n", yytext);     break;
	case MODASSIGN:      fprintf(yyout, "(MODASSIGN, %s)\n", yytext);     break;
	case BANDASSIGN:     fprintf(yyout, "(BANDASSIGN, %s)\n", yytext);    break;
	case XORASSIGN:      fprintf(yyout, "(XORASSIGN, %s)\n", yytext);     break;
	case BORASSIGN:      fprintf(yyout, "(BORASSIGN, %s)\n", yytext);     break;
	case LSASSIGN:       fprintf(yyout, "(LSASSIGN, %s)\n", yytext);      break;
	case RSASSIGN:       fprintf(yyout, "(RSASSIGN, %s)\n", yytext);      break;
	case ARROW:          fprintf(yyout, "(ARROW, %s)\n", yytext);         break;
	case PERIOD:         fprintf(yyout, "(PERIOD, %s)\n", yytext);        break;

	case COMMA:          fprintf(yyout, "(COMMA, %s)\n", yytext);         break;
	case ELLIPSIS:       fprintf(yyout, "(ELLIPSIS, %s)\n", yytext);      break;
	case QUESTION:       fprintf(yyout, "(QUESTION, %s)\n", yytext);      break;
	case COLON:          fprintf(yyout, "(COLON, %s)\n", yytext);         break;
	case SEMICOLON:      fprintf(yyout, "(SEMICOLON, %s)\n", yytext);     break;
	case LPARENTHESE:    fprintf(yyout, "(LPARENTHESE, %s)\n", yytext);   break;
	case RPARENTHESE:    fprintf(yyout, "(RPARENTHESE, %s)\n", yytext);   break;
	case LBRACE:         fprintf(yyout, "(LBRACE, %s)\n", yytext);        break;
	case RBRACE:         fprintf(yyout, "(RBRACE, %s)\n", yytext);        break;
	case LBRACKET:       fprintf(yyout, "(LBRACKET, %s)\n", yytext);      break;
	case RBRACKET:       fprintf(yyout, "(RBRACKET, %s)\n", yytext);      break;
	
	case ERRORCHAR:      fprintf(yyout, "(ERRORCHAR, %s)\n", yytext);     break;

    default:break;
  }
  return;
}


int main (int argc, char ** argv){
	int typeCode;
	fileNum = argc - 1;
	if (argc < 2) {
		fprintf(stderr, "Usage: <program_name> <input_file> <output_file>(optional)\n");
		exit(-1);	
	}
	
	if ((yyin = fopen(argv[1], "r")) == NULL) {
	    fprintf(stderr, "Can't open file %s\n", argv[1]);
		exit(-1);
	}
	if (argc >= 3) {
		if ((yyout = fopen(argv[2], "w")) == NULL) {
	    	fprintf(stderr, "Can't open file %s\n", argv[2]);
			fclose(yyin);
			exit(-1);
		}	  
	}

	while (typeCode = yylex()) {
		writeOut(typeCode);
	}

	fclose(yyin);
	if (argc >= 3) fclose(yyout);
	return 0;
}
