/*
Find missing element in a sorted array of consecutive numbers
Given an array arr[] of n distinct integers.
Elements are placed sequentially in ascending order with one element missing.
The task is to find the missing element.

Examples:

Input: arr[] = {1, 2, 4, 5, 6, 7, 8, 9}
Output: 3

Input: arr[] = {-4, -3, -1, 0, 1, 2}
Output: -2

Input: arr[] = {1, 2, 3, 4}
Output: -1
No element is missing.
*/
#include <stdio.h>

void element(int a[], int n)
{
	//approach - if the diff between two concecutive
	//elements is more than 1, then that element is
	//a missing element
	int missing = -1;

	for (int i = n; i > 0; i--) {
		if ((a[i] - a[i-1]) > 1) {
			missing = i+1;
			break;
		}
	}
	printf("missing: %d\n", missing);
}

void main(void)
{
	int a[] = {1, 2, 4, 5, 6, 7, 8, 9};
	int n = sizeof(a)/sizeof(a[0]);
	element(a, n);

	int b[] = {-4, -3, -1, 0, 1, 2};
	n = sizeof(b)/sizeof(b[0]);
	element(b, n);

	int c[] = {1, 2, 3, 4};
	n = sizeof(c)/sizeof(c[0]);
	element(c, n);
}

