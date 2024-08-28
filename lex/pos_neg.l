//Akash V V
//TLY21CS009
//22-08-2024

%{
#include<stdio.h>
#include<string.h>
char pos[1000],neg[1000],f_pos[1000],f_neg[1000];
%}

DIGIT [0-9]
%%
	
\+?{DIGIT}+	strcat(pos,yytext);strcat(pos," ");
-{DIGIT}+	strcat(neg,yytext);strcat(neg," ");
\+?{DIGIT}*\.{DIGIT}+	strcat(f_pos,yytext);strcat(f_pos," ");
-{DIGIT}*\.{DIGIT}+	strcat(f_neg,yytext);strcat(f_neg," ");
.*	;
%%

int main() {
	
	yylex();
	if(neg[0] != '\0')
		printf("NEGATIVE: %s\n",neg);
	if(pos[0] != '\0')
		printf("POSITIVE: %s\n",pos);
	if(f_neg[0] != '\0')
		printf("FRACTIONAL NEGATIVE: %s\n",f_neg);
	if(f_pos[0] != '\0')
		printf("FRACTIONAL POSITIVE: %s\n",f_pos);
	return 0;
	
}

int yywrap()
{
	return 1;
}
















INPUT:

1

-2

1.4

-3.2

1s

-2s

1.4f

-3.4d


OUTPUT:

NEGATIVE: -2 
POSITIVE: 1 
FRACTIONAL NEGATIVE: -3.2 
FRACTIONAL POSITIVE: 1.4 
