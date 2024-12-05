#include "Compiler.h"

using namespace std;

Compiler::Compiler(const string& fileName) {
	_fileName = fileName;
}

vector<char> Compiler::tokenize(const string& input) const {
    vector<char> tokens;
    for (char c : input) {
        if (c == '>' || c == '<' || c == '+' || c == '-' || c == '.' || c == ',' || c == '[' || c == ']') {
            tokens.push_back(c);
        }
    }
    return tokens;
}

void Compiler::tokenizer(const string& input) {
    _tokens = tokenize(input);
    parser(_tokens);
}
