#include "graph.h"

edge* createEdge(int s, int d){
	edge* nouv = malloc(sizeof(edge));
	nouv->source=s;
	nouv->destination=d;
	nouv->next=NULL;
	return nouv;
}

graph* createGraph(char* t) {
	int max = 0;
	int father; 
  	int child; 
	int i;
	i=0;
	int edgePossible;
	char str1[MAXIMUM];
	char str2[MAXIMUM];
	
	edge* end;
	edge* new;

	graph* liste = malloc(sizeof(graph));
	liste->initial = 0;
	liste->edges = NULL;

	while(t[i]!= '\0') {
		if ((t[i] < '0' || t[i] > '9') && t[i] != ',' && t[i] != '-'){
			printf("Error : illegal caracter. You have to put only numbers, '-' or ','");
			exit(0);
		}
		edgePossible=0;
		strcpy(str1,"");
		strcpy(str2,"");
		while (t[i]!='-' && t[i]!= '\0'){
			strncat(str1, &t[i], 1);
			i=i+1;
		}

		if (strlen(str1) == 0 || str1[0] == ','){
			printf("Error : please write a correct input");
			exit(0);
		}

		father= atoi(str1);
		if (father > max)
			max=father;
		
		if (t[i]!= '\0')
			i=i+1;

		while(t[i]!=',' && t[i]!= '\0'){
			strncat(str2, &t[i], 1);
			i=i+1;
		}

		if (strlen(str2) > 0){
			edgePossible = 1;
			child = atoi(str2);
			printf("%d-%d \n", father, child);
		
			if (child > max)
				max=child;
		}
		
		if (t[i]!= '\0')
			i=i+1;

		if (edgePossible)
			new = createEdge(father, child);
		
		if (liste->edges == NULL){
			if (edgePossible){
				liste->edges=new;
				end = liste->edges;
			}
            else if (t[strlen(t) - 1] == '-'){ // Check all wrong commands like "1-"
                printf("Error : please write a correct input");
                exit(0);
			}
			liste->initial = father;
		} 
		else {
			if (edgePossible==0){ // Check all wrong commands like "1-2,3", "1-2,3-"
				printf("Error : please write a correct input");
				exit(0);
			}
			end->next=new;
			end=new;

		}
		
	}

	liste->sizeTab=max;

	return liste;
}

void displayGraph(graph* g) {
	edge* e = g->edges;
	printf("Debut display graph");

	while (e != NULL) {
		printf("%d-%d,", e->source, e->destination);
		e = e->next;
	}

	if (g->initial != 0)
		printf("%d-%d", g->initial);
}
