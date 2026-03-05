#include <stdio.h>
#include <stdlib.h>

// Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.




typedef struct Node {
    int data;
    struct Node* next;
} Node;

int getCount(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getIntersectionNode(Node* head1, Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d = abs(c1 - c2);

    Node* curr1 = head1;
    Node* curr2 = head2;

    if (c1 > c2) {
        for (int i = 0; i < d; i++) curr1 = curr1->next;
    } else {
        for (int i = 0; i < d; i++) curr2 = curr2->next;
    }

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1 == curr2) {
            return curr1;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return NULL;
}

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);

    Node* head2 = newNode(4);
    head2->next = newNode(5);

    Node* common = newNode(6);
    common->next = newNode(7);

    head1->next->next->next = common;
    head2->next->next = common;

    Node* intersection = getIntersectionNode(head1, head2);

    if (intersection) {
        printf("The intersection point data is: %d\n", intersection->data);
    } else {
        printf("No intersection point found.\n");
    }

    return 0;
}