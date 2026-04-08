#include <stdio.h>
#include <stdlib.h>

//Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.



#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int v;

void push(int item) {
    stack[++top] = item;
}

int pop() {
    return stack[top--];
}

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < v; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }
    push(node);
}

void topological_sort() {
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    while (top != -1) {
        printf("%d ", pop());
    }
}

int main() {
    int e, u, start;
    scanf("%d %d", &v, &e);
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            adj[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &start);
        adj[u][start] = 1;
    }
    topological_sort();
    return 0;
}