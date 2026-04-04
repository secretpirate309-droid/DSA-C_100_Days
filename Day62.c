#include <stdio.h>
#include <stdlib.h>


//Build a graph with adjacency list representation. Use linked lists or dynamic arrays.



struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int n;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->n = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int directed) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    if (!directed) {
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->n; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("%d: ", i);
        while (temp) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m, directed;
    if (scanf("%d %d %d", &n, &m, &directed) != 3) return 0;

    struct Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) == 2) {
            addEdge(graph, u, v, directed);
        }
    }

    printGraph(graph);
    return 0;
}