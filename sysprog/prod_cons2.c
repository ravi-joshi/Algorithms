/*
producer and consumer problem
*/

// producer copies data into the buffer as long as there is space
// if there is no space, the producer waits until the space is available

// consumer consumes data from the buffer as long as it is not empty
// if the buffer is empty, it will wait until the data is available

// can be implemented using 2 semaphores
// semaphore indicating empty slots
// semaphore indicating full slots

// producer - 
// if buffer is full, it will wait on empty slot semaphore
// creates and puts item in the queue
// downs empty slot and ups filled slots

// consumer -
// if buffer is empty, it will wait on full semaphore
// when access is available, accesses the buffer
// downs filled slot and ups empty slot

// the producer and consumer threads are synchronized through
// semaphores. The synchronization is required because the 
// producer and consumer threads would try to produce and consume
// data continuously and if they try to produce or consume data
// in a bounded buffer, they would simply waste CPU

// That brings us to another interesting problem of bounded 
// buffer. In which case the buffer is limited and shared across
// all producers and consumers. Since it is a shared resource, it is
// protected by the lock, such as mutex
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

// global data
#define MAX_ITEMS 10
#define MAX_RESOURCES 5

int buf[MAX_ITEMS];
int in;
int out;
pthread_mutex_t mutex;
sem_t full;
sem_t empty;

void* producer(void *arg)
{
	static int item = 10;

	for (int i = 0; i < MAX_ITEMS; i++) {
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		item += 10;
		buf[in++ % MAX_ITEMS] = item;
		printf("item produced: %d\n", item);
		pthread_mutex_unlock(&mutex);
		sem_post(&full); 
	}
}

void* consumer(void *arg)
{
	int item;
	for (int i = 0; i < MAX_ITEMS; i++) {
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		item = buf[out++ % MAX_ITEMS];
		printf("item consumed: %d\n", item);
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}

void main(void)
{
	// ptherads
	pthread_t prod[MAX_RESOURCES], cons[MAX_RESOURCES];

	pthread_mutex_init(&mutex, NULL);
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, MAX_ITEMS);

	for (int i = 0; i < MAX_RESOURCES; i++) {
		pthread_create(&prod[i], 0, producer, NULL);
		pthread_create(&cons[i], 0, consumer, NULL);
	}

	for (int i = 0; i < MAX_RESOURCES; i++) {
		pthread_join(prod[i], NULL);
		pthread_join(cons[i], NULL);
	}

	// deinit the resources
	pthread_mutex_destroy(&mutex);
	sem_destroy(&full);
	sem_destroy(&empty);
}


