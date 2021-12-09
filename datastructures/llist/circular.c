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
	// push is always at the head
	*head = new;
	new->next = *head;
}

void insert_tail(struct list **head, int val)
{
	struct list	*new = malloc(sizeof(struct list));
	if (!new)
		return;

	new->val = val;
	new->next = NULL;

	struct list *tmp = *head;

	if (*head == NULL) {
		// insert at the head
		*head = new;
		new->next = *head;
		return;
	}

	// list has at least one element
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

	tmp->next = new;
}

// pop
struct list* pop(struct list **head)
{
	struct list *tmp = *head;
	if (tmp == NULL)
		return NULL;

	*head = tmp->next;
	tmp->next = NULL

	return tmp;
}

// print
void print(struct list *head)
{
}

void main(void)
{
}

