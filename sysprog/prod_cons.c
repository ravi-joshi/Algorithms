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
int buf[MAX_ITEMS];
int in;
int out;
pthread_mutex_t mutex;


