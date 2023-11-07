#include <stdio.h>
#include <stdlib.h>

// Stack
struct node
{
	int data;
	struct node* next;
};

// Top
struct node* top = NULL;

// Push
void push(int data)
{
	// Stack is empty.
	if (top == NULL)
	{
		struct node* new = (struct node*)malloc(sizeof(struct node));
		new->data = data;
		new->next = NULL;

		top = new;
	}
	// Stack isn't empty.
	else
	{
		struct node* new = (struct node*)malloc(sizeof(struct node));
		new->data = data;
		new->next = top;

		top = new;
	}
}

// Fonksiyonu int veri tipinde veri dönüþü olacak þekilde tanýmlamak yerine void olarak tanýmlayýp 
// if bloðundaki return'ü kaldýrýrsak if bloðundan sonraki kodlarý else bloðuna almalýyýz.

// Pop
int pop()
{
	// Stack is empty.
	if (top == NULL)
	{
		printf("Stack is empty. \n");
		return 1;
	}

	// Stack isn't empty.
	struct node* temp = top;
	top = top->next;
	free(temp);
	return 1;
}

// Display
int display()
{
	// Stack is empty.
	if (top == NULL)
	{
		printf("Stack is empty. \n");
		return 1;
	}

	// Stack isn't empty.
	printf("Stack: ");
	struct node* index = top;

	while (index != NULL)
	{
		printf("%d - ", index->data);
		index = index->next;
	}

	printf("\n");
	return 1;
}

int main()
{
	push(1);
	push(2);
	push(4);
	display();
	printf("------------ \n");

	pop();
	display();
	printf("------------ \n");

	pop();
	display();
	printf("------------ \n");

	pop();
	display();
	printf("------------ \n");

	push(7);
	push(9);
	push(13);
	display();
	printf("------------ \n");

	return 1;
}
