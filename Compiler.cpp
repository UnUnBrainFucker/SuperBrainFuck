#include <fstream>
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

void Compiler::parser(const vector<char>& tokens) {
    ofstream temp(_fileName);

    temp << "#include <iostream>\n";
    temp << "#include <vector>\n";
    temp << "#include <string>\n";
    temp << "\n";
    temp << "using namespace std;\n";
    temp << "\n";
    temp << "int main() {\n";
    temp << "    vector<int> memory(30000, 0);\n";
    temp << "    int pointer = 0;\n";
    temp << "\n";

    for (size_t i = 0; i < tokens.size(); ++i) {
        char c = tokens[i];
        switch (c) {
        case '>':
            temp << "    ++pointer;\n";
            break;
        case '<':
            temp << "    --pointer;\n";
            break;
        case '+':
            temp << "    ++memory[pointer];\n";
            break;
        case '-':
            temp << "    --memory[pointer];\n";
            break;
        case '.':
            temp << "    cout << static_cast<char>(memory[pointer]);\n";
            break;
        case ',':
            temp << "    memory[pointer] = cin.get();\n";
            break;
        case '[':
            temp << "    while (memory[pointer] != 0) {\n";
            break;
        case ']':
            temp << "    }\n";
            break;
        default:
            break;
        }
    }
    temp << "    return 0;\n";
    temp << "}\n";

    temp.close();
}
