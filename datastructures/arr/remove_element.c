/*
Remove an element from an array
*/

#include <stdio.h>

void rem_element(int a[], int n, int m)
{
	// brute force method - using another array
	int b[128];
	int j = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] != m)
			b[j++] = a[i];
	}
}

// method - 2. In the same list
void rem_element2(int a[], int n, int m)
{
	int j = 0;
	int move = 0;

	for (int i = 0; i < n; i++) {
		j = i;
		if (a[i] == m) {
			a[i] = a[i + 1];
			n = n-1;
			move = 1;
		} else if (move) {
			a[i] = a[i+1];
		} else
			a[i] = a[j];
	}
}

void main(void)
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(a)/sizeof(a[0]);
	rem_element2(a, n, 6);

	for (int i = 0; i < n-1; i++)
		printf("%d ", a[i]);

	printf("\n");
}
