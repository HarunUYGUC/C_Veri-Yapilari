#include <stdio.h>
#include <stdlib.h>

void sayinin_iki_kati(int x) // Value (Deðer) Tipinde Parametre Alýr
{
	x = x * 2;
	// main() scope'undan çýktýðýmýz ve deðiþkenin adresini göndermek yerine sadece deðiþkenin deðerini gönderdiðimiz için
	// buradaki deðiþiklik main() scope'undaki deðiþkeni etkilemez.
}

void sayinin_uc_kati(int* ptr) // Referance (Adres) Tipinde Parametre Alýr
{
	*ptr = (*ptr) * 3;
	// pointer'ýn içerisindeki adresteki deðere pointer'ýn içerisindeki adresteki deðerin 3 katýný atadýk.
	// main() scope'unun dýþýndayýz fakat deðiþkenin adresini gönderdiðimiz için main() scope'undaki deðiþkeni etkiler.
}

int main()
{
	int x = 20;
	int* ptr;

	ptr = &x;

	printf("x'in deðeri: %d \n", x);

	sayinin_iki_kati(x); // Sadece x deðiþkeninin deðerini gönderiyoruz.
	printf("sayinin_iki_kati() fonksiyonundan x'in deðeri: %d \n", x);

	sayinin_uc_kati(ptr); // x deðiþkeninin adresini gönderiyoruz.
	printf("sayinin_uc_kati() fonksiyonundan x'in deðeri: %d \n", x);

	return 0;
}
