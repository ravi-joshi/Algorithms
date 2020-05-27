#include <stdio.h>
#include <string.h>

void reverse(char s1[])
{
	int n = strlen(s1);
	while (n--) {
		printf("%c", s1[n]);
	}
	printf("\n");
}

void rev_inplace(char s[])
{
	int n = strlen(s);
	int i = 0;
#if 0
	while (i < j) {
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
		printf("copying...\n");
	}
#endif
	for (i = 0; i < n/2; i++) {
		char c = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = c;
	}
 
	printf("%s\n", s);
}

void main(void)
{
	char s1[] = "Ravi Joshi";
	rev_inplace(s1);
}
