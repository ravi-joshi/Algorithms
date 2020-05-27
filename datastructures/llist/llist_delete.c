/*
linked list insert operations
delete_after();
delete_before();
delete(); --> expects the list to be non-empty. Can delete from head or tail
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void delete_after(struct node **head, int data_after, int data)
{
	//expects valid head
	if (*head == NULL) {
		printf("list is NULL, invoke insert() first\n");
		return;
	}

	struct node *curr = (*head);
	struct node *prev = curr;

	while (curr != NULL) {
		if (curr->data == data_after) {
			prev->next = curr->next;
			curr->next = NULL;
			free(curr);
			break;
		}
		prev = curr;
		curr = curr->next;
	}
}

void delete_before(struct node **head, int data_before, int data)
{
	//expects valid head
	if (*head == NULL) {
		printf("list is NULL, invoke insert() first\n");
		return;
	}

	struct node *curr = (*head);
	struct node *prev = curr;
	struct node *next;

	// return error if data_after matches the head pointer
	if (curr->data_after == data) {
		printf("there is nothing to delete before head pointer\n");
		return;
	}

	curr = prev->next;
	next = curr->next;

	while (curr != NULL) {
		if (curr->data == data_before) {
			// delete prev pointer
			prev->next = NULL;
			free(prev);
			break;
		}
		prev = curr;
		curr = next;
		next = next->next;
	}
}

void delete(struct node **head, int data)
{
	struct node *curr = (*head);
	struct node *prev;

	if (curr == NULL) {
		printf("list is empty\n");
		return;
	}

	// delete head element case - special case
	if (curr->data == data) {
		(*head) = curr->next;
		curr->next = NULL;
		free(curr);
		return;
	}

	// not a head element
	prev = curr;

	// queue is non-empty
	while (curr != NULL) {
		if (curr->data == data) {
			// element to be deleted
			prev->next = curr->next;
			curr->next = NULL
			free(curr);
			break;
		}
		prev = curr;
		curr = curr->next;
	}
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
