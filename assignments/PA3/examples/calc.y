%{
void yyerror(char* s);
int yylex();
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int symbols[52];
int computeSymbolIndex(char token);
int symbolVal(char symbol);
void updateSymbolVal(char symbol, int val);
%}

%union {int num; char id;}
%start line
%token PRINT
%token EXIT_COMMAND
%token <num> NUMBER
%token <id> IDENTIFIER
%type <num> line exp term factor
%type <id> assignment

%%
line : assignment ';'			{ ; }
		| EXIT_COMMAND ';'		{ exit(EXIT_SUCCESS); }
		| PRINT exp ';'			{ printf("Printing %d\n", $2); }
		| line assignment ';' 	{ ; }
		| line PRINT exp ';' 	{ printf("Printing %d\n", $3); }
		| line EXIT_COMMAND ';' { exit(EXIT_SUCCESS); }
		;

assignment	: IDENTIFIER '=' exp { updateSymbolVal($1, $3); }
			;

exp	: term	{ $$ = $1; }
	| exp '+' term { $$ = $1 + $3; }
	| exp '-' term { $$ = $1 - $3; }
	;

term : term '*' factor { $$ = $1 * $3; }
	| term '/' factor { $$ = $1 / $3; }
	| factor { $$ = $1; }
	;

factor : NUMBER { $$ = $1; }
		| IDENTIFIER { $$ = symbolVal($1); }
		| '(' exp ')' { $$ = $2; }

%%

void yyerror(char* s) {
	fprintf(stderr, "%s\n", s);
}

int computeSymbolIndex(char token) {
	int idx = -1;
	if(islower(token)) {
		idx = token - 'a' + 26;
	} else {
		idx = token - 'A';
	}
	return idx;
}

int symbolVal(char symbol) {
	int bucket = computeSymbolIndex(symbol);
	return symbols[bucket];
}

void updateSymbolVal(char symbol, int val) {
	int bucket = computeSymbolIndex(symbol);
	symbols[bucket] = val;
}

int main(void) {
	for(int i = 0; i < 52; i ++) {
		symbols[i] = 0;
	}
	return yyparse();
}
