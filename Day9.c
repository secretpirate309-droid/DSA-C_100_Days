#include<stdio.h>
#include<string.h>


// A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.


int main()
{
    char a[10];

    printf("Enter String in Lowercase:");
    scanf("%s", &a);

    int left = 0;
    int right = strlen(a) - 1;
    
    while (left < right) {
        char temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        left++;
        right--;
    }

    printf("%s\n", a);

}