#include <stdio.h>
#include <stdlib.h>

void sayinin_iki_kati(int x) // Value (De�er) Tipinde Parametre Al�r
{
	x = x * 2;
	// main() scope'undan ��kt���m�z ve de�i�kenin adresini g�ndermek yerine sadece de�i�kenin de�erini g�nderdi�imiz i�in
	// buradaki de�i�iklik main() scope'undaki de�i�keni etkilemez.
}

void sayinin_uc_kati(int* ptr) // Referance (Adres) Tipinde Parametre Al�r
{
	*ptr = (*ptr) * 3;
	// pointer'�n i�erisindeki adresteki de�ere pointer'�n i�erisindeki adresteki de�erin 3 kat�n� atad�k.
	// main() scope'unun d���nday�z fakat de�i�kenin adresini g�nderdi�imiz i�in main() scope'undaki de�i�keni etkiler.
}

int main()
{
	int x = 20;
	int* ptr;

	ptr = &x;

	printf("x'in de�eri: %d \n", x);

	sayinin_iki_kati(x); // Sadece x de�i�keninin de�erini g�nderiyoruz.
	printf("sayinin_iki_kati() fonksiyonundan x'in de�eri: %d \n", x);

	sayinin_uc_kati(ptr); // x de�i�keninin adresini g�nderiyoruz.
	printf("sayinin_uc_kati() fonksiyonundan x'in de�eri: %d \n", x);

	return 0;
}
