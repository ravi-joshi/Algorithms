/*
BST - binary search tree
left of root - smaller than root node
right of root - larger than root node

all sub-trees are also BSTs
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left;
	struct node *right;
	int val;
};

int isbst(struct node *root)
{
	// the tree is bst as long as it honors above rules of BST
}

int main(void)
{
} 

