/*
Implement semaphore using mutex and condition variable
*/

// mutex is a locking mechanism for synchronization
// semaphore is a signaling mechanism for other threads

// mutex has two operations, lock() and unlock()
// semaphore has two operation wait() and post()

// both mutex and semaphores wait until the resource is
// available

// the thread blocks until semahore is available
// and signaled when available - condition variable

// blocking can be achieved using mutexes and signaling
// can be achieved using condition variables

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_SEM_COUNT 5

struct sem {
	int val;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
};

// following operations are associated with semaphore
void sem_init(struct sem *s, int count)
{
	// initialize semaphore
	sem->val = count;
	pthread_mutex_init(&sem->mutex, NULL);
	pthread_cond_init(&sem->cond, NULL);
}

void sem_wait(struct sem *s)
{
	pthread_mutex_lock(&s->mutex);

	if (s->val > 0) {
		s->val--;
		pthread_mutex_unlock(&s->mutex);
		return;
	}
	pthread_mutex_unlock(&s->mutex);
	pthread_cond_wait(&s->mutex);
}

void sem_signal(struct sem *s)
{
	if (s->val < MAX_SEM_COUNT) {
		pthread_mutex_lock(&s->mutex);
		s->val++;
		pthread_mutex_unlock(&s->mutex);
		pthread_cond_broadcast(&sem->cond);
	}
}

void main(void)
{
}

