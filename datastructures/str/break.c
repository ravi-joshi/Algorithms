#include <stdio.h>

void main(void)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j > 5) break;

			printf("j = %d\n", j);
		}
			printf("i = %d\n", i);
	}
}

