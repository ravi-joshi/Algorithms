/*
Alternative Sorting
Given an array of integers, print the array in such a way that the first element is first maximum and second element is first minimum and so on.

Examples :

Input : arr[] = {7, 1, 2, 3, 4, 5, 6}
Output : 7 1 6 2 5 3 4

Input : arr[] = {1, 6, 9, 4, 3, 7, 8, 2}
Output : 9 1 8 2 7 3 6 4
*/

// Brute force method
// sort the array
// define two pointers - one at first element and second at the last element
// keep printing elements until the pointers cross

#include <stdio.h>

int sort(int arr[], int sz)
{
	// sort the array
}

int main(void)
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = sizeof(a)/sizeof(a[0]);

	sort(&a[0], size);

	// now we have the sorted array
	for (int i = 0; i < size; i++) {
		printf("%d ", a
	} 
}

