#include <stdio.h>
#include <stdlib.h>


//Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.


struct Node {
    int data;
    struct Node* next;
};

struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    struct Node* curr = head;
    int len = 1;
    
    while (curr->next != NULL) {
        curr = curr->next;
        len++;
    }

    curr->next = head;

    k = k % len;
    int stepsToNewTail = len - k;
    
    struct Node* newTail = curr;
    while (stepsToNewTail--) {
        newTail = newTail->next;
    }

    head = newTail->next;
    newTail->next = NULL;

    return head;
}

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int k = 2;
    printf("Original List: ");
    printList(head);

    head = rotateRight(head, k);

    printf("Rotated List by %d: ", k);
    printList(head);

    return 0;
}