/*
Sort an array in wave form
Given an unsorted array of integers, sort the array into a wave like array. An array ‘arr[0..n-1]’ is sorted in wave form if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..
Examples:

 Input:  arr[] = {10, 5, 6, 3, 2, 20, 100, 80}
 Output: arr[] = {10, 5, 6, 2, 20, 3, 100, 80} OR
                 {20, 5, 10, 2, 80, 6, 100, 3} OR
                 any other array that is in wave form

 Input:  arr[] = {20, 10, 8, 6, 4, 2}
 Output: arr[] = {20, 8, 10, 4, 6, 2} OR
                 {10, 8, 20, 2, 6, 4} OR
                 any other array that is in wave form

 Input:  arr[] = {2, 4, 6, 8, 10, 20}
 Output: arr[] = {4, 2, 8, 6, 20, 10} OR
                 any other array that is in wave form

 Input:  arr[] = {3, 6, 5, 10, 7, 20}
 Output: arr[] = {6, 3, 10, 5, 20, 7} OR
                 any other array that is in wave form
*/

/*
 It is possible sort the array first followed by swapping the elements
 */

#include <stdio.h>

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b; 
}

void sort(int a[], int sz)
{
	for (int i = 0; i < sz; i++) {
		for (int j = i + 1; j < sz; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	// array will be sorted after this point
}

void main(void)
{
	int a[]= {1, 2, 7, 8, 34, 23, 8, 10};
	int n = sizeof(a)/sizeof(a[0]);
	sort(a, n);
	// swap the elements here
	for (int i = 0; i < n-1; i+=2) {
		swap(&a[i], &a[i+1]);
	}

	//print elements
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}

