#include <stdio.h>

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void main(void)
{
	int a[]  = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(a)/sizeof(a[0]);
	for (int i = 0; i < n-1; i+=2) {
		swap(&a[i], &a[i+1]);
	}

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}
