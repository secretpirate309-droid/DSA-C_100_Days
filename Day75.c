#include <stdio.h>
#include <stdlib.h>

//Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.


struct Node {
    int sum;
    int index;
    struct Node* next;
};

#define SIZE 1000

int hash(int key) {
    return abs(key) % SIZE;
}

void insert(struct Node** table, int sum, int index) {
    int h = hash(sum);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = table[h];
    table[h] = newNode;
}

int find(struct Node** table, int sum) {
    int h = hash(sum);
    struct Node* temp = table[h];
    while (temp) {
        if (temp->sum == sum) return temp->index;
        temp = temp->next;
    }
    return -2; 
}

int maxLen(int arr[], int n) {
    struct Node* table[SIZE] = {NULL};
    int max_len = 0;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];

        if (curr_sum == 0) {
            max_len = i + 1;
        }

        int prev_index = find(table, curr_sum);
        if (prev_index != -2) {
            if (max_len < i - prev_index) {
                max_len = i - prev_index;
            }
        } else {
            insert(table, curr_sum, i);
        }
    }
    
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of the longest 0 sum subarray is %d\n", maxLen(arr, n));
    return 0;
}