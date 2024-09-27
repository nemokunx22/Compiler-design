/*
Akash V V
TLY21CS009
27-09-2024
*/

%{ 
#include<stdio.h> 
#include "y.tab.h" 
extern int yylval; 
%} 

%% 
[0-9]+ { 
		yylval=atoi(yytext); 
		return NUMBER; 

	} 
[\t] ; 

[\n] return 0; 

. return yytext[0]; 

%% 

int yywrap() 
{ 
return 1; 
} 

