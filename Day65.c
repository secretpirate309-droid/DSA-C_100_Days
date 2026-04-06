#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Using DFS and parent tracking, detect if undirected graph has a cycle.


struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct Node* createNode(int d) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = d;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) graph->adj[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adj[dest];
    graph->adj[dest] = newNode;
}

bool isCycleUtil(struct Graph* graph, int v, bool visited[], int parent) {
    visited[v] = true;

    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->dest]) {
            if (isCycleUtil(graph, temp->dest, visited, v))
                return true;
        } else if (temp->dest != parent) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool hasCycle(struct Graph* graph) {
    bool* visited = calloc(graph->V, sizeof(bool));
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (isCycleUtil(graph, i, visited, -1)) {
                free(visited);
                return true;
            }
        }
    }
    free(visited);
    return false;
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);

    if (hasCycle(graph)) printf("Graph contains cycle\n");
    else printf("Graph doesn't contain cycle\n");

    return 0;
}