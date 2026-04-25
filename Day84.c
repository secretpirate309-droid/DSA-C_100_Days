#include <stdio.h>

//iven a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search. in c without cmnts


int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}


int main() {
    int arr[] = {1, 2, 4, 4, 4, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;

    printf("Lower Bound of %d: %d\n", x, lowerBound(arr, n, x)); // Output: 2
    printf("Upper Bound of %d: %d\n", x, upperBound(arr, n, x)); // Output: 5

    return 0;
} 