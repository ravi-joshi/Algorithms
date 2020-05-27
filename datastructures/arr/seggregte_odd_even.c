/*
Segregate Even and Odd numbers
Given an array A[], write a function that segregates even and odd numbers.
The functions should put all even numbers first, and then odd numbers.
Example:

Input  = {12, 34, 45, 9, 8, 90, 3}
Output = {12, 34, 8, 90, 45, 9, 3}
In the output, the order of numbers can be changed, i.e., in the above example,
34 can come before 12 and 3 can come before 9.
*/

//approach - maintain two pointers odd and even
// even pointer at the beginning and odd at the end
// while taking pass, if the element found is odd,
// it is saved at the odd pointer and vice-versa

//approach2 - maintain another array
// all even elements are saved at the start and odd
// elements at the end
#include <stdio.h>

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void seggregate(int a[], int n)
{
	int i = 0;
	int j = n-1;
	while (i < j) {
		if (a[i] & 0x1) {
			// odd number, swap
			swap(&a[i], &a[j]);
			j--;
		} else
			i++;
	}
}

void seggregate2(int a[], int n)
{
}

void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}

int main(void)
{
	int a[] = {1, 20, 22, 45, 56, 67, 89, 34, 56, 23};
	int n = sizeof(a)/sizeof(a[0]);
	seggregate(a, n);
	print(a, n);
	seggregate2(a, n);
	print(a, n);
}
