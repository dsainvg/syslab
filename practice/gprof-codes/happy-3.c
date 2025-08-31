#include <stdio.h>
#include <stdlib.h>

int p_cnt;

int *init(int n)
{
	int *p, size = 1000;
	p = (int *)malloc(size*sizeof(int));
	p_cnt = 0;
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
	int i = 0;
	while (i < p_cnt) {
		if (A[i] == n) return 1;
		else i++;
	}
	return 0;
}

void markvisited (int *A, int n)
{
	A[p_cnt] = n;
	p_cnt++;
}

int ishappy(int n)
{
	int *A;
	A = init(n);
	n = nextnum(n);
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
		if (ishappy(n)) printf("%d is a happy number\n", n);
}

