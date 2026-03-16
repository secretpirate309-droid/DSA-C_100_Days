#include <stdio.h>
#include <stdlib.h>



//Perform inorder, preorder, and postorder traversals of a given binary tree.


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

void inOrder(struct Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
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

int main() {
    int levelOrder[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(levelOrder) / sizeof(levelOrder[0]);
    struct Node* root = constructTree(levelOrder, n);

    printf("Inorder Traversal:   ");
    inOrder(root);
    printf("\n");

    printf("Preorder Traversal:  ");
    preOrder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}