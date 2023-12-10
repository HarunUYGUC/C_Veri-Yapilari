#include <stdio.h>

// Hash Tablosunu Tutacak Dizi
int dizi[10];

// Yazd�r
void yazdir()
{
	printf("\n **** Dizinin mevcut elemanlari...");

	for (int i = 0; i < 10; i++)
	{
		printf("\n %d. indis ==> %d", i, dizi[i]);
	}
}

// eklenecek_sayi % dizinin_eleman_sayisi = indise_eklenecek
int hash(int gelen)
{
	return gelen % 10;
}

// Ekle
void insert(int eklenecek)
{
	// �ndisi buluyoruz.
	int konum = hash(eklenecek);

	// Dizi bo� ise.
	if (dizi[konum] == 0)
	{
		dizi[konum] = eklenecek;
	}
	// �ak��ma var ise.
	else
	{
		// Dizide dola�ma (traverse) i�lemi yapaca��z.
		int temp = konum;

		// Bo� yer bulmaya �al���yoruz.
		while (dizi[temp] != 0)
		{
			/* Dizinin eleman say�s�n� ge�memesi i�in tekrar dizinin
			eleman say�s�na g�re modunu al�yoruz. Yani dizinin sonuna
			kadar yer yoksa dizinin ba��na d�n�yoruz ve orada yer ar�yoruz. */
			temp = (temp + 1) % 10;

			/* D�nd�k dola�t�k tekrar ba�a d�nd�k.
			Yani dizide bo� yer yok. */
			if (temp == konum)
			{
				printf("\n !!!!! Bos Yer Yok !!!!!");
				return;
			}
		}

		dizi[temp] = eklenecek;
	}
}

// Ara
void ara(int aranan)
{
	// �ndisi buluyoruz.
	int konum = hash(aranan);

	// Olmas� gereken indiste ise.
	if (dizi[konum] == aranan)
	{
		printf("\n %d sayisi olmasi gereken indiste bulundu. Konum = %d", aranan, konum);
		return;
	}

	// Diziyi dola��yoruz.
	int temp = konum;

	while (dizi[temp] != 0)
	{
		temp = (temp + 1) % 10;

		// Olmas� gereken indis dolu. Ba�ka indiste ise.
		if (dizi[temp] == aranan)
		{
			printf("\n %d sayisi farkli indiste bulundu. Konum = %d", aranan, temp);
			return;
		}

		// Eleman yok ise.
		if (temp == konum)
		{
			printf("\n %d sayisi bulunamadi...", aranan);
			return;
		}
	}
}

// Main
int main()
{
	yazdir();

	// �ak��ma yok.
	insert(10);
	insert(11);
	insert(22);
	insert(77);
	insert(88);
	yazdir();

	// �ak��ma var.
	insert(67);
	insert(888);
	insert(112);
	insert(777);
	insert(221);
	yazdir();

	// Dizi doldu.
	insert(666);
	yazdir();

	// Ara. Dizide olan ve olmas� gereken indiste olan elemanlar.
	ara(77);
	ara(88);
	yazdir();

	// Ara. Dizide olan ama ba�ka indiste olan elemanlar.
	ara(221);
	ara(777);
	ara(888);
	yazdir();

	// Ara. Dizide olmayan elemanlar.
	ara(666);
	yazdir();
}
