#include<stdio.h>

//Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.


int main()
{
    int n,p;
    
    printf("Enter Size Of array:");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i<n ;i++)
    {
        printf("Enter Elemnt %d:", i);
        scanf("%d", &arr[i]);
    }    

    int el;
    printf("Enter Element:");
    scanf("%d", &el);
    

    for(int i = 0; i<n; i++)
    {
        arr[i] = arr[i+1];
    }

    

    for(int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}