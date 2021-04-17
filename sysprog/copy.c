#include <stdio.h>

void main(void) {
	unsigned char c;
	unsigned char *p = &c;

	*(p) = 100;
	printf("c = %d\n", c);
}
