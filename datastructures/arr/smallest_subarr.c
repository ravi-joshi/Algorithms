/**

Smallest subarray with sum greater than x
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

Example 1:

Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is 
{4, 45, 6}


Example 2:

Input:
A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Explanation:
Minimum length subarray is {10}

**/

#include <stdio.h>

int subarr(int a[], int n, int x) {
	int b[32] = {0};
	int k = 0;
	int s = 0;

	if (n <= 0) return -1;
	if (n == 1) return 1;

	for (int i = 0; i < n; i++) {
		s = 0;
		s += a[i];

		for (int j = i + 1; j < n; j++) {
			s += a[j];
			if (s > x) b[k++] = i+j;
		}
	}

	// find the smallest
	int t = b[0];
	for (int i = 1; i < n; i++) {
		printf("b[%d]: %d\n", i, b[i]);
		if (t > b[i]) t = b[i];
	}
	printf("min arr size: %d\n", t);
}

void main(void)
{
	int a[] = {1, 4, 45, 6, 0, 19};
	int b[] = {1, 10, 5, 2, 7};
	int n = sizeof(b)/sizeof(b[0]);
	int x = 9;
	subarr(b, n, x);
}

