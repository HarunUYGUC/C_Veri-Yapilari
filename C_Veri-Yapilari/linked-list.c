// Ba�l� listeler, struct pointerlar�n birbirlerine ba�lanmas� ile ama tek y�nl� ba�lanmas� ile 
// olu�turdu�umuz listelerdir.

// Ba�l� listedeki en �nemli �eylerden birisi ilk eleman�n yani struct'�n adresidir.

#include <stdio.h>
#include <stdlib.h>

// Ba�l� listelerde herbir struct'a Node (D���m) denir.
typedef struct Node
{
	// Birden fazla data (veri) struct i�erisinde tutulabilir fakat biz bu konuyu anlmak i�in sadece bir tane tutaca��z.
	int data; // Struct i�erisinde hem veri tutaca��z
	struct Node* next; // hem de kendi cinsinden bir pointer'� tutarak bir sonraki struct'� �a��raca��z.
} node;

void write_linked_list(struct Node* n) // n yerine head_of_list veya root da yaz�labilir.
{
	node* temp = n; // As�l linked list'deki adresleri kaybetmemek i�in
	// bu adresleri tutucu bir de�i�kene at�yoruz. ��nk� �nemli olan ilk eleman�n adresidir.

	// temp yerine de iter yaz�labilir. Bu da ge�ici demektir.
	while (temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
}

int main()
{
	node* n = (node*)malloc(sizeof(node));
	n->data = 2;
	n->next = NULL; // n->next e�er ba�l� listenin son eleman�ysa NULL'a e�it olur.

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

	return 0;
}
