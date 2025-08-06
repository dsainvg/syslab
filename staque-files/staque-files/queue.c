#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue initqueue ( )
{
	queue Q;
	node *p;
	p = (node *)malloc(sizeof(node));
	p -> data = 0;
	p -> next = NULL;
	Q.front = Q.back = p;
	return Q;
}

queue destroyqueue ( queue Q )
{
	node *p;
	while (Q.front) {
		printf("aa\n");
		p = Q.front;
		Q.front = (Q.front) -> next;
		free(p);
	}	
	printf("bb\n");
	Q.front = Q.back = NULL;
	return Q;
}

/* Write the codes below yourself */

int emptyqueue(queue Q)
{
	return 0;
}

int front(queue Q)
{
	return 0;
}

queue enqueue (queue Q, int val)
{
	return Q;
}

queue dequeue(queue Q)
{
	return Q;
}

void printqueue(queue Q)
{
	/* Since there is no enqueue/dequeue code above, print a dummy line only */
	printf("Queue is empty, fill up enqueue/deqeue code first\n");
}
