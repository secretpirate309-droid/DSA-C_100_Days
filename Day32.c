#include <stdio.h>
#include <stdbool.h>

#define MAX 5
//Implement push and pop operations on a stack and verify stack operations.

typedef struct {
    int items[MAX];
    int top;
} Stack;


void initStack(Stack *s) {
    s->top = -1;
}


bool isFull(Stack *s) {
    return s->top == MAX - 1;
}


bool isEmpty(Stack *s) {
    return s->top == -1;
}


void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Overflow: Cannot push %d. Stack is full.\n", value);
    } else {
        s->items[++(s->top)] = value;
        printf("Pushed: %d\n", value);
    }
}


int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Underflow: Cannot pop. Stack is empty.\n");
        return -1; 
    } else {
        return s->items[(s->top)--];
    }
}

int main() {
    Stack s;
    initStack(&s);

    printf("--- Verifying Push & Overflow ---\n");
    for (int i = 1; i <= 6; i++) {
        push(&s, i * 10);
    }

    printf("\n--- Verifying Pop & Underflow ---\n");
    for (int i = 1; i <= 6; i++) {
        int val = pop(&s);
        if (val != -1) {
            printf("Popped: %d\n", val);
        }
    }

    return 0;
}