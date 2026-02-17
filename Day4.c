#include<stdio.h>

//Problem: Given an array of n integers, reverse the array in-place using two-pointer approach


int main()
{
    int n;

    printf("Enter Number of elements:");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enter Elemnet No %d:", i);
        scanf("%d", &arr[i]);

    }

    int*f;
    int*b;
    int t;

    f = arr;
    b = arr + n - 1;

    while(f<b)
    {
        t = *f;
        *f = *b;
        *b = t;

        f++;
        b--;

    }

    for(int i = 0; i<n; i++)
    {
        printf("%d\n", arr[i]);
    }
}