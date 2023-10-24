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

int main()
{
	node* n = (node*)malloc(sizeof(node));
	n->data = 2;
	n->next = NULL; // n->next e�er ba�l� listenin son eleman�ysa NULL'a e�it olur.

	return 0;
}
