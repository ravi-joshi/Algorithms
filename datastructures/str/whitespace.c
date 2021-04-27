/**
remove white space from the string
1. in-place - space constraint
2. additional memory - time constraint
**/

#include <stdio.h>

void rem_space(char *s) {
	char x[128] = {0};
	int j = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] != ' ') {
			x[j++] = s[i];
		}
	}
	printf("%s\n", x);
}

void main(void)
{
	rem_space("ravi joshi");
}

