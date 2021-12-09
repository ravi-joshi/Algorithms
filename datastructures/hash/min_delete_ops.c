/*Minimum delete operations to make all elements of array same
Difficulty Level : Basic
Last Updated : 24 Jun, 2021
Given an array of n elements such that elements may repeat. We can delete any number of elements from the array. The task is to find a minimum number of elements to be deleted from the array to make it equal.
Examples:

Input: arr[] = {4, 3, 4, 4, 2, 4}
Output: 2
After deleting 2 and 3 from array, array becomes 
arr[] = {4, 4, 4, 4} 

Input: arr[] = {1, 2, 3, 4, 5}
Output: 4
We can delete any four elements from array.
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
In this problem, we need to minimize the delete operations. The approach is simple, we count the frequency of each element in an array, then find the frequency of the most frequent elements in count array. Let this frequency be max_freq. To get the minimum number of elements to be deleted from the array calculate n ? max_freq where n is a number of elements in the given array.
*/

/* also print the array elements */

#include <stdio.h>

// approach-1: sort the array and then count the frequency of each elements to determine
// max frequency

// approach-2: save the frequency of each element in the hash table and then determine max frequency

void min_delete(int a[], int n) {
	int b[255] = {0};
	int max_freq = 0;

	for (int i = 0; i < n; i++) {
		b[a[i]]++;
		if (max_freq < b[a[i]]) max_freq = b[a[i]];
	}

	printf("min delete: %d\n", n - max_freq);	
}

void main(void) {
	int a[] = {1,4,4,4,3,4};
	int b[] = {1, 2, 3, 4, 5};
	int n = sizeof(a)/sizeof(a[0]);
	int m = sizeof(b)/sizeof(b[0]);
	min_delete(b, m);
}
