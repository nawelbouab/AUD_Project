#ifndef LINKEDLISTTRAVERSAL
#define LINKEDLISTTRAVERSAL

#include "graph.h"

struct node {
  edge* x;
  struct node *next;
};

typedef struct node* linkedListTraversal;

linkedListTraversal createListElement(edge* x);
linkedListTraversal deepCopyList(linkedListTraversal initial);

#endif
