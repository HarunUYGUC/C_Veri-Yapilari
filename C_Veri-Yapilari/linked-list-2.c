#include <stdio.h>
#include <stdlib.h>

// Linked List
struct node
{
	int data;
	struct node* next;
};

// Head & Tail
struct node* head = NULL;
struct node* tail = NULL;

// Add Node to Tail
void add_node_tail(int data)
{
	// Linked List is empty.
	if (head == NULL)
	{
		struct node* new = (struct node*)malloc(sizeof(struct node));
		new->data = data;
		new->next = NULL;

		head = tail = new;
	}
	// Linked List isn't empty.
	else
	{
		struct node* new = (struct node*)malloc(sizeof(struct node));
		new->data = data;
		new->next = NULL;

		tail->next = new;
		tail = new;
	}
}

// Add Node to Head
void add_node_head(int data)
{
	// Linked List is empty.
	if (head == NULL)
	{
		struct node* new = (struct node*)malloc(sizeof(struct node));
		new->data = data;
		new->next = NULL;

		head = tail = new;
	}
	// Linked List isn't empty.
	else
	{
		struct node* new = (struct node*)malloc(sizeof(struct node));
		new->data = data;
		new->next = head;

		head = new;
	}
}

// Write
void write()
{
	printf("Linked List: ");

	struct node* index = head;

	while (index != NULL)
	{
		printf("%d - ", index->data);
		index = index->next;
	}

	printf("\n");
}

// Delete Node
int delete(int data)
{
	struct node* prev = NULL;
	struct node* index = head;

	// Linked List is empty.
	if (head == NULL)
	{
		printf("Linked List is empty. \n");
		return 1;
	}

	// The data will be deleted from the beginning.
	if (head->data == data)
	{
		struct node* temp = head;
		head = head->next;
		free(temp);
		return 1;
	}

	// We will look at the second data and beyond.
	while ((index != NULL) && (index->data != data))
	{
		prev = index;
		index = index->next;
	}

	// The data to be deleted is not in the linked list.
	if (index == NULL)
	{
		printf("Data not found. \n");
		return 1;
	}

	// The data to be deleted exists in the linked list and has been deleted.
	prev->next = index->next;

	// The data we deleted is at the end of the list.
	if (tail->data == data)
	{
		tail = prev;
	}

	free(index);

	return 1;
}

int main()
{
	add_node_tail(10);
	add_node_tail(14);
	add_node_tail(16);
	add_node_tail(19);

	add_node_head(15);
	add_node_head(7);

	add_node_tail(30);

	write();
	printf("-------------- \n");

	delete(7);
	write();
	printf("-------------- \n");

	delete(55);
	write();
	printf("-------------- \n");

	delete(30);
	delete(15);
	delete(10);
	delete(14);
	delete(16);
	delete(19);
	write();
	printf("-------------- \n");

	delete(15);
	write();
	printf("-------------- \n");

	add_node_tail(5);
	add_node_tail(7);
	write();
	printf("-------------- \n");

	add_node_head(3);
	add_node_head(1);
	write();

	return 1;
}
