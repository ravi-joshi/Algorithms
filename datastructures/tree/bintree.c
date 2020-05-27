/*
binary tree traversal
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left;
	struct node *right;
	int data;
};

// in-order traversal
// left, root, right

// pre-order traversal
// root, left, right

// post-order traversal
// left, right, root

struct node* new_node(int data)
{
	struct node *new = malloc(sizeof(new));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}

void print_inorder(struct node *node)
{
	if (node == NULL) return;

	print_inorder(node->left);
	printf("%d \n", node->data);
	print_inorder(node->right);
	return;
}

void print_preorder(struct node *node)
{
	if (node == NULL) return;
	printf("%d \n", node->data);
	print_preorder(node->left);
	print_preorder(node->right);
	return;
}

void print_postorder(struct node *node)
{
	if (node == NULL) return;
	printf("%d \n", node->data);
	print_postorder(node->left);
	print_postorder(node->right);
	return;
}

void main(void)
{
	struct node *root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(3);

	root->left->left = new_node(4);
	root->left->right = new_node(5);

	root->right->right = new_node(6);
	root->right->left = new_node(7);

	print_inorder(root);
	printf("%d ", root->data);
	print_preorder(root);
	printf("%d ", root->data);
	print_postorder(root);
	printf("%d ", root->data);
}


