#include <stdio.h>
#include <stdlib.h>

//construct a binary tree from given inorder and postorder traversal arrays.


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

int search(int arr[], int strt, int end, int value) {
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value) break;
    }
    return i;
}

struct Node* buildTree(int in[], int post[], int inStrt, int inEnd, int* pIdx) {
    if (inStrt > inEnd) return NULL;

    struct Node* node = newNode(post[*pIdx]);
    (*pIdx)--;

    if (inStrt == inEnd) return node;

    int iIdx = search(in, inStrt, inEnd, node->data);

    node->right = buildTree(in, post, iIdx + 1, inEnd, pIdx);
    node->left = buildTree(in, post, inStrt, iIdx - 1, pIdx);

    return node;
}

void printPreorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(in) / sizeof(in[0]);
    int pIdx = n - 1;

    struct Node* root = buildTree(in, post, 0, n - 1, &pIdx);

    printf("Preorder traversal of constructed tree: \n");
    printPreorder(root);
    
    return 0;
}