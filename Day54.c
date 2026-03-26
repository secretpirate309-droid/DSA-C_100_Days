#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.




struct Node {
    int data;
    struct Node *left, *right;
};

struct Stack {
    int top;
    int capacity;
    struct Node** array;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct Node**)malloc(stack->capacity * sizeof(struct Node*));
    return stack;
}

void push(struct Stack* stack, struct Node* node) {
    stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void printZigZag(struct Node* root) {
    if (root == NULL) return;

    struct Stack* s1 = createStack(100);
    struct Stack* s2 = createStack(100);

    push(s1, root);

    while (!isEmpty(s1) || !isEmpty(s2)) {
        while (!isEmpty(s1)) {
            struct Node* temp = pop(s1);
            printf("%d ", temp->data);

            if (temp->left) push(s2, temp->left);
            if (temp->right) push(s2, temp->right);
        }

        while (!isEmpty(s2)) {
            struct Node* temp = pop(s2);
            printf("%d ", temp->data);

            if (temp->right) push(s1, temp->right);
            if (temp->left) push(s1, temp->left);
        }
    }
    
    free(s1->array);
    free(s1);
    free(s2->array);
    free(s2);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);

    printf("Zigzag Order traversal of binary tree is: \n");
    printZigZag(root);

    return 0;
}