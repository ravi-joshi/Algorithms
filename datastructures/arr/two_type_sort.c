/*
Sort an array containing two types of elements
We are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array. Traverse array only once.

Examples:

Input :  arr[] = [0, 1, 0, 1, 0, 0, 1, 1, 1, 0] 
Output : arr[] = [0, 0, 0, 0, 0, 1, 1, 1, 1, 1] 

Input :  arr[] = [1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1] 
Output : arr[] = [0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1] 
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
We have already discussed a solution Segregate 0s and 1s in an array



In this post, a new solution is discussed.

Step 1 : Here we can take two pointers type0 (for element 0) starting from beginning (index = 0) and type1 (for element 1) starting from end index.

Step 2: We intend to put 1 to the right side of the array. Once we have done this then 0 will definitely towards left side of array to achieve this we do following.
We compare elements at index type0
1) if this is 1 then this should be moved to right side so we need to swap this with index type1 once swapped we are sure that element at index type1 is ‘1’ so we need to decrement index type1
2) else it will be 0 then we need to simple increment index type0
*/

#include <stdio.h>

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void sort(int a[], int n)
{
	if (n < 1)
		return;

	int i = 0;
	int j = n-1;

	while (i < j) {
		if (a[i] == 1) {
			swap(&a[i], &a[j]);
			j--;
		} else {
			i++;
		}
	}
}

void main(void)
{
	int a[] = {0, 1, 0, 0, 0, 1, 1, 0};
	int n = sizeof(a)/sizeof(a[0]);
	sort(a, n);

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}
