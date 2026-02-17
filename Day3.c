#include<stdio.h>


//Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed

int main()
{
    int n,k,p;

    printf("Enter Number Of Elements");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i<n ; i++)
    {
        printf("Enter Element No %d:", i);
        scanf("%d", &arr[i]);

    }

    printf("Enter Element to search:");
    scanf("%d", &k);

    for(int i = 0; i<n ; i++)
    {
        if(arr[i] == k)
        {
            p = i+1;
            break;
        
        }
    }

    printf("Found %d at %d time \n", k,p);
    return 0;
}