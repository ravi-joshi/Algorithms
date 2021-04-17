#include <stdio.h>

int add(int a, int b) {
	printf("add, sum: %d\n", a+b);
}

int sub(int a, int b) {
	printf("sub, diff: %d\n", a-b);
}

int mul(int a, int b) {
	printf("mul, prod: %d\n", a*b);
}

void main(void) {
	int (*fnptr[])(int, int) = {add, sub, mul};
	int a = 15, b = 10;
	for (int i =0; i < 3; i++)
		(*fnptr[i])(a, b);
}
