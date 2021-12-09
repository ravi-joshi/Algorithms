/* Given an array of size of 'n' and a number 'k', find all elements that appear
 * more than n/k times
 */

#include <stdio.h>

int n_by_k_times(int a[], int n, int k) {
	if (k <= 0) return -1;
	if (n < k) return -1;

	int m = n / k;
	int b[255] = {0};
	int c = 0;

	// naive solution
	for (int i = 0; i < n; i++) {
		int v = 0;
		for (int j = i+1; j < n; j++) {
			if (a[i] == a[j]) {
				v++;
				if (v >= m) {
					b[c++] = a[i];
				}
			}
		}
	}

	if (c > 0) {
		for (int i = 0; i < c; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
	} else {
		printf("no elements found\n");
	}

	return 0;
}

void main(void) {
	int a[] = {3,1,2,2,1,2,3,3};
	int k = 4;
	int n = sizeof(a)/sizeof(a[0]);

	n_by_k_times(a, n, k);	
}

