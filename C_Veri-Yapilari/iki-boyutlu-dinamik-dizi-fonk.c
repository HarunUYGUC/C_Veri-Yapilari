#include <stdio.h>
#include <stdlib.h>

void iki_boyutlu_matris_olustur(int*** matris, int satir_sayisi, int sutun_sayisi)
{
	// Fonksiyona matrisin adresini gönderdiðimiz için bir katman yukarýya çýkmýþ oluyoruz.
	// Bu yüzden fonksiyonda matris için 3 tane yýldýz kullanmamýz gerekiyor.

	*matris = (int**)malloc(sizeof(int*) * satir_sayisi); // Burada da direkt matris = diyerek bellekte yer ayýrmayý yapamayýz.
	// Çünkü fonksiyona biz matris'in adresini gönderdik ve buradaki matris deðiþkeni içerisinde adres tutuyor. Bizim bu adresin 
	// içerisine ulaþmamýz lazým ve bunu için * komutunu kullanmalýyýz. 
	// Fonksiyonsuz programda ise direkt ptr yazarak yani yýldýz kullanmadan yaptýk çünkü orada ptr direkt içerisindeki ilk adrese
	// iþaret edecektir.

	for (int i = 0; i < satir_sayisi; i++)
	{
		*(*matris + i) = (int*)malloc(sizeof(int) * sutun_sayisi);

		for (int j = 0; j < sutun_sayisi; j++)
		{
			*(*(*matris + i) + j) = rand() % 100;
			printf("%d \t", *(*(*matris + i) + j));
		}

		printf("\n");
	}
}

int main()
{
	int** matris; // Ýki tane yýldýz kullanarak iki boyutlu bir matris oluþturduk.

	int satirSayisi, sutunSayisi;

	printf("Satýr sayýsýný giriniz: ");
	scanf_s("%d", &satirSayisi);

	printf("Sütun sayýsýný giriniz: ");
	scanf_s("%d", &sutunSayisi);

	iki_boyutlu_matris_olustur(&matris, satirSayisi, sutunSayisi); // Fonksiyona bu matrisin adresini göndermemiz gerekiyor. Yani aslýnda bir katman yukarýya 
	// çýkmýþ oluyoruz. Bu yüzden fonksiyonda matris için 3 tane yýldýz kullanmamýz gerekiyor.

	return 0;
}
