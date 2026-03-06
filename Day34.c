#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation



struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node* temp = *top;
    int poppedVal = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedVal;
}

int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(&stack, exp[i] - '0');
        } 
        else {
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            
            switch (exp[i]) {
                case '+': push(&stack, val2 + val1); break;
                case '-': push(&stack, val2 - val1); break;
                case '*': push(&stack, val2 * val1); break;
                case '/': push(&stack, val2 / val1); break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char exp[] = "231*+9-";
    printf("Postfix Evaluation Result: %d\n", evaluatePostfix(exp));
    return 0;
}