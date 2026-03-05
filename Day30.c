#include <stdio.h>
#include <stdlib.h>

//Implement using linked list with dynamic memory allocation.

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** poly, int c, int e) {
    struct Node* temp = createNode(c, e);
    if (*poly == NULL) {
        *poly = temp;
        return;
    }
    struct Node* curr = *poly;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
}

void displayPoly(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL && poly->coeff >= 0) {
            printf(" + ");
        } else if (poly != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;

    // Creating polynomial: 5x^4 + 2x^2 + 8x^0
    insertTerm(&poly1, 5, 4);
    insertTerm(&poly1, 2, 2);
    insertTerm(&poly1, 8, 0);

    printf("Polynomial: ");
    displayPoly(poly1);

    return 0;
}