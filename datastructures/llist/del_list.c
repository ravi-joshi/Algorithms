#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
	int key;
	struct node *next;
};

// simple implementation to push and pop the elements to the stack
// the implementation updates the head node, so that the caller
// need not remember updating the head pointer during the call
void push(struct node **head, int key)
{
	struct node *new = malloc(sizeof(struct node));
	if (!new) {
		*head = NULL;
		return;
	}
	
	new->key = key;
	new->next = *head;
	*head = new;
	printf("key: %d added\n", key);
}

struct node* pop(struct node **head)
{
	struct node *new = *head;
	struct node *tmp = *head;
	new->next = (*head)->next;
	*head = new;
	return tmp;
}

void delnode(struct node **head, int key)
{
	struct node *prev;
	struct node *tmp = *head;

	// handle the head element delete
	if (tmp != NULL && tmp->key == key) {
		*head = (*head)->next;
		free(tmp);
		return;
	}

	while (tmp != NULL && tmp->key != key) {
		prev = tmp;
		tmp = tmp->next;
	}

	if (tmp == NULL) printf("key not found\n");

	prev->next = tmp->next;
	free(tmp);
}

void del_list(struct node **head)
{
	if (head == NULL)
		printf("list is empty\n");

	struct node *tmp;
	while (*head) {
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}

void print_list(struct node *head)
{
	if (head == NULL) {
		printf("list is empty\n");
		return;
	}

	struct node *tmp = head;

	while(tmp != NULL) {
		printf("key: %d ", tmp->key);
		tmp = tmp->next;
	}

	printf("\n");
}

void main(void)
{
	struct node *head = NULL;

	push(&head, 5);
	push(&head, 10);
	push(&head, 15);
	push(&head, 20);

	print_list(head);
	
	del_list(&head);
	print_list(head);
}

