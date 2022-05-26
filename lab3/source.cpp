#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stack>
#include <unordered_set>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

extern void lexer(const char *input_file, const char *output_file);
void get_inputStr(const char *input_file);
void LL1_parse();

const char *scanner_outfile = "scan_result.txt";

unordered_set<string> vt({
    "if",
    "else",
    "switch",
    "case",
    "default",
    "while",
    "continue",
    "break",
    "return",
    "{",
    "}",
    ";",
    "i",
    "c",
    "++",
    "--",
    "+",
    "-",
    "*",
    "%",
    "/",
    "&",
    "~",
    "!",
    ",",
    "(",
    ")",
    "&&",
    "||",
    "<", 
    "<=", 
    ">", 
    ">=", 
    "==", 
    "!=", 
    "=", 
    "+=", 
    "-=", 
    "*=",
    "/=",
    "%=",
    "<<=",
    ">>=",
    "&=",
    "|=",
    "^=",
    "|",
    "^",
    "<<",
    ">>",
    ".",
    "->",
    ":"
    });

unordered_set<string> vn({
    "statement",
    "labeled_statement",
    "compound_statement",
    "block_item_list",
    "block_item_list'",
    "block_item",
    "assignment_statement",
    "assignment_expression",
    "assignment_op",
    "logical_or_expression",
    "logical_or_expression'",
    "logical_and_expression",
    "logical_and_expression'",
    "inclusive_or_expression",
    "inclusive_or_expression'",
    "exclusive_or_expression",
    "exclusive_or_expression'",
    "and_expression",
    "and_expression'",
    "equality_expression",
    "equality_expression'",
    "relational_expression",
    "relational_expression'",
    "shift_expression",
    "shift_expression'",
    "additive_expression",
    "additive_expression'",
    "multiplicative_expression",
    "multiplicative_expression'",
    "unary_expression",
    "unary_operator",
    "postfix_expression",
    "postfix_expression'",
    "primary_expression",
    "expression",
    "expression'",
    "constant_expression",
    "selection_statement",
    "iteration_statement",
    "jump_statement"
    });

vector<string> producers[] = {
    {"labeled_statement"},
    {"compound_statement"},
    {"assignment_statement"},
    {"selection_statement"},
    {"iteration_statement"},
    {"jump_statement"},
    {"case", "constant_expression", ":", "CASE()", "statement"},
    {"default", ":", "DEFAULT()", "statement"},
    {"{", "block_item_list", "}"},
    {"block_item", "block_item_list'"},
    {"block_item", "block_item_list'"},
    {},
    {"statement"},
    {";"},
    {"assignment_expression", ";"},
    {"i", "PUSH_SEM(i)", "assignment_op", "logical_or_expression", "ASSI(assign_op)"},
    {"=", "PUSH_ASSIGN_OP(=)"},
    {"*=", "PUSH_ASSIGN_OP(*=)"},
    {"/=", "PUSH_ASSIGN_OP(/=)"},
    {"%=", "PUSH_ASSIGN_OP(%=)"},
    {"+=", "PUSH_ASSIGN_OP(+=)"},
    {"-=", "PUSH_ASSIGN_OP(-=)"},
    {"<<=", "PUSH_ASSIGN_OP(<<=)"},
    {">>=", "PUSH_ASSIGN_OP(>>=)"},
    {"&=", "PUSH_ASSIGN_OP(&=)"},
    {"^=", "PUSH_ASSIGN_OP(^=)"},
    {"|=", "PUSH_ASSIGN_OP(|=)"},
    {"logical_and_expression", "logical_or_expression'"},
    {"||", "logical_and_expression", "GEQ_BINARY(||)", "logical_or_expression'"},
    {},
    {"inclusive_or_expression", "logical_and_expression'"},
    {"&&", "inclusive_or_expression", "GEQ_BINARY(&&)", "logical_and_expression'"},
    {},
    {"exclusive_or_expression", "inclusive_or_expression'"},
    {"|", "exclusive_or_expression", "GEQ_BINARY(|)", "inclusive_or_expression'"},
    {},
    {"and_expression", "exclusive_or_expression'"},
    {"^", "and_expression", "GEQ_BINARY(^)", "exclusive_or_expression'"},
    {},
    {"equality_expression", "and_expression'"},
    {"&", "equality_expression", "GEQ_BINARY(&)", "and_expression'"},
    {},
    {"relational_expression", "equality_expression'"},
    {"==", "relational_expression", "GEQ_BINARY(==)", "equality_expression'"},
    {"!=", "relational_expression", "GEQ_BINARY(!=)", "equality_expression'"},
    {},
    {"shift_expression", "relational_expression'"},
    {"<", "shift_expression", "GEQ_BINARY(<)", "relational_expression'"},
    {">", "shift_expression", "GEQ_BINARY(>)", "relational_expression'"},
    {"<=", "shift_expression", "GEQ_BINARY(<=)", "relational_expression'"},
    {">=", "shift_expression", "GEQ_BINARY(>=)", "relational_expression'"},
    {},
    {"additive_expression", "shift_expression'"},
    {"<<", "additive_expression", "GEQ_BINARY(<<)", "shift_expression'"},
    {">>", "additive_expression", "GEQ_BINARY(>>)", "shift_expression'"},
    {},
    {"multiplicative_expression", "additive_expression'"},
    {"+", "multiplicative_expression", "GEQ_BINARY(+)", "additive_expression'"},
    {"-", "multiplicative_expression", "GEQ_BINARY(-)", "additive_expression'"},
    {},
    {"unary_expression", "multiplicative_expression'"},
    {"*", "unary_expression", "GEQ_BINARY(*)", "multiplicative_expression'"},
    {"/", "unary_expression", "GEQ_BINARY(/)", "multiplicative_expression'"},
    {"%", "unary_expression", "GEQ_BINARY(%)", "multiplicative_expression'"},
    {},
    {"postfix_expression"},
    {"++", "unary_expression", "GEQ_UNARY1(++)"},
    {"--", "unary_expression", "GEQ_UNARY1(--)"},
    {"unary_operator", "unary_expression", "GEQ_UNARY2(unary_op)"},
    {"&", "PUSH_UNARY_OP(&)"},
    {"*", "PUSH_UNARY_OP(*)"},
    {"+", "PUSH_UNARY_OP(+)"},
    {"-", "PUSH_UNARY_OP(-)"},
    {"~", "PUSH_UNARY_OP(~)"},
    {"!", "PUSH_UNARY_OP(!)"},
    {"primary_expression", "postfix_expression'"},
    {".", "i", "PUSH_SEM(i)", "GEQ_BINARY(.)", "postfix_expression'"},
    {"->", "i", "PUSH_SEM(i)", "GEQ_BINARY(->)", "postfix_expression'"},
    {"++", "GEQ_UNARY1(++)", "postfix_expression'"},
    {"--", "GEQ_UNARY1(--)", "postfix_expression'"},
    {},
    {"i", "PUSH_SEM(i)"},
    {"c", "PUSH_SEM(c)"},
    {"(", "expression", ")"},
    {"logical_or_expression", "expression'"},
    {",", "logical_or_expression", "GEQ_BINARY(,)", "expression'"},
    {},
    {"logical_or_expression"},
    {"if", "(", "expression", ")", "IF(if)", "statement", "else", "EL(el)", "statement", "IE(ie)"},
    {"switch", "(", "expression", ")", "SWITCH(switch)", "statement", "SE(se)"},
    {"while", "WH(wh)", "(", "expression", ")", "DO(do)", "statement", "WE(we)"},
    {"continue", "CONTINUE()", ";"},
    {"break", "BREAK()", ";"},
    {"return", "expression", "RETURN()", ";"}
};

map<pair<string, string>, int> analysis_table({
	{make_pair("statement", "case"), 0},
    {make_pair("statement", "default"), 0},
    {make_pair("statement", "{"), 1},
    {make_pair("statement", ";"), 2},
    {make_pair("statement", "i"), 2},
    {make_pair("statement", "if"), 3},
    {make_pair("statement", "switch"), 3},
    {make_pair("statement", "while"), 4},
    {make_pair("statement", "continue"), 5},
    {make_pair("statement", "break"), 5},
    {make_pair("statement", "return"), 5},
    {make_pair("labeled_statement", "case"), 6},
    {make_pair("labeled_statement", "default"), 7},
    {make_pair("compound_statement", "{"),8},
    {make_pair("block_item_list", "case"), 9},
    {make_pair("block_item_list", "default"), 9},
    {make_pair("block_item_list", "{"), 9},
    {make_pair("block_item_list", ";"), 9},
    {make_pair("block_item_list", "i"), 9},
    {make_pair("block_item_list", "if"), 9},
    {make_pair("block_item_list", "switch"), 9},
    {make_pair("block_item_list", "while"), 9},
    {make_pair("block_item_list", "continue"), 9},
    {make_pair("block_item_list", "break"), 9},
    {make_pair("block_item_list", "return"), 9},
    {make_pair("block_item_list'", "case"), 10},
    {make_pair("block_item_list'", "default"), 10},
    {make_pair("block_item_list'", "{"), 10},
    {make_pair("block_item_list'", ";"), 10},
    {make_pair("block_item_list'", "i"), 10},
    {make_pair("block_item_list'", "if"), 10},
    {make_pair("block_item_list'", "switch"), 10},
    {make_pair("block_item_list'", "while"), 10},
    {make_pair("block_item_list'", "continue"), 10},
    {make_pair("block_item_list'", "break"), 10},
    {make_pair("block_item_list'", "return"), 10},
    {make_pair("block_item_list'", "}"), 11},
    {make_pair("block_item", "case"), 12},
    {make_pair("block_item", "default"), 12},
    {make_pair("block_item", "{"), 12},
    {make_pair("block_item", ";"), 12},
    {make_pair("block_item", "i"), 12},
    {make_pair("block_item", "if"), 12},
    {make_pair("block_item", "switch"), 12},
    {make_pair("block_item", "while"), 12},
    {make_pair("block_item", "continue"), 12},
    {make_pair("block_item", "break"), 12},
    {make_pair("block_item", "return"), 12},
    {make_pair("assignment_statement", ";"), 13},
	{make_pair("assignment_statement", "i"), 14},
	{make_pair("assignment_expression","i"), 15},
    {make_pair("assignment_op","="), 16},
    {make_pair("assignment_op","*="), 17},
    {make_pair("assignment_op","/="), 18},
    {make_pair("assignment_op","%="), 19},
    {make_pair("assignment_op","+="), 20},
    {make_pair("assignment_op","-="), 21},
    {make_pair("assignment_op","<<="), 22},
    {make_pair("assignment_op",">>="), 23},
    {make_pair("assignment_op","&="), 24},
    {make_pair("assignment_op","^="), 25},
    {make_pair("assignment_op","|="), 26},
    {make_pair("logical_or_expression","++"), 27},
    {make_pair("logical_or_expression","--"), 27},
    {make_pair("logical_or_expression","&"), 27},
    {make_pair("logical_or_expression","*"), 27},
    {make_pair("logical_or_expression","+"), 27},
    {make_pair("logical_or_expression","-"), 27},
    {make_pair("logical_or_expression","~"), 27},
    {make_pair("logical_or_expression","!"), 27},
    {make_pair("logical_or_expression","i"), 27},
    {make_pair("logical_or_expression","c"), 27},
    {make_pair("logical_or_expression","("), 27},
    {make_pair("logical_or_expression'","||"), 28},
    {make_pair("logical_or_expression'",";"), 29},
    {make_pair("logical_or_expression'",","), 29},
    {make_pair("logical_or_expression'",")"), 29},
    {make_pair("logical_or_expression'",":"), 29},
    {make_pair("logical_and_expression","++"), 30},
    {make_pair("logical_and_expression","--"), 30},
    {make_pair("logical_and_expression","&"), 30},
    {make_pair("logical_and_expression","*"), 30},
    {make_pair("logical_and_expression","+"), 30},
    {make_pair("logical_and_expression","-"), 30},
    {make_pair("logical_and_expression","~"), 30},
    {make_pair("logical_and_expression","!"), 30},
    {make_pair("logical_and_expression","i"), 30},
    {make_pair("logical_and_expression","c"), 30},
    {make_pair("logical_and_expression","("), 30},
    {make_pair("logical_and_expression'","&&"), 31},
    {make_pair("logical_and_expression'","||"), 32},
    {make_pair("logical_and_expression'",";"), 32},
    {make_pair("logical_and_expression'",","), 32},
    {make_pair("logical_and_expression'",")"), 32},
    {make_pair("logical_and_expression'",":"), 32},
    {make_pair("inclusive_or_expression","++"), 33},
    {make_pair("inclusive_or_expression","--"), 33},
    {make_pair("inclusive_or_expression","&"), 33},
    {make_pair("inclusive_or_expression","*"), 33},
    {make_pair("inclusive_or_expression","+"), 33},
    {make_pair("inclusive_or_expression","-"), 33},
    {make_pair("inclusive_or_expression","~"), 33},
    {make_pair("inclusive_or_expression","!"), 33},
    {make_pair("inclusive_or_expression","i"), 33},
    {make_pair("inclusive_or_expression","c"), 33},
    {make_pair("inclusive_or_expression","("), 33},
    {make_pair("inclusive_or_expression'","|"), 34},
    {make_pair("inclusive_or_expression'","&&"), 35},
    {make_pair("inclusive_or_expression'","||"), 35},
    {make_pair("inclusive_or_expression'",";"), 35},
    {make_pair("inclusive_or_expression'",","), 35},
    {make_pair("inclusive_or_expression'",")"), 35},
    {make_pair("inclusive_or_expression'",":"), 35},
    {make_pair("exclusive_or_expression","++"),36},
    {make_pair("exclusive_or_expression","--"),36},
    {make_pair("exclusive_or_expression","&"),36},
    {make_pair("exclusive_or_expression", "*"), 36},
    {make_pair("exclusive_or_expression","+"),36},
    {make_pair("exclusive_or_expression","-"),36},
    {make_pair("exclusive_or_expression","~"),36},
    {make_pair("exclusive_or_expression","!"),36},
    {make_pair("exclusive_or_expression","i"),36},
    {make_pair("exclusive_or_expression","c"),36},
    {make_pair("exclusive_or_expression","("),36},
    {make_pair("exclusive_or_expression'","^"),37},
    {make_pair("exclusive_or_expression'","|"),38},
    {make_pair("exclusive_or_expression'","&&"),38},
    {make_pair("exclusive_or_expression'","||"),38},
    {make_pair("exclusive_or_expression'",";"),38},
    {make_pair("exclusive_or_expression'",","),38},
    {make_pair("exclusive_or_expression'",")"),38},
    {make_pair("exclusive_or_expression'",":"),38},
    {make_pair("and_expression","++"),39},
    {make_pair("and_expression","--"),39},
    {make_pair("and_expression","&"),39},
    {make_pair("and_expression","*"),39},
    {make_pair("and_expression","+"),39},
    {make_pair("and_expression","-"),39},
    {make_pair("and_expression","~"),39},
    {make_pair("and_expression","!"),39},
    {make_pair("and_expression","i"),39},
    {make_pair("and_expression","c"),39},
    {make_pair("and_expression","("),39},
    {make_pair("and_expression'","&"),40},
    {make_pair("and_expression'","^"),41},
    {make_pair("and_expression'","|"),41},
    {make_pair("and_expression'","&&"),41},
    {make_pair("and_expression'","||"),41},
    {make_pair("and_expression'",";"),41},
    {make_pair("and_expression'",","),41},
    {make_pair("and_expression'",")"),41},
    {make_pair("and_expression'",":"),41},
    {make_pair("equality_expression","++"),42},
    {make_pair("equality_expression","--"),42},
    {make_pair("equality_expression","&"),42},
    {make_pair("equality_expression","*"),42},
    {make_pair("equality_expression","+"),42},
    {make_pair("equality_expression","-"),42},
    {make_pair("equality_expression","~"),42},
    {make_pair("equality_expression","!"),42},
    {make_pair("equality_expression","i"),42},
    {make_pair("equality_expression","c"),42},
    {make_pair("equality_expression","("),42},
    {make_pair("equality_expression'","=="),43},
    {make_pair("equality_expression'","!="),44},
    {make_pair("equality_expression'","&"),45},
    {make_pair("equality_expression'","^"),45},
    {make_pair("equality_expression'","|"),45},
    {make_pair("equality_expression'","&&"),45},
    {make_pair("equality_expression'","||"),45},
    {make_pair("equality_expression'",";"),45},
    {make_pair("equality_expression'",","),45},
    {make_pair("equality_expression'",")"),45},
    {make_pair("equality_expression'",":"),45},
    {make_pair("relational_expression","++"),46},
    {make_pair("relational_expression","--"),46},
    {make_pair("relational_expression","&"),46},
    {make_pair("relational_expression","*"),46},
    {make_pair("relational_expression","+"),46},
    {make_pair("relational_expression","-"),46},
    {make_pair("relational_expression","~"),46},
    {make_pair("relational_expression","!"),46},
    {make_pair("relational_expression","i"),46},
    {make_pair("relational_expression","c"),46},
    {make_pair("relational_expression","("),46},
    {make_pair("relational_expression'","<"),47},
    {make_pair("relational_expression'",">"),48},
    {make_pair("relational_expression'","<="),49},
    {make_pair("relational_expression'",">="),50},
    {make_pair("relational_expression'","=="),51},
    {make_pair("relational_expression'","!="),51},
    {make_pair("relational_expression'","&"),51},
    {make_pair("relational_expression'","^"),51},
    {make_pair("relational_expression'","|"),51},
    {make_pair("relational_expression'","&&"),51},
    {make_pair("relational_expression'","||"),51},
    {make_pair("relational_expression'",";"),51},
    {make_pair("relational_expression'",","),51},
    {make_pair("relational_expression'",")"),51},
    {make_pair("relational_expression'",":"),51},
    {make_pair("shift_expression","++"),52},
    {make_pair("shift_expression","--"),52},
    {make_pair("shift_expression","&"),52},
    {make_pair("shift_expression","*"),52},
    {make_pair("shift_expression","+"),52},
    {make_pair("shift_expression","-"),52},
    {make_pair("shift_expression","~"),52},
    {make_pair("shift_expression","!"),52},
    {make_pair("shift_expression","i"),52},
    {make_pair("shift_expression","c"),52},
    {make_pair("shift_expression","("),52}, 
    {make_pair("shift_expression'","<<"),53},
    {make_pair("shift_expression'",">>"),54},
    {make_pair("shift_expression'","<"),55},   
    {make_pair("shift_expression'",">"),55},
    {make_pair("shift_expression'","<="),55},   
    {make_pair("shift_expression'",">="),55},
    {make_pair("shift_expression'","=="),55},
    {make_pair("shift_expression'","!="),55},
    {make_pair("shift_expression'","&"),55},
    {make_pair("shift_expression'","^"),55},
    {make_pair("shift_expression'","|"),55},
    {make_pair("shift_expression'","&&"),55},
    {make_pair("shift_expression'","||"),55},
    {make_pair("shift_expression'",";"),55}, 
    {make_pair("shift_expression'",","),55},
    {make_pair("shift_expression'",")"),55},
    {make_pair("shift_expression'",":"),55},                      
    {make_pair("additive_expression","++"),56}, 
    {make_pair("additive_expression","--"),56},
    {make_pair("additive_expression","&"),56},
    {make_pair("additive_expression","*"),56},
    {make_pair("additive_expression","+"),56},
    {make_pair("additive_expression","-"),56},
    {make_pair("additive_expression","~"),56},
    {make_pair("additive_expression","!"),56},
    {make_pair("additive_expression","i"),56},
    {make_pair("additive_expression","c"),56},
    {make_pair("additive_expression","("),56},
    {make_pair("additive_expression'","+"),57},
    {make_pair("additive_expression'","-"),58},
    {make_pair("additive_expression'","<<"),59},
    {make_pair("additive_expression'",">>"),59},
    {make_pair("additive_expression'","<"),59},
    {make_pair("additive_expression'",">"),59},
    {make_pair("additive_expression'","<="),59},
    {make_pair("additive_expression'",">="),59},
    {make_pair("additive_expression'","=="),59},
    {make_pair("additive_expression'","!="),59},
    {make_pair("additive_expression'","&"),59},
    {make_pair("additive_expression'","^"),59},
    {make_pair("additive_expression'","|"),59},
    {make_pair("additive_expression'","&&"),59},
    {make_pair("additive_expression'","||"),59},
    {make_pair("additive_expression'",";"),59},
    {make_pair("additive_expression'",","),59},
    {make_pair("additive_expression'",")"),59},
    {make_pair("additive_expression'",":"),59},
    {make_pair("multiplicative_expression","++"),60},
    {make_pair("multiplicative_expression","--"),60},
    {make_pair("multiplicative_expression","&"),60},
    {make_pair("multiplicative_expression","*"),60},
    {make_pair("multiplicative_expression","+"),60},
    {make_pair("multiplicative_expression","-"),60},
    {make_pair("multiplicative_expression","~"),60},
    {make_pair("multiplicative_expression","!"),60},
    {make_pair("multiplicative_expression","i"),60},
    {make_pair("multiplicative_expression","c"),60},
    {make_pair("multiplicative_expression","("),60},
    {make_pair("multiplicative_expression'","*"),61},
    {make_pair("multiplicative_expression'","/"),62},
    {make_pair("multiplicative_expression'","%"),63},
    {make_pair("multiplicative_expression'","+"),64},
    {make_pair("multiplicative_expression'","-"),64},
    {make_pair("multiplicative_expression'","<<"),64},
    {make_pair("multiplicative_expression'",">>"),64},
    {make_pair("multiplicative_expression'","<"),64},
    {make_pair("multiplicative_expression'",">"),64},
    {make_pair("multiplicative_expression'","<="),64},
    {make_pair("multiplicative_expression'",">="),64},
    {make_pair("multiplicative_expression'","=="),64},
    {make_pair("multiplicative_expression'","!="),64},
    {make_pair("multiplicative_expression'","&"),64},
    {make_pair("multiplicative_expression'","^"),64},
    {make_pair("multiplicative_expression'","|"),64},
    {make_pair("multiplicative_expression'","&&"),64},
    {make_pair("multiplicative_expression'","||"),64},
    {make_pair("multiplicative_expression'",";"),64},
    {make_pair("multiplicative_expression'",","),64},
    {make_pair("multiplicative_expression'",")"),64},
    {make_pair("multiplicative_expression'",":"),64},
    {make_pair("unary_expression","i"),65},
    {make_pair("unary_expression","c"),65},
    {make_pair("unary_expression","("),65},
    {make_pair("unary_expression","++"),66},
    {make_pair("unary_expression","--"),67},
    {make_pair("unary_expression","&"),68},
    {make_pair("unary_expression","*"),68},
    {make_pair("unary_expression","+"),68},
    {make_pair("unary_expression","-"),68},
    {make_pair("unary_expression","~"),68},
    {make_pair("unary_expression","!"),68},
    {make_pair("unary_operator","&"),69},
    {make_pair("unary_operator","*"),70},
    {make_pair("unary_operator","+"),71},
    {make_pair("unary_operator","-"),72},
    {make_pair("unary_operator","~"),73},
    {make_pair("unary_operator","!"),74},
    {make_pair("postfix_expression","i"),75},
    {make_pair("postfix_expression","c"),75},
    {make_pair("postfix_expression","("),75},
    {make_pair("postfix_expression'","."),76},
    {make_pair("postfix_expression'","->"),77},
    {make_pair("postfix_expression'","++"),78},
    {make_pair("postfix_expression'","--"),79},
    {make_pair("postfix_expression'","*"),80},
    {make_pair("postfix_expression'","/"),80},
    {make_pair("postfix_expression'","%"),80},
    {make_pair("postfix_expression'","+"),80},
    {make_pair("postfix_expression'","-"),80},
    {make_pair("postfix_expression'","<<"),80},
    {make_pair("postfix_expression'",">>"),80},
    {make_pair("postfix_expression'","<"), 80},
    {make_pair("postfix_expression'",">"), 80},
    {make_pair("postfix_expression'","<="), 80},
    {make_pair("postfix_expression'",">="), 80},
    {make_pair("postfix_expression'","=="), 80},
    {make_pair("postfix_expression'","!="), 80},
    {make_pair("postfix_expression'","&"), 80},
    {make_pair("postfix_expression'","^"), 80},
    {make_pair("postfix_expression'","|"), 80},
    {make_pair("postfix_expression'","&&"), 80},
    {make_pair("postfix_expression'","||"), 80},
    {make_pair("postfix_expression'",";"), 80},
    {make_pair("postfix_expression'",","), 80},
    {make_pair("postfix_expression'",")"), 80},
    {make_pair("postfix_expression'",":"), 80},
    {make_pair("primary_expression","i"), 81},
    {make_pair("primary_expression","c"), 82},
    {make_pair("primary_expression","("), 83},
    {make_pair("expression","++"), 84},
    {make_pair("expression","--"), 84},
    {make_pair("expression","&"), 84},
    {make_pair("expression","*"), 84},
    {make_pair("expression","+"), 84},
    {make_pair("expression","-"), 84},
    {make_pair("expression","~"), 84},
    {make_pair("expression","!"), 84},
    {make_pair("expression","i"), 84},
    {make_pair("expression","c"), 84},
    {make_pair("expression","("), 84},
    {make_pair("expression'",","), 85},
    {make_pair("expression'",")"), 86},
    {make_pair("expression'",";"), 86},
    {make_pair("constant_expression","++"), 87},
    {make_pair("constant_expression","--"), 87},
    {make_pair("constant_expression","&"), 87},
    {make_pair("constant_expression","*"), 87},
    {make_pair("constant_expression","+"), 87},
    {make_pair("constant_expression","-"), 87},
    {make_pair("constant_expression","~"), 87},
    {make_pair("constant_expression","!"), 87},
    {make_pair("constant_expression","i"), 87},
    {make_pair("constant_expression","c"), 87},
    {make_pair("constant_expression","("), 87},
    {make_pair("selection_statement","if"), 88},
    {make_pair("selection_statement","switch"), 89},
    {make_pair("iteration_statement","while"), 90},
    {make_pair("jump_statement","continue"), 91},
    {make_pair("jump_statement","break"), 92},
    {make_pair("jump_statement","return"), 93}
}
);

struct quadruple {
    string op;
    string arg1;
    string arg2;
    string res;
};

vector<string> input_str;
vector<string> preprocessed_input_str;

vector<string> SYN;
vector<string> SEM;
vector<string> assign_op;
vector<string> unary_op;

vector<quadruple> quadruples;

int temp_num = 1;

int main(int argc, char** argv) {
    if (argc < 2) {
		cerr << "Usage: <program_name> <input_file>\n";
		exit(-1);	
	}
	
	lexer(argv[1], scanner_outfile);
	
	get_inputStr(scanner_outfile);
	LL1_parse();
	
	return 0;
}

void get_inputStr(const char *input_file) {
	ifstream fin(input_file);
	string token;
	
	while (getline(fin, token)) {
		int i;
		string type_code;
		for (i = 1; token[i] != ','; ++i) {
			type_code += token[i];
		}
        string terminal = token.substr(i+2, token.size() - (i+2) - 1);

		if (type_code == "ID") terminal = "i";
		else if (type_code == "INT_CONSTANT" || type_code == "FLOAT_CONSTANT" || type_code == "CHARACTER" || type_code == "STRING")	terminal = "c";
		
        if (vt.count(terminal)) {
            preprocessed_input_str.push_back(terminal);
		    input_str.push_back(token.substr(i+2, token.size() - (i+2) - 1));
        }
	}
	preprocessed_input_str.push_back("#");
    input_str.push_back("#");
	fin.close();
}

void print_quadruple(const quadruple& q) {
    cout << "( " << q.op << ", " << q.arg1 << ", " << q.arg2 << ", " << q.res  << " )\n";
}

void print_stack(const vector<string>& st, const string& st_name) {
    cout << st_name << ": ";
	for (auto item : st) cout << item << " ";
    cout << endl;
}

string new_temp() {
    return "t" + to_string(temp_num++);
}

void LL1_parse() {
	SYN.push_back("#");
    SYN.push_back("statement");

	int i;
	string next;

	i = 0;
	next = preprocessed_input_str[i];

    int step = 0;

	while (true) {
        string top = SYN.back();
        #ifdef DEBUG 
            if (step >= 1) cout << "\n\n";   
            cout << "Step: " << step++ << endl; 
            cout << "top of SYN: " << top << endl;
            cout << "next: " << next << endl;
            print_stack(SYN, "SYN");
            print_stack(SEM, "SEM");
            print_stack(assign_op, "assign_op");
            print_stack(unary_op, "unary_op");
        #endif
		SYN.pop_back();

		if (vt.count(top)) {
			if (top != next) {
				cerr <<  "Error: Terminal " << top << " on top of SYN stack doesn't match " << input_str[i] << "in input\n";
				return;
			}
			next = preprocessed_input_str[++i];
            #ifdef DEBUG
                cout << "operation: Next(w)\n";
            #endif
		}
		else if (vn.count(top)) {
			pair<string, string> entry = make_pair(top, next);
			if (!analysis_table.count(entry)) {
				cerr << "Error: Can't find production entry in LL(1) analysis table corresponding to (" << top << "," << preprocessed_input_str[i] << ")\n";
				return;
			}
			else {
                #ifdef DEBUG
                    cout << "operation: PUSH(" << analysis_table[entry] <<") R\n";
				#endif

                for (int j = producers[analysis_table[entry]].size() - 1; j >= 0; j--) {
                    string tmp = producers[analysis_table[entry]][j];
                    if (tmp == "PUSH_SEM(i)" || tmp == "PUSH_SEM(c)") {
                        SYN.push_back(string("PUSH_SEM(") + input_str[i] + string(")"));
                    }
                    else SYN.push_back(tmp);
                } 
			}
		}
		else if (top == "CASE()") {
            quadruple qua;
            qua.op = "case";
            qua.arg1 = "_";
            qua.arg2 = "_";
            qua.res = SEM.back();
            print_quadruple(qua);
            SEM.pop_back();
        }
        else if (top == "DEFAULT()") {
            quadruple qua;
            qua.op = "default";
            qua.arg1 = "_";
            qua.arg2 = "_";
            qua.res = "_";
            print_quadruple(qua);
        }
        else if (top.find("GEQ_BINARY") != string::npos) { // GEQ_BINARY(->)
            quadruple qua;
            qua.op = top.substr(strlen("GEQ_BINARY") + 1, top.size() - strlen("GEQ_BINARY") - 2);
            qua.arg2 = SEM.back();
            SEM.pop_back();
            qua.arg1 = SEM.back();
            SEM.pop_back();
            qua.res = new_temp();
            print_quadruple(qua);
            SEM.push_back(qua.res);
        }
        else if (top == "ASSI(assign_op)") {
            quadruple qua;
            qua.op = assign_op.back();
            assign_op.pop_back();
            qua.arg1 = SEM.back();
            SEM.pop_back();
            qua.arg2 = "_";
            qua.res = SEM.back();
            print_quadruple(qua);
        }
        else if (top.find("PUSH_ASSIGN_OP") != string::npos) {
            assign_op.push_back(top.substr(strlen("PUSH_ASSIGN_OP") + 1, top.size() - strlen("PUSH_ASSIGN_OP") - 2));
        }
        else if (top.find("GEQ_UNARY1") != string::npos) {
            quadruple qua;
            qua.op = top.substr(strlen("GEQ_UNARY1") + 1, top.size() - strlen("GEQ_UNARY1") - 2);
            qua.arg1 = SEM.back();
            qua.arg2 = "_";
            qua.res = qua.arg1;
            print_quadruple(qua);
        }
        else if (top.find("GEQ_UNARY2") != string::npos) {
            quadruple qua;
            qua.op = unary_op.back();
            unary_op.pop_back();
            qua.arg1 = SEM.back();
            SEM.pop_back();
            qua.arg2 = "_";
            qua.res = new_temp();
            print_quadruple(qua);
            SEM.push_back(qua.res);
        }
        else if (top.find("PUSH_UNARY_OP") != string::npos) {
            unary_op.push_back(top.substr(strlen("PUSH_UNARY_OP") + 1, top.size() - strlen("PUSH_UNARY_OP") - 2));
        }
        else if (top.find("PUSH_SEM") != string::npos) {
            SEM.push_back(top.substr(strlen("PUSH_SEM") + 1, top.size() - strlen("PUSH_SEM") - 2));
        }
        else if (top == "IF(if)") {
            quadruple qua;
            qua.op = "if";
            qua.arg1 = SEM.back();
            SEM.pop_back();
            qua.res = qua.arg2 = "_";
            print_quadruple(qua);
        }
        else if (top == "EL(el)") {
            quadruple qua;
            qua.op = "el";
            qua.res = qua.arg2 = qua.arg1 = "_";
            print_quadruple(qua);
        }
        else if (top == "IE(ie)") {
            quadruple qua;
            qua.op = "ie";
            qua.res = qua.arg2 = qua.arg1 = "_";
            print_quadruple(qua);
        }
        else if (top == "SWITCH(switch)") {
            quadruple qua;
            qua.op = "switch";
            qua.arg1 = SEM.back();
            SEM.pop_back();
            qua.res = qua.arg2 = "_";
            print_quadruple(qua);
        }
        else if (top == "SE(se)") {
            quadruple qua;
            qua.op = "se";
            qua.res = qua.arg2 = qua.arg1 = "_";
            print_quadruple(qua);
        }
        else if (top == "WH(wh)") {
            quadruple qua;
            qua.op = "wh";
            qua.res = qua.arg2 = qua.arg1 = "_";
            print_quadruple(qua);
        }
        else if (top == "DO(do)") {
            quadruple qua;
            qua.op = "do";
            qua.arg1 = SEM.back();
            SEM.pop_back();
            qua.res = qua.arg2 = "_";
            print_quadruple(qua);
        }
        else if (top == "WE(we)") {
            quadruple qua;
            qua.op = "we";
            qua.res = qua.arg2 = qua.arg1 = "_";
            print_quadruple(qua);
        }
        else if (top == "CONTINUE()") {
            quadruple qua;
            qua.op = "continue";
            qua.res = qua.arg2 = qua.arg1 = "_";
            print_quadruple(qua);
        }
        else if (top == "BREAK()") {
            quadruple qua;
            qua.op = "break";
            qua.res = qua.arg2 = qua.arg1 = "_";
            print_quadruple(qua);
        }
        else if (top == "RETURN()") {
            quadruple qua;
            qua.op = "return";
            qua.arg2 = qua.arg1 = "_";
            qua.res = SEM.back();
            SEM.pop_back();
            print_quadruple(qua);
        }
        else if (next == "#") {
			cout << "Successful semantic analysis!\n";
			break;
		}
		else {
			SYN.push_back("#");
            SYN.push_back("statement");
		}
	}
}