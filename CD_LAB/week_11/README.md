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
