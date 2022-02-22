#include "Person.h"
using namespace std;

bool operator!= (const Person& person1, const Person& person2) {

	return person1.m_PESEL != person2.m_PESEL;
}
bool operator< (const Person& person1, const Person& person2) {

	return person1.m_surname < person2.m_surname;
}
bool operator> (const Person& person1, const Person& person2) {

	return person1.m_surname > person2.m_surname;
}
ostream& operator<< (ostream& out, const Person& person) {

	out << person.m_PESEL << " " << person.m_name << " " << person.m_surname << " " << person.m_date_of_birth << " " << person.m_street << " " <<
		person.m_number_of_flat << " " << person.m_city;

	return out;
}
istream& operator>> (istream& in, Person& person) {

	in >> person.m_PESEL;
	in >> person.m_name;
	in >> person.m_surname;
	in >> person.m_date_of_birth;
	in >> person.m_street;
	in >> person.m_number_of_flat;
	in >> person.m_city;

	return in;
}
