/*
write a program to identify the array elements in such a way
that a + b = c. Where a,b,c are indicicies of array elements
*/

#include <stdio.h>

void sum3(int a[], int n)
{
	int j;
	int k;
	for (int i = 2; i < n; i++) {
		j = i - 1;
		k = i - 2;
		if (a[j] + a[k] == a[i]) {
			printf("n1: %d n2: %d n3: %d\n", a[j], a[k], a[i]);
		}
	}
}

void main(void)
{
	int a[] = {1,2,3,5,6,7,13};
	int n = sizeof(a)/sizeof(a[0]);
	sum3(a, n);
}
