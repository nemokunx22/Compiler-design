//Akash V V
//TLY21CS009
//22-08-2024
%{
#include<stdio.h>
%}

DIGIT [0-9]
%%
	
\+?{DIGIT}+	{printf("POSITIVE NUMBER\n");}
-{DIGIT}+	{printf("NEGATIVE NUMBER\n");}
\+?{DIGIT}*\.{DIGIT}+	{printf("POSITIVE FRACTIONAL NUMBER\n");}
-{DIGIT}*\.{DIGIT}+	{printf("NEGATIVE FRACTIONAL NUMBER\n");}
.*	;
%%

int main() {
	
	yylex();
}

int yywrap()
{
	return 1;
}
