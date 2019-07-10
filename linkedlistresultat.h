#ifndef LINKEDLISTRESULTAT
#define LINKEDLISTRESULTAT

#include "graph.h"
#include "linkedlisttraversal.h"

struct nodeResultat {
  linkedListTraversal x;
  struct nodeResultat *next;
};

typedef struct nodeResultat* linkedListResultat;

linkedListTraversal createListResultatElement(linkedListResultat x);
void addToListResultat(linkedListResultat* listeArg, linkedListTraversal valueToAdd);

#endif
