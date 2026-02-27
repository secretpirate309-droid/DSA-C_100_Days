#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

//Given an array of integers, find two elements whose sum is closest to zero.

int compare(const void* a, const void* b) 
{
    return ((int)a - (int)b);
}

int main()
{
    int n;
    printf("Enter size:");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i<n; i++)
    {
        printf("Enter Element");
        scanf("%d", &arr[i]);
    }

     qsort(arr, n, sizeof(int), compare);
    
    int left = 0, right = n - 1;
    int minSum = INT_MAX;
    int resLeft = 0, resRight = 0;
    
    while (left < right) 
    {
        int sum = arr[left] + arr[right];
        
        if (abs(sum) < abs(minSum)) 
        {
            minSum = sum;
            resLeft = arr[left];
            resRight = arr[right];
        }
        
        if (sum < 0) 
        {
            left++;
        } 
        else 
        {
            right--;
        }
    }
    
    printf("%d %d\n", resLeft, resRight);
    return 0;
}

