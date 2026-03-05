#include <stdio.h>
#include <stdlib.h>

//Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.


struct Node {
    int data;
    struct Node* next;
};

struct Node* addToEmpty(struct Node* last, int data) {
    if (last != NULL) return last;

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    last = temp;
    last->next = last; 
    return last;
}

struct Node* addEnd(struct Node* last, int data) {
    if (last == NULL) return addToEmpty(last, data);

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    
    temp->next = last->next;
    last->next = temp;
    last = temp;
    
    return last;
}

void traverse(struct Node* last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* p = last->next; 

    printf("Circular List: ");
    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != last->next); 
    printf("(head)\n");
}

int main() {
    struct Node* last = NULL;

    last = addToEmpty(last, 10);
    last = addEnd(last, 20);
    last = addEnd(last, 30);
    last = addEnd(last, 40);

    traverse(last);

    return 0;
}