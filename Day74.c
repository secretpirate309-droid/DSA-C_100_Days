
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.


int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

char* findWinner(char* votes[], int n) {
    if (n == 0) return NULL;

    qsort(votes, n, sizeof(char*), compare);

    char* winner = votes[0];
    int maxVotes = 1;
    
    char* currentCandidate = votes[0];
    int currentVotes = 1;

    for (int i = 1; i < n; i++) {
        if (strcmp(votes[i], currentCandidate) == 0) {
            currentVotes++;
        } else {
            if (currentVotes > maxVotes) {
                maxVotes = currentVotes;
                winner = currentCandidate;
            }
            currentCandidate = votes[i];
            currentVotes = 1;
        }
    }

    if (currentVotes > maxVotes) {
        winner = currentCandidate;
    }

    return winner;
}

int main() {
    char* votes[] = {"apple", "banana", "apple", "cherry", "banana", "cherry", "cherry"};
    int n = sizeof(votes) / sizeof(votes[0]);

    char* winner = findWinner(votes, n);
    printf("%s\n", winner);

    return 0;
}