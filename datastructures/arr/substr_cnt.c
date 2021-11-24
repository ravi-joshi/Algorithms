/**
 * Given a string and refstring, count number of occurances of each common
 * characters between the two
 */

/**
 * str - "India is a great country"
 * ref_str - "In the lake"
 * I:2 n:1 t:1 a:1 e:1
 */

#include <stdio.h>
#include <string.h>

void count_dup(char s[], char r[]) {
	int cnt[255] = {0};

	for (int i = 0; i < strlen(s); i++) {
		for (int j = 0; j < strlen(r); j++) {
			if (s[i] == r[j]) {
				int idx = r[j];
				cnt[idx]++;
			}
		}
	}

	for (int i = 0; i < 255; i++) {
		if (cnt[i] > 0) {
			printf("%c:%d\n", cnt[i], cnt[i]);
               
		}
	} 
}

void main(void) {
	char s[] = {"India is great"};
	char r[] = {"India Inc."};

	count_dup(s, r);
}

