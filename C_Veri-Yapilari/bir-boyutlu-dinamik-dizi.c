#include <stdio.h> // Her zaman ilk olarak eklenmesi gereken kütüphane.
#include <stdlib.h> // malloc() fonksiyonunu kullanabilmek için bu kütüphaneyi dosyamýza eklemeliyiz.

int main()
{
	int* ptr;
	int sutunSayisi; // Bir boyutlu dizi için ayný zamanda eleman sayýsý anlamýna da geliyor.

	printf("Sütun sayýsýný giriniz: ");
	scanf_s("%d", &sutunSayisi);

	ptr = (int*)malloc(sizeof(int) * sutunSayisi); // malloc() fonksiyonu ile integer (4 byte) * sutun sayýsý kadar alaný ptr pointerýna ayýrýyoruz.
	// (int*) ise integer pointer'a bu alan ayýracaðýmýzý söylemek içindir.

	for (int i = 0; i < sutunSayisi; i++)
	{
		*(ptr + i) = rand() % 100; // 1 ile 100 arasý rastgele sayý üretir.
		printf("%d ", *(ptr + i));
	}
}
