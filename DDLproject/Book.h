#include <iostream>
using namespace std;
#ifndef BOOK_H
#define BOOK_H
class Book {
	int m_ID;
	string m_title;
	string m_author;
	int m_year_of_release;
	int m_number_of_pages;
	string m_type;
	/*above variables are created to describe properties of an object that can be a book in our library*/

public:
	Book() { m_ID = 0; m_year_of_release = 0; m_number_of_pages = 0; };
	/*default constructor*/

	Book(int& ID, string& title, string& author, int& year_of_release, int& number_of_pages, string& type) : m_ID{ ID }, m_title{ title }, m_author{ author },
		m_year_of_release{ year_of_release }, m_number_of_pages{ number_of_pages }, m_type{ type } {};
	/*6 arguments constructor, mostly used to read books from database*/

	~Book() {};
	/*destructor*/

	friend bool operator!= (const Book& book1, const Book& book2);
	friend bool operator< (const Book& book1, const Book& book2);
	friend bool operator> (const Book& book1, const Book& book2);
	friend ostream& operator<< (ostream& out, const Book& book);
	friend istream& operator>> (istream& in, Book& book);
	/*overloaded operators which are necessary to make list work*/
};
#endif
