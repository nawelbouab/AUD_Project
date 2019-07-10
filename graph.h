#ifndef GRAPH
#define GRAPH

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAXIMUM 20

typedef struct edge {
	int source;
	int destination;
	struct edge* next;
} edge;

typedef struct graph {
	int initial;
	int sizeTab;
	struct edge* edges;
} graph;

edge* createEdge(int s, int d);
graph* createGraph(char* t);
void displayGraph(graph* g);

#endif