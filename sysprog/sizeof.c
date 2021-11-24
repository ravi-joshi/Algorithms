#include <stdio.h>

void main(void) {
	int r = 3, c = 4;
	printf("sizeof(int): %lu\n", sizeof(int));
	printf("sizeof(int*) * r: %lu\n", sizeof(int) * r);
	printf("sizeof(int**): %lu\n", sizeof(int));
}
