#include<stdio.h>
#include<string.h>


//Read a string and check if it is a palindrome using two-pointer comparison.

int main()
{
   
    char str[1000];
    printf("Enter String:");

    scanf("%s", str);
    
    int left = 0;
    int right = strlen(str) - 1;
    int v = 1;
    
    while (left < right) 
    {
        if (str[left] != str[right]) 
        {
            v = 0;
            break;
        }
        left++;
        right--;
    }

    if (v == 1)
    {
        printf("Palindromee\n");

    }

    else
    {
        printf("Not Palindrome\n");
    }
    
    
    
    

}