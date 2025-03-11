# Yacc Source Program Structure

A Yacc source program typically consists of three main sections: **Declarations**, **Rules**, and **Supporting C Routines**. These sections define how the input is parsed and processed.

## Step 1: Yacc Source Program Structure

The Yacc source program is divided into three parts:

1. **Declarations** 
2. **Rules**
3. **Supporting C Routines**

Each section serves a specific purpose in the creation of a parser.

## Step 2: Declarations Section

This section contains the following components:

1. **Include Standard I/O Header File**  
   - Necessary to include the standard input and output library for the program.

2. **Define Global Variables**  
   - Defines any global variables that will be used across multiple parts of the program.

3. **Define the Start Symbol**  
   - The start symbol or list rule defines the place to start the parsing process.

4. **Define Tokens**  
   - Specifies the tokens used by the parser. These tokens are typically defined in the accompanying lexical analysis file (`.lex`).

5. **Define Operators and Precedence**  
   - This section outlines the operators and their precedence, which helps the parser handle operator associativity and precedence properly.

### Example:
```yacc
%{
#include <stdio.h>
int yylex(void);
int yyerror(char *s);
%}

%token NUM
%left '+' '-'
%left '*' '/'
%%
```
 
 
 ## ALGORITHM:

Step1: A Yacc source program has three parts as follows:

       Declarations %%  translation rules %%  supporting C routines

Step2: Declarations Section: This section contains entries that:

 i. Include standard I/O header file.

 ii. Define global variables.

 iii. Define the list rule as the place to start processing.

 iv. Define the tokens used by the parser. v. Define the operators and their precedence.

Step3:  Rules Section: The rules section defines the rules that parse the input stream. Each rule of a grammar  production and the associated semantic action.

Step4:  Programs Section: The programs section contains the following subroutines. Because these subroutines are included in this file, it is not necessary to use the yacc library when processing this file.

Step5:  Main- The required main program that calls the yyparse subroutine to start the program.

Step6:  yyerror(s) -This error-handling subroutine only prints a syntax error message.

Step7:  yywrap -The wrap-up subroutine that returns a value of 1 when the end of input occurs. The calc.lex file contains include statements for standard input and output, as programmar file information if we use the -d flag with the yacc command. The y.tab.h file contains definitions for the tokens that the parser program uses.                                                 

Step8: calc.lex contains the rules to generate these tokens from the input stream.

## Program

LEX PART: `calculator.l`

YACC PART: `calculator.y`

Compile calculator.l using : `flex calculator.l`

Compile calculator.y using : `yacc -d calculator.y`

compile the intermediate generated file : `gcc lex.yy.c y.tab.c -o calculator -lfl`

run the program : `./calculator`

input:
```
3+5*(2-8)
```

output:
```
-27
```
