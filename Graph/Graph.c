#include <stdio.h>

#include "Graph.h"

void new_graph(Graph* p_graph) {
    p_graph->start = NULL;
    p_graph->size = 0;
}

void new_vertex(Vertex* p_vertex) {
    p_vertex->data = NULL;
    p_vertex->index = -1;
}

void new_edge(Edge* p_edge, Vertex* fVertex, Vertex* tVertex) {
    p_edge->mass = 0;
    p_edge->fVertex = fVertex;
    p_edge->tVertex = tVertex;
}

void add_vertex(Graph* p_graph, Vertex* fVertex, Vertex* tVertex) {
    if (p_graph->size == 0) {
        p_graph->start = fVertex;
        Edge* st_edge; new_edge(st_edge, p_graph->start, tVertex);
        ++p_graph->size;
    }
}




