#include <stdio.h>
#include <string.h>

void strcmp1(char s1[], char s2[])
{
	int i=0;
	int inequal = 0;

	int n1 = strlen(s1);
	int n2 = strlen(s2);
	if (n1 != n2) {
		printf("strings are not equal\n");
		return;
	}

	// string lengths are equal, can compare now
	while (s1[i] != '\0') {
		if (s1[i] != s2[i]) {
			inequal = 1;
			break;
		}
		i++;
	}
	
	if (inequal)
		printf("strings are inequal\n");
	else
		printf("strings are equal\n");
}

void main(void)
{
	char s1[] = "ravi joshi";
	char s2[] = "ravi Joshi";

	strcmp1(s1, s2);
}

