#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

int compare_edges(const void *a, const void *b) {
    struct Edge *e1 = (struct Edge *)a;
    struct Edge *e2 = (struct Edge *)b;
    return e1->weight - e2->weight;
}

int find_root(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find_root(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void union_sets(struct Subset subsets[], int x, int y) {
    int root_x = find_root(subsets, x);
    int root_y = find_root(subsets, y);
    if (subsets[root_x].rank < subsets[root_y].rank) {
        subsets[root_x].parent = root_y;
    } else if (subsets[root_x].rank > subsets[root_y].rank) {
        subsets[root_y].parent = root_x;
    } else {
        subsets[root_y].parent = root_x;
        subsets[root_x].rank++;
    }
}

void kruskal_mst(int v, int e, struct Edge edges[]) {
    qsort(edges, e, sizeof(struct Edge), compare_edges);
    struct Subset *subsets = (struct Subset *)malloc(v * sizeof(struct Subset));
    for (int i = 0; i < v; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    struct Edge result[v];
    int edge_count = 0;
    int i = 0;

    while (edge_count < v - 1 && i < e) {
        struct Edge next_edge = edges[i++];
        int x = find_root(subsets, next_edge.src);
        int y = find_root(subsets, next_edge.dest);
        if (x != y) {
            result[edge_count++] = next_edge;
            union_sets(subsets, x, y);
        }
    }

    printf("Edge \tWeight\n");
    int total_weight = 0;
    for (int j = 0; j < edge_count; j++) {
        printf("%d - %d \t%d\n", result[j].src, result[j].dest, result[j].weight);
        total_weight += result[j].weight;
    }
    printf("Total MST Weight: %d\n", total_weight);
    free(subsets);
}

int main() {
    int v = 4;
    int e = 5;
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    kruskal_mst(v, e, edges);
    return 0;
}
