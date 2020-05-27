/*
display circular list elements
*/

#include <stdio.h>

struct node {
	struct node *next;
	int val;
};

void display(struct node *head)
{
	struct node *curr = head;

	while (curr != head) {
		printf("%d ", curr->val);
		curr = curr->next;
	}
}

void main(void)
{
}
