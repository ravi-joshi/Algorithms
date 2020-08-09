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

struct node *root;

// in-order traversal
// left, root, right

// pre-order traversal
// root, left, right

// post-order traversal
// left, right, root

// non-recursive
struct node* search(int data)
{
	if (!root)
		return NULL;

	struct node *curr = root;

	while (curr->data != data) {
		if (curr != NULL)
			printf("%d ", curr->data);

		if (data > curr->data) {
			curr = curr->right;
		} else if (data < curr->data) {
			curr = curr->left;
		}

		// return NULL if key is not found
		if (curr == NULL)
			return NULL;
	}

	return curr;
}

// non-recursive
void insert(int data)
{
	struct node *curr = NULL;
	struct node *new = (struct node*)malloc(sizeof(*new));
	struct node *parent = NULL;

	if (!new)
		return;

	new->data = data;
	new->left = new->right = NULL;

	if (root == NULL) {
		root = new;
		return;
	}

	curr = root;
	
	// root is valid - check whether to insert in the left or right
	while (1) {
		parent = curr;

		if (data < curr->data) {
			// left
			curr = curr->left;
			if (curr == NULL) {
				parent->left = new;
				return;
			}			
		} else {
			// right
			curr = curr->right;
			if (curr == NULL) {
				parent->right = new;
				return;
			}
		}
	}
}

// free tree
void free_binary_tree(void)
{
	struct node *curr = root->left;

	// this needs to be done in 3-steps
	// step-1: free left-side elements / right-side is okay too
	// step-2: free right-side elements
	// step-3: free root element
	while (curr != NULL) {
		struct node *tmp = curr;
		curr = tmp->left;
		free(tmp);
	}
}

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
#if 0
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
#endif
}
