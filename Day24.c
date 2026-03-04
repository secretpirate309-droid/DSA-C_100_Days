#include <stdio.h>
#include <stdlib.h>

// Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* deleteFirstOccurrence(struct ListNode* head, int val) {
    if (head == NULL) return NULL;

    
    if (head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct ListNode* curr = head;
    while (curr->next != NULL) {
        if (curr->next->val == val) {
            struct ListNode* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
            return head; 
        }
        curr = curr->next;
    }
    return head;
}


struct ListNode* insertEnd(struct ListNode* head, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    
    if (head == NULL) return newNode;
    
    struct ListNode* curr = head;
    while (curr->next != NULL) curr = curr->next;
    curr->next = newNode;
    return head;
}


void printList(struct ListNode* head) {
    struct ListNode* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* head = NULL;

   
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 20);
    head = insertEnd(head, 40);

    printf("Original List: ");
    printList(head);

    int target = 20;
    printf("Deleting first occurrence of %d...\n", target);
    head = deleteFirstOccurrence(head, target);

    printf("Resulting List: ");
    printList(head);

    return 0;
}