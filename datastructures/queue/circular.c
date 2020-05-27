/*
implment circular buffer
*/

struct queue {
	char *buff;
	int read;
	int write;
	int full;
	int size;
};

// returns number of bytes successfully written
// data - data to be written
// size - requested size
int enqueue(struct queue *q, char *data, int size)
{
	int bytes = 0;
	int space = 0;

	if (!q ||
		!data ||
		size <= 0) {
		printf("Input invalid\n");
		return -1;
	}

	if (q->full) {
		printf("queue is already full\n");
		return -1;
	}

	// queue is not full, check if there is enough
	// space to copy requested number of bytes
	// if read and write pointers are 1 byte apart
	// the queue is full
	if ((q->write - q->read) == 1) {
		q->full = 1;
		printf("queue is full\n");
		return -1;
	} else {
		space = q->size - q->write;
		bytes = (space > size) ? size : space;
		memcpy(q->buff, data, bytes);
		q->write += bytes;
		q->full = (q->write == q->size) ? 1 : 0;
	}
	return bytes;
}

// buff - buffer in which data needs to be returned
// size - requested size
int dequeue(struct queue *q, char *buff, int size)
{
	int bytes = 0;

	if (!q ||
		!buff ||
		size <= 0) {
		printf("Input invalid\n");
		return -1;
	}

	if (!q->full) {
		printf("queue is empty\n");
		return -1;
	}

	// queue is non-empty, return requested amount
	// of data if available or return whatever
	// available
	if (q->read < q->write) {
		bytes = q->write - q->read;
	}
}

// pointer to the queue
// size - of the circular buffer
int init(struct queue *q, int size)
{
}

void main(void)
{
	struct queue q;
	init(&q, 100);
	
}
