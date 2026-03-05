#include <stdio.h>
#include <stdlib.h>


//Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.


struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertAtFront(struct Node** head, int newData) {
   
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    
    newNode->data = newData;

    
    newNode->next = (*head);
    newNode->prev = NULL;

    
    if ((*head) != NULL) {
        (*head)->prev = newNode;
    }


    (*head) = newNode;
}

void displayList(struct Node* node) {
    struct Node* last;
    printf("\nTraversal in forward direction: \n");
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction: \n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

int main() {
    struct Node* head = NULL;

    insertAtFront(&head, 10);
    insertAtFront(&head, 20);
    insertAtFront(&head, 30);

    displayList(head);

    return 0;
}