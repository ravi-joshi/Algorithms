/*
 * Given an array A[] and a number x, check for pair in A[] with sum as x
 */

#include <stdio.h>

// simple in-array approach
void valid_pair(int a[], int n, int x) {
	// run-time complexity of O(m * n)
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == x)
				printf("%d %d\n", a[i], a[j]);
		}	
	}
}

void main(void) {
	int a[] = {1, -1, -3, 4, 5, 6, -8};
	int n = sizeof(a)/sizeof(a[0]);
	int x = 0;

	valid_pair(a, n, x);
}


