#include<stdio.h>
#include<stdlib.h>

//Problem: Count Nodes in Linked List


struct ListNode 
{
    int val;
    struct ListNode* next;
};


int countNodes(struct ListNode* head) 
{
    int count = 0;
    struct ListNode* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}



struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    printf("Original List: ");
    printList(head);


    printf("Total Nodes: %d\n", countNodes(head));

   
    

    return 0;
}