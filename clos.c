//find the epsilon closure of all states in nfa with epsilon transitions
/*
AKASH V V
TLY21CS009
04-10-2024
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int st;
    struct node *link;
};

void findclosure(int, int);
void insert_trantbl(int, char, int);
int findalpha(char);
void print_e_closure(int);

static int set[20], nostate, noalpha, s, notransition, c, r, buffer[20];
char alphabet[20];
static int e_closure[20][20] = {0};
struct node *transition[20][20] = {NULL};

int main() {
    int i, j, m, t, n;
    struct node *temp;

    printf("Enter the number of alphabets:\n");
    scanf("%d", &noalpha);
    getchar(); // To consume the newline character

    printf("NOTE: [use letter 'e' as epsilon]\n");
    printf("NOTE: [e must be the last character, if it is present]\n");
    printf("\nEnter alphabets:\n");
    for (i = 0; i < noalpha; i++) {
        alphabet[i] = getchar();
        getchar(); // To consume the newline character
    }

    printf("\nEnter the number of states:\n");
    scanf("%d", &nostate);
    printf("\nEnter the number of transitions:\n");
    scanf("%d", &notransition);
    printf("NOTE: [Transition is in the form –> qno alphabet qno]\n");
    printf("\nEnter transitions:\n");

    for (i = 0; i < notransition; i++) {
        scanf("%d %c %d", &r, &c, &s);
        r++,s++;
        insert_trantbl(r, c, s);
    }

    printf("\ne-closure of states……\n");
    printf("-----------------------\n");
    for (i = 1; i <= nostate; i++) {
        c = 0;
        for (j = 0; j < 20; j++) {
            buffer[j] = 0;
            e_closure[i][j] = 0;
        }
        findclosure(i, i);
        printf("e-closure(q%d): ", i-1);
        print_e_closure(i);
        printf("\n"); // Move to next line after printing closure
    }

    return 0;
}

void findclosure(int x, int sta) {
    struct node *temp;
    int i;

    if (buffer[x])
        return;

    e_closure[sta][c++] = x;
    buffer[x] = 1;

    // Check for epsilon transitions
    if (alphabet[noalpha - 1] == 'e' && transition[x][noalpha - 1] != NULL) {
        temp = transition[x][noalpha - 1];
        while (temp != NULL) {
            findclosure(temp->st, sta);
            temp = temp->link;
        }
    }
}

void insert_trantbl(int r, char c, int s) {
    int j;
    struct node *temp;

    j = findalpha(c);
    if (j == 999) {
        printf("Error: Invalid alphabet\n");
        exit(0);
    }

    temp = (struct node *)malloc(sizeof(struct node));
    temp->st = s;
    temp->link = transition[r][j];
    transition[r][j] = temp;
}

int findalpha(char c) {
    int i;
    for (i = 0; i < noalpha; i++) {
        if (alphabet[i] == c)
            return i;
    }
    return 999; // Return an error code if not found
}

void print_e_closure(int i) {
    int j;
    printf("{");
    for (j = 0; e_closure[i][j] != 0; j++) {
        printf("q%d", e_closure[i][j]-1);
        if (e_closure[i][j + 1] != 0) { // Check if there's another state
            printf(", ");
        }
    }
    printf("}");
}


/*

OUTPUT

Enter the number of alphabets:
4
NOTE: [use letter 'e' as epsilon]
NOTE: [e must be the last character, if it is present]

Enter alphabets:
a
b
c
e

Enter the number of states:
3

Enter the number of transitions:
5
NOTE: [Transition is in the form –> qno alphabet qno]

Enter transitions:
0 a 0
1 b 1
2 c 2
0 e 1
1 e 2

e-closure of states……
-----------------------
e-closure(q0): {q0, q1, q2}
e-closure(q1): {q1, q2}
e-closure(q2): {q2}

*/





	
