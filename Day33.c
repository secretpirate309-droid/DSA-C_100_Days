
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//convert an infix expression to postfix notation using stack.


#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixToPostfix(char* infix) {
    printf("Postfix Expression: ");
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            printf("%c", c);
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                printf("%c", pop());
            pop(); // Remove '('
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                printf("%c", pop());
            }
            push(c);
        }
    }

    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    char infix[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(infix);
    return 0;
}