#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// job structure
struct job_queue {
	struct job_queue *next;
	int job_id;
};

struct job_queue *job_head;
pthread_mutex_t mutex;

void process(struct job_queue *job)
{
	printf("job_id %d processed\n", job->job_id);
}

// will have two threads
// thread-1 will keep adding jobs to the queue
// thread-2 will get access to the queue and run
// the jobs from the queue
void* thread1(void *arg)
{
	struct job_queue *job = NULL;
	// will process the job_queue until it is empty
	while (1) {
		printf("processor thread\n");
		pthread_mutex_lock(&mutex);
		if (job_head == NULL) break;

		while (job_head) {
			job = job_head;
			job_head = job_head->next;
			process(job);
			free(job);
		}
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int max_jobs;

void* thread2(void *arg)
{
	struct job_queue *job;
	while (1) {
		printf("producer thread\n");
		job = malloc(sizeof(job));
		if (!job)
			return NULL;

		job->job_id++;
		pthread_mutex_lock(&mutex);
		job->next = job_head;
		job_head = job;
		pthread_mutex_unlock(&mutex);

		if (max_jobs++ == 25)
			break;
	}
	return NULL;
}

void main(void)
{
	pthread_mutex_init(&mutex, NULL);
	pthread_t th1, th2;

	if (pthread_create(&th1, NULL, thread1, NULL)) {
		printf("thread1 creation failed\n");
	}
	if (pthread_create(&th2, NULL, thread2, NULL)) {
		printf("thread2 creation failed\n");
	}

	while(1);
}



