/*
AKASH V V
TLY21CS009
24-10-24
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

char input[100];
int i, error;

void E();
void T();
void Eprime();
void Tprime();
void F();

void main() {
  i = 0;
  error = 0;
  printf("Enter an arithmetic expression: ");
  scanf("%s", input);
  E();
  
  if (strlen(input) == i && error == 0)
    printf("\nAccepted..!!!\n");
  else 
    printf("\nRejected..!!!\n");
}

void E() {
  T();
  Eprime();
}

void Eprime() {
  if (input[i] == '+') {
    i++;
    T();
    Eprime();
  }
}

void T() {
  F();
  Tprime();
}

void Tprime() {
  if (input[i] == '*') {
    i++;
    F();
    Tprime();
  }
}

void F() {
  if (isalnum(input[i])) {
    i++;
  } 
  else if (input[i] == '(') {
    i++;
    E();
    if (input[i] == ')') 
      i++;
    else 
      error = 1;
  } 
  else
    error = 1;
}

/*
OUTPUT

Enter an arithmetic expression: a+b*c

Accepted..!!!
*/
