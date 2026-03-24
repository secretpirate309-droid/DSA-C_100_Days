#include <stdio.h>
#include <stdlib.h>

//Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.


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

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL || root->data == n1 || root->data == n2) {
        return root;
    }

    struct Node* leftLCA = findLCA(root->left, n1, n2);
    struct Node* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    int val1 = 4, val2 = 5;
    struct Node* lca = findLCA(root, val1, val2);

    if (lca != NULL)
        printf("LCA of %d and %d is: %d\n", val1, val2, lca->data);
    else
        printf("LCA not found.\n");

    return 0;
}