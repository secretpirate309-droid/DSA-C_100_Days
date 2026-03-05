#include <stdio.h>
#include <stdlib.h>


//Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.




struct Node {
    int data;
    struct Node* next;
};


int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    return count;
}


void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct Node* head = NULL;

    
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);

    int target = 1;
    printf("Occurrences of %d: %d\n", target, countOccurrences(head, target));

    return 0;
}