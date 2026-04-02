#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>




//Check whether a given binary tree satisfies the Min-Heap property.



struct Node {
    int data;
    struct Node *left, *right;
};

int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isComplete(struct Node* root, int index, int totalNodes) {
    if (root == NULL) return true;
    if (index >= totalNodes) return false;
    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

bool isMinHeapProperty(struct Node* root) {
    if (root->left == NULL && root->right == NULL) return true;

    if (root->right == NULL) {
        return root->data <= root->left->data;
    } else {
        if (root->data <= root->left->data && root->data <= root->right->data) {
            return isMinHeapProperty(root->left) && isMinHeapProperty(root->right);
        } else {
            return false;
        }
    }
}

bool isMinHeap(struct Node* root) {
    if (root == NULL) return true;
    int n = countNodes(root);
    return isComplete(root, 0, n) && isMinHeapProperty(root);
}