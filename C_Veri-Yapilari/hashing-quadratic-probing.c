#include <stdio.h>

// Hash Tablosunu Tutacak Dizi
// Quadratic Probing i�in dizimiz kesinlikle asal say�da eleman i�ermelidir.
int dizi[7];

// Yazd�r
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
	// �ndisi buluyoruz.
	int konum = hash(eklenecek);

	// Konum bo� ise.
	if (dizi[konum] == 0)
	{
		dizi[konum] = eklenecek;
	}
	// �ak��ma var ise. Yani konumda ba�ka eleman varsa.
	else
	{
		for (int i = 0; i < 7; i++)
		{
			// Quadratic Probing Form�l�
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
	// Konum bo�.
	insert(3);
	insert(5);
	insert(22);
	yazdir();

	// Konum dolu. Ba�ka indise eklenir.
	insert(10);
	insert(17);
	yazdir();
}
