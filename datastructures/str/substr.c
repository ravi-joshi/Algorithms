/*
Recursive function to do substring search
Given a text txt[] and a pattern pat[], write a recursive function “contains(char pat[], char txt[])” that returns true if pat[] is present in txt[], otherwise false.

Examples:

1) Input:   txt[] =  "THIS IS A TEST TEXT"
            pat[] = "TEST"
  Output:  true


2) Input:  txt[] =  "geeksforgeeks"
           pat[] = "quiz"
  Output:  false;
*/

// Algorithm
// if txt[] str is null return false
// if pat[] str is null return false
// if txt[] is smaller than pat[] in length, then return false
// while searching if we are at the last character from txt[]
// but pat[] still has characters left, return false
// compare each character one-by-one and if matches, progress
// to the next character, until they differ or match
// if differ, return false, if matched, return true
#include <stdio.h>
#include <string.h>

int is_substr(char s1[], char s2[])
{
	// compare two strings using the sliding window
	int m = strlen(s1);
	int n = strlen(s2);

	if (n < m) {
		printf("s2 is smaller than s1\n");
		return -1;
	}

	if (n == 1) {
		printf("s2 is an empty string\n");
		return -1;
	}

	for (int i = 0; i < n - m; i++) {
		int j;
		for (j = 0; j < m; j++) {
			if (s2[i+j] != s1[j])
				break;
		}
		if (j == m) return i;
	}

	return -1;
}

void main(void)
{
	char s2[] = "geeksforgeeks";
	char s1[] = "ravij";
	int l = is_substr(s1, s2);
	if (l < 0)
		printf("s1 is not a substr\n");
	else
		printf("s1 is a substr\n");
}

