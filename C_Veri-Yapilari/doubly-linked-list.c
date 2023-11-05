#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

// Head & Tail
struct node* head = NULL;
struct node* tail = NULL;

// Create Node (Automated)
struct node* create_node(int data)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->data = data;
	new->next = NULL;
	new->prev = NULL;

	return new;
}

// Add Node to Tail
void add_node_tail(int data)
{
	struct node* new = create_node(data);

	// Doubly Linked List is empty.
	if (head == NULL)
	{
		head = new;
	}
	// Doubly Linked List isn't empty. (Traverse (Dolaþmak) iþlemi yapýlýr.)
	// Traverse iþleminde elimizdeki node'u kaybetmemek için node'umuzu geçici bir node'a atayýp onunla iþlem yapýyoruz.
	else
	{
		struct node* temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		new->prev = temp;
		temp->next = new;
	}
}

// Add Node to Head
void add_node_head(int data)
{
	struct node* new = create_node(data);

	// Doubly Linked List is empty.
	if (head == NULL)
	{
		head = new;
		return;
	}

	// Doubly Linked List isn't empty.
	head->prev = new;
	new->next = head;
	head = new;
}

// Add Node Somewhere in the Middle
void add_node_sw_mid(int data, int front_which_data)
{
	// Traverse (Dolaþmak) Ýþlemi
	struct node* temp = head;
	struct node* willBeInsertedMid = create_node(data);
	struct node* previous = NULL;

	// Doubly Linked List is empty.
	if (head == NULL)
	{
		head = willBeInsertedMid;
	}
	// Add Node to Head
	else if (head->data == willBeInsertedMid)
	{
		add_node_head(data);
	}
	// Doubly Linked List isn't empty. Add Node Somewhere in the Middle
	else
	{
		while (temp->next != NULL)
		{
			if (temp->data == front_which_data)
			{
				previous = temp->prev;
				break;
			}

			temp = temp->next;
		}

		temp->prev = willBeInsertedMid;
		willBeInsertedMid->next = temp;
		willBeInsertedMid->prev = previous;

		previous->next = willBeInsertedMid;
	}
}

// Write (Burada da Traverse iþlemi yapýlýr.)
void write()
{
	struct node* temp = head;

	while (temp != NULL)
	{
		printf("%d - ", temp->data);
		temp = temp->next;
	}
}

int main()
{
	// Menu Created
	int i, choice, num, num1;

	while (1)
	{
		printf("\n 1: Sona Eleman Ekleme");
		printf("\n 2: Baþa Eleman Ekleme");
		printf("\n 3: Araya Eleman Ekleme");
		printf("\n Seçiminizi Yapýn...");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\n Sona eklemek istediðiniz elemaný girin...");
			scanf_s("%d", &num);

			add_node_tail(num);
			write();

			break;
		case 2:
			printf("\n Baþa eklemek istediðiniz elemaný girin...");
			scanf_s("%d", &num);

			add_node_head(num);
			write();

			break;
		case 3:
			printf("\n Araya eklemek istediðiniz elemaný girin...");
			scanf_s("%d", &num);

			printf("\n Hangi elemanýn önüne eklemek istiyorsunuz?: ");
			scanf_s("%d", &num1);

			add_node_sw_mid(num, num1);
			write();

			break;
		}
	}

	return 0;
}
