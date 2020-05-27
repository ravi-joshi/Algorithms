/*
check if given string is a valid ip address
*/

// ip address assumed to be ipv4 for simplicity
// ipv4 address has a.b.c.d format - notice 3 dots
// a, b, c and d need to be between 0 and 255
// ip addresses are passed in decimal format

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_validip(char ip[], int n)
{
	if (n < 0 || n > 15) {
		printf("invalid ip address format\n");
		return 0;
	}

	char *c = ".";
	char *token;
	int invalid = 0;

	token = strtok(ip, c);
	while (token != NULL) {
		printf("ip: %s\n", token);

		int ipn = atoi(token);
		if (ipn < 0 || ipn > 255)
			invalid = 1;

		token = strtok(NULL, c);
	}

	return invalid;
}

void main(void)
{
	char ip[] = "10.256.a.1";
	int n = strlen(ip);
	printf("%s\n", (is_validip(ip, n) ? "invalid ip" : "valid ip"));
}
