decDigit            [0-9]
nzDecDigit          [1-9]
decInt              {nzDecDigit}{decDigit}*
hexPrefix           (0[xX])
hexDigit            [a-fA-F0-9]
hexInt              {hexPrefix}{hexDigit}+
octDigit            [0-7]
octInt              0{octDigit}*
letter_             [a-zA-Z_]
id                  {letter_}({letter_}|{decDigit})*

%{
#include <iostream>
#include <cstdio>
#include "y.tab.hpp"
#include "tree.h"

using namespace std;

void update_col();
void update_row();
void terminationCheck();
extern YYSTYPE yylval;
extern void yyerror(const char *);
int yycol = 1;
int yyrow = 1;
%}

%%

"/*"              {                                                     update_col(); terminationCheck();         }
"//"[^\n]*        {                                                     /* consume //-comment */                  }
"char"            {yylval.node = new TreeNode("char");                  update_col(); cout << "(CHAR,"          << yytext << ")\n"; return(CHAR);               }
"int"             {yylval.node = new TreeNode("int");                   update_col(); cout << "(INT,"           << yytext << ")\n"; return(INT);                }
"double"          {yylval.node = new TreeNode("double");                update_col(); cout << "(DOUBLE,"        << yytext << ")\n"; return(DOUBLE);             }
"void"            {yylval.node = new TreeNode("void");                  update_col(); cout << "(VOID,"          << yytext << ")\n"; return(VOID);               }
"sizeof"          {yylval.node = new TreeNode("sizeof");                update_col(); cout << "(SIZEOF,"        << yytext << ")\n"; return(SIZEOF);             }
"if"              {yylval.node = new TreeNode("if");                    update_col(); cout << "(IF,"            << yytext << ")\n"; return(IF);                 }
"else"            {yylval.node = new TreeNode("else");                  update_col(); cout << "(ELSE,"          << yytext << ")\n"; return(ELSE);               } 
"switch"          {yylval.node = new TreeNode("switch");                update_col(); cout << "(SWITCH,"        << yytext << ")\n"; return(SWITCH);             }
"case"            {yylval.node = new TreeNode("case");                  update_col(); cout << "(CASE,"          << yytext << ")\n"; return(CASE);               }
"default"         {yylval.node = new TreeNode("default");               update_col(); cout << "(DEFAULT,"       << yytext << ")\n"; return(DEFAULT);            }
"while"           {yylval.node = new TreeNode("while");                 update_col(); cout << "(WHILE,"         << yytext << ")\n"; return(WHILE);              }
"do"              {yylval.node = new TreeNode("do");                    update_col(); cout << "(DO,"            << yytext << ")\n"; return(DO);                 }
"for"             {yylval.node = new TreeNode("for");                   update_col(); cout << "(FOR,"           << yytext << ")\n"; return(FOR);                }
"goto"            {yylval.node = new TreeNode("goto");                  update_col(); cout << "(GOTO,"          << yytext << ")\n"; return(GOTO);               }
"break"           {yylval.node = new TreeNode("break");                 update_col(); cout << "(BREAK,"         << yytext << ")\n"; return(BREAK);              }
"continue"        {yylval.node = new TreeNode("continue");              update_col(); cout << "(CONTINUE,"      << yytext << ")\n"; return(CONTINUE);           }
"return"          {yylval.node = new TreeNode("return");                update_col(); cout << "(RETURN,"        << yytext << ")\n"; return(RETURN);             }

{id}              {yylval.node = new TreeNode("identifier", yytext);    update_col(); cout << "(IDENTIFIER,"    << yytext << ")\n"; return(IDENTIFIER);         }
{hexInt}          {yylval.node = new TreeNode("int_constant", yytext);  update_col(); cout << "(INT_CONSTANT,"  << yytext << ")\n"; return(INT_CONSTANT);       }
{octInt}          {yylval.node = new TreeNode("int_constant", yytext);  update_col(); cout << "(INT_CONSTANT,"  << yytext << ")\n"; return(INT_CONSTANT);       }
{decInt}          {yylval.node = new TreeNode("int_constant", yytext);  update_col(); cout << "(INT_CONSTANT,"  << yytext << ")\n"; return(INT_CONSTANT);       }

";"               {yylval.node = new TreeNode(";");                     update_col(); cout << "(;,"             << yytext << ")\n"; return(';');                }
","               {yylval.node = new TreeNode(",");                     update_col(); cout << "(,,"             << yytext << ")\n"; return(',');                }
":"               {yylval.node = new TreeNode(":");                     update_col(); cout << "(:,"             << yytext << ")\n"; return(':');                }
"{"               {yylval.node = new TreeNode("{");                     update_col(); cout << "({,"             << yytext << ")\n"; return('{');                }
"}"               {yylval.node = new TreeNode("}");                     update_col(); cout << "(},"             << yytext << ")\n"; return('}');                }
"("               {yylval.node = new TreeNode("(");                     update_col(); cout << "((,"             << yytext << ")\n"; return('(');                }  
")"               {yylval.node = new TreeNode(")");                     update_col(); cout << "(),"             << yytext << ")\n"; return(')');                }
"["               {yylval.node = new TreeNode("[");                     update_col(); cout << "([,"             << yytext << ")\n"; return('[');                }
"]"               {yylval.node = new TreeNode("]");                     update_col(); cout << "(],"             << yytext << ")\n"; return(']');                }
"="               {yylval.node = new TreeNode("=");                     update_col(); cout << "(=,"             << yytext  << ")\n"; return('=');                }
">>="             {yylval.node = new TreeNode(">>=");                   update_col(); cout << "(RIGHT_SHIFT_ASSIGN,"  << yytext << ")\n"; return(RIGHT_SHIFT_ASSIGN); }
"<<="             {yylval.node = new TreeNode("<<=");                   update_col(); cout << "(LEFT_SHIFT_ASSIGN,"   << yytext << ")\n"; return(LEFT_SHIFT_ASSIGN);  }
"+="              {yylval.node = new TreeNode("+=");                    update_col(); cout << "(ADD_ASSIGN,"          << yytext << ")\n"; return(ADD_ASSIGN);         }
"-="              {yylval.node = new TreeNode("-=");                    update_col(); cout << "(SUB_ASSIGN,"          << yytext << ")\n"; return(SUB_ASSIGN);         }
"*="              {yylval.node = new TreeNode("*=");                    update_col(); cout << "(MUL_ASSIGN,"          << yytext << ")\n"; return(MUL_ASSIGN);         }
"/="              {yylval.node = new TreeNode("/=");                    update_col(); cout << "(DIV_ASSIGN,"          << yytext << ")\n"; return(DIV_ASSIGN);         }
"%="              {yylval.node = new TreeNode("%=");                    update_col(); cout << "(MOD_ASSIGN,"          << yytext << ")\n"; return(MOD_ASSIGN);         }
"&="              {yylval.node = new TreeNode("&=");                    update_col(); cout << "(AND_ASSIGN,"          << yytext << ")\n"; return(AND_ASSIGN);         } 
"^="              {yylval.node = new TreeNode("^=");                    update_col(); cout << "(XOR_ASSIGN,"          << yytext << ")\n"; return(XOR_ASSIGN);         }
"|="              {yylval.node = new TreeNode("|=");                    update_col(); cout << "(OR_ASSIGN,"           << yytext << ")\n"; return(OR_ASSIGN);          }
"&"               {yylval.node = new TreeNode("&");                     update_col(); cout << "(&,"                   << yytext << ")\n"; return('&');                }
"|"               {yylval.node = new TreeNode("|");                     update_col(); cout << "(|,"                   << yytext << ")\n"; return('|');                }
"^"               {yylval.node = new TreeNode("^");                     update_col(); cout << "(^,"                   << yytext << ")\n"; return('^');                }
"!"               {yylval.node = new TreeNode("!");                     update_col(); cout << "(!,"                   << yytext << ")\n"; return('!');                }
"~"               {yylval.node = new TreeNode("~");                     update_col(); cout << "(~,"                   << yytext << ")\n"; return('~');                }
"+"               {yylval.node = new TreeNode("+");                     update_col(); cout << "(+,"                   << yytext << ")\n"; return('+');                }
"-"               {yylval.node = new TreeNode("-");                     update_col(); cout << "(-,"                   << yytext << ")\n"; return('-');                }
"*"               {yylval.node = new TreeNode("*");                     update_col(); cout << "(*,"                   << yytext << ")\n"; return('*');                }
"/"               {yylval.node = new TreeNode("/");                     update_col(); cout << "(/,"                   << yytext << ")\n"; return('/');                }
"%"               {yylval.node = new TreeNode("%");                     update_col(); cout << "(%,"                   << yytext << ")\n"; return('%');                }
"=="              {yylval.node = new TreeNode("==");                    update_col(); cout << "(EQ_OP,"               << yytext << ")\n"; return(EQ_OP);              }
"!="              {yylval.node = new TreeNode("!=");                    update_col(); cout << "(NE_OP,"               << yytext << ")\n"; return(NE_OP);              }
"<="              {yylval.node = new TreeNode("<=");                    update_col(); cout << "(LE_OP,"               << yytext << ")\n"; return(LE_OP);              }
">="              {yylval.node = new TreeNode(">=");                    update_col(); cout << "(GE_OP,"               << yytext << ")\n"; return(GE_OP);              }
"<"               {yylval.node = new TreeNode("<");                     update_col(); cout << "(<,"                   << yytext << ")\n"; return('<');                }
">"               {yylval.node = new TreeNode(">");                     update_col(); cout << "(>,"                   << yytext << ")\n"; return('>');                }
"?"               {yylval.node = new TreeNode("?");                     update_col(); cout << "(?,"                   << yytext << ")\n"; return('?');                }
">>"              {yylval.node = new TreeNode(">>");                    update_col(); cout << "(RIGHT_SHIFT_OP,"      << yytext << ")\n"; return(RIGHT_SHIFT_OP);     }
"<<"              {yylval.node = new TreeNode("<<");                    update_col(); cout << "(LEFT_SHIFT_OP,"       << yytext << ")\n"; return(LEFT_SHIFT_OP);      }
"++"              {yylval.node = new TreeNode("++");                    update_col(); cout << "(INC_OP,"              << yytext << ")\n"; return(INC_OP);             }
"--"              {yylval.node = new TreeNode("--");                    update_col(); cout << "(DEC_OP,"              << yytext << ")\n"; return(DEC_OP);             }
"."               {yylval.node = new TreeNode(".");                     update_col(); cout << "(.,"                   << yytext << ")\n"; return('.');                }
"->"              {yylval.node = new TreeNode("->");                    update_col(); cout << "(PTR_OP,"              << yytext << ")\n"; return(PTR_OP);             }
"&&"              {yylval.node = new TreeNode("&&");                    update_col(); cout << "(AND_OP,"              << yytext << ")\n"; return(AND_OP);             }
"||"              {yylval.node = new TreeNode("||");                    update_col(); cout << "(OP_OP,"               << yytext << ")\n"; return(OR_OP);              }


[ \t\v\f]         {                                                     update_col();                             }
"\n"              {                                                     update_row();                            }
.                 {                                                     yyerror("Unrecognized");                   }                

%%


int yywrap(void){
  return 1;
}

void update_col() {
  for (int i = 0; yytext[i] != '\0'; i++){
    if(yytext[i] == '\t') yycol += 8 - (yycol % 8);
    else  yycol++;
  }

}

void update_row() {
  yycol = 1;
  ++yyrow;
}

void terminationCheck() {
	char current, prev;
	prev = 0;
  
	while ((current = yyinput()))      
	{
		if (prev == '*' && current == '/') return;
		prev = current;
	}
	yyerror("Unterminated comment");
}
