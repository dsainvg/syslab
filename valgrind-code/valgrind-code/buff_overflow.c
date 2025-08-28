#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int n = 16, i, *A;
	A = (int *)malloc(n * sizeof(int));
	printf("A starts at %p, and ends at %p\n", A, A+n-1);
	for (i=1; i<=n; ++i) A[i] = i * i;
	for (i=1; i<=n; ++i) printf("%d ", A[i]);
	printf("\n");
	free(A);
	exit(0);
}
