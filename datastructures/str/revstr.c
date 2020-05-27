#include <stdio.h>
#include <string.h>

void revstr(char *arr, int sz)
{
	if (sz <= 0)
		return;

	// string is valid
	int i = 0;
	int j = sz - 1;

	while (i < j) {
		char c = arr[i];
		arr[i] = arr[j];
		arr[j] = c;
		i++;
		j--;
	}

	printf("%s\n", arr);
}

void main(void)
{
	char arr[]="Ravi Joshi";
	revstr(arr, strlen(arr));
}
