/*
linked list insert operations
insert_after();
insert_before();
insert(); --> inserts at the head if list is null, else inserts at the tail
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void insert_after(struct node **head, int data_after, int data)
{
	//expects valid head
	if (*head == NULL) {
		printf("list is NULL, invoke insert() first\n");
		return;
	}

	struct node *tmp = (*head);
	struct node *prev;
	struct node *next;
	struct node *new = malloc(sizeof(new));
	if (!new) {
		printf("malloc failed\n");
		return;
	}

	new->data = data;
	new->next = NULL;

	while (tmp != NULL) {
		prev = tmp;
		next = tmp->next;

		if (tmp->data == data_after) {
			prev->next = new;
			new->next = next;
			break;
		}
		tmp = tmp->next;
	}
}

void insert_before(struct node **head, int data_before, int data)
{
	//expects valid head
	if (*head == NULL) {
		printf("list is NULL, invoke insert() first\n");
		return;
	}

	struct node *curr = (*head);
	struct node *prev = NULL;
	struct node *next = NULL;

	struct node *new = malloc(sizeof(new));
	if (!new) {
		printf("malloc failed\n");
		return;
	}

	new->data = data;
	new->next = NULL;

	prev = curr;
	curr = curr->next;

	while (curr != NULL) {
		if (curr->data == data_before) {
			prev->next = new;
			new->next = curr;
			break;
		}
		prev = curr;
		curr = curr->next;
	}
}

void insert(struct node **head, int data)
{
	struct node *tmp = (*head);
	struct node *new = malloc(sizeof(struct node));
	if (!new) {
		printf("malloc failed\n");
		return;	
	}

	if (tmp == NULL) {
		new->data = data;
		new->next = NULL;
		(*head) = new;
		return;
	}

	// queue is non-empty
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	new->data = data;
	new->next = NULL;
	tmp->next = new;
}

struct node* dequeue(struct node **head)
{
	// dequeue always happens at the head
	struct node *tmp = *head;
	if (tmp == NULL) {
		printf("queue is empty\n");
		return NULL;
	}

	(*head) = tmp->next;
	return tmp;
}

void print(struct node *head)
{
	struct node *curr = head;
	while (curr != NULL) {
		printf("%d\n", curr->data);
		curr = curr->next;
	}
}

void main(void)
{
	// driver code here
	struct node *head = NULL;
	insert(&head, 1);
	printf("data enqueued\n");
	insert(&head, 2);
	printf("data enqueued\n");
	insert(&head, 3);
	printf("data enqueued\n");
	insert(&head, 5);
	printf("data enqueued\n");
	insert(&head, 6);
	printf("data enqueued\n");
	insert_before(&head, 5, 4);
	printf("data enqueued\n");
	insert_after(&head, 6, 7);
	printf("data enqueued\n");

	print(head);

	// dequeue elements
	struct node *tmp;
	tmp = dequeue(&head);
	if (tmp) {
		printf("data: %d\n", tmp->data);
		free(tmp);
	}
	tmp = dequeue(&head);
	if (tmp) {
		printf("data: %d\n", tmp->data);
		free(tmp);
	}
	tmp = dequeue(&head);
	if (tmp) {
		printf("data: %d\n", tmp->data);
		free(tmp);
	}
	tmp = dequeue(&head);
	if (tmp) {
		printf("data: %d\n", tmp->data);
		free(tmp);
	}
	tmp = dequeue(&head);
	if (tmp) {
		printf("data: %d\n", tmp->data);
		free(tmp);
	}
	tmp = dequeue(&head);
	if (tmp) {
		printf("data: %d\n", tmp->data);
		free(tmp);
	}
	tmp = dequeue(&head);
	if (tmp) {
		printf("data: %d\n", tmp->data);
		free(tmp);
	}
}
