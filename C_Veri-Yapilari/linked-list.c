// Baðlý listeler, struct pointerlarýn birbirlerine baðlanmasý ile ama tek yönlü baðlanmasý ile 
// oluþturduðumuz listelerdir.

// Baðlý listedeki en önemli þeylerden birisi ilk elemanýn yani struct'ýn adresidir.

#include <stdio.h>
#include <stdlib.h>

// Baðlý listelerde herbir struct'a Node (Düðüm) denir.
typedef struct Node
{
	// Birden fazla data (veri) struct içerisinde tutulabilir fakat biz bu konuyu anlmak için sadece bir tane tutacaðýz.
	int data; // Struct içerisinde hem veri tutacaðýz
	struct Node* next; // hem de kendi cinsinden bir pointer'ý tutarak bir sonraki struct'ý çaðýracaðýz.
} node;

void write_linked_list(struct Node* n) // n yerine head_of_list veya root da yazýlabilir.
{
	node* temp = n; // Asýl linked list'deki adresleri kaybetmemek için
	// bu adresleri tutucu bir deðiþkene atýyoruz. Çünkü önemli olan ilk elemanýn adresidir.

	// temp yerine de iter yazýlabilir. Bu da geçici demektir.
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
	n->next = NULL; // n->next eðer baðlý listenin son elemanýysa NULL'a eþit olur.

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
