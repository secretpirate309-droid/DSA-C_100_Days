#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


//Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

struct Edge {
    int target, weight;
    struct Edge* next;
};

struct Graph {
    int numVertices;
    struct Edge** adjLists;
};

struct Node {
    int vertex, dist;
};

struct PriorityQueue {
    int size;
    struct Node* heap;
};

struct Edge* createEdge(int target, int weight) {
    struct Edge* newEdge = malloc(sizeof(struct Edge));
    newEdge->target = target;
    newEdge->weight = weight;
    newEdge->next = NULL;
    return newEdge;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Edge*));
    for (int i = 0; i < vertices; i++) graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int s, int d, int w) {
    struct Edge* newEdge = createEdge(d, w);
    newEdge->next = graph->adjLists[s];
    graph->adjLists[s] = newEdge;
}

void swap(struct Node* a, struct Node* b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct PriorityQueue* pq, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < pq->size && pq->heap[left].dist < pq->heap[smallest].dist) smallest = left;
    if (right < pq->size && pq->heap[right].dist < pq->heap[smallest].dist) smallest = right;
    if (smallest != i) {
        swap(&pq->heap[i], &pq->heap[smallest]);
        heapify(pq, smallest);
    }
}

void push(struct PriorityQueue* pq, int vertex, int dist) {
    pq->heap[pq->size].vertex = vertex;
    pq->heap[pq->size].dist = dist;
    int i = pq->size++;
    while (i != 0 && pq->heap[(i - 1) / 2].dist > pq->heap[i].dist) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

struct Node pop(struct PriorityQueue* pq) {
    struct Node root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    heapify(pq, 0);
    return root;
}

void dijkstra(struct Graph* graph, int start) {
    int n = graph->numVertices;
    int* dist = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;

    struct PriorityQueue* pq = malloc(sizeof(struct PriorityQueue));
    pq->heap = malloc(n * n * sizeof(struct Node));
    pq->size = 0;

    dist[start] = 0;
    push(pq, start, 0);

    while (pq->size != 0) {
        struct Node top = pop(pq);
        int u = top.vertex;

        if (top.dist > dist[u]) continue;

        struct Edge* temp = graph->adjLists[u];
        while (temp) {
            int v = temp->target;
            int weight = temp->weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(pq, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++) printf("Vertex %d: %d\n", i, dist[i]);
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 2, 6);
    addEdge(graph, 3, 0, 7);
    addEdge(graph, 4, 1, 3);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 4, 3, 2);

    dijkstra(graph, 0);
    return 0;
}