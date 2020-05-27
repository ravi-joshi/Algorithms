#include <stdio.h>
#include <string.h>

void f_upper(char s[])
{
	int n = strlen(s);
	// use linear search
	while (n-- > 0) {
		if (s[n] >= 'A' && s[n] <= 'Z') {
			printf("%c\n", s[n]);
			break;
		}
	}
}

void r_upper(char s[], int idx)
{
	if (s[idx] == '\0') return;

	if (s[idx] >= 'A' && s[idx] <= 'Z') {
		printf("%c\n", s[idx]);
		return;
	}

	r_upper(s, idx+1);
}

void main(void)
{
	char s[] = "ravI josHi";
	r_upper(s, 0);
}

