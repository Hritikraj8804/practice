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
| 1     | Write a C program to identify different types of Tokens in a given Program.                                    | [./experiments/01_token_identifier/token\_identifier.c](./experiments/01_token_identifier/token_identifier.c)                             |
| 2     | Write a Lex Program to implement a Lexical Analyzer using Lex tool.                                             | [./experiments/02_lexical_analyzer_lex/lexer.l](./experiments/02_lexical_analyzer_lex/lexer.l)                                           |
| 3     | Write a C program to Simulate Lexical Analyzer to validating a given input String.                              | [./experiments/03_lexical_analyzer_c/lexical\_analyzer.c](./experiments/03_lexical_analyzer_c/lexical_analyzer.c)                         |
| 4     | Write a C program to implement the Brute force technique of Top down Parsing.                                   | [./experiments/04_brute_force_top_down/brute\_force\_top\_down.c](./experiments/04_brute_force_top_down/brute_force_top_down.c)         |
| 5     | Write a C program to implement a Recursive Descent Parser.                                                      | [./experiments/05_recursive_descent_parser/recursive\_descent\_parser.c](./experiments/05_recursive_descent_parser/recursive_descent_parser.c) |
| 6     | Write C program to compute the First and Follow Sets for the given Grammar.                                     | [./experiments/06_first_follow_sets/first\_follow.c](./experiments/06_first_follow_sets/first_follow.c)                                   |
| 7     | Write a C program for eliminating the left recursion and left factoring of a given grammar                      | [./experiments/07_left_recursion_factoring/elimination.c](./experiments/07_left_recursion_factoring/elimination.c)                         |
| 8     | Write a C program to check the validity of input string using Predictive Parser.                                 | [./experiments/08_predictive_parser/predictive\_parser.c](./experiments/08_predictive_parser/predictive_parser.c)                         |
| 9     | Write a C program for implementation of LR parsing algorithm to accept a given input string.                     | [./experiments/09_lr_parser/lr\_parser.c](./experiments/09_lr_parser/lr_parser.c)                                                       |

