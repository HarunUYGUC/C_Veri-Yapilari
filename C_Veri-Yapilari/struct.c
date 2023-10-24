#include <stdio.h>
#include <stdlib.h>

// Bu �ekilde sturct olu�turursak bu struct'tan bir de�i�ken �retmek istersek "struct Person p1" gibi uzun bir kod yazm�� oluyoruz.
// Daha k�sa kod yazmak i�in a�a��daki �ekilde typedef komutunu kullanarak yapabiliriz.

//struct Person
//{
//	char* name;
//	int age;
//};

// Bundan sonra "struct Person p1" yazmak yerine "person p1" yazabiliriz.
typedef struct Person
{
	char* name;
	int age;
} person;

typedef struct Student
{
	int schoolNumber;
	struct Person p; // struct i�erisinde struct yapm�� olduk.
	// ��nk� ��renci ayn� zamanda bir ki�idir ve ki�ideki �zellikleri de kullanabilmelidir.
} student;

// Bu fonksiyon bu �ekilde hata verir ��nk� struct'� biz main() i�erisinde tan�mlad�k. 
// Bu fonksiyon o yap�ya ula�amayaca�� i�in .name ve .age bilgisine ula�amaz.
// Struct'lar referans de�il adres tipli oldu�u i�in fonksiyona struct'�n adresini g�ndermemiz gerekmektedir.
// Veya struct'� main() fonksiyonunu d���nda yani global olarak tan�mlamal�y�z. Bu y�ntem daha mant�kl� ve zaten 
// genelde �yle yap�l�r.
void display_person(struct Person p) // Global typedef'li struct sonras�nda "struct Person p" yerine "person p" yapabiliriz.
{
	printf("Person's name: %s \n", p.name);
	printf("Person's age: %d \n", p.age);
}

void display_student(student s)
{
	printf("Student's school number: %d \n", s.schoolNumber);
	printf("Student's name: %s \n", s.p.name);
	printf("Student's age: %d \n", s.p.age);
}

int main()
{
	// struct'lar birden fazla farkl� de��ikeni i�erisinde bar�nd�rabilir.
	// Buna Nesne Y�nelimli dillerde Class denir.

	// struct'� main() i�erisinde de�il, global olarak tan�mlayaca��z. ��nk� main() i�erisinde
	// tan�mlarsak a��klad���m hata ortaya ��kacakt�r.

	//struct Person // Bunu s�n�f ismi gibi d���nebiliriz.
	//{
	//	char* name;
	//	int age;
	//};

	//struct Person p1; // Struct yap�s�ndan bir de�i�ken �retmek istersek 
	// bu �ekilde bir kullan�m yapmal�y�z. Person struct'�ndan p1 de�i�kenini �rettik.
	// Person s�n�f�ndan p1 nesnesini olu�turduk gibi d���nebiliriz.

	// Global typedef'li struct sonras�nda "struct Person p1" yerine "person p1" yapabiliriz.
	person p1;

	// Di�er de�i�kenlerin kullan�m� a�a��daki �ekildeydi.
	int x = 5;
	printf("%d \n", x);

	int* ptr = &x;
	printf("%d \n", *ptr);
	
	// struct'�n kullan�m� ise bu �ekildedir.
	p1.name = "Ahmet";
	p1.age = 20;

	printf("Person's name: %s \n", p1.name);
	printf("Person's age: %d \n", p1.age);

	printf("-------------------- \n");

	display_person(p1); // Burada fonksiyona p1'in adresini g�nderiyoruz fakat fonksiyon bu adrese ula�am�yor.
	// Fonksiyonun bu adrese ula�mas� i�in bizim bu struct'tan �retilmi� p1 de�i�keninin adresini pointer'a atay�p
	// pointer'�n adresini fonksiyon'a g�ndermeliyiz.
	// Veya struct'� main() fonksiyonunu d���nda yani global olarak tan�mlamal�y�z. Bu y�ntem daha mant�kl� ve zaten 
	// genelde �yle yap�l�r.

	printf("-------------------- \n");

	student s1;
	s1.schoolNumber = 2000;
	s1.p.age = 18; // struct i�erisindeki struct'a bu �ekilde ula��r�z.
	s1.p.name = "Ali";

	display_student(s1);

	printf("-------------------- \n");
	// printf("-------------------- \n"); aras�ndaki kodlar bende nedense �al��m�yor.

	// person* ptr = &p1; // struct tipinde pointer olu�turduk.
	// int* ptr ile asl�nda ayn�. Sonu�ta person struct'� da bir veri tipi

	// ptr = &p1; // Person struct'�ndan �retti�imiz p1 de�i�keninin adresini struct pointer'�na atad�k.
	
	// Normalde pointer'�n i�erisindeki adresteki de�ere ula�mak i�in pointer'�n ba��na * koyar�z ve i�erisine gireriz
	// fakat struct pointer'da b�yle bir �ey yapamay�z ��nk� i�erisinde sadece bir adres yok,
	// birden fazla de�i�ken oldu�u i�in birden fazla adres var.
	// Bu sorunun ��z�m� "ptr->name" �eklindedir.

	// printf("Person's name: %s \n", ptr->name);
	// printf("Person's age: %d \n", ptr->age);

	printf("-------------------- \n");

	person p;

	p.age = 20;
	p.name = "Ahmet";

	// Struct'lar t�pk� diziler gibi ilk eleman�n adresine kay�tl�d�rlar.
	// Struct i�erisinde ilk hangi de�i�ken varsa o de��ikenin adresi ile struct'�n adresi ayn�d�r. 
	printf("Struct'�n adresi: %p \n", &p);
	printf("Struct i�erisindeki name'in adresi: %p \n", &(p.name));
	printf("Struct i�erisindeki age'in adresi: %p \n", &(p.age));

	person* prs;
	prs = &p;

	printf("p.age'in adresi: %p \n", &(prs->age));

	printf("-------------------- \n");

	student* std;

	std = (student*)malloc(sizeof(student));

	std->schoolNumber = 2005;
	std->p.name = "Kyle";
	std->p.age = 21;

	// struct Student i�erisindeki struct Person p; yi struct Person* p; �eklinde pointer olarak tan�mlarsak
	// std->p.name = "Kyle"; olarak de�il std->p->name = "Kyle"; olarak tan�mlamal�y�z.

	printf("std pointer'�n adresi: %p \n", &std);
	printf("student'�n adresi: %p \n", std);
	printf("student'�n schoolNumber'�n�n adresi: %p \n", &(std->schoolNumber));
	printf("student'�n person'�n�n adresi: %p \n", &(std->p));
	printf("student'�n person'�n�n name'inin adresi: %p \n", &(std->p.name));
	printf("student'�n person'�n�n age'inin adresi: %p \n", &(std->p.age));

	return 0;
}
