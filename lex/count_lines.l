//akash v v
//Roll no 09
%{
#include <stdio.h>
int char_count = 0;
int word_count = 0;
int line_count = 0;
%}
%%
\n
{ line_count++; word_count++; }
[ \t]+
{ word_count++; } // Match spaces or tabs
.
{ char_count++; }
%%
int main() {
FILE *file = fopen("input.c", "r");
// Hardcoded file path
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
