/*
binary search works best on the sorted list
works on the concept of device-and-conquer
3 pointers identified
low - start of the array
mid - center of the array
high - end of the array

while searching, compare the search element
with the center element, if element is less
than the item being searched, select the right
half (start = mid, end = high), else select
the left half (start = low, end = mid).
continue until the item is identified
*/

#include <stdio.h>

int binary(int a[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l)/2;

		if (a[mid] == x)
			return mid;

		// select left half if element in the mid
		// is higher than x
		if (a[mid] > x)
			binary(a, l, mid-1, x);

		// otherwise the element can be present
		// only in the right half
		binary(a, mid+1, r, x);
	}
}

void main(void)
{
	int a[] = {0, 0, 0, 0, 1, 1, 1};
	int x = 1;
	int n = sizeof(a)/sizeof(a[0]);
	printf("loc: %d\n", binary(a, 0, n-1, x));
}	
