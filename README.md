
# Compiler design lab

```
Declaration
%%
rule [A-Z][a-z]+
%%
```

- phone number program - [1-9][0-9]-------[0-9] , 10 times it will be repeated
- email verification - akash@gmail.com to generalise this in lexcode -> [ ]@[ ].com

> We are gonna save the lex program as <filename>.l
since there is no compiler to run the lex program we have to convert it to its c code
> Lex <filename>.l
now the file name will be converted to c file and then it could be run normally like gcc


#### TO COMPILE AND RUN A YACC PROGRAM
-lex file -> lex <filename> -> gcc lex.yy.c -ll -> a.out
- yacc file -> yacc -d <filename> -> gcc lex.yy.c y.tab -ll


ppl-17@ppl17:~/Desktop/akash_09/yacc$ lex calc_lex.l
ppl-17@ppl17:~/Desktop/akash_09/yacc$ yacc -d calc_yacc.y
ppl-17@ppl17:~/Desktop/akash_09/yacc$ gcc lex.yy.c y.tab.c -ll -lm

- lm for power
