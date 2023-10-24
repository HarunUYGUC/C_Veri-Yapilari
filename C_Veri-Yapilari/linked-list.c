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

int main()
{
	node* n = (node*)malloc(sizeof(node));
	n->data = 2;
	n->next = NULL; // n->next eðer baðlý listenin son elemanýysa NULL'a eþit olur.

	return 0;
}
