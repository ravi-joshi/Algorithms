/*
check if the given array is left-rotated or right-rotated
*/

// assumption - the array is sorted and then rotated
// algorithm

// if the array is left-rotated, the n-d+1 element will
// be smaller than nth element

// if the array is right-rotated, d+1th element is smaller
// than dth element

#include <stdio.h>

int left_rotated(int a[], int n)
{
	int lrotated = 0;

	for (int i = 0; i < n; i++) {
		if (a[i+1] < a[i])
			lrotated=1;			
	}

	printf("left rotated (%s)\n", (lrotated) ? "YES" : "NO");
}

int right_rotated(int a[], int n)
{
	int rrotated = 0;
	for (int i = 0; i < n; i++) {
		if (a[i+1
	}
}

void main(void)
{
	int a[] = {5,6,1,2,3,4}; //right rotated by 2
	int b[] = {3,4,5,6,1,2}; //left rotated by 2

	left_rotated(a, sizeof(a)/sizeof(a[0]));
	right_rotated(a, sizeof(a)/sizeof(a[0]));
	left_rotated(b, sizeof(b)/sizeof(b[0]));
	right_rotated(b, sizeof(b)/sizeof(b[0]));
}
