#include <stdio.h>
#include <stdlib.h>


int main ()
{
	int *p, *q;
	p = (int *)malloc(10 * sizeof(int));
	q = p + 5;
	p = (int *)malloc(5 * sizeof(int));
	exit(0);
}
