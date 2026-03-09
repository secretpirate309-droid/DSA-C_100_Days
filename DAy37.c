#include <stdio.h>
#include <stdlib.h>


//Implement a Priority Queue using an array. An element with smaller value has higher priority.


#define MAX 10

int pq[MAX];
int size = 0;

void enqueue(int data) {
    if (size == MAX) {
        printf("Queue Overflow!\n");
        return;
    }

    int i;
    for (i = size - 1; i >= 0; i--) {
        if (data > pq[i]) {
            pq[i + 1] = pq[i];
        } else {
            break;
        }
    }
    
    pq[i + 1] = data;
    size++;
    printf("Enqueued: %d\n", data);
}

int dequeue() {
    if (size == 0) {
        printf("Queue Underflow!\n");
        return -1;
    }
    
    int element = pq[size - 1];
    size--;
    return element;
}

void display() {
    if (size == 0) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Priority Queue: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    enqueue(30);
    enqueue(10);
    enqueue(50);
    enqueue(20);

    display();

    printf("Dequeued (Highest Priority): %d\n", dequeue());
    display();

    return 0;
}