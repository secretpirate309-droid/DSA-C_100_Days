#include<stdio.h>

//Given integers a and b, compute a^b using recursion without using pow() function.


int powe(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }

    else
    {
        return n * powe(n,p-1);
    }


    
}

int main()
{
    int p,n;
    printf("Enter Digit And Power:");
    scanf("%d %d", &n,&p);
    int r;
    r = powe(n,p);
    printf("%d\n", r);
}

