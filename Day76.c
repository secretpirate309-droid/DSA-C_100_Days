#include <stdio.h>

//Using DFS or BFS, count number of connected components.



int vis[100];
int graph[100][100];
int n;

void dfs(int v) {
    vis[v] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && !vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    int e, u, v, count = 0;
    
    if (scanf("%d %d", &n, &e) != 2) return 0;

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            count++;
            dfs(i);
        }
    }

    printf("%d\n", count);
    return 0;
}