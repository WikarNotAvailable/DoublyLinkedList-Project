#include <iostream>
#include <memory>
#include <utility>
using namespace std;
#ifndef NODE_H
#define NODE_H
template <class T>
class Node {

public:
	T m_object;
	/*object of choosen type*/

	shared_ptr<Node<T>> m_prev;
	/*pointer to previous node*/

	shared_ptr<Node<T>> m_next;
	/*pointer to next node*/

	Node(T object) : m_object{ object } {};
	/*1 argument constructor*/

	~Node() {};
	/*destructor*/
	friend ostream& operator<< <>(ostream& out, const Node& node);
	/*operator overloading of operator <<*/
};
template <class T> ostream& operator<< (ostream& out, const Node<T>& node) {

	out << node.m_object << endl;
	return out;
}
#endif
