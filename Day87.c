#include <stdio.h>


//Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.



long long integer_sqrt(long long n) {
    if (n < 2) return n;

    long long low = 0;
    long long high = n / 2;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;

        if (square == n) {
            return mid;
        } else if (square < n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    long long n;
    printf("Enter a number: ");
    if (scanf("%lld", &n) != 1) return 1;

    if (n < 0) {
        printf("Undefined for negative numbers.\n");
    } else {
        printf("Integer square root of %lld is %lld\n", n, integer_sqrt(n));
    }

    return 0;
}