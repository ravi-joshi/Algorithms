/* write a program to delete the first element of the list */

#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *next;
	int data;
};

struct node *head = NULL;

struct node* delete_first(struct node **head) {
	struct node *tmp = *head;

	if (!tmp) {
		// list is empty
		return NULL;
	}

	// list has at least one element
	*head = tmp->next;
	tmp->next = NULL;
	return tmp;
}

struct node* del_first(void) {
	struct node *tmp = head;

	if (!tmp) return NULL;

	head = head->next;
	tmp->next = NULL;
	return tmp;
}

void insert_head(struct node **head, int data) {
	struct node *tmp = (struct node*) malloc (sizeof(struct node));
	if (!tmp) return;

	tmp->data = data;
	tmp->next = *head; 	// prepend new node
	*head = tmp;		// update head
}

void ins_head(int head) {
	struct node *tmp = (struct node*) malloc(sizeof(struct node));
	if (!tmp) return NULL;

	tmp->data = data;
	tmp->next = head;
	head = tmp;
}

// returns updated head
struct node* inserthead(struct node *head, int data) {
	struct node *tmp = (struct node *) malloc(sizeof(struct node));
	if (!tmp) return NULL;

	tmp->data = data;
	tmp->next = tmp;
	head = tmp;

	return head;
}

struct node* delete_first(struct node *head) {
}

void print_list(struct node *head) {
}

void main(void) {
}


