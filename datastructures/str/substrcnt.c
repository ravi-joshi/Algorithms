/*
Frequency of a substring in a string
Given a input string and a substring. Find the frequency of occurrences of substring in given string.

Examples:

Input : man (pattern)
        dhimanman (string)
Output : 2

Input : nn (pattern)
        Banana (String)
Output : 0

Input : man (pattern)
        dhimanman (string)
Output : 2

Input : aa (pattern)
        aaaaa (String)
Output : 4


Recommended: Please try your approach on {IDE} first, before moving on to the solution.
A simple solution is to match characters one by one. And whenever we see a complete match, we increment count. Below is simple solution based on Naive pattern searching.
*/
#include <stdio.h>
#include <string.h>

void cntsubstr(char str[], char pat[])
{
	int n = strlen(str);
	int m = strlen(pat);
	int c = 0;

	for (int i = 0; i < n - m; i++) {
		int j;
		for (j = 0; j < m; j++) {
			if (str[i+j] != pat[j])
				break;
		}
		if (j == m) {
			c++;
			j = 0;
		}
	}

	printf("occurance count=%d\n", c);
}

int main(void)
{
	char str[] = "geeksforgeeks";
	char pat[] = "geeks";
	cntsubstr(str, pat);
}
