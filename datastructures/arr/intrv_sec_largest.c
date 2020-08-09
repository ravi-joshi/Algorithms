/*
Next Greater Element

Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1.

Examples:

    For any array, rightmost element always has next greater element as -1.
    For an array which is sorted in decreasing order, all elements have next greater element as -1.
    For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.
*/

/*
Algorithm: 
- use 2 loops
- for every outer loop selected by the loop
- the inner loop will look for the element greater than
- the element selected by the outer loop
*/
#include <stdio.h>

void second_greatest(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		int next = -1;
		for (int j = i+1; j < n; j++) {
			if (a[i] < a[j]) {
				next = a[j];
				break;
			}
		}
		printf("element: %d next: %d\n", a[i], next);
	}
}

void main(void)
{
	int a[] = {11, 13, 21, 3};
	int n = sizeof(a)/sizeof(a[0]);
	second_greatest(a, n);
}

