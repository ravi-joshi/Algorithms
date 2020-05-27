/*
add two numbers without mathematical operator
*/
#include <stdio.h>

int add(int a, int b)
{
	int carry = a & b;
	printf("carry: %d\n", carry);
	return a ^ b;
}

void main(void)
{
	printf("sum: %d\n", add(5, 10));
}

