/**
 Implement soft timers in C.
 - Thread1 produces timers
 - Thread2 consumes timers based on their timeouts
**/
#include <stdio.h>
#include <pthread.h>

typedef void (*timer_func)(void *user_data);
pthread_mutex *mutex;

struct timer {
	int timeout;
	timer_func func;
	struct timer *next;
};

void timer_func(void *user_data) {
	printf("timer expired\n");
}

void print(void *head) {
}

void producer(struct timer *head, int sec, void *user_data, timer_func func) {
}

void consumer(struct timer *head) {
}

void main(void) {
}

