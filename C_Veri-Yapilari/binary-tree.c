#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	// We need to show the right and left of the node.
	struct node* left;
	struct node* right;
};

struct node* new_node(int data)
{
	struct node* new = malloc(sizeof(struct node));
	new->data = data;
	new->left = NULL;
	new->right = NULL;

	return new;
}

int main()
{
	// Root
	struct node* root = new_node(1);

	root->left = new_node(2);
	root->right = new_node(3);

	root->left->left = new_node(4);
	root->left->right = new_node(5);

	root->right->left = new_node(6);
	root->right->right = new_node(7);

	printf("Root: %d \n", root->data);
	printf("Root->Left: %d \n", root->left->data);
	printf("Root->Right: %d \n", root->right->data);
	
	printf("Root->Left->Left: %d \n", root->left->left->data);
	printf("Root->Left->Right: %d \n", root->left->right->data);
	
	printf("Root->Right->Left: %d \n", root->right->left->data);
	printf("Root->Right->Right: %d \n", root->right->right->data);

	return 1;
}
