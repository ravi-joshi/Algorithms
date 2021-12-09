#include <stdio.h>

/* given an array and sum, identify the pair within the array
 * that can provide the given sum
 */

void pair_with_sum(int a[], int n, int s) {
	if (n <= 1) return;
	
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == s) {
				printf("pair: %d, %d\n", a[i], a[j]);
			}
		}
	}
}

void main(void) {
	int a[] = {0, -1, 2, -3, 1};
	int n = sizeof(a)/sizeof(a[0]);
	int s = -2;
	pair_with_sum(a, n, s);
}

