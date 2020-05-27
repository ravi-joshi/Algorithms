/*
Simple binary search algorithm without recursion
*/
#include <stdio.h>
#include <sys/types.h>

int binsearch(int a[], int l, int r, int e)
{
	// simple binary search without recursion
	int mid;
	while (r >= l) {
		mid = l + (r - l)/2;
		if (e == a[mid])
			return mid;

		if (e > a[mid]) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	return -1;
}

void main(void)
{
	int a[] = {0,0,0,0,0,0,1,1,1,1,1,1};
	size_t s = sizeof(a)/sizeof(a[0]);
	int loc = binsearch(a, 0, s, 1);
	printf("the change happens at location: %d\n", loc);
}
