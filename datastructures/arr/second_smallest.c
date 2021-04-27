/**
find out smallest and second smallest in a given array (unsorted)
use single sweep of the array
**/

#include <stdio.h>

void second_smallest(int a[], int n) {
	int small = a[0];
	int ssmall = a[1];
	int t;

	if (small < ssmall) {
		t = ssmall;
		ssmall = small;
		small = t;
	}

	for (int i = 2; i < n; i++) {
		if (a[i] < small)
			small = a[i];
		if (small < ssmall) {
			t = ssmall;
			ssmall = small;
			small = t;
		}
	}
		printf("small: %d ssmall: %d\n", small, ssmall);

}

void main(void) {
	int a[] = { 5, 2, 3, 6, 4, 7};
	second_smallest(a, 5);
}
