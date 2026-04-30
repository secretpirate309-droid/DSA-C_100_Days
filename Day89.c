#include <stdio.h>
#include <stdbool.h>

//Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.



bool isPossible(int arr[], int n, int m, int mid) {
    int students = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) return false;

        if (currentSum + arr[i] > mid) {
            students++;
            currentSum = arr[i];
            if (students > m) return false;
        } else {
            currentSum += arr[i];
        }
    }
    return true;
}

int allocateBooks(int arr[], int n, int m) {
    if (m > n) return -1;

    int low = 0, high = 0, result = -1;
    for (int i = 0; i < n; i++) {
        high += arr[i];
        if (arr[i] > low) low = arr[i];
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int arr[] = {12, 34, 67, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 2;

    printf("%d\n", allocateBooks(arr, n, m));
    return 0;
}