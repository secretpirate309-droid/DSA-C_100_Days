#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

void push(Stack *s, int val) {
    s->items[++(s->top)] = val;
}

int pop(Stack *s) {
    return s->items[(s->top)--];
}

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void enqueue(Queue *q, int val) {
    q->items[++(q->rear)] = val;
}

int dequeue(Queue *q) {
    return q->items[++(q->front)];
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void reverseQueue(Queue *q) {
    Stack s;
    s.top = -1;

    while (!isEmpty(q)) {
        push(&s, dequeue(q));
    }

    while (s.top != -1) {
        enqueue(q, pop(&s));
    }
}

int main() {
    Queue q;
    q.front = q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Original Queue: 10 20 30 40\n");

    reverseQueue(&q);

    printf("Reversed Queue: ");
    while (!isEmpty(&q)) {
        printf("%d ", dequeue(&q));
    }
    
    return 0;
}