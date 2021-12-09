/*
Find elements which are present in first array and not in second
Difficulty Level : Easy
Last Updated : 11 Aug, 2021
Given two arrays, the task is that we find numbers which are present in first array, but not present in the second array. 
Examples : 
 

Input : a[] = {1, 2, 3, 4, 5, 10};
    b[] = {2, 3, 1, 0, 5};
Output : 4 10    
4 and 10 are present in first array, but
not in second array.

Input : a[] = {4, 3, 5, 9, 11};
        b[] = {4, 9, 3, 11, 10};
Output : 5
*/

#include <stdio.h>

// find intersection of the two arrays
void intersection(int a[], int n, int b[], int m) {
	int c[255] = {0};
	for (int i = 0; i < m; i++) {
		c[b[i]] = 1;
	}

	for (int i = 0; i < n; i++) {
		if (c[a[i]] == 1) continue;
		printf("%d ", a[i]);
	}
	printf("\n");
}

void union_arr(int a[], int n, int b[], int m) {
	int c[255] = {0};
	for (int i = 0; i < m; i++) {
		c[b[i]] = 1;
		printf("%d ", b[i]);
	}

	for (int i = 0; i < n; i++) {
		if (c[a[i]] == 1) continue;
		printf("%d ", a[i]);
	}
	printf("\n");
}

void main(void) {
	int a[] = {1,2,3,4,5,6,7,8};
	int n = sizeof(a)/sizeof(a[0]);
	int b[] = {1,2,3,4,5,6,7,8};
	int m = sizeof(b)/sizeof(b[0]);

	intersection(a, n, b, m);
	union_arr(a, n, b, m);
}



