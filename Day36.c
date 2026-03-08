#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// Circular Queue Using Array - Implement using linked list with dynamic memory allocation.


typedef struct Node {
    int val;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int capacity;
    int currentCount;
} MyCircularDeque;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->head = NULL;
    obj->tail = NULL;
    obj->capacity = k;
    obj->currentCount = 0;
    return obj;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->currentCount == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->currentCount == obj->capacity;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
    Node* newNode = createNode(value);
    if (myCircularDequeIsEmpty(obj)) {
        obj->head = obj->tail = newNode;
    } else {
        newNode->next = obj->head;
        obj->head->prev = newNode;
        obj->head = newNode;
    }
    obj->currentCount++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (myCircularDequeIsFull(obj)) return false;
    Node* newNode = createNode(value);
    if (myCircularDequeIsEmpty(obj)) {
        obj->head = obj->tail = newNode;
    } else {
        newNode->prev = obj->tail;
        obj->tail->next = newNode;
        obj->tail = newNode;
    }
    obj->currentCount++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    Node* temp = obj->head;
    if (obj->currentCount == 1) {
        obj->head = obj->tail = NULL;
    } else {
        obj->head = obj->head->next;
        obj->head->prev = NULL;
    }
    free(temp);
    obj->currentCount--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (myCircularDequeIsEmpty(obj)) return false;
    Node* temp = obj->tail;
    if (obj->currentCount == 1) {
        obj->head = obj->tail = NULL;
    } else {
        obj->tail = obj->tail->prev;
        obj->tail->next = NULL;
    }
    free(temp);
    obj->currentCount--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    return myCircularDequeIsEmpty(obj) ? -1 : obj->head->val;
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    return myCircularDequeIsEmpty(obj) ? -1 : obj->tail->val;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj);
}

int main() {
    MyCircularDeque* deque = myCircularDequeCreate(3);

    printf("Insert Last 1: %s\n", myCircularDequeInsertLast(deque, 1) ? "True" : "False");
    printf("Insert Last 2: %s\n", myCircularDequeInsertLast(deque, 2) ? "True" : "False");
    printf("Insert Front 3: %s\n", myCircularDequeInsertFront(deque, 3) ? "True" : "False");
    printf("Insert Front 4 (should fail): %s\n", myCircularDequeInsertFront(deque, 4) ? "True" : "False");

    printf("Rear element: %d\n", myCircularDequeGetRear(deque));
    printf("Is Full: %s\n", myCircularDequeIsFull(deque) ? "True" : "False");

    printf("Delete Last: %s\n", myCircularDequeDeleteLast(deque) ? "True" : "False");
    printf("Insert Front 4: %s\n", myCircularDequeInsertFront(deque, 4) ? "True" : "False");
    
    printf("Front element: %d\n", myCircularDequeGetFront(deque));

    myCircularDequeFree(deque);
    return 0;
}