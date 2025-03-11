LEX PART: calculator.l

YACC PART: calculator.y

flex calculator.l
yacc -d calculator.y

gcc lex.yy.c y.tab.c -o calculator -lfl

./calculator

3+5*(2-8)
-27
