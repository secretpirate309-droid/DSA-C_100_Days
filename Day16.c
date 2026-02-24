#include<stdio.h>


// Given an array of integers, count the frequency of each distinct element and print the result.

int main()
{
    int n;
    printf("Enter Size of Array:");
    scanf("%d", &n);
    int arr[n];

    
    int freq[1001] = {0};
    for(int i = 0; i<n; i++)
    {
        printf("Enter Element:");
        scanf("%d", &arr[i]);
        freq[arr[i]]++;

    }



    for(int i = 0; i < n; i++) 
    {
        if (freq[arr[i]] > 0) {
            printf("%d:%d ", arr[i], freq[arr[i]]);
            freq[arr[i]] = 0; 
        }
    }
    printf("\n");
    
    return 0;

    
}