# Compiler Design Experiments

This repository contains C and Lex/Yacc implementations for various compiler design experiments.


## Table of Contents

* [Introduction](#introduction)
* [Experiments](#experiments)
* [Getting Started](#getting-started)
    * [Prerequisites](#prerequisites)
    * [Compilation](#compilation)
    * [Running](#running)
* [Repository Structure](#repository-structure)
* [Contributing](#contributing)
* [License](#license)

## Introduction

This repository provides practical implementations of fundamental concepts in compiler design.  The experiments cover lexical analysis, parsing techniques, and basic code generation.  These implementations are primarily in C, with some experiments utilizing Lex and Yacc.

## Experiments

The following is a list of experiments included in this repository:

| S.No. | List of Experiments                                                                                             | Code Location                                                                                                                               |
| :---- | :-------------------------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------ |
| 1     | Write a C program to identify different types of Tokens in a given Program.                                    | [week_1](./week_1)                             |
| 2     | Write a Lex Program to implement a Lexical Analyzer using Lex tool.                                             | [./experiments/02_lexical_analyzer_lex/lexer.l](./experiments/02_lexical_analyzer_lex/lexer.l)                                           |
| 3     | Write a C program to Simulate Lexical Analyzer to validating a given input String.                              | [./experiments/03_lexical_analyzer_c/lexical\_analyzer.c](./experiments/03_lexical_analyzer_c/lexical_analyzer.c)                         |
| 4     | Write a C program to implement the Brute force technique of Top down Parsing.                                   | [./experiments/04_brute_force_top_down/brute\_force\_top\_down.c](./experiments/04_brute_force_top_down/brute_force_top_down.c)         |
| 5     | Write a C program to implement a Recursive Descent Parser.                                                      | [./experiments/05_recursive_descent_parser/recursive\_descent\_parser.c](./experiments/05_recursive_descent_parser/recursive_descent_parser.c) |
| 6     | Write C program to compute the First and Follow Sets for the given Grammar.                                     | [./experiments/06_first_follow_sets/first\_follow.c](./experiments/06_first_follow_sets/first_follow.c)                                   |
| 7     | Write a C program for eliminating the left recursion and left factoring of a given grammar                      | [./experiments/07_left_recursion_factoring/elimination.c](./experiments/07_left_recursion_factoring/elimination.c)                         |
| 8     | Write a C program to check the validity of input string using Predictive Parser.                                 | [./experiments/08_predictive_parser/predictive\_parser.c](./experiments/08_predictive_parser/predictive_parser.c)                         |
| 9     | Write a C program for implementation of LR parsing algorithm to accept a given input string.                     | [./experiments/09_lr_parser/lr\_parser.c](./experiments/09_lr_parser/lr_parser.c)                                                       |
| 10    | Write a C program for implementation of a Shift Reduce Parser using Stack Data Structure to accept a given input string of a given grammar. | [./experiments/10_shift_reduce_parser/shift\_reduce\_parser.c](./experiments/10_shift_reduce_parser/shift_reduce_parser.c)                   |
| 11    | Simulate the calculator using LEX and YACC tool.                                                                | [./experiments/11_calculator_lex_yacc/calculator.l](./experiments/11_calculator_lex_yacc/calculator.l), [./experiments/11_calculator_lex_yacc/calculator.y](./experiments/11_calculator_lex_yacc/calculator.y) |
| 12    | Generate YACC specification for a few syntactic categories.                                                     | [./experiments/12_yacc_spec/grammar.y](./experiments/12_yacc_spec/grammar.y)                                                             |
| 13    | Write a C program for generating the three address code of a given expression/statement.                       | [./experiments/13_three_address_code/three\_address\_code.c](./experiments/13_three_address_code/three_address_code.c)                     |
| 14    | Write a C program for implementation of a Code Generation Algorithm of a given expression/statement.           | [./experiments/14_code_generation/code\_generation.c](./experiments/14_code_generation/code_generation.c)                               |

## Getting Started

### Prerequisites

To run these experiments, you will need the following software:

* **C Compiler:** A C compiler such as GCC is required.  Ensure it is in your system's PATH.
* **Lex and Yacc:** For experiments involving lexical analysis and parsing, you'll need Lex and Yacc.  On most Linux systems, Flex and Bison are readily available and commonly used as replacements.  Install these if they are not already present on your system.

### Compilation

The compilation process varies slightly depending on the type of experiment.

#### C Programs

For standalone C programs, use GCC:

```bash
gcc <experiment_name>.c -o <experiment_name>
```

For example:

```bash
gcc token_identifier.c -o token_identifier
```

#### Lex Programs

For Lex programs (e.g., those with a `.l` extension), use Flex:

```bash
flex <lexer_file>.l
gcc lex.yy.c -o <output_name> -lfl
```

For example:

```bash
flex lexer.l
gcc lex.yy.c -o lexer -lfl
```

#### Yacc Programs

For Yacc programs (e.g., those with a `.y` extension), use Bison:

```bash
bison -d <grammar_file>.y
gcc <grammar_file>.tab.c -o <output_name> -ly -lfl
```

For example:

```bash
bison -d grammar.y
gcc grammar.tab.c -o parser -ly -lfl
```

* The `-d` flag in the `bison` command generates a header file (`.tab.h`) containing token definitions, which may be needed by other parts of your program.
* The `-lfl` flag links the Flex library.
* The `-ly` flag links the Yacc library.
* If your Yacc program uses functions from the math library, you might need to add `-lm` to the gcc command.

#### Lex and Yacc Together

For programs that use both Lex and Yacc (e.g., the calculator example):

1.  Compile the Lex file:

    ```bash
    flex <lexer_file>.l
    ```

2.  Compile the Yacc file:

    ```bash
    bison -d <grammar_file>.y
    ```

3.  Compile the combined program:

    ```bash
    gcc lex.yy.c <grammar_file>.tab.c -o <output_name> -ly -lfl
    ```
For example:

```bash
flex calculator.l
bison -d calculator.y
gcc lex.yy.c calculator.tab.c -o calculator -ly -lfl
```

### Running

To execute a compiled program, open a terminal, navigate to the directory where the executable is located, and run it:

```bash
./<program_name>
```

For example:

```bash
./token_identifier
```

## Repository Structure

```
Compiler Design Experiments/
├── README.md
├── experiments/
│   ├── 01_token_identifier/
│   │   └── token_identifier.c
│   ├── 02_lexical_analyzer_lex/
│   │   └── lexer.l
│   ├── 03_lexical_analyzer_c/
│   │   └── lexical_analyzer.c
│   ├── 04_brute_force_top_down/
│   │   └── brute_force_top_down.c
│   ├── 05_recursive_descent_parser/
│   │   └── recursive_descent_parser.c
│   ├── 06_first_follow_sets/
│   │   └── first_follow.c
│   ├── 07_left_recursion_factoring/
│   │   └── elimination.c
│   ├── 08_predictive_parser/
│   │   └── predictive_parser.c
│   ├── 09_lr_parser/
│   │   └── lr_parser.c
│   ├── 10_shift_reduce_parser/
│   │   └── shift_reduce_parser.c
│   ├── 11_calculator_lex_yacc/
│   │   ├── calculator.l
│   │   └── calculator.y
│   ├── 12_yacc_spec/
│   │   └── grammar.y
│   ├── 13_three_address_code/
│   │   └── three_address_code.c
│   └── 14_code_generation/
│   │   └── code_generation.c
```

## Contributing

Contributions are welcome! If you would like to contribute to this repository, please follow these guidelines:

* Fork the repository.
* Create a new branch for your feature or bug fix.
* Write clear and concise code.
* Provide comments to explain your code.
* Update the `README.md` file if necessary.
* Submit a pull reque
