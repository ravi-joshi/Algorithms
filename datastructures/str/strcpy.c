#include <stdio.h>
#include <string.h>

void str_cpy(char *s1, char *s2, int n1, int n2)
{
	if (n2 < n1) {
		printf("s2 does not have enough space to copy the string\n");
		return;
	}

	// algorithm is to keep copying character-by-charater from s1 to s2
	while (*s1 != '\0') {
		*s2 = *s1;
		s2++;
		s1++;
		printf("copying...\n");
	}
	*s2 = '\0';
}

void str_cpy2(char s1[], char s2[], int idx)
{
	if (s1[idx] == '\0')
		return;

	printf("copying...\n");
	s2[idx] = s1[idx];
	str_cpy2(s1, s2, idx++);
}

void main(void)
{
	char s1[] = "Ravi Joshi";
	char s2[64];

	str_cpy2(s1, s2, 0);
	printf("s2: %s\n", s2);
}

