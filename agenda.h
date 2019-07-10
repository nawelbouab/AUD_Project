#ifndef QUEUE
#define QUEUE

#include "graph.h"

struct agendaStr;
typedef struct agendaStr * agenda;

#define NOT_VISITED 1
#define VISITED 3

typedef struct QList // A linked list (LL) node to store a queue entry 
{ 
    edge* key;
    int state;
    struct QList *next; 
} list; 

// The queue, with 2 pointers front and rear 
typedef struct Queue 
{ 
    struct QList *front, *rear; 
    int size;
    int sizeBeforePermut;
} queue; 

typedef struct Stack {
    struct QList *top;
} stack;

void enQueue(agenda q, edge* x);
edge* deQueue(agenda q);
int isEmpty(agenda q);
agenda deepCopy(agenda q);
void print(agenda q);

queue* createQueue(); // create a queue
list* newEl(edge* x); //create new element in the list

#endif