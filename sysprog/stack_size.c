#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	unsigned int a;
	unsigned int *b = malloc(sizeof(int));

	printf("a: %p b: %p\n", (void*)&a, (void*)b);
	free(b);
}
