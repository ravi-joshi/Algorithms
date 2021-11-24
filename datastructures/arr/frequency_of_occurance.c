/*
 amazon-interview-questions
 Program to find the frequency of each element in the array OR write a program to count the
 occurrence of each number in a given string.
*/

#include <stdio.h>

void find_freq(int a[], int n) {
	int count = 0;
	int fr[n];
	int visited = -1;

	for (int i = 0; i < n; i++) {
		count = 1;
		for (int j = i+1; j < n; j++) {
			if (a[i] == a[j]) {
				count++;
				fr[j] = visited;
			}
		}
		if (fr[i] != visited)
			fr[i] = count;
	}

	for (int i = 0; i < n; i++) {
		if (fr[i] != visited)
			printf("a[%d]: %d\n", a[i], fr[i]);
	}
}

void main(void) {
	int a[] = {1,1,2,2,2,1,4,3,5,6,2,1,3,4,6};
	int n = sizeof(a)/sizeof(a[0]);
	find_freq(a, n);	
}
