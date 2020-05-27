#include <stdio.h>

int main(void)
{
	int arr[10] = {1, 10, 5, 6, 100, 40, 40, 60};
	int i, j, temp = 0;
	int n = 10;

	for (i = 0; i < n-1; i++) {
		for (j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (i = 0; i < n; i++) printf("%d\n", arr[i]);
	return 0;
}
