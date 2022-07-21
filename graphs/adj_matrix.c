#include <stdio.h>

#define V 5

void init(int graph[V][V]) {
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++) graph[i][j] = 0;
}

void add_edge(int graph[V][V], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void display(int graph[V][V]) {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V];
    init(graph);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 0);
    add_edge(graph, 2, 3);

    display(graph);
}