#include <stdio.h>
#include <stdlib.h>

// Node
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

// Root
struct node* root = NULL;

// Create Node
struct node* create_node(int data)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->data = data;
	new->left = NULL;
	new->right = NULL;

	// Binary Search Tree is empty.
	if (root == NULL)
	{
		root = new;
	}

	return new;
}

// Inorder
void inorder(struct node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d - ", root->data);
		inorder(root->right);
	}
}

// Add
struct node* add(struct node* node, int data)
{	
	// Binary Search Tree is empty.
	if (node == NULL)
	{
		return create_node(data);
	}
	
	// We compare the data we will add with the data in the node.
	if (data < node->data)
	{
		node->left = add(node->left, data);
	}
	else if (data > node->data)
	{
		node->right = add(node->right, data);
	}

	return node;
}

// Menu
int main()
{
	int choice;

	while (1)
	{
		printf("\n 1- Sayý ekle...");
		printf("\n 2- Inorder traversal...");
		printf("\n Seçiminizi yapýn...");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\n Girmek istediðiniz sayý...");
			scanf_s("%d", &choice);
			add(root, choice);
			break;
		case 2:
			inorder(root);
			break;
		}
	}
}
