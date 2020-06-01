/*
Given a sorted and rotated array, find if there is a pair with a given sum

Given an array that is sorted and then rotated around an unknown point. Find if the array has a pair with a given sum ‘x’.
It may be assumed that all elements in the array are distinct.

Examples :

Input: arr[] = {11, 15, 6, 8, 9, 10}, x = 16
Output: true
There is a pair (6, 10) with sum 16

Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 35
Output: true
There is a pair (26, 9) with sum 35

Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 45
Output: false
There is no pair with sum 45.
*/
#include <stdio.h>

void find_pair(int a[], int n, int sum)
{
	int found = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] + a[j] == sum) {
				printf("pair found (%d, %d)\n", a[i], a[j]);
				found = 1;
				break;
			}
		}
	}

	if (found == 0)
		printf("pair not found\n");
}

void main(void)
{
	int a[] = {11, 15, 26, 38, 9, 10};
	int n = sizeof(a)/sizeof(a[0]);
	find_pair(a, n, 16);
}

