#include <iostream>
using namespace std;
#ifndef PERSON_H
#define PERSON_H
class Person {
	string m_PESEL;
	string m_name;
	string m_surname;
	string m_date_of_birth;
	string m_street;
	string m_number_of_flat;
	string m_city;
	/*above variables are created to describe properties of an object that can be a person in our library*/
public:
	Person() {};
	/*default constructor*/

	Person(string& PESEL, string& name, string& surname, string& date_of_birth, string& street, string& number_of_flat, string& city) : m_PESEL{ PESEL },
		m_name{ name }, m_surname{ surname }, m_date_of_birth{ date_of_birth }, m_street{ street }, m_number_of_flat{ number_of_flat }, m_city{ city } {};
	/*7 arguments constructor, mostly used to read People from database */

	~Person() {};
	/*destructor*/

	friend bool operator!= (const Person& person1, const Person& person2);
	friend bool operator< (const Person& person1, const Person& person2);
	friend bool operator> (const Person& person1, const Person& person2);
	friend ostream& operator<< (ostream& out, const Person& person);
	friend istream& operator>> (istream& in, Person& person);
	/*overloaded operators which are necessary to make list work*/

};
#endif

