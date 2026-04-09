#include <stdio.h>
#include <stdlib.h>

//Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#define MAX 100

int main() {
    int n, e;
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    if (scanf("%d %d", &n, &e) != 2) return 1;

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    int topo_order[MAX];

    while (front < rear) {
        int u = queue[front++];
        topo_order[count++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    if (count != n) {
        printf("Cycle detected\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }

    return 0;
}