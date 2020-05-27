/*
find length of circular linked list
*/

#include <stdio.h>

struct node {
	int val;
	struct node *next;
};

int len(struct node *head)
{
	struct node *curr = head;
	int len = 0;

	// no elements
	if (curr == NULL)
		return 0;

	// just 1 element
	if (curr && curr->next == NULL)
		return 1;

	// more than 1 elements
	while (curr != head) {
		len++;
		curr = curr->next;
	}

	return len;
}

void main(void)
{
}
