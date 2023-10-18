#include <stdio.h>
#include <stdlib.h>

void iki_boyutlu_matris_olustur(int*** matris, int satir_sayisi, int sutun_sayisi)
{
	// Fonksiyona matrisin adresini g�nderdi�imiz i�in bir katman yukar�ya ��km�� oluyoruz.
	// Bu y�zden fonksiyonda matris i�in 3 tane y�ld�z kullanmam�z gerekiyor.

	*matris = (int**)malloc(sizeof(int*) * satir_sayisi); // Burada da direkt matris = diyerek bellekte yer ay�rmay� yapamay�z.
	// ��nk� fonksiyona biz matris'in adresini g�nderdik ve buradaki matris de�i�keni i�erisinde adres tutuyor. Bizim bu adresin 
	// i�erisine ula�mam�z laz�m ve bunu i�in * komutunu kullanmal�y�z. 
	// Fonksiyonsuz programda ise direkt ptr yazarak yani y�ld�z kullanmadan yapt�k ��nk� orada ptr direkt i�erisindeki ilk adrese
	// i�aret edecektir.

	for (int i = 0; i < satir_sayisi; i++)
	{
		*(*matris + i) = (int*)malloc(sizeof(int) * sutun_sayisi);

		for (int j = 0; j < sutun_sayisi; j++)
		{
			*(*(*matris + i) + j) = rand() % 100;
			printf("%d \t", *(*(*matris + i) + j));
		}

		printf("\n");
	}
}

int main()
{
	int** matris; // �ki tane y�ld�z kullanarak iki boyutlu bir matris olu�turduk.

	int satirSayisi, sutunSayisi;

	printf("Sat�r say�s�n� giriniz: ");
	scanf_s("%d", &satirSayisi);

	printf("S�tun say�s�n� giriniz: ");
	scanf_s("%d", &sutunSayisi);

	iki_boyutlu_matris_olustur(&matris, satirSayisi, sutunSayisi); // Fonksiyona bu matrisin adresini g�ndermemiz gerekiyor. Yani asl�nda bir katman yukar�ya 
	// ��km�� oluyoruz. Bu y�zden fonksiyonda matris i�in 3 tane y�ld�z kullanmam�z gerekiyor.

	return 0;
}
