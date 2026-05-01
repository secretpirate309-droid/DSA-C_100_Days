#include <stdio.h>
#include <stdbool.h>

//Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.



bool isPossible(int boards[], int n, int k, int mid) {
    int painters = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + boards[i] > mid) {
            painters++;
            currentSum = boards[i];
            if (painters > k) return false;
        } else {
            currentSum += boards[i];
        }
    }
    return true;
}

int partition(int boards[], int n, int k) {
    int low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int boards[] = {10, 20, 30, 40};
    int n = sizeof(boards) / sizeof(boards[0]);
    int k = 2;
    printf("%d\n", partition(boards, n, k));
    return 0;
}