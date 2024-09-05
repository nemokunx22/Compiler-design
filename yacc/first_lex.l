/*
AKASH V V
TLY21CS009
05-09-24
*/
%{
#include<stdio.h>
#include"y.tab.h"
%}

%%
[aA]	{return A;}
[bB]	{return B;}
[\n]	{return NL;}
.	{printf("rejected\n"); exit(0);}	
%%


int yywrap()
{
	return 1;
}
