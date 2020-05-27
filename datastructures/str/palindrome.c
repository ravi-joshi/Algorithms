#include <stdio.h>
#include <string.h>

void is_palindrome(char s[])
{
	//define two pointers, one at the start
	//and the second one at the end
	//compare the characters, if same, then
	//string is a palindrome
	int i = strlen(s);
	int j = 0;
	int palindrome = 1;

	while (i < j) {
		if (s[i++] != s[j++]) {
			palindrome = 0;
			break;
		}
	}
	if (palindrome)
		printf("%s is a palindrome\n", s);
	else
		printf("%s is a not a palindrome\n", s);
}

void main(void)
{
	char s[] = "geeksforgeeks";
	char s1[] = "ablewasiereisawelba";
	is_palindrome(s);
	is_palindrome(s1);
}
