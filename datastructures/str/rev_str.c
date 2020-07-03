/*
reverse a given string without reversing the words
the words are seperated by a period (.)

e.g
i/p: india.is.a.great.country
o/p: country.great.a.is.india
*/
#include <stdio.h>
#include <string.h>

void revstr(char s[], int n)
{
	char s1[n+1];
	int j;
	int m = 0;
	int ci = 0; // length copied so far

	char *vptr = strtok(s, ".");
	while (vptr != NULL) {
		int l = strlen(vptr);
		ci += l;
		j = n - ci;
		int k = j - 1;

		for (int i = 0; i < l; i++, j++) {
			s1[j] = vptr[i];
		}

		s1[k] = '.';
		ci++;

		//for (int i = 0; i < l; i++)
		//	printf("%c", s1[i]);
		//printf("\n");

		vptr = strtok(NULL, ".");
	}
	//s1[n+1] = '\0';
	for (int i = 0; i < n; i++)
		printf("%c", s1[i]);

	printf("\n");
}

void main(void)
{
	char s[] = "india.is.a.great.country";
	int n = strlen(s);
	revstr(s, n);
}

