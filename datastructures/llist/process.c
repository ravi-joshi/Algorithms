/*
write a program that adds nodes to the list and another thread removes the nodes
The nodes are just time at which they need to be removed from
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int timeout;
	struct node *next;
};

struct node *head;
pthread_mutex_t mutex;

void add_node(struct node **head, int timeout)
{
	struct node *new;
	new = malloc(sizeof(*new));
	if (!new)
		return;

	// allocation is okay
	pthread_mutex_lock(&mutex);
	if (*head == NULL) {
		new->timeout = timeout;
		*head = new;
		pthread_mutex_unlock(&mutex);
		return;
	}

	struct node *tmp = *head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

	tmp->next = new;
	// head is unchanged
	pthread_mutex_unlock(&mutex);
}

struct node* get_node(struct node **head, int timeout)
{
	// also deletes the node from the list
	// before returning
	pthread_mutex_lock(&mutex);
	struct node *curr = (*head);
	if (!curr) {
		printf("list is empty\n");
		pthread_mutex_unlock(&mutex);
		return NULL;
	}

	// special case - if head element
	if (curr->timeout == timeout) {
		*head = curr->next;
		pthread_mutex_unlock(&mutex);
		return curr;
	}

	// list is not null, get the element
	struct node *prev = curr;
	while (curr->next != NULL) {
		if (curr->timeout == timeout) {
			prev->next = curr->next;
			pthread_mutex_unlock(&mutex);
			return curr;
		}
		prev = curr;
		curr = curr->next;
	}
	pthread_mutex_unlock(&mutex);
	return NULL;
}

void* thread_producer(void *args)
{
	int t;
	for (t = 1; t < 50; t++) {
		add_node(&head, t);
		printf("node added: %d\n", t);
	}
	return NULL;
}

void* thread_consumer(void *args)
{
	for (int t = 1; t < 50; t++) {
		struct node *n = get_node(&head, t);
		if (n) {
			printf("retrieved node: %d\n", t);
			free(n);
		}
	}
	return NULL;
}

void main(void)
{
	pthread_t th_id1, th_id2;

	pthread_mutex_init(&mutex, NULL);

	pthread_create(&th_id2, NULL, thread_producer, NULL);
	pthread_join(th_id1, NULL);

	pthread_create(&th_id1, NULL, thread_consumer, NULL);
	pthread_join(th_id2, NULL);

	pthread_mutex_destroy(&mutex);
}

