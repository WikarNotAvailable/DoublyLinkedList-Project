#include "Person.h"
#include "DoublyLinkedList.h"
#include "Book.h"
#include "Borrowing.h"

#ifndef LIBRARY_H
#define LIBRARY_H

class Library {

	DoublyLinkedList<Person> m_people;
	/*list of objects of type Person*/

	DoublyLinkedList<Book> m_books;
	/*list of objects of type Book*/

	DoublyLinkedList<Borrowing> m_borrowings;
	/*list of objects of type Borrowing*/

	void load_people(string& people);
	/*function that load people from text file*/

	void load_books(string& books);
	/*function that load books from text file*/

	void load_borrowings(string& borrowings);
	/*function that load borrowings from text file*/

public:
	Library(string& people, string& books, string& borrowings);
	/*3 arguments constructor*/

	~Library() {};
	/*destructor*/

	void print_library();
	/*function that prints all the lists*/

	void pop_front_library();
	/*function that pops front from all the lists*/

	void pop_back_library();
	/*function that pops back from all the lists*/

	void erase_in_library(int index);
	/*function that erases element of the selected index in each list*/

	void size_library();
	/*function that prints size of each list in the library*/

	void sort_library();
	/*function that sorts all the lists in the library*/

	void reverse_sort_library();
	/*function that sorts all the lists in the library in the reversed order*/

	void test_operators(DoublyLinkedList<Book>& booklist, DoublyLinkedList<Borrowing>& borrowinglist, DoublyLinkedList<Person>& peoplelist);
	/*function that is testing operators*/

	void make_output_file(string& file);
	/*function that write an output file*/
};
#endif
