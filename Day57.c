
#include <stdio.h>
#include <stdlib.h>

//Convert a binary tree into its mirror image by swapping left and right children at every node.


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void mirror(struct Node* node) {
    if (node == NULL) {
        return;
    }

    struct Node* temp = node->left;
    node->left = node->right;
    node->right = temp;

    mirror(node->left);
    mirror(node->right);
}

void inOrder(struct Node* node) {
    if (node == NULL) return;
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder traversal of original tree: ");
    inOrder(root);
    
    mirror(root);

    printf("\nInorder traversal of mirrored tree: ");
    inOrder(root);

    return 0;
}