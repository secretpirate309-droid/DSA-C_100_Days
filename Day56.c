#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//Check whether a given binary tree is symmetric around its center.


struct Node {
    int data;
    struct Node *left, *right;
};

bool isMirror(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 && root2 && root1->data == root2->data) {
        return isMirror(root1->left, root2->right) &&
               isMirror(root1->right, root2->left);
    }

    return false;
}

bool isSymmetric(struct Node* root) {
    if (root == NULL)
        return true;
    
    return isMirror(root->left, root->right);
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
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);

    if (isSymmetric(root))
        printf("The tree is symmetric.\n");
    else
        printf("The tree is not symmetric.\n");

    return 0;
}