#include <stdio.h>

/* sort the elements of matrix in ascending order - in place */

void print(int n, int a[][4])
{
	int i, j;
			
	// matrix elements can be sorted either row-wise
	// or col-wise. Let us sort the elements row-wise
	int temp = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (int k = 0; k < n - j - 1; k++) {
				if (a[i][k] > a[i][k+1]) {
					int t = a[i][k];
					a[i][k] = a[i][k+1];
					a[i][k+1] = t;
				}
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int n = 3;
	int a[4][4] = {{3,2,4,1},
				 {12,23,45,1},
				 {2,6,66,56},
				 {23,54,67,3}};
	print(4, a);
	return 0;
}
