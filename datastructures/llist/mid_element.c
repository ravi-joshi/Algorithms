/*
Find the mid element of the linked list
If the list has odd elements, then return the
mid element. If the list has even numbers, then
return the second mid element
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *next;
	int d;
};

void push(struct node **head, int d)
{
	struct node *tmp = malloc(sizeof(struct node));
	if (!tmp)
		return;

	tmp->d = d;
	tmp->next = (*head);
	(*head) = tmp;
	printf("data: %d added\n", d);
}

void mid(struct node *head)
{
	struct node *slow = head;
	struct node *fast = head;

	while (fast != NULL && fast->next != NULL) {
		// fast is moving twice as fast as slow
		// when fast reaches end of the list,
		// the slow would be at the middle
		fast = fast->next->next;
		slow = slow->next;
	}

	printf("mid element: %d\n", slow->d);
}

void freelist(struct node **head)
{
	struct node *tmp;

	if (!(*head)) {
		printf("list is empty\n");
		return;
	}

	while (*head) {
		tmp = (*head);
		(*head) = (*head)->next;
		free(tmp);
	}

	printf("list deleted\n");
}

void printlist(struct node *head)
{
	struct node *tmp = head;
	if (!head) {
		printf("list is empty\n");
		return;
	}

	while (tmp) {
		printf("%d ", tmp->d);
		tmp = tmp->next;
	}
	printf("\n");
}

void main(void)
{
	struct node *head = NULL;
 	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	push(&head, 6);

	printlist(head);

	mid(head);

	freelist(&head);

	printlist(head);	
}
