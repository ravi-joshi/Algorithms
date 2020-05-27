/*
sort elements in the linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void enqueue(struct node **head, int data)
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

void sort(struct node *head)
{
	// ascending / descending
	// elements are not ordered but the data will be
	// reordered
	int t = 0;
	struct node *tmp = head;
	struct node *i;
	struct node *j;

	for (i = tmp; i != NULL; i = i->next) {
		for (j = i->next; j != NULL; j = j->next) {
			if (i->data > j->data) {
				t = i->data;
				i->data = j->data;
				j->data = t;
			}
		}
	}
}

void print(struct node *head)
{
	struct node *tmp = head;
	while (tmp != NULL) {
		printf("tmp->data: %d\n", tmp->data);
		tmp = tmp->next;
	}
}

void main(void)
{
	// driver code here
	struct node *head = NULL;
	enqueue(&head, 10);
	enqueue(&head, 2);
	enqueue(&head, 23);
	enqueue(&head, 56);
	enqueue(&head, 5);
	enqueue(&head, 12);
	enqueue(&head, 44);
	enqueue(&head, 35);
	printf("data enqueued - elements:\n");
	print(head);

	// sort elements
	sort(head);

	printf("elements sorted - elements:\n");
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
	printf("elements deleted\n");
}
