#include <stdio.h>

#define MAX_VERTICES 10

void add_edge(int adj[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void print_matrix(int adj[MAX_VERTICES][MAX_VERTICES], int v) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int v = 4;
    int adj[MAX_VERTICES][MAX_VERTICES] = {0};
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 2);
    add_edge(adj, 1, 2);
    add_edge(adj, 2, 3);
    printf("Adjacency Matrix:\n");
    print_matrix(adj, v);
    return 0;
}
