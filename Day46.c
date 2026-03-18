#include <stdio.h>
#include <stdlib.h>

//Level Order Traversal 

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node** createQueue(int* front, int* rear) {
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 500); 
    *front = *rear = 0;
    return queue;
}

void enqueue(struct Node** queue, int* rear, struct Node* new_node) {
    queue[*rear] = new_node;
    (*rear)++;
}

struct Node* dequeue(struct Node** queue, int* front) {
    (*front)++;
    return queue[*front - 1];
}

void printLevelOrder(struct Node* root) {
    int front, rear;
    struct Node** queue = createQueue(&front, &rear);
    struct Node* temp_node = root;

    while (temp_node) {
        printf("%d ", temp_node->data);

        if (temp_node->left)
            enqueue(queue, &rear, temp_node->left);

        if (temp_node->right)
            enqueue(queue, &rear, temp_node->right);

        if (front != rear)
            temp_node = dequeue(queue, &front);
        else
            temp_node = NULL;
    }
    free(queue);
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order Traversal: ");
    printLevelOrder(root);
    printf("\n");

    return 0;
}