/*
implement circular queue using array
*/

// algorithm
// elements are queued at rear and dequeued from front

struct queue {
	int front;
	int rear;
	int size;
	char buff[0];
};

// enqueue
// queue is full if rear == max-1 && front = -1
// queue is also full if rear == front - 1
// if queue is not full, if rear == max - 1, reset rear = 0 and save data
int enqueue(struct queue *q, char *data, int size)
{
	int bytes = 0;

	if (!q || !data || size <= 0)
		return -1;

	if ((q->rear == size -1 && q->front == -1) ||
		q->rear == q->front -1) {
		printf("queue full\n");
		return -1;
	}

	// queue is not full
	if (q->rear == -1) {
		// queue is empty
		bytes = (q->size > size) ? size : q->size;
		memcpy(q->buff, data, bytes);
		q->rear += bytes;
		return bytes;		
	} else {
		int available = 0;

		// queue is completely empty, let us get available
		// space and that is the number of bytes we can copy
		if ((q->rear == q->size - 1) && q->front != -1) {
			// space in the front of the queue
			q->rear = 0;
			available = q->front - q->rear;
			bytes = (available > size) ? size : available;
			memcpy(q->buff, data, bytes);
			q->rear += bytes;
			return bytes;		
		} else if (q->front > q->rear)
			available = q->front - q->rear;
			bytes = (available > size) ? size : available;
			memcpy(q->buff, data, bytes);
			q->rear += bytes;
			return bytes;		
		} else {
			// need to do in two steps
			// step1 - copy up to the end first
			available = q->size - q->rear;
			bytes = (available > size) ? size : available;
			memcpy(q->buff, data, bytes);
			q->rear += bytes;

			// since q->rear reached max, reset it to 0
			q->rear = 0;
			bytes += q->front - q->rear;
			memcpy(q->buff, data, q->front - q->rear);
			q->rear += bytes;
			return bytes;
		}
	}
}

// dequeue
// if rear == front == -1, queue is empty
// if front = rear, then set front = rear = -1
// if front == max - 1,then set front = -1
int dequeue(struct queue *q, char *buff, int size)
{
}

// initialize
int init(struct queue *q, int size)
{
	if (q) {
		memset(sizeof(q), 0, sizeof(*q));
		q->buff = malloc(size);
		q->front = q->rear = -1;
		q->size = size;
	}
}

void main(void)
{
}

