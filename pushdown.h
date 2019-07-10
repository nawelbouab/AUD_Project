#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Stack_element 
{ 
    int data; 
    struct Stack_element* next; 
} stack; 

struct Stack_element* top;

void push(int data); //Insert the element into linked list nothing but which is the top node of Stack
int pop();//Return top element from the Stack and move the top pointer to the second node of linked list or Stack
int peek(); // Return the top element.
void display(); //Print all element of Stack.


