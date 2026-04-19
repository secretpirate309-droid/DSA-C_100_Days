#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

//Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.



#define V 100

int findMinKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

int primMST(int graph[V][V], int n) {
    int key[V];
    bool mstSet[V];
    int totalWeight = 0;

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;

    for (int count = 0; count < n; count++) {
        int u = findMinKey(key, mstSet, n);
        mstSet[u] = true;
        totalWeight += key[u];

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }
    return totalWeight;
}

int main() {
    int n, edges;
    int graph[V][V] = {0};

    if (scanf("%d %d", &n, &edges) != 2) return 0;

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("%d\n", primMST(graph, n));

    return 0;
}