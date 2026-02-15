/*
pgit add prog_7.crogram to implement Dijkstra's Algorithm to find the shortest path from a source vertex to all other vertices in a weighted graph
*/

#include <stdio.h>

#define MAX 10
#define INF 9999

int minDistance(int dist[], int visited[], int n) {
    int min = INF;
    int min_index = -1;
    int i;

    for (i = 0; i < n; i++) {
        if (visited[i] == 0 && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int dist[MAX];
    int visited[MAX];
    int i, j;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] &&
                graph[u][j] != 0 &&
                dist[u] != INF &&
                dist[u] + graph[u][j] < dist[j]) {

                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", start);
    for (i = 0; i < n; i++) {
        printf("To vertex %d = %d\n", i, dist[i]);
    }
}

int main() {
    int graph[MAX][MAX];
    int n, i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}
