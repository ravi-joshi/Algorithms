/*
Find out an out-of-order element in an almost sorted array
*/

// the idea is to traverse the array and keep
// comparing the element with its' next location to
// identify the out-of-order element
#include <stdio.h>

void ooo(int a[], int n)
{
	if (n <= 1)
		return;

	int i = 0;
	int loc;
	int val;
	int found = 0;

	while (i <  n) {
		if (a[i] > a[i+1]) {
			loc = i;
			val = a[i];
			found = 1;
			break;
		}
		i++;
	}

	if (found)
		printf("loc: %d val:%d\n", loc, val);
}

void main(void)
{
	int a[] = {1, 2, 3, 4, 10, 5, 6, 7, 8, 9};
	int n = sizeof(a)/sizeof(a[0]);
	ooo(a, n);
}
