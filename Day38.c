#include <stdio.h>
#define SIZE 5

//Deque (Double-Ended Queue)

//A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack. in c

int deque[SIZE];
int front = -1, rear = -1;

void insertFront(int x) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Overflow\n");
    } else if (front == -1) { // First element
        front = rear = 0;
        deque[front] = x;
    } else if (front == 0) { // Wrap around
        front = SIZE - 1;
        deque[front] = x;
    } else {
        front--;
        deque[front] = x;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Underflow\n");
    } else if (front == rear) { // Only one element
        front = rear = -1;
    } else if (rear == 0) { // Wrap around
        rear = SIZE - 1;
    } else {
        rear--;
    }
}