/*
Find out the mid of a linked list
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

int mid(struct node *head)
{
	struct node *slow = head;
	struct node *fast = head;

	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow->data;
}

void main(void)
{
}
