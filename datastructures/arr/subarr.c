/*
Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.
*/

#include <stdio.h>

void subarr(int a[], int n, int s) {
	int b[16] = {0};

	int k = 0;
	for (int i = 0; i < n; i++) {
		int s1 = 0;
		k = 0;
		s1 += a[i];
		b[k++] = a[i];
		for (int j = i+1; j < n; j++) {
			b[k++] = a[j];
			s1 += a[j];
			if (s1 == s) {
				printf("sum with subarry found\n");
				goto print;
			}
		}
	}

	return;

print:
	for (int i = 0; i < k; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
}

void main(void) {
	int a[] = {1, 1, 3, 2, 4, 5, 10};
	int n = sizeof(a)/sizeof(a[0]);
	int sum = 7;

	subarr(a, n, sum);
}
