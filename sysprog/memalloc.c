/*
allocate memory for 2d, 3d and 4d arrays
*/
#include <stdio.h>
#include <stdlib.h>

void** alloc_2d_array(int r, int c)
{
	void **arr;

	// allocate memory row-wise first
	arr = malloc(sizeof(int*) * r);

	for (int i = 0; i < r; i++) {
		arr[i] = malloc(sizeof(int) * c);
	}

	return arr;
}

void*** alloc_3d_array(int r, int c, int h)
{
	void ***p = malloc(sizeof(int **) * r);
	if (p) {
		for (int i = 0; i < r; i++) {
			p[i] = malloc(sizeof(int *) * c);
			if (p[i]) {
				for (int j = 0; j < c; j++) {
					p[i][j] = malloc(sizeof(int) * h);
				}
			}
		}
	}

	return p;
}

void**** alloc_4d_array(int r, int c, int h, int d)
{
	void ****p = malloc(sizeof(int ***) * r);
	if (p) {
		for (int i = 0; i < r; i++) {
			p[i] = malloc(sizeof(int **) * c);
			if (p[i]) {
				for (int j = 0; j < c; j++) {
					p[i][j] = malloc(sizeof(int *) * h);
					if (p[i][j]) {
						for (int k = 0; k < h; k++) {
							p[i][j][k] = malloc(sizeof(int) * d);
						}
					}
				}
			}
		}
	}

	return p;
}

void main(void)
{
}
