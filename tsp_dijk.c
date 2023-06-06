#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_CITIES 100

int minDistance(int distances[], bool visited[], int cities) {
    int min = INT_MAX, min_index;
    int i;

    for (i = 0; i < cities; i++) {
        if (visited[i] == false && distances[i] <= min) {
            min = distances[i];
            min_index = i;
        }
    }

    return min_index;
}
void printPath(int parent[], int city) {
    if (parent[city] == -1) {
        printf("%d ", city);
        return;
    }

    printPath(parent, parent[city]);
    printf("%d ", city);
}

void dijkstra(int graph[MAX_CITIES][MAX_CITIES], int source, int destination, int cities) {
    int distances[MAX_CITIES]; // Stores the shortest distances from the source to each city
    bool visited[MAX_CITIES];  // Tracks the visited cities
    int parent[MAX_CITIES];    // Stores the parent city of each city in the shortest path
    int i, j;

    for (i = 0; i < cities; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    distances[source] = 0; // Distance from source to source is 0

    for (i = 0; i < cities - 1; i++) {
        int u = minDistance(distances, visited, cities);
        visited[u] = true;

        for (j = 0; j < cities; j++) {
            if (!visited[j] && graph[u][j] && distances[u] != INT_MAX &&
                distances[u] + graph[u][j] < distances[j]) {
                distances[j] = distances[u] + graph[u][j];
                parent[j] = u;
            }
        }
    }
    printf("Shortest path from %d to %d: ", source, destination);
    printPath(parent, destination);
    printf("\nShortest distance: %d\n", distances[destination]);
}

int main() {
    int cities, i, j;
    int source, destination;

    printf("Enter the number of cities: ");
    scanf("%d", &cities);

    int graph[MAX_CITIES][MAX_CITIES];

    printf("Enter the distance matrix:\n");
    for (i = 0; i < cities; i++) {
        for (j = 0; j < cities; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source city: ");
    scanf("%d", &source);

    printf("Enter the destination city: ");
    scanf("%d", &destination);

    dijkstra(graph, source, destination, cities);

    return 0;
}
