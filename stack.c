#include "agenda.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct agendaStr {
    struct QList *top;
};

struct Queue *createQueue() 
{ 
    struct Queue *q = malloc(sizeof(struct Queue)); 
    q->size = 0;
    q->sizeBeforePermut = 0;
    q->front = q->rear = NULL; 
    return q; 
}

agenda createAgenda()
{
    stack* q = malloc(sizeof(struct Stack)); 
    q->top = NULL; 
    return q; 
}

struct QList* newEl(edge* x) 
{
    struct QList *temp = malloc(sizeof(struct QList)); 
    temp->key = x; 
    temp->state= NOT_VISITED;
    temp->next = NULL; 
    return temp;
} 

void enQueue(agenda q, edge* x) 
{
    struct QList* newElement = newEl(x);
    newElement->next = q->top;
    q->top = newElement;
} 


edge* deQueue(agenda q)
{
  struct QList* deletedElement = q->top;
  edge* resultat = q->top->key;
  q->top = q->top->next;
  free(deletedElement);
  return resultat;
} 

int isEmpty(agenda q)
{
  return q->top == NULL;
}

void printQueue(agenda q)
{
    list* it = q->top;
    while(it != NULL){
        printf("%d\n", it->key->destination);
        it = it->next;
    }
}


agenda deepCopy(agenda q)
{
    if(q->top == NULL){
      return createAgenda();
    }
    stack* resultat = createAgenda();
    resultat->top = newEl(q->top->key);
    struct QList* it_copy = resultat->top;
    struct QList* it = q->top;
    while(it->next != NULL){
      it_copy -> next = newEl(it->next->key);
      it_copy = it_copy->next;
      it = it->next;
    }
    return resultat;
}
