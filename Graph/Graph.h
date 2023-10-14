#ifndef GRAPH_C_H
#define GRAPH_C_H

#include <stdio.h>

typedef struct Vertex {
    void* data;
    int index;
} Vertex;

typedef struct Edge {
    int mass;
    Vertex* fVertex;
    Vertex* tVertex;
} Edge;

typedef struct Graph {
    Vertex* start;
    size_t size; 
} Graph;

void new_graph(Graph*);
void new_vertex(Vertex*);
void new_edge(Edge*);

void add_vertex(Graph*, Vertex*, Vertex*);

#endif
