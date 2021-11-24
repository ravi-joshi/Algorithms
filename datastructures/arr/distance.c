/**
Write Test data for the program which finds the distance between 2 given character of a sentence.
SAMPLE INPUT: findDistance("Ajay is here", A, h) => 10
**/

/*
 * assumptions:
 * - only 2 characters are given for calculating the distance
 * - first, second or both characters may not be present in the str
 * - the first and second characters could repeat in the str
 * - calculate the distance only between the first occurance of each
 * - characters.
 * - input string is atleast 2 characters long
 * - search is case sensitive ('a' and 'A' are different)	
 */

#include <stdio.h>
#include <string.h>

int find_distance(char a[], char f, char s) {
	/* function returns the distance between f and s in the input str */
	int n = strlen(a);
	int f_first = 0;
	int s_first = 0;
	int f_loc = 0, s_loc = 0;

	if (n < 2) {
		printf("string is too short (%s)\n", a);
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == f && !f_first) {
			f_first = 1;
			f_loc = i;
		}
		if (a[i] == s && !s_first) {
			s_first = 1;
			s_loc = i;
		}
	}

	printf("s: %u f: %u\n", s_loc, f_loc);
	return (s_loc > f_loc) ? s_loc - f_loc : f_loc - s_loc;
}

void main(void) {
	char a[] = {"Ravi Arun Joshi"};
	char f = 'a';
	char s = 'J';

	int d = find_distance(a, f, s);
	printf("distance: %u\n", d); 
}
