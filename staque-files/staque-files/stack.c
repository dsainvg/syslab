#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack initstack ( )
{
	stack S;
	S = (stack)malloc(sizeof(node));
	S -> data = 0; S -> next = NULL;
	return S;
}

stack destroystack ( stack S )
{
	node *p;
	while (S) {
		p = S; S = S -> next; free(p);
	}	
	return NULL;
}

int emptystack(stack S)
{
	if (S == NULL) return 1;
	else return 0;
}

int top(stack S)
{
	/* assumes stack is not empty is checked already */
	return (S->data);
}

stack push (stack S, int val)
{
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->data = val; temp->next = S;
	return temp;
}

stack pop(stack S)
{
	/* assumes stack is not empty is checked already */
	node *temp = S->next;
	free(S);
	return (temp);
}

void printstack ( stack S )
{
	node *p;
	printf("The contents of the stack (from top) is: ");
	while (S) {
		p = S; 
		printf("%d  ", p->data);
		S = S -> next; 
	}	
	printf("\n\n");
}
