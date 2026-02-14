/*
program to implement the undirected graph using the adjacency matrix
*/
#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];      // adjacency matrix
int visited[MAX];       // visited array
int n;                  // number of vertices

/* Function to perform BFS */
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    int i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("BFS Traversal: ");

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

/* Function to perform DFS */
void DFS(int start) {
    int i;

    printf("%d ", start);
    visited[start] = 1;

    for (i = 0; i < n; i++) {
        if (adj[start][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFS(start);

    return 0;
}
