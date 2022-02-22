#include "Book.h"
using namespace std;
bool operator!= (const Book& book1, const Book& book2) {

	return book1.m_ID != book2.m_ID;
}
bool operator< (const Book& book1, const Book& book2) {

	return book1.m_title < book2.m_title;
}
bool operator> (const Book& book1, const Book& book2) {

	return book1.m_title > book2.m_title;
}
ostream& operator<< (ostream& out, const Book& book) {

	out << book.m_ID << " " << book.m_title << " " << book.m_author << " " << book.m_year_of_release << " " <<
		book.m_number_of_pages << " " << book.m_type;

	return out;
}
istream& operator>> (istream& in, Book& book) {

	in >> book.m_ID;
	in >> book.m_title;
	in >> book.m_author;
	in >> book.m_year_of_release;
	in >> book.m_number_of_pages;
	in >> book.m_type;

	return in;
}
