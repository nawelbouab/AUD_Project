// #ifndef QUEUE
// #define QUEUE

// #include <stdlib.h>
// #include <stdio.h>
// #include <stdbool.h>


// #define NOT_VISITED 1
// #define VISITED 3

// typedef struct QList // A linked list (LL) node to store a queue entry 
// { 
//     int key;
//     int state;
//     struct QList *next; 
// } list; 

// // The queue, with 2 pointers front and rear 
// typedef struct Queue 
// { 
//     struct QList *front, *rear; 
//     int size;
//     int sizeBeforePermut;
// } queue; 

// queue* createQueue(); // create a queue
// list* newEl(int x); //create new element in the list
// void enQueue(queue *q, int x); //add x to q
// int deQueue(queue *q); 
// int isEmpty(struct Queue *q);
// int fact(int j);
// queue* deepCopy(queue* q);
// void printQueue(queue* q);

// #endif