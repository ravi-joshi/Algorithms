
/**
implement strstr() function
**/

#include <stdio.h>
#include <string.h>

int substr(char s[], char x[], int m, int n) {
	int flag = 0;
	int tmp = 0;
	int i, j;

	for (i =0; s[i] != '\0'; i++) {
		if (s[i] == x[0]) {
			for (j = i; ;j++) {
				if (x[j-i] == '\0') { flag = 1; break;}
				if (s[j] == x[j-i]) continue;
				else break;
			}
		}
		if (flag == 1) break;
	}

	if (flag == 1) return i;
	else return -1;
}

void main(void)
{
	char *s = "ravi joshi";
	char *x = "ravi";
	int m = strlen(s);
	int n = strlen(x);

	int p = substr(s, x, m, n);
	if (p > 0) printf("substr pos: %d\n", p);
	else printf("substr not found\n");
}
