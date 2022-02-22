#include "Node.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <exception>
using namespace std;
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
template <class T>
class DoublyLinkedList {

	int m_counter;
	/*counter of elements in the list*/

	shared_ptr<Node<T>> m_head;
	/*pointer to head*/

	shared_ptr<Node<T>> m_tail;
	/*pointer to tail*/
public:

	DoublyLinkedList() : m_counter{ 0 }, m_head{ nullptr }, m_tail{ nullptr } {};
	/*default constructor*/

	DoublyLinkedList(const DoublyLinkedList& list);
	/*copying constructor*/

	DoublyLinkedList(DoublyLinkedList&& list);
	/*move constructor*/

	~DoublyLinkedList() {};
	/*destructor*/

	int size() const { return m_counter; };
	/*function that returns size*/

	void push_front(const T& object);
	/*function that add new element on the front of the list*/

	void push_back(const T& object);
	/*function that add new element on the back of the list*/

	void pop_front();
	/*function that removes element from the front*/

	void pop_back();
	/*function that removes element from the back*/

	void erase(int index);
	/*function that removes element of the selected index*/

	void print();
	/*functions that print the list*/

	int search(const T& object);
	/*function that returns the index of the searched object*/

	T get(int index) const;
	/*function that returns and object of the selected index*/

	void sort();
	/*function that sorts in descending order*/

	void reverse_sort();
	/*function that sorts in ascending order*/

	void read_binary(const string& file_name);
	/*function that read and fill the list with the objects from binary file*/

	void save_binary(const string& file_name);
	/*function that save the list to binary file*/

	DoublyLinkedList& operator= (const DoublyLinkedList& list);
	/*copying operator*/

	DoublyLinkedList& operator= (DoublyLinkedList&& list);
	/*move operator*/

};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& list) : m_counter{ 0 }, m_head{ nullptr }, m_tail{ nullptr } {

	shared_ptr<Node<T>> temp = list.m_head;

	for (int i = 0; i < list.size(); i++) {

		push_back(temp->m_object);
		temp = temp->m_next;
	}
}
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList&& list) : m_head{ nullptr }, m_tail{ nullptr }, m_counter{ list.m_counter }  {

	swap(m_head, list.m_head);
	swap(m_tail, list.m_tail);
	list.m_counter = 0;
}
template <class T>
T DoublyLinkedList<T>::get(int index) const {

	if (index < 0 || index > m_counter) {
		throw out_of_range("Out_of_range_getting");
	}

	if (index == 0) {
		return m_head->m_object;
	}

	if (index == m_counter - 1) {
		return m_tail->m_object;
	}

	shared_ptr<Node<T>> temp_node = m_head;

	for (int i = 0; i < index; ++i)
	{
		temp_node = temp_node->m_next;
	}

	return temp_node->m_object;
}
template<class T>
void DoublyLinkedList<T>::push_front(const T& object) {

	shared_ptr<Node<T>> node(make_shared<Node<T>>(object));
	node->m_next = m_head;

	if (m_head != nullptr) {
		m_head->m_prev = node;
	}

	m_head = node;

	if (m_counter == 0) {
		m_tail = m_head;
	}

	m_counter++;
}
template <class T>
void DoublyLinkedList<T>::push_back(const T& object) {

	if (m_counter == 0) {
		push_front(object);
		return;
	}

	shared_ptr<Node<T>> node(make_shared<Node<T>>(object));
	node->m_prev = m_tail;
	m_tail->m_next = node;
	m_tail = node;

	m_counter++;
}
template<class T>
void DoublyLinkedList<T>::pop_front() {

	if (m_counter == 0) {
		return;
	}

	m_head = m_head->m_next;

	if (m_head != nullptr) {
		m_head->m_prev = nullptr;
	}
	else {
		m_tail = nullptr;
	}

	m_counter--;
}
template<class T>
void DoublyLinkedList<T>::pop_back() {

	if (m_counter == 0) {
		return;
	}

	if (m_counter == 1) {
		pop_front();
		return;
	}

	m_tail = m_tail->m_prev;
	m_tail->m_next = nullptr;

	m_counter--;
}
template <class T>
void DoublyLinkedList<T>::erase(int index)
{
	if (m_counter == 0) {
		return;
	}

	if (index < 0 || index >= m_counter) {
		return;
	}

	if (index == 0)
	{
		pop_front();
		return;
	}

	else if (index == m_counter - 1)
	{
		pop_back();
		return;
	}

	shared_ptr<Node<T>> node = m_head;

	for (int i = 0; i < index; ++i)
	{
		node = node->m_next;
	}

	shared_ptr<Node<T>> prev_node = node->m_prev;
	shared_ptr<Node<T>> next_node = node->m_next;

	prev_node->m_next = next_node;
	next_node->m_prev = prev_node;

	m_counter--;
}
template<class T>
int DoublyLinkedList<T>::search(const T& object) {

	if (m_counter == 0) {
		return -1;
	}

	int index = 0;
	shared_ptr<Node<T>> temp = m_head;

	while (temp->m_object != object) {

		index++;
		temp = temp->m_next;

		if (!temp)
		{
			return -1;
		}
	}

	return index;
}
template <class T>
void DoublyLinkedList<T>::print() {

	shared_ptr<Node<T>> temp = m_head;

	while (temp != nullptr) {
		cout << temp->m_object << endl;
		temp = temp->m_next;
	}

	cout << endl;
}
template <class T>
void DoublyLinkedList<T>::sort() {
	if (m_counter <= 1) {
		return;
	}

	shared_ptr<Node<T>> temp = m_head;
	shared_ptr<Node<T>> comp = m_head->m_next;
	bool sort = true;

	while (sort) {

		sort = false;

		for (int i = 0; i < m_counter - 1; i++) {

			if (temp->m_object < comp->m_object) {
				swap(temp->m_object, comp->m_object);
				sort = true;
			}

			temp = temp->m_next;
			comp = comp->m_next;
		}

		temp = m_head;
		comp = m_head->m_next;
	}
}
template <class T>
void DoublyLinkedList<T>::reverse_sort() {
	if (m_counter <= 1) {
		return;
	}

	shared_ptr<Node<T>> temp = m_head;
	shared_ptr<Node<T>> comp = m_head->m_next;
	bool sort = true;

	while (sort) {

		sort = false;

		for (int i = 0; i < m_counter - 1; i++) {

			if (temp->m_object > comp->m_object) {
				swap(temp->m_object, comp->m_object);
				sort = true;
			}

			temp = temp->m_next;
			comp = comp->m_next;
		}

		temp = m_head;
		comp = m_head->m_next;
	}
}
template <class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator= (const DoublyLinkedList& list) {

	m_counter = 0;
	m_head = nullptr;
	m_tail = nullptr;
	shared_ptr<Node<T>> temp = list.m_head;

	for (int i = 0; i < list.size(); i++) {

		push_back(temp->m_object);
		temp = temp->m_next;
	}

	return *this;
}
template <class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator= (DoublyLinkedList&& list) {

	if (&list == this)
		return *this;

	m_head = nullptr;
	m_tail = nullptr;
	m_counter = list.m_counter;
	list.m_counter = 0;
	swap(m_head, list.m_head);
	swap(m_tail, list.m_tail);

	return *this;
}
template <class T>
void DoublyLinkedList<T>::save_binary(const string& file_name) {

	ofstream stream;
	shared_ptr<Node<T>> temp = m_head;
	stream.open(file_name, ios::binary);

	for (int i = 0; i < m_counter; i++) {

		stream << temp->m_object << endl;
		temp = temp->m_next;
	}
	stream.close();
}
template <class T>
void DoublyLinkedList<T>::read_binary(const string& file_name) {

	ifstream stream;
	stream.open(file_name, ios::binary);
	T temp_object{};

	while (stream >> temp_object) {

		(*this).push_back(temp_object);
	}
	stream.close();
}
#endif
