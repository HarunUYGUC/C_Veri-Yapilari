#include <stdio.h>

// Hash Tablosunu Tutacak Dizi
// Quadratic Probing için dizimiz kesinlikle asal sayýda eleman içermelidir.
int dizi[7];

// Yazdýr
void yazdir()
{
	printf("\n ***** Dizinin Elemanlari *****");

	for (int i = 0; i < 7; i++)
	{
		printf("\n %d. indis ==> %d", i, dizi[i]);
	}
}

// eklenecek_sayi % dizinin_eleman_sayisi = indise_eklenecek
int hash(int gelen)
{
	return gelen % 7;
}

// Ekle
void insert(int eklenecek)
{
	// Ýndisi buluyoruz.
	int konum = hash(eklenecek);

	// Konum boþ ise.
	if (dizi[konum] == 0)
	{
		dizi[konum] = eklenecek;
	}
	// Çakýþma var ise. Yani konumda baþka eleman varsa.
	else
	{
		for (int i = 0; i < 7; i++)
		{
			// Quadratic Probing Formülü
			int kontrol = (konum + i*i) % 7;

			if (dizi[kontrol] == 0)
			{
				dizi[kontrol] = eklenecek;
				return;
			}
		}
	}
}

int main()
{
	// Konum boþ.
	insert(3);
	insert(5);
	insert(22);
	yazdir();

	// Konum dolu. Baþka indise eklenir.
	insert(10);
	insert(17);
	yazdir();
}
