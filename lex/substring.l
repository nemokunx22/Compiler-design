//Akash V V
//Roll no : 09
%{
#include<stdio.h>
#include<ctype.h>
int i;
%}//contains the header files and the global variables

%%
[a-z A-Z]* {
        for(i=0;i<=yyleng;i++)
        {
            if((yytext[i]=='a') && (yytext[i+1]=='b')&&(yytext[i+2]=='c'))
            {
                yytext[i]='A';
                yytext[i+1]='B';
                yytext[i+2]='C';
            }
        }
            printf("%s",yytext);
}
[\t]* return 1;
.* {ECHO;}
\n {printf("%s",yytext);}
%%

int main()
{
    yylex();//calling the yylex function to start the lexical analysis
}
//for ignoring the comments
int yywrap()
{
    return 1;
}



