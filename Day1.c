#include<stdio.h>

/*Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space. /*/


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
    printf("Enter positon in array");
    scanf("%d", &p);

    for(int i = 0; i<n; i++)
    {
        arr[i] = arr[i+1];
    }

    arr[p] = el;
    n++;

    for(int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}