#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void alloc_2d_single_blk(int r, int c)
{
	int *arr = (int *) malloc(sizeof(int) * r * c);
	if (!arr)
		return -ENOMEM;

	// allocation success
	int k = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			//specific location *(arr + i*c +j)
			*(arr + i*c + j) = ++k;
		}
	}

	return 0;
}

int alloc_2d_array_of_ponters(int r, int c)
{
	int *arr[r] = (int *)malloc(sizeof(int) * c);
	if (!arr)
		return -ENOMEM;

	// allocation okay - access as arr[i][j]
	int k = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			//specific location *(arr + i*c +j)
			arr[i][j] = ++k;
			*(*(arr+i) + j) = k;
		}
	}

	return 0;
}

int alloc_2d_array_double_ptr(int r, int c)
{
	int **arr = (int **)malloc(sizeof(int *) * r);
	if (!(*arr))
		return -ENOMEM;

	// allocate row memory
	for (int i = 0; i < r; i++)
		arr[i] = (int*)malloc(sizeof(int) * c);
	if (!arr[i])
		return -ENOMEM;

	// allocation is okay
	int k = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			*(*(arr+i)+j) = k++;
		}
	}
}

void* alloc_2d_single_blk(int r, int c) {
	return malloc(r * c * sizeof(int));
}

void alloc_2d_ptr_arr(int r, int c) {
	void *a[r];
	int k = 0;
	for (int i = 0; i < r; i++)
		a[i] = malloc(c * sizeof(int));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			*((int*)(*(a+i) + j)) = ++k;
			printf("*(*(a+%d) + %d): %d ", i, j, *((int*)(*(a+i) + j)));
		}
		printf("\n");
	}

	// free memory
	for (int i = 0; i < r; i++)
		free(a[i]);
}

void fill_and_print_single_blk(void *a, int r, int c) {
	int k = 0;
	int *p = (int*)a;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			*(p + i*c + j) = ++k;
			printf("p[%d][%d] = %d ", i, j, *(p + i*c + j));
		}
		printf("\n");
	}
}

void main(void) {
	//void *p = alloc_2d_single_blk(3, 3);
	//fill_and_print(p, 3, 3);
	//free(p);
	alloc_2d_ptr_arr(3, 3);
}

