
#include <stdio.h>
#include <string.h>


//Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

char firstNonRepeating(char* s) {
    int count[26] = {0};
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
    }

    for (i = 0; s[i] != '\0'; i++) {
        if (count[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[100];
    
    printf("Enter a string: ");
    scanf("%s", s);

    char result = firstNonRepeating(s);
    
    if (result != '$') {
        printf("The first non-repeating character is: %c\n", result);
    } else {
        printf("$\n");
    }

    return 0;
}