
#include <stdio.h>
#include <stdlib.h>


//Perform DFS starting from a given source vertex using recursion.

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int n;
    struct Node** adj;
};

void dfsRecursive(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adj[vertex];
    while (temp) {
        if (!visited[temp->dest]) {
            dfsRecursive(graph, temp->dest, visited);
        }
        temp = temp->next;
    }
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

int main() {
    int n = 5;
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->n = n;
    graph->adj = malloc(n * sizeof(struct Node*));
    
    for (int i = 0; i < n; i++) graph->adj[i] = NULL;

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    int* visited = calloc(n, sizeof(int));

    printf("DFS Order: ");
    dfsRecursive(graph, 0, visited);

    return 0;
}