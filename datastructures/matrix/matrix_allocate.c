/*
allocate memory for 2D-arry and fill the values by accessing
the array elements through pointers
*/

#include <stdio.h>
#include <stdlib.h>

void allocate_2D(int m, int n)
{
	// allocate using single pointer
	int **p = (int**) malloc(sizeof(int*) * m);

	if (p) {
		for (int i = 0; i < m; i++) {
			p[i] = (int*) malloc(sizeof(int) * n);
			if (p[i] == NULL)
				printf("malloc failed\n");
		}
	}

	// fill values using pointers
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			*(*(p + i) + j) = ++count;
			//p[i][j] = ++count;
		}
	}

	// print arr
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	
	// free the allocations
	if (p) {
		for (int i = 0; i < m; i++) {
			free(p[i]);
		}
	}

	free(p);
}

void allocate_3D(int m, int n, int o)
{
	int ***p = (int***) malloc(sizeof(int**) * m);

	for (int i = 0; i < m; i++) {
		p[i] = (int**)malloc(sizeof(int**) * n);
		for (int j = 0; j < n; j++) {
			p[i][j] = (int*) malloc(sizeof(int*) * o);
		}
	}

	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < o; k++) 
				*(*(*(p + i) + j) + k) = ++count;
		}
	}

	// print arr
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < o; k++)
				printf("%d ", p[i][j][k]);
		}
		printf("\n");
	}
	
	// free the allocations
	if (p) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				free(p[i][j]);

			free(p[i]);
		}
	}

	free(p);
}

void main(void)
{
	allocate_3D(3, 3, 3);
}
