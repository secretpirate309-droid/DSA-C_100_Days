#include <stdio.h>
#include <stdlib.h>


//Construct a Binary Tree from the given level-order traversal. in c


struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* constructTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int front = 0, rear = 0;
    
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* parent = queue[front++];

        if (i < n) {
            parent->left = newNode(arr[i]);
            queue[rear++] = parent->left;
            i++;
        }

        if (i < n) {
            parent->right = newNode(arr[i]);
            queue[rear++] = parent->right;
            i++;
        }
    }
    
    free(queue);
    return root;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    int levelOrder[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(levelOrder) / sizeof(levelOrder[0]);

    struct Node* root = constructTree(levelOrder, n);

    printf("Inorder traversal: ");
    inOrder(root);
    printf("\n");

    return 0;
}