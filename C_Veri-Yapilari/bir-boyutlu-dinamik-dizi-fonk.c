//AS
#include <stdio.h>
#include <stdlib.h>

void bir_boyutlu_matris_olustur(int** ptr, int sutunSayisi)
{
	*ptr = (int*)malloc(sizeof(int) * sutunSayisi);

	for (int i = 0; i < sutunSayisi; i++)
	{
		*(*ptr + i) = rand() % 100;
		printf("%d \t", *(*ptr + i));
	}
}

int main()
{
	int sutunSayisi;
	int* ptr;

	printf("Sütun sayýsýný giriniz: ");
	scanf_s("%d", &sutunSayisi);

	bir_boyutlu_matris_olustur(&ptr, sutunSayisi);

	return 0;
}
