/*
Sort an array of 0s, 1s and 2s
Given an array A[] consisting 0s, 1s and 2s. The task is to write a function that sorts the given array.
The functions should put all 0s first, then all 1s and all 2s in last.

Examples:

Input: {0, 1, 2, 0, 1, 2}
Output: {0, 0, 1, 1, 2, 2}

Input: {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}
Output: {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}
*/

// approach1 - try with simple ascending order sorting
// approach2 - count number of 0, 1 and 2s and appropriately fill the array
// approach3 - use similar approach as seggregating 0s and 1s

#include <stdio.h>

void sort(int a[], int n)
{
	int temp;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void sort2(int a[], int n)
{
	// count number of 0s and 1s and fill remaining with 2s
	int zeroes = 0;
	int ones = 0;
	int i;

	for (i = 0; i < n; i++) {
		if (a[i] == 0) zeroes++;
		else if (a[i] == 1) ones++;	
	}

	for (i = 0; i < zeroes; i++)
		a[i] = 0;

	for (i = zeroes; i < (n - zeroes); i++)
		a[i] = 1;

	for (i = (n-zeroes); i < n; i++)
		a[i] = 2; 
}

void print_arr(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}

void main(void)
{
	int a[] = {0, 2, 1, 1, 2, 0, 0, 1, 1, 2, 2, 0};
	int n = sizeof(a)/sizeof(a[0]);

	sort2(a, n);

	print_arr(a, n);
}
