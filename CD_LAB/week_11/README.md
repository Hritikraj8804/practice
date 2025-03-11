ALGORITHM:

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
