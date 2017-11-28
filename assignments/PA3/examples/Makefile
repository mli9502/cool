.PHONY: clean

calc: calc.y calc.l
	yacc -d calc.y
	lex calc.l
	gcc -ll lex.yy.c y.tab.c -o calc

clean:
	-rm *~ lex.yy.c y.tab.* calc
