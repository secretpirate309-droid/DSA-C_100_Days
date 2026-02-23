#include<stdio.h>

//Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

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


    int v = 0;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
           if(i == j)
           {
             if(arr[i][j] != 1) 
             {
                v = 1;
                break;
             }
           }
        }

    }

    if(v == 1)
    {
        printf("Not Identity Matrix\n");
    }

    else
    {
        printf("Identity Matrix\n");
    }


    
}