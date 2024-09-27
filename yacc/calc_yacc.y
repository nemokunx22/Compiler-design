/*
Akash V V
TLY21CS009
27-09-2024
*/

%{ 
#include<stdio.h> 
#include<math.h>
int yylex(void);
void yyerror();
int flag=0; 
%} 

%token NUMBER 

%left '+' '-'

%left '*' '/' '%'

%right '^'
 
%right UMINUS

%left '(' ')'

%% 

ArithmeticExpression: E{ 

		printf("\nResult=%d\n", $$); 

		return 0; 

		}; 
E:E'+'E {$$=$1+$3;} 

|E'-'E {$$=$1-$3;} 

|E'*'E {$$=$1*$3;} 

|E'/'E {$$=$1/$3;} 

|E'%'E {$$=$1%$3;} 

|E'^'E {$$=pow($1,$3);}

|'-' E %prec UMINUS { $$ = -$2;}

|'('E')' {$$=$2;} 

| NUMBER {$$=$1;} 


; 

%% 
void main() 
{ 
printf("\nEnter Arithmetic expression:\n"); 
yyparse();
 
if(flag==0) 
printf("\nEntered arithmetic expression is Valid\n\n"); 
} 

void yyerror() 
{ 
printf("\nEntered arithmetic expression is Invalid\n\n"); 
flag=1; 
} 
