/*
n = 4

00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33

n = 5

00 01 02 03 04
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 44
*/
#include <stdio.h>

void print(int n)
{
	int i, j;
	/*int arr[5][5] = {{1, 2, 3, 4, 5},
					 {6, 7, 8, 9, 10},
					 {11, 12, 13, 14, 15},
				     {16, 17, 18, 19, 20},
					 {21, 22, 23, 24, 25}};*/
					
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j)
				printf("X");
			else if (i + j == n - 1)
				printf("X");
			else
				printf(" ");
		}
		printf("\n");
	}
}

int main(void)
{
	print(5);
	return 0;
}
