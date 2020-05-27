/*
printing all substrings of a string
the algorithm would be to use a sliding scale
on the string to start printing from that
location
*/

#include <stdio.h>
#include <string.h>

void allsubstr(char s[])
{
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			printf("%c", s[j]);
		}
		printf("\n");
	}
}

void main(void)
{
	char s[] = "ravi joshi";
	allsubstr(s);
}
