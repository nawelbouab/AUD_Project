#include "agenda.h"
#include <stddef.h>

struct agendaStr {
    struct QList *front, *rear;
    int size;
    int sizeBeforePermut;
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
    struct Queue *q = malloc(sizeof(struct Queue)); 
    q->size = 0;
    q->sizeBeforePermut = 0;
    q->front = q->rear = NULL; 
    return q; 
}

//create new element in the list
struct QList* newEl(edge* x) 
{ 
    struct QList *temp = malloc(sizeof(struct QList)); 
    temp->key = x; 
    temp->state= NOT_VISITED;
    temp->next = NULL; 
    return temp;  
} 

//add x to q
void enQueue(agenda q, edge* x) 
{ 
    struct QList *temp = newEl(x); 
    q->size++;
    if (q->rear == NULL) //if queue empty
    { 
       q->front = q->rear = temp; 
       return; 
    } 
    // Add at the end of queue and change rear 
    q->rear->next = temp; 
    q->rear = temp; 
} 


edge* deQueue(agenda q) 
{ 
    if (q->front == NULL){ // queue empty
       printf("Queue Underflow \n");
       return 1; 
     }
    q->size--;
    q->sizeBeforePermut--;
    struct QList *temp = q->front; //move front to the next el
    q->front = q->front->next; 
    edge* returnValue = temp->key;
    free(temp);
   
    if (q->front == NULL) //front==NULL -> rear==NULL
       q->rear = NULL; 
    return returnValue; 
} 

int isEmpty(agenda q) { //check if the queue is empty or no 
	return (q->rear==NULL) ;
}


int fact(int n){
    if (n==1) return 1;
    return n*fact(n-1);
}

void printQueue(agenda q){
    list* it = q->front;
    while(it != NULL){
        printf("%d", it->key->source);
        printf("-");
        printf("%d\n", it->key->destination);
        it = it->next;
    }
}


agenda deepCopy(agenda q){
    if (q == NULL){
        return NULL;
    }
    queue* newQ = createAgenda();
    list* it = q->front;
    while(it!=NULL){
        enQueue(newQ, it->key);
        it=it->next;
    }

    return newQ;

    
}