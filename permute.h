#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "agenda.h"

typedef struct tableau {
	int size;
	int* t;
} tableau;

typedef struct LinkedListElement //  
{ 
    queue* v;
    struct LinkedListElement *next; 
} element; 

void permuteQueue(queue* q, element** resultat);