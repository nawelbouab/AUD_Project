#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "permute.h"

tableau* createTable(queue* q){
	list* e=q->front;
	int count=0;
	while(e!=NULL){
		count++;
		e=e->next;
	}

	int *values=malloc(count*sizeof(int));
	int i=0;
	e=q->front;
	while(e!=NULL){
		values[i]=e->key;
		i++;
		e=e->next;
	}

	tableau* tabl = malloc(sizeof(tableau));
	tabl->size=count;
	tabl->t=values;

	return tabl;
}

void printArray(int* a, int length) {
	int i;
	for(i=0;i<length;i++) {
        printf("%d ", a[i]);
	}

}

void swap(int *x, int *y){
	int t;
	t = *x;
  	*x = *y;
  	*y = t;
}

queue* createQueueFromArray(int* a, int length){
	queue* q = createQueue();
	for (int i = 0; i < length ; ++i)
	{
		enQueue(q, a[i]);
	}
	return q;
}

void permuteTable(tableau* n, int i, int length, element** resultat) {
  
  if (length == i){
	//printArray(table_queue,length);
	element* el=malloc(sizeof(element));
	el->v = createQueueFromArray(n->t,length);
	el->next = NULL;
	// printf("Creation permutation\n");
	if(*resultat == NULL){
		//printf("First permutation created\n");
		*resultat = el;
	}
	else{
		element* it=*resultat;
		while(it->next!=NULL){
			it=it->next;
		}
		it->next=el;
	}
	return;
  }

  int j = i;
  for (j = i; j < length; j++) {
	swap(n->t+i,n->t+j);
	permuteTable(n,i+1,length, resultat);
	swap(n->t+i,n->t+j);
  }
  return;
}

void permuteQueue(queue* q, element** resultat){

	tableau* n=createTable(q);
	permuteTable(n, 0, n->size, resultat);
}

// int main(int argc, char const *argv[])
// {
	
// 	queue* q;
// 	q=createQueue();
// 	enQueue(q,1);
// 	enQueue(q,2);
// 	enQueue(q,3);
// 	// enQueue(q,4);
// 	// enQueue(q,5);

	

// 	// tableau *n = createTable(q);

// 	element* resultat= NULL;
// 	permuteQueue(q, &resultat);
// 	element* it=resultat;

// 	//element* first=NULL;
// 	//permuteTable(n, 0, n->size, &first);
// 	//printf("valeur de first : %d\n", first );
// 	// element* it=first;
// 	list* it2=NULL;

// 	while(it!=NULL){
// 	 	it2=it->v->front;
// 	 	printf("Voici une permutation\n");
// 	 	while(it2!=NULL){
// 	 		printf(" %d------ ", it2->key);
// 	 		it2=it2->next;
// 	 	}
// 		it=it->next;
// 	}
	
// 	return 0;
// }

