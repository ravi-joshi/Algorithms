#include <stdio.h>

void foo(int *a) {
	int b = 1;
	if (a < &b)
		printf("increasing stack\n");
	else
		printf("decreasing stack\n");
		
}

void main(void) {
	int a = 0;
	foo(&a);
}
