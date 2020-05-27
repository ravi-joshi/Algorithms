/*
write a program to find the location in an
array that changes from 0 to 1
*/

// algorithm-1: sequential search
#include <stdio.h>

// algorithm-2:
// define 2 pointers, fast and slow
// slow pointer increments by 1
// fast pointer increments by 2
// that way, the array can be traversed in half the time

int loc(int a[], int n)
{
	int slow = 0;
	int fast = 0;
	int j = 0;

	for (slow = 0, fast = 0; slow < n && fast < n; slow++, fast += 2) {
		j++;
		if (a[slow] & 0x1) {
			printf("slow: %d j = %d\n", slow, j);
			break;
		} else if (a[fast] & 0x1) {
			printf("fast: %d j = %d\n", fast, j);
			break;
		}
	}
}

void main(void)
{
	int a[] = {0,1,1,1,1,1,1,1,1,1,1,1};
	int i;
	int n = sizeof(a)/sizeof(a[0]);
	loc(a, n);

#if 0
	for (i=0; i < n; i++) {
		if (a[i] & 0x1) {
			printf("location: %d\n", i);
			break;
		}
	}
#endif
}

/*
int binarysearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l)/2;
		
	if (arr[mid] == x)
		return mid;

	if (arr[mid] > x)
		return binarysearch(arr, l, mid - 1, x);

	return binarysearch(arr, mid+1, r, x);
	}
}
*/
