#include <stdio.h>

int main(void)
{

	int arr[10] = {1, 10, 15, 20, 25, 30, 30, 35};
	int i, j;
	int n = 10;

	for (i = 0; i < n-1; i++) {
		if (arr[i] == arr[i+1])
			printf("first repeated num: %u\n", arr[i]);
	}

	return 0;
}
