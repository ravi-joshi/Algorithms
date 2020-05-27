/*
 Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements

 arr[] - array of 'n' elements
 d - number of elements to be rotated
*/
#include <stdio.h>

/* first algorithm -
 * needs extra space to save the elements to be rotated
 */

void print_arr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
}

void rotate(int arr[], int d, int n)
{
	int tmp[100];
	int i;

	// save first 'd' elements in temp array
	for (i = 0; i < d; i++) {
		tmp[i] = arr[i];
	}

	// rotate array elements left
	for (i = 0; i < d; i++) {
		for (int j = 0; j < n - 1; j++) {
			arr[j] = arr[j + 1];
		}
	}

	print_arr(arr, n);

	// after rotate, copy the elements from temp array
	int j = 0;
	for (i = n-d; i < n; i++) {
		arr[i] = tmp[j++];
	}

	print_arr(arr, n);
}

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	int d = 2;

	rotate(arr, d, n);

	return 0;
}

