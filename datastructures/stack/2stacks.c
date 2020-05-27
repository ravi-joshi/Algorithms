/* implement two stacks in the same array */

// The data structure implements fairly simple
// algorithm to devide the array in 2 parts and
// make use of array as the basic DS

#include <stdio.h>
#include <stdlib.h>

struct twostacks{
	int *arr;
	int size;
	int top1;
	int top2; 
};

struct twostacks stack;

void init(int size)
{
	stack.size = size;
	stack.arr = malloc(size);
	if (!stack.arr) {
		printf("malloc failed\n");
		return;
	}

	// current top values of both stacks
	stack.top1 = 0;
	stack.top2 = size/2 - 1;
}

void deinit(void)
{
	free(stack.arr);
}

void push1(int data)
{
	if (stack.top1 < (stack.size/2 - 1)) {
		stack.arr[stack.top1++] = data;
		printf("stored %d in stack1, top1: %d\n", data, stack.top1);
	}
}

void push2(int data)
{
	if (stack.top2 < (stack.size - 1)) {
		stack.arr[stack.top2++] = data;
		printf("stored %d in stack2, top2: %d\n", data, stack.top2);
	}
}

int pop1()
{
	int x;

	if (stack.top1 >= 0) {
		x = stack.arr[stack.top1];
		stack.top1--;
		printf("returning %d from stack1\n", x);
		return x;
	} else
		printf("stack1 is empty\n");
}

int pop2()
{
	int x;
	if (stack.top2 > (stack.size/2 - 1)) {
		x = stack.arr[stack.top2];
		stack.top2--;
		printf("returning %d from stack2\n", x);
		return x;
	} else
		printf("stack2 is empty\n");
}

void main(void)
{
	init(10);
	push1(1);
	push1(2);
	push1(3);
	push1(4);
	push2(10);
	push2(9);
	push2(8);
	push2(7);

	// pop operations
	printf("pop1: %d\n", pop1());
	printf("pop1: %d\n", pop1());
	printf("pop1: %d\n", pop1());
	printf("pop1: %d\n", pop1());

	printf("pop2: %d\n", pop2());
	printf("pop2: %d\n", pop2());
	printf("pop2: %d\n", pop2());
	printf("pop2: %d\n", pop2());

	deinit();
}


