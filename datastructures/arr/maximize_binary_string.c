/*
Minimum number of operations required to maximize the Binary String
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void min_operations(char s[], int n)
{
	// the value can be maximized if all 1's
	// in the string are moved to the left
	int cnt1 = 0;
	int cnt0 = 0;
	// simple solution is to count 1's in the
	// string (let us say cnt1) and count number
	// of 0's in the string between 0 and cnt1
	printf("string: %s\n", s);

	for (int i = 0; i < n; i++) {
		if (s[i] == '1')
			cnt1++;
	}

	for (int i = 0; i < cnt1; i++) {
		if (s[i] == '0')
			cnt0++;
	}
	printf("min operations: %d\n", cnt0);
}

void min_operations2(char s[], int n) {
	int cnt1 = 0;
	int cnt2 = 0;
	int ans = 0;

	int i = 0;
	int j = n - 1;

	printf("string: %s\n", s);
	for (; i < j; i++, j--) {
		if (s[i] == '0' && s[j] == '1') {
			ans++;
			i++;
			j--;
		}
		if (s[i] == '0')
			i--;
		if (s[j] == '1')
			j++;
	}
	printf("count: %d\n", ans);
}

void main(void)
{
	char s[] = "10001100";
	int n = strlen(s);
	min_operations2(s, n);
}
