/**
check if the given arr is sorted or not
**/

#include <stdio.h>

void sorted(int a[], int n)
{
	// check increasing order
	int sorted = 0;
	for (int i = 0; i < n-1; i++) {
		if (a[i] < a[i+1]) sorted = 1;
		else { sorted = 0; break; }
	}
	if (sorted) { printf("arr is sorted in increasing order\n"); return;}

	sorted = 0;
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i+1]) sorted = 1;
		else {sorted = 0; break; }
	}
	if (sorted) { printf("arr is sorted in decreasing order\n"); return; }

	printf("arr is unsorted\n");
}

void main(void)
{
	int a[] = {5, 4, 3, 2, 1};
	int n = sizeof(a)/sizeof(a[0]);
	sorted(a, n);
}


