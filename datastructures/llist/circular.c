/*
implement circular list using singly linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct list {
	int val;
	struct list *next;
};

// push
void push(struct list **head, int val)
{
	struct list *new = malloc(sizeof(struct list));
	if (!new)
		return;

	new->val = val;
	
	if (*head == NULL) {
		*head = new;	
		*head->next = head;
	} else {
		new->next = *head;
		*head = new;
	}
}

void insert_tail(struct list **head, int val)
{
	struct list *curr = *head; 
	struct list *prev;
	struct list *new;

	while (curr == *head) {
		prev = curr;
		curr = curr->next;
	}

	new = malloc(sizeof(struct list));
	if (!new)
		return;

	new->val = val;
	prev->next = new;
	new->next = prev;
}

// pop
int pop(struct list **head)
{
}

// print
void print(struct list *head)
{
}

void main(void)
{
}

