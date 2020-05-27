/*
write a program to queue the tasks one-by-one, process the queue when possible.
If the task has timedout, process/run the task
*/

// similar to producer/consumer problem, one thread adds processes to the queue
// and another thread will pull the process from the queue for processing
// the producer and consumer threads are synchronized using semaphore and mutex
// is used to protect the shared resource - that is queue
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>

struct node {
	int timeout;
	struct node *next;
};

// consumer thread will keep processing the queue as long as 
// there are processes in the queue. The consumer thread will
// will wait on a semaphore for the producer thread to create
// an entry in to the queue

sem_t sem;
struct node *head;

// process task
void process(struct node *task)
{
	printf("processed task, timeout: %d\n", task->timeout);
	free(task);	
}

// consumer thread
void* consumer(void *arg)
{
	struct node *task;
	while (1) {
		sem_wait(&sem);
		if (!head) {
			printf("no tasks to process\n");
			sem_post(&sem);
		}

		// process as long as there are tasks
		while (head) {
			task = head;
			head = head->next;
			task->next = NULL;
			process(task);
		}
		sem_post(&sem);
	}
}

// producer thread
void* producer(void *arg)
{
	struct node *new;

	while (1) {
		sem_wait(&sem);	// wait for the queue access
		new = malloc(sizeof(new));
		if (!new)
			return NULL;

		new->timeout = rand() + 10;
		new->next = head;
		head = new;
		printf("producer added task, timeout: %d\n", new->timeout);
		sem_post(&sem);
	}
}

// driver main
void main(void)
{
	pthread_t t[2];
	sem_init(&sem, 0, 1);

	if (pthread_create(&t[0], 0, consumer, NULL) > 0) {
		printf("thread creation failed\n");
		return;
	}

	if (pthread_create(&t[1], 0, producer, NULL) > 0) {
		printf("thread creation failed\n");
		return;
	}

	// join threads so that main waits until the threads complete
	// the execution
	for (int i = 0; i < 2; i++) {
		if (pthread_join(t[i], NULL) > 0) {
			printf("thread creation failed\n");
			return;
		}
	}

	sem_destroy(&sem);
}

