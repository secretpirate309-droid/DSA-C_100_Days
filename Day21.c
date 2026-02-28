#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;


Node* head = NULL;

void add(int n) {
    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        printf("Enter Data for Node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) 
        {
           
            head = newNode;
        } 
        else 
        {
            
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            
            temp->next = newNode;
        }
    }
}

int main() {
    int n;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    add(n);


    printf("\nYour Linked List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next; 
    }
    printf("NULL\n");

    return 0;
}