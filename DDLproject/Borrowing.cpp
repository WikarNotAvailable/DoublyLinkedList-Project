#include "Borrowing.h"
using namespace std;

bool operator!= (const Borrowing& borrowing1, const Borrowing& borrowing2) {

	return (borrowing1.m_PESEL != borrowing2.m_PESEL || borrowing1.m_ID != borrowing2.m_ID);
}
bool operator< (const Borrowing& borrowing1, const Borrowing& borrowing2) {

	return (borrowing1.m_ID < borrowing2.m_ID);
}
bool operator> (const Borrowing& borrowing1, const Borrowing& borrowing2) {

	return (borrowing1.m_ID > borrowing2.m_ID);
}
ostream& operator<< (ostream& out, const Borrowing& borrowing) {

	out << borrowing.m_PESEL << " " << borrowing.m_ID << " " << borrowing.m_surname << " " <<
		borrowing.m_date_l << " " << borrowing.m_date_r;

	return out;
}
istream& operator>> (istream& in, Borrowing& borrowing) {

	in >> borrowing.m_PESEL;
	in >> borrowing.m_ID;
	in >> borrowing.m_surname;
	in >> borrowing.m_date_l;
	in >> borrowing.m_date_r;

	return in;
}