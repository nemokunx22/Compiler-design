/*
AKASH V V
TLY21CS009
05-09-24
*/
%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
void yyerror(const char *s);
extern int yylex();
%}

%token A B NL

%%

stmt:	S NL {printf("Valid string\n"); exit(0);}
	;
S:	A S B
	|
	;

%%

void yyerror(const char *s) {
    printf("Rejected\n");
    exit(1);
}

int main() {
    yyparse();
    return 0;
}

