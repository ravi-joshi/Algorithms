/*
Move all zeroes to end of array using Two-Pointers

Given an array of random numbers, Push all the zero’s of the given array to the end of the array. For example, if the given arrays is {1, 0, 2, 6, 0, 4}, it should be changed to {1, 2, 6, 4, 0, 0}. The order of all other elements should be the same.

Examples:

Input: arr[]={8, 9, 0, 1, 2, 0, 3}
Output: arr[]={8, 9, 1, 2, 3, 0, 0}
Explanation:

Swap {0 ,1} -> Resulting array {8, 9, 1, 0, 2, 0, 3}
Swap {0 ,2} -> Resulting array {8, 9, 1, 2, 0, 0, 3}
Swap {0 ,3} -> Final array {8, 9, 1, 2, 3, 0, 0}

Input: arr[]={4, 5, 0, 0, 0, 0, 6, 7}
Output: arr[]={4, 5, 6, 7, 0, 0, 0, 0}
*/
#include <stdio.h>

void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}

void swap_zeroes(int arr[], int n)
{
	// have 2 pointers i and j
	// start iteration from i and if zero is
	// encountered, replace it with j pointer
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0 && arr[j] == 0) {
			arr[i] = arr[i] + arr[j];
			arr[j] = arr[i] - arr[j];
			arr[i] = arr[i] - arr[j];
		}
		if (arr[j] != 0) j++;
	}
}

void main(void)
{
	int a[] = {1,0,2,0,3,0,4,0};
	int n = sizeof(a)/sizeof(a[0]);
	swap_zeroes(a, n);
	print(a, n);
}

