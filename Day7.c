#include<stdio.h>



int main()
{
    int n;
    printf("Enter Number Of Elements:");
    scanf("%d", &n);



    int arr[n];
    for(int i = 0; i<n; i++)
    {
        printf("Enter Element No. %d:", i);
        scanf("%d", &arr[i]);

    }

    for(int i = 0; i<n; i++)
    {
        if(arr[i] == arr[i+1])
        {
            arr[i] = arr[i+1];

        }
    }

    for(int i = 0; i<n; i++)
    {
        printf("%d", arr[i]);
    }
}