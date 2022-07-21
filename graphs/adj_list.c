#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node *next;
};

struct Graph {
    int numVertices;
    struct Node **adjLists;
};

struct Node *new_node(int vertex) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->vertex = vertex;
    node->next = NULL;

    return node;
}

struct Graph *new_graph(int vericesCount) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

    graph->numVertices = vericesCount;
    graph->adjLists = malloc(vericesCount * sizeof(struct Node *));

    for (int i = 0; i < vericesCount; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void add_edge(struct Graph *graph, int u, int v) {
    struct Node *newNode = new_node(v);
    newNode->next = graph->adjLists[u];
    graph->adjLists[u] = newNode;

    newNode = new_node(u);
    newNode->next = graph->adjLists[v];
    graph->adjLists[v] = newNode;
}

void display(struct Graph *graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        struct Node *node = graph->adjLists[i];
        while (node != NULL) {
            printf("%d ", node->vertex);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph *graph = new_graph(4);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);

    display(graph);
}