#ifndef BFS
#define BFS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "agenda.h"
#include "linkedlisttraversal.h"
#include "linkedlistresultat.h"

typedef agenda;

void graphsearch(graph* g, 
                 agenda q, 
                 int* tab, 
                 linkedListTraversal traversal, 
                 linkedListResultat* resultat,
                 bool first_run);

#endif

