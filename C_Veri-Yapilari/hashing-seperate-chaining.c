#include <stdio.h>
#include <stdlib.h>

// Linked List Yap�s�
struct node
{
	int data;
	struct node* next;
};

// Hash Tablosunu Tutacak Dizi
// Elemanlar linked list yap�s�nda saklanaca�� i�in dizinin veri tipi b�yle olmal�d�r.
struct node* dizi[10];

// D���m Olu�tur
struct node* create_node()
{
	struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));

	yeniDugum->data = 0;
	yeniDugum->next = NULL;

	return yeniDugum;
}

// Dizinin i�erisini varsay�lan olarak dolduruyoruz.
void init()
{
	for (int i = 0; i < 10; i++)
	{
		dizi[i] = create_node();
	}
}

// Hash
int hash(int gelen)
{
	return gelen % 10;
}

// Ekle
void insert(int eklenecek)
{
	// �ndisi buluyoruz.
	int konum = hash(eklenecek);

	// Konum bo� ise.
	if (dizi[konum]->data == 0)
	{
		dizi[konum]->data = eklenecek;
	}
	// �ak��ma var ise. Yani konumda ba�ka eleman varsa.
	else
	{
		struct node* yeniDugum = create_node();
		yeniDugum->data = eklenecek;

		// Diziyi dola��yoruz. (Traverse)
		struct node* temp = dizi[konum];

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = yeniDugum;
	}
}

// Ara
struct node* search(int aranan)
{
	int konum = hash(aranan);

	// �ak��ma yok. Yani linked list'in ilk eleman� diyebiliriz.
	if (dizi[konum]->data == aranan)
	{
		return dizi[konum];
	}
	// �ak��ma var. Yani linked list'deki 1. elemandan sonra herhangi bir yerde.
	else
	{
		// Arama ��lemi (Traversse)
		struct node* temp = dizi[konum];

		while (temp != NULL)
		{
			if (temp->data == aranan)
			{
				return temp;
			}

			temp = temp->next;
		}
	}
}

// Yazd�r
void yazdir()
{
	for (int i = 0; i < 10; i++)
	{
		printf("\n %d. indis ==> %d", i, dizi[i]->data);
		struct node* temp = dizi[i]->next;

		while (temp != NULL)
		{
			printf(" => %d", temp->data);
			temp = temp->next;
		}
	}

	printf("\n **********************");
}

int main()
{
	// Dizinin i�erisini 0 ile doldurduk.
	init();
	yazdir();

	// �ak��ma yok. Eklenmesi gereken yere eklenir.
	insert(19);
	insert(25);
	insert(13);
	yazdir();

	// �ak��ma var. Eklenecek eleman o indesteki elemana linked list olarak eklenir.
	insert(225);
	insert(325);
	insert(555);
	insert(223);
	yazdir();

	// Ara
	// Bulunan
	struct node* aranan = search(25);

	if (aranan == NULL)
		printf("\n Bulunamadi...");
	else
		printf("\n Bulundu... %d", aranan->data);

	// Bulunmayan
	struct node* aranan2 = search(355);

	if (aranan2 == NULL)
		printf("\n Bulunamadi...");
	else
		printf("\n Bulundu... %d", aranan2->data);

	yazdir();
}
