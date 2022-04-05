%option yylineno

%{

#include <stdio.h>
#include "clang.tab.h"

extern void yyerror(const char *);
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
<INITIAL>int                 {return INT;}
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

void terminationCheck() {
	char current, prev;
	prev = 0;
  
	while ((current = input()))      
	{
		if (prev == '*' && current == '/') return;
		prev = current;
	}
	yyerror("unterminated comment");
}
