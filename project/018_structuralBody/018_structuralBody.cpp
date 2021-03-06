#include <iostream>
using namespace std;
void printBook(struct Book book);

struct Book
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
};

#pragma warning(disable:4996)
int main(){
	Book book1;
	Book book2;

	// book1 详述
	strcpy(book1.title, "C++ 教程");
	strcpy(book1.author, "Runoob");
	strcpy(book1.subject, "编程语言");
	book1.book_id = 123456;

	// book2 详述
	strcpy(book2.title, "CSS 教程");
	strcpy(book2.author, "Runoob");
	strcpy(book2.subject, "前端技术");
	book2.book_id = 12346;

	// 输出 Book1 信息
	printBook(book1);

	// 输出 Book2 信息
	printBook(book2);

	system("PAUSE");
	return 0;
}

void printBook(struct Book book)
{
	cout << "书标题 : " << book.title << endl;
	cout << "书作者 : " << book.author << endl;
	cout << "书类目 : " << book.subject << endl;
	cout << "书 ID : " << book.book_id << endl;
}