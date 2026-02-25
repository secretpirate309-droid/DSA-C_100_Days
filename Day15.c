#include<stdio.h>


//Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

int main()
{
     int n;

    printf("Enter Rows and coloumns of Square matrix:");

    scanf("%d", &n);

    int arr[n][n];

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            printf("Enter Element:");
            scanf("%d", &arr[i][j]);
        }

    }

    int s = 0;

    for(int i = 0; i<n; i++)
    {
        
        
            s = s + arr[i][i];
    
    
    }

    printf("%d\n", s);
}