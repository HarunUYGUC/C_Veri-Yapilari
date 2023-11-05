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
	// Doubly Linked List isn't empty. (Traverse (Dola�mak) i�lemi yap�l�r.)
	// Traverse i�leminde elimizdeki node'u kaybetmemek i�in node'umuzu ge�ici bir node'a atay�p onunla i�lem yap�yoruz.
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
	// Traverse (Dola�mak) ��lemi
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

// Write (Burada da Traverse i�lemi yap�l�r.)
void write()
{
	struct node* temp = head;

	while (temp != NULL)
	{
		printf("%d - ", temp->data);
		temp = temp->next;
	}
}

// Delete Node from Head
void delete_head()
{
	// Doubly Linked List is empty.
	if (head == NULL)
	{
		printf("\n Liste zaten bo�.");
		return;
	}

	// Delete Node from Tail
	if (head->next == NULL)
	{
		free(head);
		head = NULL;
		return;
	}

	// Delete Node from Head
	struct node* second = head->next;
	free(head);
	second->prev = NULL;
	head = second;
}

// Delete Node from Tail
void delete_tail()
{
	// Doubly Linked List is empty.
	if (head == NULL)
	{
		printf("\n Liste zaten bo�.");
		return;
	}

	// Delete Node from Head
	if (head->next == NULL)
	{
		delete_head();
		return;
	}

	// Delete Node from Tail
	struct node* temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	struct node* previous = temp->prev;
	free(temp);
	previous->next = NULL;
}

// Delete Node Somewhere in the Middle
void delete_node_sw_mid(int data)
{
	struct node* temp = head;

	while (temp->next != NULL)
	{
		if (temp->data == data)
		{
			break;
		}

		temp = temp->next;
	}

	struct node* following = temp->next;
	struct node* previous = temp->prev;
	free(temp);

	previous->next = following;
	following->prev = previous;
}

int main()
{
	// Menu Created
	int choice, num, num1;

	while (1)
	{
		printf("\n 1: Sona Eleman Ekleme");
		printf("\n 2: Ba�a Eleman Ekleme");
		printf("\n 3: Araya Eleman Ekleme");
		printf("\n 4: Ba�tan Eleman Sil");
		printf("\n 5: Sondan Eleman Sil");
		printf("\n 6: Aradan Eleman Sil");
		printf("\n Se�iminizi Yap�n...");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\n Sona eklemek istedi�iniz eleman� girin...");
			scanf_s("%d", &num);

			add_node_tail(num);
			write();

			break;
		case 2:
			printf("\n Ba�a eklemek istedi�iniz eleman� girin...");
			scanf_s("%d", &num);

			add_node_head(num);
			write();

			break;
		case 3:
			printf("\n Araya eklemek istedi�iniz eleman� girin...");
			scanf_s("%d", &num);

			printf("\n Hangi eleman�n �n�ne eklemek istiyorsunuz?: ");
			scanf_s("%d", &num1);

			add_node_sw_mid(num, num1);
			write();

			break;
		case 4:
			delete_head();
			write();

			break;
		case 5:
			delete_tail();
			write();

			break;
		case 6:
			printf("Silinmesini istedi�iniz eleman� girin...");
			scanf_s("%d", &num);

			delete_node_sw_mid(num);
			write();

			break;
		}
	}

	return 0;
}
