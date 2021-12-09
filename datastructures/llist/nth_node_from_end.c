/* return the value of nth node from the end of the linked list */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

int nth_node(struct node *head, int n) {
	// 2-pointer method
	struct node *t1 = head;
	struct node *t2;
	struct node *h = head;

	for (int i = 0; i < n; i++) {
		h = h->next;
	}
	t2 = h;  // points to head + nth node

	while (t3 != NULL) {
		t3 = t3->next;
		t1 = t1->next;
	}

	return t1->data;
}

void main(void) {
}

