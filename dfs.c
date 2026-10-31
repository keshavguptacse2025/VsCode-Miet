#include <stdio.h>

#define MAX 20

void dfs_util(int adj[MAX][MAX], int n, int u, int visited[MAX]) {
    visited[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfs_util(adj, n, v, visited);
        }
    }
}

void dfs(int adj[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    dfs_util(adj, n, start, visited);
    printf("\n");
}

int main() {
    int n = 5;
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };
    dfs(adj, n, 0);
    return 0;
}
