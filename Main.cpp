#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio> // For remove() function
#include "Compiler.h"

using namespace std;

bool isValidBrainFuckFile(const string& filename);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <input.bf or input.sbf> <output.exe>" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputFile = argv[2];

    // Validate file extension
    if (!isValidBrainFuckFile(inputFile)) {
        cerr << "Error: Input file must have .bf or .sbf extension" << endl;
        return 1;
    }

    // Create a temporary C++ file name
    string tempCppFile = inputFile + ".cpp";

    // Read the Brainfuck file
    ifstream bfFile(inputFile);
    if (!bfFile.is_open()) {
        cerr << "Error opening input file: " << inputFile << endl;
        return 1;
    }

    // Read the entire file content
    string bfCode((istreambuf_iterator<char>(bfFile)), istreambuf_iterator<char>());
    bfFile.close();

    // Create compiler instance with temporary C++ file
    Compiler compiler(tempCppFile);

    // Tokenize and parse the Brainfuck code
    compiler.tokenizer(bfCode);

    // Compile the temporary C++ file to an executable
    string compileCmd = "g++ " + tempCppFile + " -o " + outputFile;
    int compileResult = system(compileCmd.c_str());

    // Remove the temporary C++ file using standard C remove() function
    if (remove(tempCppFile.c_str()) != 0) {
        cerr << "Error deleting temporary file: " << tempCppFile << endl;
        // This is not a critical failure, so we continue
    }

    if (compileResult != 0) {
        cerr << "Compilation failed!" << endl;
        return 1;
    }

    cout << "Successfully compiled " << inputFile << " to " << outputFile << endl;
    return 0;
}

bool isValidBrainFuckFile(const string& filename) {
    if (filename.size() >= 3 && filename.substr(filename.size() - 3) == ".bf") {
        return true;
    }
    if (filename.size() >= 4 && filename.substr(filename.size() - 4) == ".sbf") {
        return true;
    }
    return false;
}
