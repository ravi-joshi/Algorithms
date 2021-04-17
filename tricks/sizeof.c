#include <stdio.h>

#define mysizeof(type) ((char*)(&type+1) - (char*)(&type))

void main(void)
{
	int i;
	short s;
	float f;
	char c;
	double d;
	long l;
	long long ll;

	printf("char: %d\n", (int)mysizeof(c));
	printf("short: %d\n", (int)mysizeof(s));
	printf("int: %d\n", (int)mysizeof(i));
	printf("float: %u\n", (int)mysizeof(f));
	printf("double: %u\n", (int)mysizeof(d));
	printf("long: %u\n", (int)mysizeof(l));
	printf("long long: %u\n", (int)mysizeof(ll));
}
