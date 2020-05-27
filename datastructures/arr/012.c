/*
sort 0, 1 and 2s in ascending order
*/

#include <stdio.h>

void sort(int a[], int n)
{
	int t = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}

void print(int a[], int s)
{
	for (int i = 0; i < s; i++)
		printf("%d\n", a[i]);
}

void main(void)
{
	int a[] = { 0, 2, 1, 0, 2, 2, 1, 2, 0, 0};
	int s = sizeof(a)/sizeof(a[0]);
	sort(a, s);
	print(a, s);
}
