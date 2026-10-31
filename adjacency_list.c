#include <stdio.h>
#include <stdlib.h>

struct AdjNode {
    int dest;
    struct AdjNode *next;
};

struct Graph {
    int numVertices;
    struct AdjNode **adjLists;
};

struct AdjNode *create_node(int dest) {
    struct AdjNode *newNode = (struct AdjNode *)malloc(sizeof(struct AdjNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph *create_graph(int vertices) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct AdjNode **)malloc(vertices * sizeof(struct AdjNode *));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void add_edge(struct Graph *graph, int src, int dest) {
    struct AdjNode *newNode = create_node(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = create_node(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void print_graph(struct Graph *graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct AdjNode *curr = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (curr) {
            printf("-> %d ", curr->dest);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices = 4;
    struct Graph *graph = create_graph(vertices);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    printf("Adjacency List Representation:\n");
    print_graph(graph);
    return 0;
}
