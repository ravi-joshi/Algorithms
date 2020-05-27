/*
Sort an almost sorted array where only two elements are swapped
Given an almost sorted array where only two elements are swapped, how to sort the array efficiently?
Examples :

Input:  arr[] = {10, 20, 60, 40, 50, 30}  
// 30 and 60 are swapped
Output: arr[] = {10, 20, 30, 40, 50, 60}

Input:  arr[] = {10, 20, 40, 30, 50, 60}  
// 30 and 40 are swapped
Output: arr[] = {10, 20, 30, 40, 50, 60}

Input:   arr[] = {1, 5, 3}
// 3 and 5 are swapped
Output:  arr[] = {1, 3, 5}
Expected time complexity is O(n) and only one swap operation to fix the array.
*/

// Since only one swap is allowed and only one sweep through
// the array is allowed, this needs to be done carefully
// Array is almost sorted, so the elements are in increasing order
// sweep through the array and compare the elements with next element
// record the element if OoO and reach until the end.

#include <stdio.h>

void sort(int a[], int n)
{
	int i = 0;
	int found = 0;
	int loc1 = 0, loc2 = 0;

	while (i < n-1) {
		if (a[i] > a[i+1]) {
			found = 1;
			loc1 = i;
		} else if ((a[i] > a[i+1]) && found == 1) {
			loc2 = i;
		}
		i++;
	}

	if (found) {
		int temp = a[loc1];
		a[loc1] = a[loc2];
		a[loc2] = a[loc1];
	}
}

void main(void)
{
	int a[] = {1, 2, 3, 4, 5, 10, 7, 8, 9, 6};
	int n = sizeof(a)/sizeof(a[0]);

	sort(a, n);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}

