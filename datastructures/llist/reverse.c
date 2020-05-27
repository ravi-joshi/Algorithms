/*
Reverse a linked list
Given pointer to the head node of a linked list, the task is to reverse the linked list. We need to reverse the list by changing links between nodes.

Examples:

Input: Head of following linked list
1->2->3->4->NULL
Output: Linked list should be changed to,
4->3->2->1->NULL

Input: Head of following linked list
1->2->3->4->5->NULL
Output: Linked list should be changed to,
5->4->3->2->1->NULL

Input: NULL
Output: NULL

Input: 1->NULL
Output: 1->NULL
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *next;
	int val;
};

void push(struct node **head, int v)
{
	struct node *new = malloc(sizeof(struct node));
	if (!new)
		return;
	new->val = v;
	new->next = *head;
	*head = new;

	// head is updated, no need to update
	// in the caller
}

void reverse(struct node **head)
{
	struct node *curr = *head;
	struct node *prev = NULL;
	struct node *next = NULL;

	if (!curr)
		return;

	if (curr && curr->next == NULL)
		return;

	// there are at least two elements
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev; // reversing magic
		prev = curr;
		curr = next;
	}
	*head = prev;
}

void printlist(struct node *head)
{
	// head is not getting modified
	struct node *tmp = head;
	while (tmp) {
		printf("%d \n", tmp->val);
		tmp = tmp->next;
	}
}

struct node* freelist(struct node *head)
{
	// head can be freed as well
	if (head == NULL)
		return NULL;

	struct node *tmp = head;
	while (tmp) {
		struct node *t = tmp;
		tmp = tmp->next;
		free(t);
	}
	return head;
}

void main(void)
{
	struct node *head = NULL;
	push(&head, 5);
	push(&head, 10);
	push(&head, 15);
	push(&head, 20);

	printlist(head);

	reverse(&head);

	printlist(head);

	freelist(head);
}
