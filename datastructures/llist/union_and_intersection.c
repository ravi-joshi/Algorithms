/* print the union and intersection of 2 linked lists */

/* union - all elements in list1 and list2, except the duplicates */
/* intersection - elements appearing in both list1 and list2 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void push(struct node **head, int data);
int is_present(struct node *head, int data);

/* list returns the head pointer of the union of two lists */
struct node* get_union(struct node *h1, struct node *h2) {
	struct node *result = NULL;
	struct node *t1 = h1;
	struct node *t2 = h2;

	while (t1 != NULL) {
		push(&result, t1->data);
		t1 = t1->next;
	}

	while (t2 != NULL) {
		if (!is_present(result, t2->data))
			push(result, t2->data);
		t2 = t2->next;
	}

	return result;
}

struct node* get_intersection(struct node *h1, struct node *h2) {
	struct node *result = NULL;
	struct node *t1 = h1;
	struct node *t2 = h2;

	while (t1 != NULL) {
		if (is_present(t2, t1->data)
			push(result, t1->data);
		t1 = t1->next;
	}
}

void push(struct node **head_ref, int data) {
	struct node *n = malloc(sizeof(struct node));
	n->data = data;

	n->next = *(head_ref);
	*(head_ref) = n;
}

struct node* pop(struct node **head_ref) {
	struct node *t = *head_ref;
	if (!t) return;

	*head_ref = *head_ref->next;
	t->next = NULL;
	return t;
}

void print_list(struct node *head) {
	struct node *t = head;
	while (t != NULL) {
		printf("%d", t->data);
		printf("->");
		t = t->next;
	}
	printf("\n");
}

int is_present(struct node *head, int data) {
	struct node *t = head;
	while (t != NULL) {
		if (t->data == data) return 1;
		t = t->next;
	}
	return 0;
}

