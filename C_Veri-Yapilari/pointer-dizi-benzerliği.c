#include <stdio.h>
#include <stdlib.h>

int main()
{
	int dizi[] = { 1, 2, 3 };

	printf("Dizinin ilk eleman�: %d \n", dizi[0]);
	printf("Dizinin adresi: %p \n", &dizi);
	// Dizinin adresi ile dizinin ilk eleman�n adresi ayn�d�r.
	// Diziler dizideki ilk eleman�n adresinde tutulurlar.

	printf("Dizinin ilk eleman�n�n adresi: %p \n", &dizi[0]);
	printf("Dizinin ikinci eleman�n�n adresi: %p \n", &dizi[1]);
	printf("Dizinin ���nc� eleman�n�n adresi: %p \n", &dizi[2]);
	
	printf("Dizinin adresi: %p \n", dizi); // Di�er bir de�i�le diziler ilk eleman�n adresini tutar.
	// Dizilerde t�pk� pointerlar gibi kullan�labilir. Sadece ad�n� yazarak ilk eleman�n adresine ula�abiliriz.
	// Dizi ile pointer'�n en b�y�k ortak �zelli�i.

	printf("Dizinin ilk eleman�: %d \n", *dizi);
	printf("Dizinin ikinci eleman�: %d \n", *(dizi + 1));
	printf("Dizinin ���nc� eleman�: %d \n", *(dizi + 2));
	// (dizi + 1) �eklinde (yani "+i") yaparak bir sonraki adrese ge�i� yap�yoruz. * ile de adresin i�erisindeki de�eri okuyoruz.

	printf("Dizinin ilk eleman�: %d \n", dizi[0]);
	printf("Dizinin ikinci eleman�: %d \n", dizi[1]);
	printf("Dizinin ���nc� eleman�: %d \n", dizi[2]);

	printf("Dizinin ilk eleman�n�n adresi: %p \n", dizi);
	printf("Dizinin ikinci eleman�n�n adresi: %p \n", dizi + 1);
	printf("Dizinin ���nc� eleman�n�n adresi: %p \n", dizi + 2);

	// Dizinin adersi ile i�erisindeki ilk eleman�n adresi ayn�d�r.
	// Pointer'lar ise i�erisindeki eleman�n adresiyle ayn� adreste de�ildir. Pointer'lar�n kendi adresi vard�r.

	return 0;
}
