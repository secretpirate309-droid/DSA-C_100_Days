#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
    printf("Enqueued: %d\n", value);
}

void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow! The queue is empty.\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Dequeued: %d\n", temp->data);

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

int main() {
    struct Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    dequeue(q);
    dequeue(q);
    
    enqueue(q, 40);

    return 0;
}