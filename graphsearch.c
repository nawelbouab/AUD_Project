#include "graphsearch.h"
#include "permute.h"
#include <stdbool.h>

void graphsearch(graph* g, 
                 agenda q, 
                 int* tab, 
                 linkedListTraversal traversal, 
                 linkedListResultat* resultat,
                 bool first_run){
	edge* e = g->edges;
	if(isEmpty(q)){
    addToListResultat(resultat, traversal);
		return;
	}

  /*
   * We continue dequeueing from agenda as log as
   * we encounter a node previously visited.
  */
  int s;
  edge* edge_element;
  do {
    edge_element = deQueue(q);
    s = edge_element->destination;
  } while(tab[s - 1] == VISITED && !isEmpty(q));

  /*
   * We add the traversal the the results 
   * if the last element was a duplicate, 
   * thus we didn't make a recursive call.
  */
  if(tab[s - 1] == VISITED && isEmpty(q)){
    addToListResultat(resultat, traversal);
    return;
  }
  /* 
   * We add the current node to the result
   * and we mark it as visited.
  */
  if(!first_run){
	  addToList(&traversal, edge_element);
  }
  tab[s - 1] = VISITED;

  /*
   * We create a list of children of the current node
  */
	queue* children = createQueue();
  edge* edges_it = g->edges;
	while (edges_it != NULL) {
		if(edges_it->source == s && tab[edges_it->destination - 1] == NOT_VISITED) {
			enQueue(children, edges_it);
		}
		edges_it = edges_it->next;
	}

  /*
   * We create a list of all permutations and store it
   * into the variable `children_permutations`
  */
	element* children_permutations= NULL;
	permuteQueue(children, &children_permutations);

  /*
   * We iterate on all the permutations and call
   * graphsearch on each of them.
  */
	element* it=children_permutations;
	while(it!=NULL){
    // we clone the queue
		agenda clonedQueue = deepCopy(q);
    // we clone the traversal
		linkedListTraversal clonedtraversal = deepCopyList(traversal);
    // we clone the visited tab
		int* clonedTab = malloc(g->sizeTab*sizeof(int));
		for (int i = 0; i < g->sizeTab; ++i)
		{
			clonedTab[i] = tab[i];
		}
    // we clone the current permutation 
		children = it->v;
		while(!isEmpty(children))
			enQueue(clonedQueue,deQueue(children));
    //we make the recursive call
		graphsearch(g,clonedQueue, clonedTab, clonedtraversal, resultat, 0);
		it = it->next;
	}
}