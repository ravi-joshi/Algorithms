#include <stdio.h>

 /* Given an array a[] of entirely positive or negative integers, identify
  * the only positive or negative integer in the array
  */

int neg_or_pos(int a[], int n) {
	if (n == 1) return a[0];

	// more than 1 integers in the list
	int p = a[0];
	for (int i = 1; i < n; i++) {
		if ((a[i] > 0 && p > 0) || 
			(a[i] < 0 && p < 0)) {
			p = a[i];
			continue;
		} else if ((a[i] > 0 && p < 0) ||
					(a[i] < 0 && p > 0)) {
			return a[i];
		}
	}
}

void main(void) {
	int a[] = {-1, -2, -3, 4, -5, -6, -7};
	int b[] = {1, 2, 3, -4, 5, 6, 7};

	int n1 = sizeof(a)/sizeof(a[0]);
	int n2 = sizeof(b)/sizeof(b[0]);

	printf("neg_or_pos: %d\n", neg_or_pos(a, n1));
	printf("neg_or_pos: %d\n", neg_or_pos(b, n2));
}

