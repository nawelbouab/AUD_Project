#include <stdlib.h>
#include <stdio.h>
#include "linkedlistresultat.h"

linkedListTraversal createListResultatElement(linkedListResultat x){
    linkedListTraversal element = (linkedListTraversal) malloc( sizeof(struct nodeResultat) ); 
    element->next = NULL;
    element->x = x;
    return element;
} 

void printListResultat(linkedListResultat listeArg){
    linkedListTraversal it = listeArg;
    while(it != NULL){
        printList(it->x);
        it = it->next;
    }
}

bool isDuplicate(linkedListResultat listeArg, linkedListTraversal valueToAdd){
    if(listeArg == NULL){
      return false;
    }
    linkedListResultat it_dup = listeArg;
    while(it_dup != NULL){
        linkedListTraversal current_traversal = it_dup->x;
        linkedListTraversal it = valueToAdd;

        while(current_traversal->next != NULL && 
              it->next != NULL){
          if(current_traversal->x->source != it->x->source || 
             current_traversal->x->destination != it->x->destination){
               break;
             }
          current_traversal = current_traversal->next;
          it = it->next;
        }
        if(it->next == NULL && current_traversal->next == NULL){
          return true;
        }
        it_dup=it_dup->next;
    }
    return false;
}

void addToListResultat(linkedListResultat* listeArg, linkedListTraversal valueToAdd){
    if(isDuplicate(*listeArg, valueToAdd)){
      return;
    }
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