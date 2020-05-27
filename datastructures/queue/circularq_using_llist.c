/*
implement circular queue using linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct queue {
	struct node *front, *back;
};

void init(struct queue *q)
{
	q = (struct queue *)malloc(sizeof(struct queue));
	if (!q) {
		printf("malloc failed\n");
		return;
	}

	q->front = q->back = NULL;
}

// enqueue
void enqueue(struct queue *q, int val)
{
	struct node *new = (struct node *)malloc(sizeof(*new));
	if (q) {
		printf("queue is NULL\n");
		return;
	}

	// if this is the first node
	if (q->front == NULL)
		q->front = new;
	else
		q->back->link = new;

	q->back = new;
	q->back->link = q->front;
}

// dequeue
int dequeue(struct queue *q)
{
	if (!q) {
		printf("queue is null\n");
		return -1;
	}

	int data = 0;

	// handle special case of last node deletion
	if (q->front = q->back) {
		data = q->front->data;
		free(q->front);
		q->front = q->back = NULL;
		return data;
	}

	// queue is not NULL - detach from the front
	struct node *temp = q->front;
	q->front = q->front->link;
	q->back->link = q->front;

	data = temp->data;
	free(temp);

	return data;
}

void print(struct queue *q)
{
	if (!q) {
		printf("queue is null\n");
		return;
	}

	// queue is okay - loop through and print
	struct node *temp = q->front;
	while (temp != q->front) {
		printf("data: %d\n", temp->data);
		temp = temp->link;
	}
	printf("data: %d\n", temp->data);
}

void main(void)
{
	struct queue *q;
	init(q);

	enqueue(q, 5);
	enqueue(q, 10);
	enqueue(q, 15);
	enqueue(q, 20);
	enqueue(q, 25);
	//print(q);

#if 0
	printf("dequeue: %d\n", dequeue(q));
	printf("dequeue: %d\n", dequeue(q));
	printf("dequeue: %d\n", dequeue(q));
	printf("dequeue: %d\n", dequeue(q));
	printf("dequeue: %d\n", dequeue(q));
	free(q);
#endif
}

