#include <stdio.h>
#include <stdlib.h>

#include <staque.h>

#define ITER_CNT 10

int main ( )
{
	stack S;
	queue Q;
	int i;
	S = initstack();
	for (i=0; i<ITER_CNT; ++i) { S = push(S, rand() % 100); printstack(S); }
	S = destroystack(S);
	Q = initqueue();
	for (i=0; i<ITER_CNT; ++i) { Q = enqueue(Q, rand() % 100); printqueue(Q); }
	Q = destroyqueue(Q);
	exit(0);
}
