#include <stdio.h>
#include <stdlib.h>

// Queue Node
struct node
{
	int data;
	struct node* next;
};

// Front & Rear
struct node* front = NULL;
struct node* rear = NULL;

// Enqueue (Eleman Ekle)
void enqueue(int data)
{
	// Queue is empty.
	if (front == NULL)
	{
		struct node* new = (struct node*)malloc(sizeof(struct node));
		new->data = data;
		new->next = NULL;

		front = rear = new;
	}
	// Queue isn't empty.
	else
	{
		struct node* new = (struct node*)malloc(sizeof(struct node));
		new->data = data;
		new->next = NULL;

		rear->next = new;
		rear = new;
	}
}

// Display Queue
void display()
{
	// Queue is empty.
	if (front == NULL)
	{
		printf("Queue is empty. \n");
		return 1;
	}

	printf("Queue: ");
	struct node* index = front;

	while (index != NULL)
	{
		printf("%d - ", index->data);
		index = index->next;
	}

	printf("\n");
}

// Dequeue (Eleman Sil)
int dequeue()
{
	// Queue is empty.
	if (front == NULL)
	{
		printf("Queue is empty. \n");
		return 1;
	}

	struct node* temp = front;
	front = front->next;
	free(temp);
}

// Main
int main()
{
	enqueue(5);
	enqueue(6);
	enqueue(8);
	enqueue(10);
	display();
	printf("-------------- \n");

	dequeue();
	display();
	printf("-------------- \n");

	dequeue();
	display();
	printf("-------------- \n");

	dequeue();
	dequeue();
	display();
	printf("-------------- \n");

	enqueue(1);
	enqueue(3);
	display();

	return 1;
}
