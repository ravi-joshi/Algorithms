/*
Queue – Linked List Implementation
In the previous post, we introduced Queue and discussed array implementation. In this post, linked list implementation is discussed. The following two main operations must be implemented efficiently.

In a Queue data structure, we maintain two pointers, front and rear. The front points the first item of queue and rear points to last item.

enQueue() This operation adds a new node after rear and moves rear to the next node.
deQueue() This operation removes the front node and moves front to the next node.
*/

// Algorithm - queue is first in, first out data structure
// the items are enqueued at the tail and dequeued from the
// head. We will use head update method, in which case
// the caller need not take care of additional responsibility
// to update the head

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
