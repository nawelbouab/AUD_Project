#include <stdlib.h>
#include <stdio.h>
#include "linkedlisttraversal.h"

linkedListTraversal createListElement(edge* x){
    linkedListTraversal element = (linkedListTraversal) malloc( sizeof(struct node) ); 
    element->next = NULL;
    element->x = x;
    return element;
} 

void printList(linkedListTraversal listeArg){
    linkedListTraversal it = listeArg;
    while(it->next != NULL){
        printf("%d-%d, ", it->x->source, it->x->destination);
        it = it->next;
    }
    printf("%d-%d\n", it->x->source, it->x->destination);
}

linkedListTraversal deepCopyList(linkedListTraversal initial){
    if(initial == NULL){
      return NULL;
    }
    linkedListTraversal copy = createListElement(initial->x);
    linkedListTraversal it_copy = copy;
    linkedListTraversal it = initial;
    while(it->next != NULL){
      it_copy -> next = createListElement(it->next->x);
      it_copy = it_copy->next;
      it = it->next;
    }
    return copy;
}

void addToList(linkedListTraversal* listeArg, edge* valueToAdd){
    if(*listeArg == NULL){
      *listeArg = createListElement(valueToAdd);
      return;
    }
    linkedListTraversal it = *listeArg;
    while(it->next != NULL){
        it=it->next;
    }
    it->next = createListElement(valueToAdd);
}
