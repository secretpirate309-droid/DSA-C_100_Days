#include <stdio.h>
#include <string.h>


//Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.



char findFirstRepeated(char* s) {
    int seen[256] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        if (seen[(unsigned char)s[i]] == 1) {
            return s[i];
        }
        seen[(unsigned char)s[i]] = 1;
    }

    return '\0';
}

int main() {
    char s[] = "geeksforgeeks";
    char result = findFirstRepeated(s);

    if (result != '\0') {
        printf("%c\n", result);
    } else {
        printf("-1\n");
    }

    return 0;
}