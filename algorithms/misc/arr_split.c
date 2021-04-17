#include <stdio.h>
#include <stdbool.h>

bool foo(int a[], int n)
{
	int left = 0;

	for (int i = 0; i < n; i++) {
		left += a[i];

		int right = 0;
		for (int j = i+1; j < n; j++) {
			right += a[j];
		}
		if (left == right) return true;
	}

	return false;
}

void main(void)
{
	//int a[] = {1, 1, 3};
	int a[] = {10, 1, 1, 3, 2, 1, 2};
	int n = sizeof(a)/sizeof(a[0]);
	printf("ret: %d\n", foo(a, n));
}
