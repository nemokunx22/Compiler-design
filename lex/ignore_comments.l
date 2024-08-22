//Akash V V
//TLY21CS009
//22-08-2024
%{
#include <stdio.h>

int comment_count = 0;
%}

%%

\/\/[^\n]*	{ comment_count++; } 
\/\*([^*]|\*+[^\/])*\*\/	{ comment_count++; }

%%

int main()
{
    FILE *file = fopen("INPUT_COM.c", "r");
    if (!file)
    {
        perror("Error opening file\n");
        return 1;
    }
    yyin = file;
    yylex();
    fclose(file);
    return 0;
}

int yywrap() {
    return 1;
}





