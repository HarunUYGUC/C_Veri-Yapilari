#include <stdio.h>
#include <stdlib.h>


int main()
{
	int a = 20;
	int* ptr;
	int** ptr2;
	int*** ptr3;

	printf("a deðiþkeninin deðeri: %d \n", a);
	printf("a'nýn adresi: %p \n", &a);

	printf("--------------------- \n");
	ptr = &a;

	printf("%p \n", ptr);
	printf("%p \n", &ptr);
	printf("%d \n", *ptr);

	printf("--------------------- \n");
	ptr2 = &ptr;

	printf("%p \n", ptr2);
	printf("%p \n", &ptr2);
	printf("%p \n", *ptr2);
	printf("%d \n", **ptr2);

	printf("--------------------- \n");
	ptr3 = &ptr2;

	printf("%p \n", ptr3); // ptr2'nin adresi.
	printf("%p \n", &ptr3); 
	printf("%p \n", *ptr3); // ptr'nin adresi.
	printf("%p \n", **ptr3); // a'nýn adresi.
	printf("%d \n", ***ptr3); // a'nýn deðeri.

	return 0;
}
