#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** ptr; // Pointer'�n i�erisinde sat�rlar�n adresleri tutulurken sat�rlarda ki pointer'larda da kendi sat�rlar�ndaki s�tunlar�n adresleri tutulacak.
	// Yani pointerlar� tutan bir pointer olu�turaca��m�z i�in pointer'�n pointer'�n� yani int** ptr'yi tan�mlamal�y�z.
	int satirSayisi, sutunSayisi;

	printf("Sat�r say�s�n� giriniz: ");
	scanf_s("%d", &satirSayisi);

	printf("S�tun say�s�n� giriniz: ");
	scanf_s("%d", &sutunSayisi);

	ptr = (int**)malloc(sizeof(int*) * satirSayisi);
	/*
	 (int**) d��taki pointer�n i�ini doldurdu�umuz ve d��taki pointer'da ikinci katman oldu�u i�in iki tane y�ld�z kullan�l�rken
	 sizeof(int*) komutunda ise bir tane y�ld�z kullan�r�z. ��nk� pointer'�n i�indeki pointer'lar� dolduraca��z.
	 Tam olarak bu y�zden bir boyutlu dizide her iki komuttaki y�ld�zlar bir eksik olarak yap�l�yor. 
	 ��nk� pointer'�n i�erisindeki de�erler doldurulacak.
	 */

	for (int i = 0; i < satirSayisi; i++)
	{
		*(ptr + i) = (int*)malloc(sizeof(int) * sutunSayisi); // Sat�rlar�n adreslerini tutan pointer'lar�n i�erisine s�t�n say�s� kadar alan a��yoruz.

		for (int j = 0; j < sutunSayisi; j++)
		{
			*(*(ptr + i) + j) = rand() % 100; // Her sat�r ve s�tuna rastgele eleman at�yoruz.
			printf("%d \t", *(*(ptr + i) + j)); // \t komutu ile her s�tun bittikten sonra bir tab'l�kbo�luk olu�turuyoruz ki hem say�lar kar��mas�n hem de d�zg�n bir matris �ekli olu�sun.
		}

		printf("\n"); // \n komutu ile her sat�r bittikten sonra alt sat�ra ge�iyoruz ki d�zg�n bir matris �ekli olu�sun.
	}
}
