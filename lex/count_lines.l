//akash v v
//roll no 09
%{
#include <stdio.h>
int char_count = 0;
int word_count = 0;
int line_count = 0;
%}
%%
\n	{ line_count++; word_count++; }
[ \t]+ 	{ word_count++; }
. 	{ char_count++; }
%%
int main() {
FILE *file = fopen("input.txt", "r");
if (!file) {
perror("Error opening file");
return 1;
}
yyin = file;
yylex();
printf("Lines: %d\n", line_count);
printf("Words: %d\n", word_count);
printf("Characters: %d\n", char_count);
return 0;
}


/*
INPUT

#include<stdio.h>
void main()
{
	int a,=5,b=6,c;
	c = a+b;
	printf("sum is %d\n",c);
}

OUTPUT

Lines: 7
Words: 16
Characters: 71
*/
