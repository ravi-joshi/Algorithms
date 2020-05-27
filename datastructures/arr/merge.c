/*
Merge an array of size n into another array of size m+n
There are two sorted arrays. First one is of size m+n containing only m elements.
Another one is of size n and contains n elements. Merge these two arrays into the
first array of size m+n such that the output is sorted.

Input: array with m+n elements (mPlusN[]).
MergemPlusNNA => Value is not filled/available in array mPlusN[]. There should be n such array blocks.

Input: array with n elements (N[]).
MergeN

Output: N[] merged into mPlusN[] (Modified mPlusN[])
MergemPlusN_Res
*/

// assume both are sorted same (ascending or descending)
// NA elements are marked with special number -1
// arrays don't have negative numbers

// array with m+n size has missing elements and those 
// elements are in array with size m

// loop through the array of size m+n, check if the
// element is -1 and replace with the next element
// array of size m

#include <stdio.h>

void main(void)
{
	int a[] = {-1, 2, -1, -1, 5, 6, -1};
	int b[] = {1, 3, 4, 7};

	int sa = sizeof(a)/sizeof(a[0]);
	int sb = sizeof(b)/sizeof(b[0]);

	if (sa < sb) {
		printf("insufficient array size for merge\n");
		return;
	}

	int i = 0;
	int j = 0;

	while (i < sa) {
		if (a[i] == -1) {
			a[i] = b[j];
			printf("a[%d]=%d ", i, a[i]);
			j++;
		}
		i++;
	}

	//print array
	for (i = 0; i < sa; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}


