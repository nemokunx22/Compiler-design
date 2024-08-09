#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main() {
    int l = 1;
    int t = 0;
    int j = 0;
    int i, flag;
    char ch, str[20];
    FILE *input;

    input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    char keyword[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                            "do", "double", "else", "enum", "extern", "float", "for", "goto",
                            "if", "int", "long", "register", "return", "short", "signed",
                            "sizeof", "static", "struct", "switch", "typedef", "union",
                            "unsigned", "void", "volatile", "while"};

    printf("Line no. \t Token no. \t\t Token \t\t Lexeme\n\n");

    while (!feof(input)) {
        i = 0;
        flag = 0;
        ch = fgetc(input);

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            printf("%7d\t\t %7d\t\t Operator\t %7c\n", l, t, ch);
            t++;
        }

        else if (ch == ';' || ch == '{' || ch == '}' || ch == '(' || ch == ')' || 
                 ch == '?' || ch == '@' || ch == '!' || ch == '%') {
            printf("%7d\t\t %7d\t\t Special symbol\t %7c\n", l, t, ch);
            t++;
        }

        else if (isdigit(ch)) {
            printf("%7d\t\t %7d\t\t Digit\t\t %7c\n", l, t, ch);
            t++;
        }

        else if (isalpha(ch)) {
            str[i] = ch;
            i++;
            ch = fgetc(input);

            while (isalnum(ch) && ch != ' ') {
                str[i] = ch;
                i++;
                ch = fgetc(input);
            }

            str[i] = '\0';

            for (j = 0; j <= 30; j++) {
                if (strcmp(str, keyword[j]) == 0) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1) {
                printf("%7d\t\t %7d\t\t Keyword\t %7s\n", l, t, str);
                t++;
            } else {
                printf("%7d\t\t %7d\t\t Identifier\t %7s\n", l, t, str);
                t++;
            }
        }

        else if (ch == '\n') {
            l++;
        }
    }

    fclose(input);
    return 0;
}

