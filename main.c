#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "graphsearch.h"
#include "linkedlisttraversal.h"
#include "linkedlistresultat.h"


int main(int argc, char *argv[] )  {  

	if(argc < 2){  
		printf("No argument passed through command line.\n");  
		return 0;
	} 
	
	char *t = argv[1];
	graph* newGraph = createGraph(t);
	int* tab = malloc(newGraph->sizeTab*sizeof(int));

	for (int i = 0; i < newGraph->sizeTab; ++i)
	{
		tab[i] = NOT_VISITED;
	}

	linkedListTraversal traversal=NULL;
  linkedListResultat resultat=NULL;
  edge* fake_first_node = createEdge(0, newGraph->initial);

	agenda agenda=createAgenda();

  enQueue(agenda,fake_first_node);
  graphsearch(newGraph, agenda, tab, traversal, &resultat, 1);
  printListResultat(resultat);

}
 
 