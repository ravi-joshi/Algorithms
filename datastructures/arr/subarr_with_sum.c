/*
Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case is N and S, where N is the size of array and S is the sum. The second line of each test case contains N space separated integers denoting the array elements.

Output:
For each testcase, in a new line, print the starting and ending positions(1 indexing) of first such occuring subarray from the left if sum equals to subarray, else print -1.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1010

Example:
Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
Output:
2 4
1 5

Explanation :
Testcase1: sum of elements from 2nd position to 4th position is 12
Testcase2: sum of elements from 1st position to 5th position is 15
*/
#include <stdio.h>

void subarr_with_sum(int a[], int n, int sum)
{
	int b[32] = {0};
	int k = 0;
	int s = 0;
	int f = 0;

	for (int i = 0; i < n; i++) {
		k = 0;
		s = 0;
		for (int j = i; j < n; j++) {
			b[k++] = a[j];
			s += a[j];
			if (s == sum) {
				f = 1;
				printf("sum reached\n");
				goto final;
			}
		}
	}

final:
	if (f) {
		for (int i = 0; i < k; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
	} else {
		printf("subarry not found\n");
	}
}

void main(void)
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(a)/sizeof(a[0]);
	subarr_with_sum(a, n, 99);
}
