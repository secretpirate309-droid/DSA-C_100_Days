#include <stdio.h>
#include <stdlib.h>

//Construct a binary tree from given preorder and inorder traversal arrays.
 



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
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

struct Node* buildTree(int in[], int pre[], int inStrt, int inEnd) {
    static int preIndex = 0;

    if (inStrt > inEnd) return NULL;

    struct Node* tNode = newNode(pre[preIndex++]);

    if (inStrt == inEnd) return tNode;

    int inIndex = search(in, inStrt, inEnd, tNode->data);

    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

void printInorder(struct Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    int in[] = { 4, 2, 5, 1, 6, 3 };
    int pre[] = { 1, 2, 4, 5, 3, 6 };
    int len = sizeof(in) / sizeof(in[0]);

    struct Node* root = buildTree(in, pre, 0, len - 1);

    printf("Inorder traversal of the constructed tree is: \n");
    printInorder(root);
    
    return 0;
}