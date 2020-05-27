/*
queue implementation using front and rear pointers
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *front, *rear;

void enqueue(struct node **head, int data)
{
	struct node *tmp = (*head);

	struct node *new = malloc(sizeof(new));
	if (!new) {
		printf("malloc failed\n");
		return;
	}

	// check if head is null - first element
	if (tmp == NULL) {
		new->data = data;
		new->next = NULL;
		front = rear = new;
		(*head) = front;
		return;
	}
	// at least one element in the queue
	new->data = data;
	new->next = NULL;
	rear->next = new;
	rear = new;
}

struct node* dequeue(struct node **head)
{
	struct node *tmp;
	if ((*head) == NULL) {
		printf("queue is empty\n");
		return NULL;
	}

	// at least one element in the queue
	// dequeue always happens at the front
	tmp = front;
	front = front->next;
	(*head) = front;
	return tmp;
}

void main(void)
{
	// driver code here
	struct node *head = NULL;
	enqueue(&head, 1);
	printf("data enqueued\n");
	enqueue(&head, 2);
	printf("data enqueued\n");
	enqueue(&head, 3);
	printf("data enqueued\n");
	enqueue(&head, 4);
	printf("data enqueued\n");
	enqueue(&head, 5);
	printf("data enqueued\n");
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
}

