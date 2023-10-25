#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
} node;

void write_linked_list(struct Node* n)
{
	node* temp = n; 

	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}

	printf("\n--------------- \n");
}

struct Node* create_linked_list(int data)
{
	node* n = (node*)malloc(sizeof(node));
	n->data = data;
	n->next = NULL;

	return n;
}

void add_node_head_of_linked_list(struct Node** linked_list, int data)
{
	node* new_linked_list = create_linked_list(data);
	new_linked_list->next = *linked_list;
	*linked_list = new_linked_list;
}

void add_node_end_of_linked_list(struct Node** linked_list, int data)
{
	node* temp = *linked_list;

	if (*linked_list == NULL)
	{
		*linked_list = create_linked_list(data);
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = create_linked_list(data);
	}
}

int main()
{
	node* n = (node*)malloc(sizeof(node));
	n->data = 2;
	n->next = NULL;

	n->next = (node*)malloc(sizeof(node));
	n->next->data = 3;
	n->next->next = NULL;

	printf("%d \n", n->data);
	printf("%d \n", n->next->data);

	printf("----------------- \n");

	printf("%p \n", &n);
	printf("%p \n", n);
	printf("%p \n", &(n->data));
	printf("%p \n", &(n->next));

	printf("----------------- \n");

	write_linked_list(n);

	node* root = create_linked_list(5);
	
	write_linked_list(root);

	add_node_head_of_linked_list(&root, 4);
	add_node_head_of_linked_list(&root, 3);
	write_linked_list(root);

	add_node_end_of_linked_list(&root, 6);
	write_linked_list(root);

	node* root2 = NULL;
	add_node_end_of_linked_list(&root2, 10);
	write_linked_list(root2);

	return 0;
}
