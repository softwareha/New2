#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n;                     // Number of vertices in the graph
int adj[MAX][MAX];         // Adjacency Matrix
int visited[MAX];          // Array to keep track of visited vertices
int stack[MAX];            // Stack to store the topological ordering
int top = -1;              // Top of the stack

void createGraph() {
    int i, maxEdges, origin, destin;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    maxEdges = n * (n - 1);

    for (i = 1; i <= maxEdges; i++) {
        printf("Enter edge %d (-1 -1 to quit): ", i);
        scanf("%d %d", &origin, &destin);

        if ((origin == -1) && (destin == -1))
            break;

        if (origin >= n || destin >= n || origin < 0 || destin < 0) {
            printf("Invalid edge!\n");
            i--;
        } else
            adj[origin][destin] = 1;
    }
}

void dfs(int vertex) {
    int i;
    visited[vertex] = 1;

    for (i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && visited[i] == 0)
            dfs(i);
    }

    stack[++top] = vertex;
}

void topologicalSort() {
    int i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    top = -1;

    for (i = 0; i < n; i++) {
        if (visited[i] == 0)
            dfs(i);
    }

    printf("Topological Sorting: ");

    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main() {
    createGraph();
    topologicalSort();
    return 0;
}
