/*
 * Find whether an array is a subset of another array
 */

#include <stdio.h>

int subset(int a[], int n, int b[], int m) {
	// n - length of a[]
	// m - lenght of b[]

	// hashing is the best method for this
	// let us start with simple comparison
	int i, j;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			// compare every element of a[] with all the elements of b[]
			// if the element is found, it is good to pick the next element
			// for comparison
			if (b[i] == a[j]) break;
		}

		// when the above loop was run all the way, the element was not found
		// obviously, the subarry comparison fails
		if (j == n) return 0;
	}

	return 1;
}

int sortnsearch(int a[], int m, int b[], int n) {
	return 0;
}

int hashset(int a[], int n, int b[], int m) {
	// using simple hashset and assume max elements 255
	int hash[255] = {0};

	for (int i = 0; i < n; i++) {
		// save all elements from a[]
		hash[a[i]] = a[i];
	}

	// loop through second array to check the collission
	for (int i = 0; i < m; i++) {
		if (hash[b[i]] == 0) return 0;
	}

	return 1;
}

void main(void) {
	int a[] = {1, 2, 4, 7, 10, 23};
	int n = sizeof(a)/sizeof(a[0]);
	int b[] = {11, 17, 3};
	int m = sizeof(b)/sizeof(b[0]);

	int ret = hashset(a, n, b, m);

	if (ret) {
		printf("b is a subset of a\n");
	} else {
		printf("b is not a subset of a\n");
	}
}
