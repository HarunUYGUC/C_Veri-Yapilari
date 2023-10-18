#include <stdio.h>
#include <stdlib.h>

int main()
{
	int dizi[] = { 1, 2, 3 };

	printf("Dizinin ilk elemaný: %d \n", dizi[0]);
	printf("Dizinin adresi: %p \n", &dizi);
	// Dizinin adresi ile dizinin ilk elemanýn adresi aynýdýr.
	// Diziler dizideki ilk elemanýn adresinde tutulurlar.

	printf("Dizinin ilk elemanýnýn adresi: %p \n", &dizi[0]);
	printf("Dizinin ikinci elemanýnýn adresi: %p \n", &dizi[1]);
	printf("Dizinin üçüncü elemanýnýn adresi: %p \n", &dizi[2]);
	
	printf("Dizinin adresi: %p \n", dizi); // Diðer bir deðiþle diziler ilk elemanýn adresini tutar.
	// Dizilerde týpký pointerlar gibi kullanýlabilir. Sadece adýný yazarak ilk elemanýn adresine ulaþabiliriz.
	// Dizi ile pointer'ýn en büyük ortak özelliði.

	printf("Dizinin ilk elemaný: %d \n", *dizi);
	printf("Dizinin ikinci elemaný: %d \n", *(dizi + 1));
	printf("Dizinin üçüncü elemaný: %d \n", *(dizi + 2));
	// (dizi + 1) þeklinde (yani "+i") yaparak bir sonraki adrese geçiþ yapýyoruz. * ile de adresin içerisindeki deðeri okuyoruz.

	printf("Dizinin ilk elemaný: %d \n", dizi[0]);
	printf("Dizinin ikinci elemaný: %d \n", dizi[1]);
	printf("Dizinin üçüncü elemaný: %d \n", dizi[2]);

	printf("Dizinin ilk elemanýnýn adresi: %p \n", dizi);
	printf("Dizinin ikinci elemanýnýn adresi: %p \n", dizi + 1);
	printf("Dizinin üçüncü elemanýnýn adresi: %p \n", dizi + 2);

	// Dizinin adersi ile içerisindeki ilk elemanýn adresi aynýdýr.
	// Pointer'lar ise içerisindeki elemanýn adresiyle ayný adreste deðildir. Pointer'larýn kendi adresi vardýr.

	return 0;
}
