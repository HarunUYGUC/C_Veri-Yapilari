#include <stdio.h>

// Hash Tablosunu Tutacak Dizi
int dizi[10];

// Yazdýr
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
	// Ýndisi buluyoruz.
	int konum = hash(eklenecek);

	// Dizi boþ ise.
	if (dizi[konum] == 0)
	{
		dizi[konum] = eklenecek;
	}
	// Çakýþma var ise.
	else
	{
		// Dizide dolaþma (traverse) iþlemi yapacaðýz.
		int temp = konum;

		// Boþ yer bulmaya çalýþýyoruz.
		while (dizi[temp] != 0)
		{
			/* Dizinin eleman sayýsýný geçmemesi için tekrar dizinin
			eleman sayýsýna göre modunu alýyoruz. Yani dizinin sonuna
			kadar yer yoksa dizinin baþýna dönüyoruz ve orada yer arýyoruz. */
			temp = (temp + 1) % 10;

			/* Döndük dolaþtýk tekrar baþa döndük.
			Yani dizide boþ yer yok. */
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
	// Ýndisi buluyoruz.
	int konum = hash(aranan);

	// Olmasý gereken indiste ise.
	if (dizi[konum] == aranan)
	{
		printf("\n %d sayisi olmasi gereken indiste bulundu. Konum = %d", aranan, konum);
		return;
	}

	// Diziyi dolaþýyoruz.
	int temp = konum;

	while (dizi[temp] != 0)
	{
		temp = (temp + 1) % 10;

		// Olmasý gereken indis dolu. Baþka indiste ise.
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

	// Çakýþma yok.
	insert(10);
	insert(11);
	insert(22);
	insert(77);
	insert(88);
	yazdir();

	// Çakýþma var.
	insert(67);
	insert(888);
	insert(112);
	insert(777);
	insert(221);
	yazdir();

	// Dizi doldu.
	insert(666);
	yazdir();

	// Ara. Dizide olan ve olmasý gereken indiste olan elemanlar.
	ara(77);
	ara(88);
	yazdir();

	// Ara. Dizide olan ama baþka indiste olan elemanlar.
	ara(221);
	ara(777);
	ara(888);
	yazdir();

	// Ara. Dizide olmayan elemanlar.
	ara(666);
	yazdir();
}
