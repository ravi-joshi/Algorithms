/**

Find all pairs with a given sum
Easy Accuracy: 35.71% Submissions: 2185 Points: 2

Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.

Example 1:

Input:
A[] = {1, 2, 4, 5, 7}
B[] = {5, 6, 3, 4, 8} 
X = 9 
Output: 
1 8
4 5 
5 4
Explanation:
(1, 8), (4, 5), (5, 4) are the
pairs which sum to 9.

Example 2:

Input:
A[] = {-1, -2, 4, -6, 5, 7}
B[] = {6, 3, 4, 0} 
X = 8 
Output:
4 4 
5 3

**/

#include <stdio.h>

int sumarr(int a[], int b[], int m, int n, int x) {
	if (m != n) return -1;

	if (m == 1 && n == 1) {
		printf("(%d %d)\n", m, n);
		return 0;
	}

	int sum;

	// all looks good
	for (int i = 0; i < m; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum = a[i] + b[j];
			if (x == sum) {
				printf("(%d %d)\n", a[i], b[j]);
			}			
			sum = 0;
		}
	}
}

void main(void)
{
	int a[] = {1, 2, 4, 5, 7};
	int b[] = {5, 6, 3, 4, 8};
	int m = sizeof(a)/sizeof(a[0]);
	int n = sizeof(b)/sizeof(b[0]);
	int x = 9;
	sumarr(a, b, m, n, x);
}


