#include <stdio.h>

void swap(int *a, int *b)
{
	*a = *a + *b; // 15
	*b = *a - *b; // 15 - 10 = 5
	*a = *a - *b; // 15 - 5 = 10;
}

void sort(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(&a[i], &a[j]);
			}
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}

void main(void) {
	int a[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};
	int n = sizeof(a)/sizeof(a[0]);
	sort(a, n);
}
