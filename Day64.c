#include <stdio.h>
#include <stdlib.h>

//Perform BFS from a given source using queue.

#define MAX 10

void bfs(int adj[MAX][MAX], int visited[MAX], int start, int n) {
    int queue[MAX];
    int front = -1, rear = -1;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear) {
        int current = queue[++front];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int n, start;
    int adj[MAX][MAX];
    int visited[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(adj, visited, start, n);
    printf("\n");

    return 0;
}