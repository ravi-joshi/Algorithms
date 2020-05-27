/*
implement strstr - substring operation
*/

#include <stdio.h>
#include <string.h>

// algorithm
// The idea is to find the substring in a given string
// both string and substring are known along with their lengths
// brute-force method is to start parsing the mainstring
// and keep comparing the first character of the substr
// if first character is found, then define another loop
// compare rest of the characters

// second method - much simpler

int substr(char s1[], char s2[], int n1, int n2)
{
	int found = 0;

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			if (s1[i+j] != s2[j]) {
				found = 0;
				break;
			} else {
				found += 1;
			}
		}
		if (found == n2)
			return found;
	}

	return found;
}

void main(void)
{
	char s1[] = "ravi joshi";
	char s2[] = "ravi j";
	int r = substr(s1, s2, strlen(s1), strlen(s2));
	if (r)
		printf("substr found\n");
	else
		printf("substr not found\n");
}



