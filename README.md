# SuperBrainFuck Compiler

## Overview

SuperBrainFuck is a specialized compiler that transforms Brainfuck code—an esoteric, minimalist programming language—into fully executable programs. Unlike traditional programming languages with verbose syntax, Brainfuck uses only eight simple characters to represent computational operations, creating a unique and challenging coding experience.
Once I finally get around to doing it, I hope this compiler will be able to read (and possibly write) files of sorts.
The main reason I made this compiler is (believe it or not) to RickRoll my friends. I hope to make a program that will convert a video (eg RickRoll) to ascii art and play it in the console while playing the music (the music part is not as important).

## Project Structure

The project is composed of three essential source files:

1. `Main.cpp`: The primary entry point of the compiler, handling command-line arguments and overall compilation workflow
2. `Compiler.h`: A header file defining the core Compiler class structure and method declarations
3. `Compiler.cpp`: The implementation of the Compiler class, containing the core logic for tokenization and parsing of Brainfuck code

## Prerequisites

To use the SuperBrainFuck compiler, you'll need:
- A modern C++ compiler (g++ recommended)
- Basic familiarity with command-line interfaces
- Basic understanding of compiler concepts (optional, but helpful)

## Compilation

To compile the SuperBrainFuck compiler itself, use the following command:

```bash
g++ Main.cpp Compiler.cpp -o bfc.exe
```

This command generates an executable named `bfc.exe` that you can use to compile Brainfuck programs into native executables.

## Usage

The compiler requires two command-line arguments:
1. An input Brainfuck file (must have `.bf` or `.sbf` extension)
2. The desired name for the output executable

Syntax:
```bash
./bfc.exe [input_file] [output_executable]
```

Example:
```bash
./bfc.exe hello_world.bf hello_world.exe
```

## Adding to System PATH

### Windows
1. Open System Properties
2. Navigate to "Environment Variables"
3. Under "System Variables", select "Path"
4. Click "Edit"
5. Click "New"
6. Add the full directory path containing `bfc.exe`

### macOS/Linux
Add the following line to your `.bashrc` or `.bash_profile`:
```bash
export PATH=$PATH:/full/path/to/compiler/directory
```

## Brainfuck Language Commands

Brainfuck uses eight simple commands to perform complex computations:

| Command | Description | Operation |
|---------|-------------|------------|
| `>` | Move memory pointer right | Shifts the data pointer to the next memory cell |
| `<` | Move memory pointer left | Shifts the data pointer to the previous memory cell |
| `+` | Increment memory cell | Increases the value at the current memory cell by 1 |
| `-` | Decrement memory cell | Decreases the value at the current memory cell by 1 |
| `.` | Output character | Prints the ASCII character represented by the current memory cell's value |
| `,` | Input character | Reads a single character from input and stores its ASCII value in the current memory cell |
| `[` | Start of loop | Begins a loop that continues while the current cell's value is non-zero |
| `]` | End of loop | Marks the end of a loop, returning to the corresponding `[` if the current cell's value is non-zero |

## Compiler Internals

The SuperBrainFuck compiler operates through a sophisticated three-stage process:

1. **Tokenization**: 
   - Extracts valid Brainfuck commands from the input file
   - Filters out any non-Brainfuck characters
   - Prepares a clean token stream for parsing

2. **Parsing**:
   - Translates Brainfuck commands into equivalent C++ code
   - Generates a complete, executable C++ source file
   - Handles memory management and command translation

3. **Compilation**:
   - Uses g++ to compile the generated C++ code
   - Produces a native executable from the translated source

## Implementation Details

- Uses a fixed memory array of 30,000 integer cells
- Supports nested loops and complex Brainfuck programs
- Provides robust error handling for invalid input files

## Example Brainfuck Program

Here's a classic "Hello World" program in Brainfuck:
```brainfuck
++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.
```

## Limitations

- Fixed memory size of 30,000 integer cells
- Supports only standard Brainfuck syntax (for now)
- Requires G++ compiler for final executable generation

## Contributing

Contributions are welcome! Feel free to:
- Submit bug reports
- Suggest feature improvements
- Send pull requests with enhancements

## License

MIT License

Copyright (c) 2024 [Your Name or Organization]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.