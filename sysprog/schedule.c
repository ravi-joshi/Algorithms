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
sem_t full;
sem_t empty;

pthread_mutex_t mutex;
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
	//int n = 0;

	//while (n++ < 5) {
	while (1) {
		sem_wait(&full);
		if (!head) {
			printf("no tasks to process\n");
			sem_post(&sem);
		}

		pthread_mutex_lock(&mutex);
		// process as long as there are tasks
		while (head) {
			task = head;
			head = head->next;
			task->next = NULL;
			process(task);
		}
		pthread_mutex_unlock(&mutex);

		sem_post(&sem);
		sem_post(&empty);
		
	}
}

// producer thread
void* producer(void *arg)
{
	struct node *new;
	//int n = 0;

	//while (n++ < 5) {
	while (1) {
		sem_wait(&empty);	// wait for the queue access
		new = malloc(sizeof(new));
		if (!new)
			return NULL;

		pthread_mutex_lock(&mutex);
		new->timeout = rand() + 10;
		new->next = head;
		head = new;
		pthread_mutex_unlock(&mutex);

		printf("producer added task, timeout: %d\n", new->timeout);
		sem_post(&full);
	}
}

// driver main
void main(void)
{
	pthread_t t[2];
	sem_init(&sem, 0, 1);
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, 5);

	pthread_mutex_init(&mutex, NULL);

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
	sem_destroy(&empty);
	sem_destroy(&full);

	pthread_mutex_destroy(&mutex);
}

