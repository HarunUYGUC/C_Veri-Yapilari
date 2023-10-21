// Bir sorun var ama nedenini bir türlü anlayamadým. Sonuçlar biraz fazla ya da eksik çýkýyor.

#include <stdio.h>
#include <stdlib.h>

void matris_olustur(int*** matris, int satir, int sutun)
{
	*matris = (int**)malloc(sizeof(int*) * satir);

	for (int i = 0; i < satir; i++)
	{
		*(*matris + i) = (int*)malloc(sizeof(int) * sutun);

		for (int j = 0; j < sutun; j++)
		{
			*(*(*matris + i) + j) = rand() % 100;
		}
	}
}

void matris_yaz(int** matris, int satir, int sutun)
{
	for (int i = 0; i < satir; i++)
	{
		for (int j = 0; j < sutun; j++)
		{
			printf("%d \t", *(*matris + i) + j);
		}

		printf("\n");
	}

	printf("\n");
}

int** matris_topla(int** matris1, int satir1, int sutun1, 
	int** matris2, int satir2, int sutun2)
{
	int** matris3;

	matris_olustur(&matris3, satir1, sutun1);

	if ((satir1 == satir2) && (sutun1 == sutun2))
	{
		for (int i = 0; i < satir1; i++)
		{
			for (int j = 0; j < sutun1; j++)
			{
				(*(*(matris3 + i) + j)) = 0;
				// matris3[i][j] = matris1[i][j] + matris2[i][j];
				(*(*(matris3 + i) + j)) += (*(*(matris1 + i) + j)) + (*(*(matris2 + i) + j));
			}
		}

		return matris3;
	}
	else
	{
		printf("Ýki matrisin satýr ve sutun sayýsý eþit olmadýðýndan dolayý matrisler toplanamaz.");
		return 0;
	}
}

int** matris_carp(int** matris1, int satir1, int sutun1, 
	int** matris2, int satir2, int sutun2)
{
	int** matris3;

	matris_olustur(&matris3, satir1, sutun2);

	if (sutun1 == satir2)
	{
		for (int satir = 0; satir < satir1; satir++)
		{
			for (int sutun = 0; sutun < sutun2; sutun++)
			{
				matris3[satir][sutun] = 0;

				for (int eleman = 0; eleman < sutun1; eleman++)
				{
					matris3[satir][sutun] += matris1[satir][eleman] * matris2[eleman][sutun];
				}
			}
		}

		return matris3;
	}
	else
	{
		printf("Birinci matrisin sütun sayýsý ile ikinci matrisin satýr sayýsý eþit olmadýðýndan dolayý matrisler çarpýlamaz.");
		return 0;
	}
}

int main()
{
	int** matris1;
	int** matris2;
	int** matris3;
	int** matris4;

	int satir1, sutun1, satir2, sutun2;

	printf("Satýr sayýsýný giriniz: ");
	scanf_s("%d", &satir1);
	printf("Sütun sayýsýný giriniz: ");
	scanf_s("%d", &sutun1);

	printf("Satýr sayýsýný giriniz: ");
	scanf_s("%d", &satir2);
	printf("Sütun sayýsýný giriniz: ");
	scanf_s("%d", &sutun2);

	matris_olustur(&matris1, satir1, sutun1);
	matris_olustur(&matris2, satir2, sutun2);

	matris_yaz(matris1, satir1, sutun1);
	matris_yaz(matris2, satir2, sutun2);

	matris3 = matris_topla(matris1, satir1, sutun1, 
		matris2, satir2, sutun2);

	matris_yaz(matris3, satir1, sutun1);

	matris4 = matris_carp(matris1, satir1, sutun1,
		matris2, satir2, sutun2);

	matris_yaz(matris3, satir1, sutun2);

	return 0;
}
