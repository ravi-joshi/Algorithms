/*
Given a linked list of N nodes. The task is to reverse this list.

Input:
The first line of input contains the number of test cases T. For each test case, the first line contains the length of the linked list and the next line contains the elements of the linked list.

Output:
For each test case, print the reversed linked list in a new line.

User Task:
The task is to complete the function reverseList() with head reference as the only argument and should return new head after reversing the list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 104

Example:
Input:
2
6
1 2 3 4 5 6
5
2 7 8 9 10
Output:
6 5 4 3 2 1
10 9 8 7 2

Explanation:
Testcase 1: After reversing the list, elements are 6->5->4->3->2->1.
Testcase 2: After reversing the list, elements are 10->9->8->7->2.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *next;
	int data;
};

struct node *head;

void push(int data)
{
	struct node *new = malloc(sizeof(struct node));
	if (!new)
		return;

	new->data = data;
	new->next = head;
	head = new;
}

void print(void)
{
	struct node *tmp = head;
	while (tmp) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void reverse(void)
{
	struct node *curr = head;
	struct node *prev = NULL;
	struct node *next = NULL;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

void freelist(void)
{
	while (head) {
		struct node *tmp = head;
		head = head->next;
		free(tmp);
	}
	head = NULL;
}

void main(void)
{
	head = NULL;
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);

	print();
	reverse();
	print();
	freelist();	
}

