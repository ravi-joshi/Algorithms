/*
Find out the length of the list
*/

struct node {
	void *data;
	struct node *next;
};

void insert(struct node *head, void *data)
{
}

int len(struct node *head)
{
	int count = 0;
	struct node *curr = head;
	while (curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}

void main(void)
{
}
