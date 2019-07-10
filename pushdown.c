#include "pushdown.h"


int isEmpty(){
	return top==NULL;
}

void push(int data){
	struct Stack_element* temp;
	temp = malloc(sizeof(struct Stack_element));

	if (!temp) { 
        printf("\nHeap Overflow"); 
        exit(1); 
    } 

    temp->data=data;
    temp->next=top;
    top=temp;

}

int pop() {
	struct Stack_element* temp; 

    if (top == NULL) { 
        printf("\nStack Underflow"); 
        exit(1); 
    } 
    else { 
        temp = top; 
        top = top->next; 
        temp->next = NULL; 
        free(temp); 
    } 

}

int peek(){
	if (!isEmpty(top)) 
        return top->data; 
	else
		exit(EXIT_FAILURE);
}

void display() // remove at the beginning 
{ 
    struct Stack_element* temp; 
  
    if (top == NULL) { 
        printf("\nStack Underflow"); 
        exit(1); 
    } 
    else { 
        temp = top; 
        while (temp != NULL) { 
            printf("%d->", temp->data); 
            temp = temp->next; 
        } 
    } 
} 

