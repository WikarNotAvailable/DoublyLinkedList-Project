#include <iostream>
using namespace std;
#ifndef BORROWING_H
#define BORROWING_H
class Borrowing {
	string m_PESEL;
	int m_ID;
	string m_surname;
	string m_date_l;
	string m_date_r;
	/*above variables are created to describe properties of an object that can be a borrowing in our library*/

public:
	Borrowing() { m_ID = 0; };
	/*default constructor*/

	Borrowing(string& PESEL, int& ID, string& surname, string& date_l, string& date_r) : m_PESEL{ PESEL }, m_ID{ ID }, m_surname{ surname }, m_date_l{ date_l },
		m_date_r{ date_r } {};
	/*5 arguments constructor, mostly used to read borrowings from database*/

	~Borrowing() {};
	/*destructor*/

	friend bool operator!= (const Borrowing& borrowing1, const Borrowing& borrowing2);
	friend bool operator< (const Borrowing& borrowing1, const Borrowing& borrowing2);
	friend bool operator> (const Borrowing& borrowing1, const Borrowing& borrowing2);
	friend ostream& operator<< (ostream& out, const Borrowing& borrowing);
	friend istream& operator>> (istream& in, Borrowing& borrowing);
	/*overloaded operators which are necessary to make list work*/

};
#endif

