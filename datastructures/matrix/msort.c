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

/* sort the elements of matrix in ascending order */

void print(int n)
{
	int i, j, tmp;
			
	int a[10][10];
	int b[100];
	
	// fill elements O(n2)
	int k = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			b[k++] = a[i][j];
		}
	}
	
	// sort in the flattened matrix O(n2)
	for (i = 0; i < k; i++) {
		for (j = i + 1; j < k; j++) {
			if (b[i] > b[j]) {
				tmp = b[i];
				b[i] = b[j];
				b[j] = tmp;
			}
		}
	}

	// sorted matrix O(n)
	printf("sorted single arr\n");
	for (i = 0; i < k; i++)
		printf("%d ", b[i]);
	
	printf("sorted matrix\n");
	k = 0;
	// matrix refilling O(n2)
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = b[k++];
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	print(3);
	return 0;
}
