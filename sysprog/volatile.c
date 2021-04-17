#include <stdio.h>

typedef unsigned int uint32_t;

volatile uint32_t* const wport = (uint32_t*)0x80000000;
volatile uint32_t* const rport = (uint32_t*)0x80008000;

void read_port(void) {
	uint32_t val = *wport;
	// work with val as needed
	val = 0x55555555;
	*wport = val;
	printf("wport: 0x%d\n", *wport);
}

void write_port(void) {
	uint32_t val = *rport;
	// work with val as needed
	val = 0xFFFFFFFF;
	*rport = val;
	printf("rport: 0x%d\n", *rport);
}

void main(void)
{
	read_port();
	write_port();
}
