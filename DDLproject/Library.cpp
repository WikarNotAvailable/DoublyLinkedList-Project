#include "Library.h"
using namespace std;

Library::Library(string& people, string& books, string& borrowings) {

    load_people(people);
    load_books(books);
    load_borrowings(borrowings);
}
void Library::load_people(string& people) {

    fstream stream;
    stream.open(people, ios::in);

    if (stream.is_open()) {

        string PESEL;
        string name;
        string surname;
        string date_of_birth;
        string street;
        string number_of_flat;
        string city;

        while (stream >> PESEL >> name >> surname >> date_of_birth >> street >> number_of_flat >> city) {

            Person a{ PESEL, name, surname, date_of_birth, street, number_of_flat, city };
            m_people.push_front(a);
        }
        stream.close();
    }
}
void Library::load_books(string& books) {

    fstream stream;
    stream.open(books, ios::in);

    if (stream.is_open()) {

        int ID;
        string title;
        string author;
        int year_of_release;
        int number_of_pages;
        string type;

        while (stream >> ID >> title >> author >> year_of_release >> number_of_pages >> type) {

            Book a{ ID, title, author, year_of_release, number_of_pages, type };
            m_books.push_back(a);
        }
        stream.close();
    }
}
void Library::load_borrowings(string& borrowings) {

    fstream stream;
    stream.open(borrowings, ios::in);

    if (stream.is_open()) {

        string PESEL;
        int ID;
        string surname;
        string date_l;
        string date_r;

        while (stream >> PESEL >> ID >> surname >> date_l >> date_r) {

            Borrowing a{ PESEL, ID, surname, date_l, date_r };
            m_borrowings.push_back(a);
        }
        stream.close();
    }
}
void Library::print_library() {

    m_people.print();
    m_books.print();
    m_borrowings.print();
}
void Library::pop_front_library() {

    m_people.pop_front();
    m_books.pop_front();
    m_borrowings.pop_front();
}
void Library::pop_back_library() {

    m_people.pop_back();
    m_books.pop_back();
    m_borrowings.pop_back();
}
void Library::size_library() {

    cout << "PEOPLE SIZE: " << m_people.size() << endl;
    cout << "BOOKS SIZE: " << m_books.size() << endl;
    cout << "BORROWINGS SIZE: " << m_borrowings.size() << endl;
}
void Library::erase_in_library(int index) {

    m_people.erase(index);
    m_books.erase(index);
    m_borrowings.erase(index);
}
void Library::sort_library() {

    m_people.sort();
    m_books.sort();
    m_borrowings.sort();
}
void Library::reverse_sort_library() {

    m_people.reverse_sort();
    m_books.reverse_sort();
    m_borrowings.reverse_sort();
}
void Library::test_operators(DoublyLinkedList<Book>& booklist, DoublyLinkedList<Borrowing>& borrowinglist, DoublyLinkedList<Person>& peoplelist) {

    booklist = m_books;
    borrowinglist = move(m_borrowings);
    peoplelist = move(m_people);
}
void Library::make_output_file(string& file) {

    ofstream of(file);
    if (of.good()) {

        for (int i = 0; i < m_people.size(); i++) {
            of << m_people.get(i) << endl;
        }

        of << endl;

        for (int i = 0; i < m_books.size(); i++) {
            of << m_books.get(i) << endl;
        }

        of << endl;

        for (int i = 0; i < m_borrowings.size(); i++) {
            of << m_borrowings.get(i) << endl;
        }
    }
    of.close();
}