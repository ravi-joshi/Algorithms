/*
allocate memory for 2d, 3d and 4d arrays
*/
#include <stdio.h>
#include <stdlib.h>

/*	2D- array

	arr -> points to the series of rows
	(arr + i) -> points to the 'i'th row of the matrix
	*(arr + i) -> points to the base address of the 'i'th row
	*(arr + i) + j -> address of 'j'th element in the 'i'th row
	*(*(arr + i) + j) -> 'j'th element in the 'i'th row
*/

void** alloc_2d_array(int r, int c)
{
	// allocate memory blocks for rows of each 2D array
	// we are allocating memory to series of integer pointers
	// hence the size of integer
	void **arr = malloc(sizeof(int*) * r);

	for (int i = 0; i < r; i++) {
		// allocate memory blocks for columns of each 2D array	
		arr[i] = malloc(sizeof(int) * c);
	}

	return arr;
}

/* 3D array
	arr -> points to the series of 2D arrays
	(arr + i) -> points to 'i'th 2D array
	*(arr + i) -> points to the base address of 'i'th 2D array. '0'th location of first row of 'i'th 2D array
	*(arr + i) + j -> points to the 'j'th 1D array of the 'i'th 2D array
	*(*(arr + i) + j) -> base addr of the 'j'th 1D array of the 'i'th 2D array
	*(*(arr + i) + j) + k -> points to the 'k'th element in the 'j'th row of 'i'th 2D array
	*(*(*(arr + i) + j) + k) -> value of the 'k'th element in the 'j'th row of 'i'th 2D array
*/

void*** alloc_3d_array(int h, int r, int c)
{
	void ***p = malloc(sizeof(int**) * h); // a -> num of 2D arrays
	// using size of pointer to the pointer to denote that the
	// pointer is pointing to the 2D arrays

	if (p) {
		for (int i = 0; i < h; i++) {
			p[i] = malloc(sizeof(int*) * r);
			if (p[i]) {
				p[i][j] = malloc(sizeof(int) * h);
				if (!p[i][j]) {
					// free p[i]
					// free p
					// return
				}
			}
		}
	}


	// do operation with p
	// free p[i][j]
	// free p[i]
	// free p

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
