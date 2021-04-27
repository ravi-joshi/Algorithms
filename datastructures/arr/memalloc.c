/**
allocate 2d and 3d arrays dynamically
**/

#include <stdio.h>
#include <stdlib.h>

void** alloc_2d(int r, int c) {
	void **p = malloc(sizeof(int*) * r);
	if (*p == NULL) {
		return NULL;
	}

	for (int i = 0; i  < r; i++) {
		p[i] = malloc(sizeof(int) * c);
		// ideally check the pointer allocation success here
		if (!p[i]) printf("malloc failed\n");
	}

	return p;
}

void*** alloc_3d(int r, int c, int h) {
	void ***p = malloc(sizeof(int**) * r); // allocate row-wise first
	if (**p == NULL)
		return NULL;

	// allocate column-wise
	for (int i = 0; i < r; i++) {
		p[i] = malloc(sizeof(int*) * c);
		if (p[i]) {
			for (int j = 0; j < c; j++) {
				p[i][j] = malloc(sizeof(int) * h);
				if (!p[i][j])
					printf("malloc failed\n");
			}
		}
	}
}

void random_place(int *a, int m, int n, int x) {
	for (int i = 0; i < m; i++) {
		for (int j =0; j < n; j++) {
			*(*(a+i) + j) = x;
		}
	}
}

void random_place2(int a[][4], int m, int n) {
}

void random_place3(int *a[7], int m, int n) {
}

void random_3d(int a[][][4], int m, int n, int o) {
}

void randon2_3d(int *a, int m, int n, int o) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < o; k++) {
				*(a + a * (n * o) + m * o + c);
			}
		}
	}
}
