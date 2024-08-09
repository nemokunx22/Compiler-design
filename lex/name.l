%{
#include <stdio.h>
%}

%%
specificword { printf("The word 'specificword' was found!\n"); }
. { printf("%s", yytext); }
\n { printf("\n"); }
%% 

int main() {
    printf("Enter input (press Ctrl+D to end):\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}

