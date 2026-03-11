#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap *heap, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap->data[index] < heap->data[parent]) {
        swap(&heap->data[index], &heap->data[parent]);
        heapifyUp(heap, parent);
    }
}

void heapifyDown(MinHeap *heap, int index) {
    int smallest = index;
    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest])
        smallest = left;

    if (right < heap->size && heap->data[right] < heap->data[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->data[index], &heap->data[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insert(MinHeap *heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap Overflow\n");
        return;
    }
    heap->data[heap->size] = value;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

int extractMin(MinHeap *heap) {
    if (heap->size <= 0) return -1;
    
    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    
    return root;
}

void printHeap(MinHeap *heap) {
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->data[i]);
    printf("\n");
}

int main() {
    MinHeap heap = {.size = 0};

    insert(&heap, 10);
    insert(&heap, 40);
    insert(&heap, 15);
    insert(&heap, 5);
    
    printf("Heap elements: ");
    printHeap(&heap);

    printf("Extracted Min: %d\n", extractMin(&heap));
    printf("Heap after extraction: ");
    printHeap(&heap);

    return 0;
}