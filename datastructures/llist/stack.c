/*
Implementation of stack, which is first-in and first-out
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node **head, int data)
{
	struct node *new = malloc(sizeof(struct node));
	if (!new)
		return;

	new->data = data;
	new->next = (*head);
	(*head) = new;
}

struct node* pop(struct node **head)
{
	struct node *tmp = *head;
	if (tmp != NULL) {
		(*head) = tmp->next;
		tmp->next = NULL;
	}

	return tmp;
}

void main(void)
{
	struct node *head;
	struct node *tmp;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	printf("stored\n");
	tmp = pop(&head);
	if (tmp) {
	printf("pop: %d\n", tmp->data);
	free(tmp);
	}
	tmp = pop(&head);
	if (tmp) {
	printf("pop: %d\n", tmp->data);
	free(tmp);
	}
	tmp = pop(&head);
	if (tmp) {
	printf("pop: %d\n", tmp->data);
	free(tmp);
	}
	tmp = pop(&head);
	if (tmp) {
	printf("pop: %d\n", tmp->data);
	free(tmp);
	}
	tmp = pop(&head);
	if (tmp) {
	printf("pop: %d\n", tmp->data);
	free(tmp);
	}
}
