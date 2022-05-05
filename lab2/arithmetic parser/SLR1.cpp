#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <stack>

using namespace std;

extern void lexer(const char *input_file, const char *output_file);
void get_inputStr(const char *input_file, vector<string>& preprocessed_input_str);
void SLR1_parse(const vector<string>& preprocessed_input_str);

const char *scanner_outfile = "scan_result.txt";
const char *scanner_infile = "input_expr.txt";

const pair<string, vector<string>> producers[] = {
    {"E'",{"E"}},
    {"E",{"F"}},
    {"E",{"E","+","F"}},
    {"E",{"E","-","F"}},
    {"F",{"G"}},
    {"F",{"F","*","G"}},
    {"F",{"F","/","G"}},
    {"F",{"F","%","G"}},
    {"G",{"H"}},
    {"G",{"++","G"}},
    {"G",{"--","G"}},
    {"G",{"J","G"}},
    {"G",{"sizeof","(","K",")"}},
    {"H",{"I"}},
    {"H",{"H","++"}},
    {"H",{"H","--"}},
    {"H",{"H",".","i"}},
    {"H",{"H","->","i"}},
    {"I",{"i"}},
    {"I",{"c"}},
    {"I",{"(","E",")"}},
    {"J",{"&"}},
    {"J",{"*"}},
    {"J",{"+"}},
    {"J",{"-"}},
    {"J",{"~"}},
    {"J",{"!"}},
    {"K",{"L"}},
    {"K",{"r","K"}},
    {"L",{"t"}},
    {"L",{"M"}},
    {"M",{"s","i"}}
};

map<pair<int, string>, string> action(
    {
        {make_pair(0, "i"), "s7"},
        {make_pair(0, "c"), "s8"},
        {make_pair(0, "+"), "s9"},
        {make_pair(0, "-"), "s10"},
        {make_pair(0, "*"), "s11"},
        {make_pair(0, "++"), "s12"},
        {make_pair(0, "--"), "s13"},
        {make_pair(0, "sizeof"), "s14"},
        {make_pair(0, "("), "s15"},
        {make_pair(0, "&"), "s16"},
        {make_pair(0, "~"), "s17"},
        {make_pair(0, "!"), "s18"},
        {make_pair(1, "+"), "s19"},
        {make_pair(1, "-"), "s20"},
        {make_pair(1, "#"), "acc"},
        {make_pair(2, "+"), "r1"},
        {make_pair(2, "-"), "r1"},
        {make_pair(2, "*"), "s21"},
        {make_pair(2, "/"), "s22"},
        {make_pair(2, "%"), "s23"},
        {make_pair(2, ")"), "r1"},
        {make_pair(2, "#"), "r1"},
        {make_pair(3, "+"), "r4"},
        {make_pair(3, "-"), "r4"},
        {make_pair(3, "*"), "r4"},
        {make_pair(3, "/"), "r4"},
        {make_pair(3, "%"), "r4"},
        {make_pair(3, ")"), "r4"},
        {make_pair(3, "#"), "r4"},
        {make_pair(4, "+"), "r8"},
        {make_pair(4, "-"), "r8"},
        {make_pair(4, "*"), "r8"},
        {make_pair(4, "/"), "r8"},
        {make_pair(4, "%"), "r8"},
        {make_pair(4, "++"), "s24"},
        {make_pair(4, "--"), "s25"},
        {make_pair(4, "."), "s26"},
        {make_pair(4, "->"), "s27"},
        {make_pair(4, ")"), "r8"},
        {make_pair(4, "#"), "r8"},
        {make_pair(5, "+"), "r13"},
        {make_pair(5, "-"), "r13"},
        {make_pair(5, "*"), "r13"},
        {make_pair(5, "/"), "r13"},
        {make_pair(5, "%"), "r13"},
        {make_pair(5, "++"), "r13"},
        {make_pair(5, "--"), "r13"},
        {make_pair(5, "."), "r13"},
        {make_pair(5, "->"), "r13"},
        {make_pair(5, ")"), "r13"},
        {make_pair(5, "#"), "r13"},
        {make_pair(6, "i"), "s7"},
        {make_pair(6, "c"), "s8"},
        {make_pair(6, "+"), "s9"},
        {make_pair(6, "-"), "s10"},
        {make_pair(6, "*"), "s11"},
        {make_pair(6, "++"), "s12"},
        {make_pair(6, "--"), "s13"},
        {make_pair(6, "sizeof"), "s14"},
        {make_pair(6, "("), "s15"},
        {make_pair(6, "&"), "s16"},
        {make_pair(6, "~"), "s17"},
        {make_pair(6, "!"), "s18"},
        {make_pair(7, "+"), "r18"},
        {make_pair(7, "-"), "r18"},
        {make_pair(7, "*"), "r18"},
        {make_pair(7, "/"), "r18"},
        {make_pair(7, "%"), "r18"},
        {make_pair(7, "++"), "r18"},
        {make_pair(7, "--"), "r18"},
        {make_pair(7, "."), "r18"},
        {make_pair(7, "->"), "r18"},
        {make_pair(7, ")"), "r18"},
        {make_pair(7, "#"), "r18"},
        {make_pair(8, "+"), "r19"},
        {make_pair(8, "-"), "r19"},
        {make_pair(8, "*"), "r19"},
        {make_pair(8, "/"), "r19"},
        {make_pair(8, "%"), "r19"},
        {make_pair(8, "++"), "r19"},
        {make_pair(8, "--"), "r19"},
        {make_pair(8, "."), "r19"},
        {make_pair(8, "->"), "r19"},
        {make_pair(8, ")"), "r19"},
        {make_pair(8, "#"), "r19"},
        {make_pair(9, "i"), "r23"},
        {make_pair(9, "c"), "r23"},
        {make_pair(9, "+"), "r23"},
        {make_pair(9, "-"), "r23"},
        {make_pair(9, "*"), "r23"},
        {make_pair(9, "++"), "r23"},
        {make_pair(9, "--"), "r23"},
        {make_pair(9, "sizeof"), "r23"},
        {make_pair(9, "("), "r23"},
        {make_pair(9, "&"), "r23"},
        {make_pair(9, "~"), "r23"},
        {make_pair(9, "!"), "r23"},
        {make_pair(10, "i"), "r24"},
        {make_pair(10, "c"), "r24"},
        {make_pair(10, "+"), "r24"},
        {make_pair(10, "-"), "r24"},
        {make_pair(10, "*"), "r24"},
        {make_pair(10, "++"), "r24"},
        {make_pair(10, "--"), "r24"},
        {make_pair(10, "sizeof"), "r24"},
        {make_pair(10, "("), "r24"},
        {make_pair(10, "&"), "r24"},
        {make_pair(10, "~"), "r24"},
        {make_pair(10, "!"), "r24"},
        {make_pair(11, "i"), "r22"},
        {make_pair(11, "c"), "r22"},
        {make_pair(11, "+"), "r22"},
        {make_pair(11, "-"), "r22"},
        {make_pair(11, "*"), "r22"},
        {make_pair(11, "++"), "r22"},
        {make_pair(11, "--"), "r22"},
        {make_pair(11, "sizeof"), "r22"},
        {make_pair(11, "("), "r22"},
        {make_pair(11, "&"), "r22"},
        {make_pair(11, "~"), "r22"},
        {make_pair(11, "!"), "r22"},
        {make_pair(12, "i"), "s7"},
        {make_pair(12, "c"), "s8"},
        {make_pair(12, "+"), "s9"},
        {make_pair(12, "-"), "s10"},
        {make_pair(12, "*"), "s11"},
        {make_pair(12, "++"), "s12"},
        {make_pair(12, "--"), "s13"},
        {make_pair(12, "sizeof"), "s14"},
        {make_pair(12, "("), "s15"},
        {make_pair(12, "&"), "s16"},
        {make_pair(12, "~"), "s17"},
        {make_pair(12, "!"), "s18"},
        {make_pair(13, "i"), "s7"},
        {make_pair(13, "c"), "s8"},
        {make_pair(13, "+"), "s9"},
        {make_pair(13, "-"), "s10"},
        {make_pair(13, "*"), "s11"},
        {make_pair(13, "++"), "s12"},
        {make_pair(13, "--"), "s13"},
        {make_pair(13, "sizeof"), "s14"},
        {make_pair(13, "("), "s15"},
        {make_pair(13, "&"), "s16"},
        {make_pair(13, "~"), "s17"},
        {make_pair(13, "!"), "s18"},
        {make_pair(14, "("), "s31"},
        {make_pair(15, "i"), "s7"},
        {make_pair(15, "c"), "s8"},
        {make_pair(15, "+"), "s9"},
        {make_pair(15, "-"), "s10"},
        {make_pair(15, "*"), "s11"},
        {make_pair(15, "++"), "s12"},
        {make_pair(15, "--"), "s13"},
        {make_pair(15, "sizeof"), "s14"},
        {make_pair(15, "("), "s15"},
        {make_pair(15, "&"), "s16"},
        {make_pair(15, "~"), "s17"},
        {make_pair(15, "!"), "s18"},
        {make_pair(16, "i"), "r21"},
        {make_pair(16, "c"), "r21"},
        {make_pair(16, "+"), "r21"},
        {make_pair(16, "-"), "r21"},
        {make_pair(16, "*"), "r21"},
        {make_pair(16, "++"), "r21"},
        {make_pair(16, "--"), "r21"},
        {make_pair(16, "sizeof"), "r21"},
        {make_pair(16, "("), "r21"},
        {make_pair(16, "&"), "r21"},
        {make_pair(16, "~"), "r21"},
        {make_pair(16, "!"), "r21"},
        {make_pair(17, "i"), "r25"},
        {make_pair(17, "c"), "r25"},
        {make_pair(17, "+"), "r25"},
        {make_pair(17, "-"), "r25"},
        {make_pair(17, "*"), "r25"},
        {make_pair(17, "++"), "r25"},
        {make_pair(17, "--"), "r25"},
        {make_pair(17, "sizeof"), "r25"},
        {make_pair(17, "("), "r25"},
        {make_pair(17, "&"), "r25"},
        {make_pair(17, "~"), "r25"},
        {make_pair(17, "!"), "r25"},
        {make_pair(18, "i"), "r26"},
        {make_pair(18, "c"), "r26"},
        {make_pair(18, "+"), "r26"},
        {make_pair(18, "-"), "r26"},
        {make_pair(18, "*"), "r26"},
        {make_pair(18, "++"), "r26"},
        {make_pair(18, "--"), "r26"},
        {make_pair(18, "sizeof"), "r26"},
        {make_pair(18, "("), "r26"},
        {make_pair(18, "&"), "r26"},
        {make_pair(18, "~"), "r26"},
        {make_pair(18, "!"), "r26"},
        {make_pair(19, "i"), "s7"},
        {make_pair(19, "c"), "s8"},
        {make_pair(19, "+"), "s9"},
        {make_pair(19, "-"), "s10"},
        {make_pair(19, "*"), "s11"},
        {make_pair(19, "++"), "s12"},
        {make_pair(19, "--"), "s13"},
        {make_pair(19, "sizeof"), "s14"},
        {make_pair(19, "("), "s15"},
        {make_pair(19, "&"), "s16"},
        {make_pair(19, "~"), "s17"},
        {make_pair(19, "!"), "s18"},
        {make_pair(20, "i"), "s7"},
        {make_pair(20, "c"), "s8"},
        {make_pair(20, "+"), "s9"},
        {make_pair(20, "-"), "s10"},
        {make_pair(20, "*"), "s11"},
        {make_pair(20, "++"), "s12"},
        {make_pair(20, "--"), "s13"},
        {make_pair(20, "sizeof"), "s14"},
        {make_pair(20, "("), "s15"},
        {make_pair(20, "&"), "s16"},
        {make_pair(20, "~"), "s17"},
        {make_pair(20, "!"), "s18"},
        {make_pair(21, "i"), "s7"},
        {make_pair(21, "c"), "s8"},
        {make_pair(21, "+"), "s9"},
        {make_pair(21, "-"), "s10"},
        {make_pair(21, "*"), "s11"},
        {make_pair(21, "++"), "s12"},
        {make_pair(21, "--"), "s13"},
        {make_pair(21, "sizeof"), "s14"},
        {make_pair(21, "("), "s15"},
        {make_pair(21, "&"), "s16"},
        {make_pair(21, "~"), "s17"},
        {make_pair(21, "!"), "s18"},
        {make_pair(22, "i"), "s7"},
        {make_pair(22, "c"), "s8"},
        {make_pair(22, "+"), "s9"},
        {make_pair(22, "-"), "s10"},
        {make_pair(22, "*"), "s11"},
        {make_pair(22, "++"), "s12"},
        {make_pair(22, "--"), "s13"},
        {make_pair(22, "sizeof"), "s14"},
        {make_pair(22, "("), "s15"},
        {make_pair(22, "&"), "s16"},
        {make_pair(22, "~"), "s17"},
        {make_pair(22, "!"), "s18"},
        {make_pair(23, "i"), "s7"},
        {make_pair(23, "c"), "s8"},
        {make_pair(23, "+"), "s9"},
        {make_pair(23, "-"), "s10"},
        {make_pair(23, "*"), "s11"},
        {make_pair(23, "++"), "s12"},
        {make_pair(23, "--"), "s13"},
        {make_pair(23, "sizeof"), "s14"},
        {make_pair(23, "("), "s15"},
        {make_pair(23, "&"), "s16"},
        {make_pair(23, "~"), "s17"},
        {make_pair(23, "!"), "s18"},
        {make_pair(24, "+"), "r14"},
        {make_pair(24, "-"), "r14"},
        {make_pair(24, "*"), "r14"},
        {make_pair(24, "/"), "r14"},
        {make_pair(24, "%"), "r14"},
        {make_pair(24, "++"), "r14"},
        {make_pair(24, "--"), "r14"},
        {make_pair(24, "."), "r14"},
        {make_pair(24, "->"), "r14"},
        {make_pair(24, ")"), "r14"},
        {make_pair(24, "#"), "r14"},
        {make_pair(25, "+"), "r15"},
        {make_pair(25, "-"), "r15"},
        {make_pair(25, "*"), "r15"},
        {make_pair(25, "/"), "r15"},
        {make_pair(25, "%"), "r15"},
        {make_pair(25, "++"), "r15"},
        {make_pair(25, "--"), "r15"},
        {make_pair(25, "."), "r15"},
        {make_pair(25, "->"), "r15"},
        {make_pair(25, ")"), "r15"},
        {make_pair(25, "#"), "r15"},
        {make_pair(26, "i"), "s38"},
        {make_pair(27, "i"), "s39"},
        {make_pair(28, "+"), "r11"},
        {make_pair(28, "-"), "r11"},
        {make_pair(28, "*"), "r11"},
        {make_pair(28, "/"), "r11"},
        {make_pair(28, "%"), "r11"},
        {make_pair(28, ")"), "r11"},
        {make_pair(28, "#"), "r11"},
        {make_pair(29, "+"), "r9"},
        {make_pair(29, "-"), "r9"},
        {make_pair(29, "*"), "r9"},
        {make_pair(29, "/"), "r9"},
        {make_pair(29, "%"), "r9"},
        {make_pair(29, ")"), "r9"},
        {make_pair(29, "#"), "r9"},
        {make_pair(30, "+"), "r10"},
        {make_pair(30, "-"), "r10"},
        {make_pair(30, "*"), "r10"},
        {make_pair(30, "/"), "r10"},
        {make_pair(30, "%"), "r10"},
        {make_pair(30, ")"), "r10"},
        {make_pair(30, "#"), "r10"},
        {make_pair(31, "r"), "s43"},
        {make_pair(31, "s"), "s44"},
        {make_pair(31, "t"), "s45"},
        {make_pair(32, "+"), "s19"},
        {make_pair(32, "-"), "s20"},
        {make_pair(32, ")"), "s46"},
        {make_pair(33, "+"), "r2"},
        {make_pair(33, "-"), "r2"},
        {make_pair(33, "*"), "s21"},
        {make_pair(33, "/"), "s22"},
        {make_pair(33, "%"), "s23"},
        {make_pair(33, ")"), "r2"},
        {make_pair(33, "#"), "r2"},
        {make_pair(34, "+"), "r3"},
        {make_pair(34, "-"), "r3"},
        {make_pair(34, "*"), "s21"},
        {make_pair(34, "/"), "s22"},
        {make_pair(34, "%"), "s23"},
        {make_pair(34, ")"), "r3"},
        {make_pair(34, "#"), "r3"},
        {make_pair(35, "+"), "r5"},
        {make_pair(35, "-"), "r5"},
        {make_pair(35, "*"), "r5"},
        {make_pair(35, "/"), "r5"},
        {make_pair(35, "%"), "r5"},
        {make_pair(35, ")"), "r5"},
        {make_pair(35, "#"), "r5"},
        {make_pair(36, "+"), "r6"},
        {make_pair(36, "-"), "r6"},
        {make_pair(36, "*"), "r6"},
        {make_pair(36, "/"), "r6"},
        {make_pair(36, "%"), "r6"},
        {make_pair(36, ")"), "r6"},
        {make_pair(36, "#"), "r6"},
        {make_pair(37, "+"), "r7"},
        {make_pair(37, "-"), "r7"},
        {make_pair(37, "*"), "r7"},
        {make_pair(37, "/"), "r7"},
        {make_pair(37, "%"), "r7"},
        {make_pair(37, ")"), "r7"},
        {make_pair(37, "#"), "r7"},
        {make_pair(38, "+"), "r16"},
        {make_pair(38, "-"), "r16"},
        {make_pair(38, "*"), "r16"},
        {make_pair(38, "/"), "r16"},
        {make_pair(38, "%"), "r16"},
        {make_pair(38, "++"), "r16"},
        {make_pair(38, "--"), "r16"},
        {make_pair(38, "."), "r16"},
        {make_pair(38, "->"), "r16"},
        {make_pair(38, ")"), "r16"},
        {make_pair(38, "#"), "r16"},
        {make_pair(39, "+"), "r17"},
        {make_pair(39, "-"), "r17"},
        {make_pair(39, "*"), "r17"},
        {make_pair(39, "/"), "r17"},
        {make_pair(39, "%"), "r17"},
        {make_pair(39, "++"), "r17"},
        {make_pair(39, "--"), "r17"},
        {make_pair(39, "."), "r17"},
        {make_pair(39, "->"), "r17"},
        {make_pair(39, ")"), "r17"},
        {make_pair(39, "#"), "r17"},
        {make_pair(40, ")"), "s47"},
        {make_pair(41, ")"), "r27"},
        {make_pair(42, ")"), "r30"},
        {make_pair(43, "r"), "s43"},
        {make_pair(43, "s"), "s44"},
        {make_pair(43, "t"), "s45"},
        {make_pair(44, "i"), "s49"},
        {make_pair(45, ")"), "r29"},
        {make_pair(46, "+"), "r20"},
        {make_pair(46, "-"), "r20"},
        {make_pair(46, "*"), "r20"},
        {make_pair(46, "/"), "r20"},
        {make_pair(46, "%"), "r20"},
        {make_pair(46, "++"), "r20"},
        {make_pair(46, "--"), "r20"},
        {make_pair(46, "."), "r20"},
        {make_pair(46, "->"), "r20"},
        {make_pair(46, ")"), "r20"},
        {make_pair(46, "#"), "r20"},
        {make_pair(47, "+"), "r12"},
        {make_pair(47, "-"), "r12"},
        {make_pair(47, "*"), "r12"},
        {make_pair(47, "/"), "r12"},
        {make_pair(47, "%"), "r12"},
        {make_pair(47, ")"), "r12"},
        {make_pair(47, "#"), "r12"},
        {make_pair(48, ")"), "r28"},
        {make_pair(49, ")"), "r31"}
    }
);

map<pair<int, string>, int> go (
    {
        {make_pair(0, "E"), 1},
        {make_pair(0, "F"), 2},
        {make_pair(0, "G"), 3},
        {make_pair(0, "H"), 4},
        {make_pair(0, "I"), 5},
        {make_pair(0, "J"), 6},
        {make_pair(6, "G"), 28},
        {make_pair(6, "H"), 4},
        {make_pair(6, "I"), 5},
        {make_pair(6, "J"), 6},
        {make_pair(12, "G"), 29},
        {make_pair(12, "H"), 4},
        {make_pair(12, "I"), 5},
        {make_pair(12, "J"), 6},
        {make_pair(13, "G"), 30},
        {make_pair(13, "H"), 4},
        {make_pair(13, "I"), 5},
        {make_pair(13, "J"), 6},
        {make_pair(15, "E"), 32},
        {make_pair(15, "F"), 2},
        {make_pair(15, "G"), 3},
        {make_pair(15, "H"), 4},
        {make_pair(15, "I"), 5},
        {make_pair(15, "J"), 6},
        {make_pair(19, "F"), 33},
        {make_pair(19, "G"), 3},
        {make_pair(19, "H"), 4},
        {make_pair(19, "I"), 5},
        {make_pair(19, "J"), 6},
        {make_pair(20, "F"), 34},
        {make_pair(20, "G"), 3},
        {make_pair(20, "H"), 4},
        {make_pair(20, "I"), 5},
        {make_pair(20, "J"), 6},
        {make_pair(21, "G"), 35},
        {make_pair(21, "H"), 4},
        {make_pair(21, "I"), 5},
        {make_pair(21, "J"), 6},
        {make_pair(22, "G"), 36},
        {make_pair(22, "H"), 4},
        {make_pair(22, "I"), 5},
        {make_pair(22, "J"), 6},
        {make_pair(23, "G"), 37},
        {make_pair(23, "H"), 4},
        {make_pair(23, "I"), 5},
        {make_pair(23, "J"), 6},
        {make_pair(31, "K"), 40},
        {make_pair(31, "L"), 41},
        {make_pair(31, "M"), 42},
        {make_pair(43, "K"), 48},
        {make_pair(43, "L"), 41},
        {make_pair(43, "M"), 42},
    }
);

int expr_num = 0;
vector<string> input_str;
map<string, int> cnt; 

int main(int argc, char** argv) {
    if (argc < 2) {
		cerr << "Usage: <program_name> <input_file>\n";
		exit(-1);	
	}
	ifstream fin(argv[1]);
	string input_expr;
	
	while (getline(fin, input_expr)) {
		++expr_num;
        input_str.clear();
        cnt.clear();
		ofstream fout(scanner_infile);
		fout << input_expr;
		fout.close();
		lexer(scanner_infile, scanner_outfile);
		vector<string> preprocessed_input_str;
		get_inputStr(scanner_outfile, preprocessed_input_str);
		SLR1_parse(preprocessed_input_str);
	}
	return 0;
}

void get_inputStr(const char *input_file, vector<string>& preprocessed_input_str) {
	ifstream fin(input_file);
	string token;
	while (getline(fin, token)) {
		int i;
		string type_code;
		for (i = 1; token[i] != ','; ++i) {
			type_code += token[i];
		}
	
		if (type_code == "ID") preprocessed_input_str.push_back("i");
		else if (type_code == "INT_CONSTANT" || type_code == "FLOAT_CONSTANT" || type_code == "CHARACTER" || type_code == "STRING")	preprocessed_input_str.push_back("c");
		else if (type_code == "CHAR" || type_code == "DOUBLE" || type_code == "FLOAT" || type_code == "INT" || type_code == "LONG" || type_code == "SHORT" || type_code == "SIGNED" || type_code == "UNSIGNED" || type_code == "VOID") preprocessed_input_str.push_back("t");
		else if (type_code == "STRUCT" || type_code == "UNION" || type_code == "ENUM") preprocessed_input_str.push_back("s");
		else if (type_code == "CONST" || type_code == "RESTRICT" || type_code == "VOLATILE") preprocessed_input_str.push_back("r");
		else preprocessed_input_str.push_back(token.substr(i+2, token.size() - (i+2) - 1));
        input_str.push_back(token.substr(i+2, token.size() - (i+2) - 1));
	}
	preprocessed_input_str.push_back("#");
	fin.close();
}

void SLR1_parse(const vector<string>& preprocessed_input_str) {
	stack<int> states;
    int i;
    string next;
    int top_state;

	states.push(0);
	i = 0;
	next = preprocessed_input_str[i];
    if (next != "#") cnt[input_str[i]]++;

	while (true) {
		top_state = states.top();
        pair<int, string> state_next = make_pair(top_state, next);

		if (!action.count(state_next)) {
			cerr << "Line " << expr_num << ": Arithmetic syntax parsing error at ";
			if (next == "#") cerr << "the end"; 
			else cerr << input_str[i] << " (" << cnt[input_str[i]] << ")";
            cerr << " !\nError: Action[" << top_state << ", " << next << "] is empty!\n";
			return;
		}
		else if (action[state_next][0] == 's') {
            states.push(stoi(action[state_next].substr(1)));
            next = preprocessed_input_str[++i];
            if (next != "#") cnt[input_str[i]]++;
        }
        else if (action[state_next][0] == 'r') {
            int producer_num = stoi(action[state_next].substr(1));
            for (int j = 0; j < producers[producer_num].second.size(); ++j) states.pop();
            top_state = states.top();
            pair<int, string> tmp = make_pair(top_state, producers[producer_num].first);
            if (go.count(tmp)) states.push(go[tmp]);
            else {
                cerr << "Line " << expr_num << ": Arithmetic syntax parsing error at ";
			    if (next == "#") cerr << "the end"; 
			    else cerr << input_str[i] << " (" << cnt[input_str[i]] << ")";
                cerr << " !\nError: GOTO[" << top_state << ", " << producers[producer_num].first << "] is empty!\n";
			    return;
            }
        }
        else {
            cout << "Line " << expr_num << ": Successful arithmetic syntax parsing!\n";
			break;
        }
    }
}