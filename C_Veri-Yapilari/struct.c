#include <stdio.h>
#include <stdlib.h>

// Bu şekilde sturct oluşturursak bu struct'tan bir değişken üretmek istersek "struct Person p1" gibi uzun bir kod yazmış oluyoruz.
// Daha kısa kod yazmak için aşağıdaki şekilde typedef komutunu kullanarak yapabiliriz.

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
	struct Person p; // struct içerisinde struct yapmış olduk.
	// Çünkü öğrenci aynı zamanda bir kişidir ve kişideki özellikleri de kullanabilmelidir.
} student;

// Bu fonksiyon bu şekilde hata verir çünkü struct'ı biz main() içerisinde tanımladık. 
// Bu fonksiyon o yapıya ulaşamayacağı için .name ve .age bilgisine ulaşamaz.
// Struct'lar referans değil adres tipli olduğu için fonksiyona struct'ın adresini göndermemiz gerekmektedir.
// Veya struct'ı main() fonksiyonunu dışında yani global olarak tanımlamalıyız. Bu yöntem daha mantıklı ve zaten 
// genelde öyle yapılır.
void display_person(struct Person p) // Global typedef'li struct sonrasında "struct Person p" yerine "person p" yapabiliriz.
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
	// struct'lar birden fazla farklı değşikeni içerisinde barındırabilir.
	// Buna Nesne Yönelimli dillerde Class denir.

	// struct'ı main() içerisinde değil, global olarak tanımlayacağız. Çünkü main() içerisinde
	// tanımlarsak açıkladığım hata ortaya çıkacaktır.

	//struct Person // Bunu sınıf ismi gibi düşünebiliriz.
	//{
	//	char* name;
	//	int age;
	//};

	//struct Person p1; // Struct yapısından bir değişken üretmek istersek 
	// bu şekilde bir kullanım yapmalıyız. Person struct'ından p1 değişkenini ürettik.
	// Person sınıfından p1 nesnesini oluşturduk gibi düşünebiliriz.

	// Global typedef'li struct sonrasında "struct Person p1" yerine "person p1" yapabiliriz.
	person p1;

	// Diğer değişkenlerin kullanımı aşağıdaki şekildeydi.
	int x = 5;
	printf("%d \n", x);

	int* ptr = &x;
	printf("%d \n", *ptr);
	
	// struct'ın kullanımı ise bu şekildedir.
	p1.name = "Ahmet";
	p1.age = 20;

	printf("Person's name: %s \n", p1.name);
	printf("Person's age: %d \n", p1.age);

	printf("-------------------- \n");

	display_person(p1); // Burada fonksiyona p1'in adresini gönderiyoruz fakat fonksiyon bu adrese ulaşamıyor.
	// Fonksiyonun bu adrese ulaşması için bizim bu struct'tan üretilmiş p1 değişkeninin adresini pointer'a atayıp
	// pointer'ın adresini fonksiyon'a göndermeliyiz.
	// Veya struct'ı main() fonksiyonunu dışında yani global olarak tanımlamalıyız. Bu yöntem daha mantıklı ve zaten 
	// genelde öyle yapılır.

	printf("-------------------- \n");

	student s1;
	s1.schoolNumber = 2000;
	s1.p.age = 18; // struct içerisindeki struct'a bu şekilde ulaşırız.
	s1.p.name = "Ali";

	display_student(s1);

	printf("-------------------- \n");
	// printf("-------------------- \n"); arasındaki kodlar bende nedense çalışmıyor.

	// person* ptr = &p1; // struct tipinde pointer oluşturduk.
	// int* ptr ile aslında aynı. Sonuçta person struct'ı da bir veri tipi

	// ptr = &p1; // Person struct'ından ürettiğimiz p1 değişkeninin adresini struct pointer'ına atadık.
	
	// Normalde pointer'ın içerisindeki adresteki değere ulaşmak için pointer'ın başına * koyarız ve içerisine gireriz
	// fakat struct pointer'da böyle bir şey yapamayız çünkü içerisinde sadece bir adres yok,
	// birden fazla değişken olduğu için birden fazla adres var.
	// Bu sorunun çözümü "ptr->name" şeklindedir.

	// printf("Person's name: %s \n", ptr->name);
	// printf("Person's age: %d \n", ptr->age);

	printf("-------------------- \n");

	person p;

	p.age = 20;
	p.name = "Ahmet";

	// Struct'lar tıpkı diziler gibi ilk elemanın adresine kayıtlıdırlar.
	// Struct içerisinde ilk hangi değişken varsa o değşikenin adresi ile struct'ın adresi aynıdır. 
	printf("Struct'ın adresi: %p \n", &p);
	printf("Struct içerisindeki name'in adresi: %p \n", &(p.name));
	printf("Struct içerisindeki age'in adresi: %p \n", &(p.age));

	person* prs;
	prs = &p;

	printf("p.age'in adresi: %p \n", &(prs->age));

	printf("-------------------- \n");

	student* std;

	std = (student*)malloc(sizeof(student));

	std->schoolNumber = 2005;
	std->p.name = "Kyle";
	std->p.age = 21;

	// struct Student içerisindeki struct Person p; yi struct Person* p; şeklinde pointer olarak tanımlarsak
	// std->p.name = "Kyle"; olarak değil std->p->name = "Kyle"; olarak tanımlamalıyız.

	printf("std pointer'ın adresi: %p \n", &std);
	printf("student'ın adresi: %p \n", std);
	printf("student'ın schoolNumber'ının adresi: %p \n", &(std->schoolNumber));
	printf("student'ın person'ının adresi: %p \n", &(std->p));
	printf("student'ın person'ının name'inin adresi: %p \n", &(std->p.name));
	printf("student'ın person'ının age'inin adresi: %p \n", &(std->p.age));

	return 0;
}
