#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stack>
#include <unordered_set>
#include <map>
#include <vector>
#include <utility>

using namespace std;

extern void lexer(const char *input_file, const char *output_file);
void get_inputStr(const char *input_file, vector<string>& preprocessed_input_str);
void LL1_parse(const vector<string>& preprocessed_input_str);

const char *scanner_infile = "input_expr.txt";
const char *scanner_outfile = "scan_result.txt";
unordered_set<string> vt({"i","c","+","-","*","/","%","++","--","sizeof",".","->","(",")","&","~","!","r","s","t"});
unordered_set<string> vn({"E","E'","F","F'","G","H","H'","I","J","K","L","M"});
map<pair<string, string>, vector<string>> analysis_table({
	{make_pair("E","i"),{"F","E'"}},
	{make_pair("E","c"),{"F","E'"}},
	{make_pair("E","+"),{"F","E'"}},
	{make_pair("E","-"),{"F","E'"}},
	{make_pair("E","*"),{"F","E'"}},
	{make_pair("E","++"),{"F","E'"}},
	{make_pair("E","--"),{"F","E'"}},
	{make_pair("E","sizeof"),{"F","E'"}},
	{make_pair("E","("),{"F","E'"}},
	{make_pair("E","&"),{"F","E'"}},
	{make_pair("E","~"),{"F","E'"}},
	{make_pair("E","!"),{"F","E'"}},
	{make_pair("E'","+"),{"+","F","E'"}},
	{make_pair("E'","-"),{"-","F","E'"}},
	{make_pair("E'",")"),{}},
	{make_pair("E'","#"),{}},
	{make_pair("F","i"),{"G","F'"}},
	{make_pair("F","c"),{"G","F'"}},
	{make_pair("F","+"),{"G","F'"}},
	{make_pair("F","-"),{"G","F'"}},
	{make_pair("F","*"),{"G","F'"}},
	{make_pair("F","++"),{"G","F'"}},
	{make_pair("F","--"),{"G","F'"}},
	{make_pair("F","sizeof"),{"G","F'"}},
	{make_pair("F","("),{"G","F'"}},
	{make_pair("F","&"),{"G","F'"}},
	{make_pair("F","~"),{"G","F'"}},
	{make_pair("F","!"),{"G","F'"}},
	{make_pair("F'","+"),{}},
	{make_pair("F'","-"),{}},
	{make_pair("F'","*"),{"*","G","F'"}},
	{make_pair("F'","/"),{"/","G","F'"}},
	{make_pair("F'","%"),{"%","G","F'"}},
	{make_pair("F'",")"),{}},
	{make_pair("F'","#"),{}},
	{make_pair("G","i"),{"H"}},
	{make_pair("G","c"),{"H"}},
	{make_pair("G","+"),{"J","G"}},
	{make_pair("G","-"),{"J","G"}},
	{make_pair("G","*"),{"J","G"}},
	{make_pair("G","++"),{"++","G"}},
	{make_pair("G","--"),{"--","G"}},
	{make_pair("G","sizeof"),{"sizeof","(","K",")"}},
	{make_pair("G","("),{"H"}},
	{make_pair("G","&"),{"J","G"}},
	{make_pair("G","~"),{"J","G"}},
	{make_pair("G","!"),{"J","G"}},
	{make_pair("H","i"),{"I","H'"}},
	{make_pair("H","c"),{"I","H'"}},
	{make_pair("H","("),{"I","H'"}},
	{make_pair("H'","+"),{}},
	{make_pair("H'","-"),{}},
	{make_pair("H'","*"),{}},
	{make_pair("H'","/"),{}},
	{make_pair("H'","%"),{}},
	{make_pair("H'","++"),{"++","H'"}},
	{make_pair("H'","--"),{"--","H'"}},
	{make_pair("H'","."),{".","i","H'"}},
	{make_pair("H'","->"),{"->","i","H'"}},
	{make_pair("H'",")"),{}},
	{make_pair("H'","#"),{}},
	{make_pair("I","i"),{"i"}},
	{make_pair("I","c"),{"c"}},
	{make_pair("I","("),{"(","E",")"}},
	{make_pair("J","+"),{"+"}},
	{make_pair("J","-"),{"-"}},
	{make_pair("J","*"),{"*"}},
	{make_pair("J","&"),{"&"}},
	{make_pair("J","~"),{"~"}},
	{make_pair("J","!"),{"!"}},
	{make_pair("K","r"),{"r","K"}},
	{make_pair("K","s"),{"L"}},
	{make_pair("K","t"),{"L"}},
	{make_pair("L","s"),{"M"}},
	{make_pair("L","t"),{"t"}},
	{make_pair("M","s"),{"s","i"}},
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
		LL1_parse(preprocessed_input_str);
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

void LL1_parse(const vector<string>& preprocessed_input_str) {
	stack<string> analysis_stack;
	int i;
	string next;

	analysis_stack.push("#");
	analysis_stack.push("E");
	i = 0;
	next = preprocessed_input_str[i];

	if (next != "#") cnt[input_str[i]]++;

	while (true) {
		string top = analysis_stack.top();
		analysis_stack.pop();
		if (vt.count(top)) {
			if (top != next) {
				cerr << "Line " << expr_num << ": Arithmetic syntax parsing error at ";
				if (next == "#") cerr << "the end !\nError: Terminal " << top << " on top of LL(1) analysis stack doesn't match #, the end flag of input\n";
				else cerr << input_str[i] << " (" << cnt[input_str[i]] << ") !\nError: Terminal " << top << " on top of LL(1) analysis stack doesn't match " << input_str[i] << " in input\n";
				return;
			}
			next = preprocessed_input_str[++i];
			if (next != "#") cnt[input_str[i]]++;
		}
		else if (vn.count(top)) {
			pair<string, string> production = make_pair(top, next);
			if (!analysis_table.count(production)) {
				cerr << "Line " << expr_num << ": Arithmetic syntax parsing error at ";
				if (next == "#") cerr << "the end";
				else cerr << input_str[i] << " (" << cnt[input_str[i]] << ")";
				cerr << " !\nError: Can't find production entry in LL(1) analysis table corresponding to (" << top << "," << next << ")\n";
				return;
			}
			else {
				for (int j = analysis_table[production].size() - 1; j >= 0; j--) analysis_stack.push(analysis_table[production][j]);
			}
		}
		else if (next != "#") {
			cerr << "Line " << expr_num << ": Arithmetic syntax parsing error at " << input_str[i] << " (" << cnt[input_str[i]] << ") !\nError: Now " << top << " is on top of LL(1) analysis stack while next word is " << next << endl;
			return;
		}
		else {
			cout << "Line " << expr_num << ": Successful arithmetic syntax parsing!\n";
			break;
		}
	}
}