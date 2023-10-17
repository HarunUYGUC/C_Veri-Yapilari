#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 10;
	int* ptr;

	ptr = &a;

	printf("a deðiþkeninin deðeri: %d \n", a);
	printf("a'nýn adresi: %p \n", &a);
	printf("Pointer'ýn içerisindeki adres. (a'nýn adresi.): %p \n", ptr);
	printf("Pointer'ýn içerisindeki adresteki deðer. (a'nýn deðeri.): %d \n", *ptr);
	printf("Pointer'ýn adresi: %p \n", &ptr);

	int** ptr2;

	ptr2 = ptr;
	printf("Pointer2'nin içerisindeki adres. (a'nýn adresi.): %p \n", ptr2);
	// ptr'nin içerisindeki adresi ptr2'ye atadýðýmýz için yine a'nýn adresine ulaþýrýz. 
	// Bu kullaným biraz saçma. Sadece mantýðýný göstermek için yaptým. Asýl kullaným aþaðýdaki gibidir.

	ptr2 = &ptr;
	printf("Pointer2'nin içerisindeki adres. (ptr'nin adresi.): %p \n", ptr2);
	printf("Pointer2'nin içerisindeki adresteki adres. (a'nýn adresi.): %p \n", *ptr2);
	// Deðer deðil adres dedik çünkü ptr2, 2 katmanlý bir pointerdýr. Yani tuttuðu adresteki adres yine bir adres tutar. 
	printf("Pointer2'nin içerisindeki adresteki adresteki deðer. (a'nýn deðeri.): %d \n", **ptr2);
	// 2 katmanlý bir pointer yaptýðýmýz için 2. yýldýzda (*) artýk asýl tuttuðumuz deðere ulaþýrýz.

	return 0;
}
