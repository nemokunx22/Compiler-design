//Akash V V
//Roll no : 09
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int l = 1; // Line number
    int t = 0; // Token number
    int i, j, flag;
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

    while ((ch = fgetc(input)) != EOF) {
        // Check for single-line comments
        if (ch == '/') {
            char nextChar = fgetc(input);
            if (nextChar == '/') {
                // Skip the rest of the line
                while (ch != '\n' && ch != EOF) {
                    ch = fgetc(input);
                }
                if (ch == '\n') {
                    l++; // Update line number for the next line
                }
                continue;
            } else if (nextChar == '*') {
                // Skip multi-line comments
                ch = fgetc(input); // Continue reading after '/*'
                while (ch != EOF) {
                    if (ch == '*') {
                        char afterStar = fgetc(input);
                        if (afterStar == '/') {
                            break; // End of multi-line comment
                        } else {
                            ungetc(afterStar, input);
                        }
                    }
                    ch = fgetc(input);
                }
                continue;
            } else {
                ungetc(nextChar, input); // Not a comment, put the character back
            }
        }

        // Process tokens
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            printf("%7d\t\t %7d\t\t Operator\t %7c\n", l, t, ch);
            t++;
        } else if (ch == ';' || ch == '{' || ch == '}' || ch == '(' || ch == ')' || 
                   ch == '?' || ch == '@' || ch == '!' || ch == '%') {
            printf("%7d\t\t %7d\t\t Special symbol\t %7c\n", l, t, ch);
            t++;
        } else if (isdigit(ch)) {
            // Process digits
            str[0] = ch;
            i = 1;
            ch = fgetc(input);
            while (isdigit(ch)) {
                str[i] = ch;
                i++;
                ch = fgetc(input);
            }
            str[i] = '\0';
            ungetc(ch, input); // Put the last read character back to process later

            printf("%7d\t\t %7d\t\t Digit\t\t %7s\n", l, t, str);
            t++;
        } else if (isalpha(ch)) {
            // Process identifiers and keywords
            str[0] = ch;
            i = 1;
            ch = fgetc(input);

            while (isalnum(ch) || ch == '_') {
                str[i] = ch;
                i++;
                ch = fgetc(input);
            }
            str[i] = '\0';
            ungetc(ch, input); // Put the last read character back to process later

            // Check if the identifier is a keyword
            flag = 0;
            for (j = 0; j < 32; j++) {
                if (strcmp(str, keyword[j]) == 0) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1) {
                printf("%7d\t\t %7d\t\t Keyword\t %7s\n", l, t, str);
            } else {
                printf("%7d\t\t %7d\t\t Identifier\t %7s\n", l, t, str);
            }
            t++;
        } else if (ch == '\n') {
            l++;
        }
    }

    fclose(input);
    return 0;
}
