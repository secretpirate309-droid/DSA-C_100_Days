#include <stdio.h>
#include <stdbool.h>


//Using BFS or DFS, check if the entire graph is connected.

#define MAX 100

void bfs(int graph[MAX][MAX], int n, int start, bool visited[]) {
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int n, edges;
    int graph[MAX][MAX] = {0};
    bool visited[MAX] = {false};

    if (scanf("%d %d", &n, &edges) != 2) return 0;

    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    if (n == 0) {
        printf("Connected\n");
        return 0;
    }

    bfs(graph, n, 0, visited);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("Not Connected\n");
            return 0;
        }
    }

    printf("Connected\n");
    return 0;
}