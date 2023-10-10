#include <stdio.h> // Her zaman ilk olarak eklenmesi gereken k�t�phane.
#include <stdlib.h> // malloc() fonksiyonunu kullanabilmek i�in bu k�t�phaneyi dosyam�za eklemeliyiz.

int main()
{
	int* ptr;
	int sutunSayisi; // Bir boyutlu dizi i�in ayn� zamanda eleman say�s� anlam�na da geliyor.

	printf("S�tun say�s�n� giriniz: ");
	scanf_s("%d", &sutunSayisi);

	ptr = (int*)malloc(sizeof(int) * sutunSayisi); // malloc() fonksiyonu ile integer (4 byte) * sutun say�s� kadar alan� ptr pointer�na ay�r�yoruz.
	// (int*) ise integer pointer'a bu alan ay�raca��m�z� s�ylemek i�indir.

	for (int i = 0; i < sutunSayisi; i++)
	{
		*(ptr + i) = rand() % 100; // 1 ile 100 aras� rastgele say� �retir.
		printf("%d ", *(ptr + i));
	}
}
