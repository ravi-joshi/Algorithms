/*
write a program to identify the indices in an array
whose addition will result in the sum

a + b = c
*/

#include <stdio.h>

void sum_idx(int a[], int n, int s)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] + a[j] == s) {
				printf("idx1: %d idx2: %d s: %d\n", i, j, s);
				return;
			}
		}
	}
}

void main(void)
{
	int a[] = {1,2,3,4,5,9,14};
	int n = sizeof(a)/sizeof(a[0]);
	sum_idx(a, n, 14);
}

