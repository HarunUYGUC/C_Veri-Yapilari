#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** ptr; // Pointer'ýn içerisinde satýrlarýn adresleri tutulurken satýrlarda ki pointer'larda da kendi satýrlarýndaki sütunlarýn adresleri tutulacak.
	// Yani pointerlarý tutan bir pointer oluþturacaðýmýz için pointer'ýn pointer'ýný yani int** ptr'yi tanýmlamalýyýz.
	int satirSayisi, sutunSayisi;

	printf("Satýr sayýsýný giriniz: ");
	scanf_s("%d", &satirSayisi);

	printf("Sütun sayýsýný giriniz: ");
	scanf_s("%d", &sutunSayisi);

	ptr = (int**)malloc(sizeof(int*) * satirSayisi);
	/*
	 (int**) dýþtaki pointerýn içini doldurduðumuz ve dýþtaki pointer'da ikinci katman olduðu için iki tane yýldýz kullanýlýrken
	 sizeof(int*) komutunda ise bir tane yýldýz kullanýrýz. Çünkü pointer'ýn içindeki pointer'larý dolduracaðýz.
	 Tam olarak bu yüzden bir boyutlu dizide her iki komuttaki yýldýzlar bir eksik olarak yapýlýyor. 
	 Çünkü pointer'ýn içerisindeki deðerler doldurulacak.
	 */

	for (int i = 0; i < satirSayisi; i++)
	{
		*(ptr + i) = (int*)malloc(sizeof(int) * sutunSayisi); // Satýrlarýn adreslerini tutan pointer'larýn içerisine sütün sayýsý kadar alan açýyoruz.

		for (int j = 0; j < sutunSayisi; j++)
		{
			*(*(ptr + i) + j) = rand() % 100; // Her satýr ve sütuna rastgele eleman atýyoruz.
			printf("%d \t", *(*(ptr + i) + j)); // \t komutu ile her sütun bittikten sonra bir tab'lýkboþluk oluþturuyoruz ki hem sayýlar karýþmasýn hem de düzgün bir matris þekli oluþsun.
		}

		printf("\n"); // \n komutu ile her satýr bittikten sonra alt satýra geçiyoruz ki düzgün bir matris þekli oluþsun.
	}
}
