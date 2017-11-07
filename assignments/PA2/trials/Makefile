.PHONY: clean run
all: lexer myscanner.h myscanner.cpp lex.yy.c
	g++ -c lex.yy.c -o lex.yy.o
	g++ -c -std=c++11 myscanner.cpp -o myscanner.o
	g++ myscanner.o lex.yy.o -o myscanner

lexer: test1.l
	lex test1.l
	gcc lex.yy.c -ll

run:
	$(MAKE) clean
	$(MAKE) all
	./myscanner < config.in

clean:
	-rm myscanner
	-rm *.o *.out lex.yy.c
	-rm *~
	-rm
