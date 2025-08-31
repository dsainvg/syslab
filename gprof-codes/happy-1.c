#include <stdio.h>
#include <stdlib.h>

int *init(int n)
{
	int *p, size, i;
	if (n <100) size = 200;
	else size = n+1;
	p = (int *)malloc(size*sizeof(int));
	for(i=0; i<size; i++) p[i] = 0;
	return p;
}

int nextnum(int n)
{
	int sum = 0, d;
	while (n != 0)
	{
		d = n%10;
		sum += d*d;
		n = n/10;
	}
	return sum;
}

int isvisited (int *A, int n)
{
	if (A[n] == 1) return 1;
	else return 0;
}

void markvisited (int *A, int n)
{
		A[n] = 1;
}

int ishappy(int n)
{
	int *A;
	A = init(n);
	markvisited(A, n);
	while(1){
		n = nextnum(n);
		if (!isvisited(A, n)) {
			markvisited(A, n);
			continue;
		}
		if (n==1) return 1; 
		else return 0;
	}
}

int main()
{
	int n;
	for(n=1; n<=100000; n++)
	{
		if (ishappy(n)) printf("%d is a happy number\n", n);
	}
}

