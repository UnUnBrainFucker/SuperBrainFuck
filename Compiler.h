#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Compiler
{
private:
	vector<char> _tokens;
	vector<int> _memory;
	int _pointer = 0;
	vector<int> _loop_stack;
	string _fileName;
public:
	Compiler(const string& fileName);
    vector<char> tokenize(const string& input) const;
    void tokenizer(const string& input);
    void parser(const vector<char>& tokens);
};