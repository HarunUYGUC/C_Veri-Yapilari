#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 10;
	int* ptr;

	ptr = &a;

	printf("a de�i�keninin de�eri: %d \n", a);
	printf("a'n�n adresi: %p \n", &a);
	printf("Pointer'�n i�erisindeki adres. (a'n�n adresi.): %p \n", ptr);
	printf("Pointer'�n i�erisindeki adresteki de�er. (a'n�n de�eri.): %d \n", *ptr);
	printf("Pointer'�n adresi: %p \n", &ptr);

	int** ptr2;

	ptr2 = ptr;
	printf("Pointer2'nin i�erisindeki adres. (a'n�n adresi.): %p \n", ptr2);
	// ptr'nin i�erisindeki adresi ptr2'ye atad���m�z i�in yine a'n�n adresine ula��r�z. 
	// Bu kullan�m biraz sa�ma. Sadece mant���n� g�stermek i�in yapt�m. As�l kullan�m a�a��daki gibidir.

	ptr2 = &ptr;
	printf("Pointer2'nin i�erisindeki adres. (ptr'nin adresi.): %p \n", ptr2);
	printf("Pointer2'nin i�erisindeki adresteki adres. (a'n�n adresi.): %p \n", *ptr2);
	// De�er de�il adres dedik ��nk� ptr2, 2 katmanl� bir pointerd�r. Yani tuttu�u adresteki adres yine bir adres tutar. 
	printf("Pointer2'nin i�erisindeki adresteki adresteki de�er. (a'n�n de�eri.): %d \n", **ptr2);
	// 2 katmanl� bir pointer yapt���m�z i�in 2. y�ld�zda (*) art�k as�l tuttu�umuz de�ere ula��r�z.

	return 0;
}
