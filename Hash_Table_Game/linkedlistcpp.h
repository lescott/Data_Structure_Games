/* * * * * * * * * * * * * * * * * * * * * * * * * * */
// linkedlistcpp.h
// A linked list implementation in C++.
// Author: Lauren E. Scott
// June 24, 2014
//
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

template <class T>
class Node {

public:
	Node() {};
	~Node() {}

	Node* getNext() { return next; }
	T getData() { return data; }
	void setNext(Node* node) { next = node; }
	void setValue(T value) { data = value; }

private:
	Node* next;
	T     data;

};

template<class T>
class LList {
public:
	LList() { head = 0; }
	Node<T>* getHead() { return head; }
	void print();
	void append(T data);
	void push_front(T data);
	void del(T data);
	bool is_empty();
	Node<T>* random_list();

private:
	Node<T>* head;
};

/* * * * * * * * * * * * * * * * * * * * * */
// Function: append
// Appends a value to the back of the list.
/* * * * * * * * * * * * * * * * * * * * * */

template <class T>
void LList<T>::append(T data) {
	Node<T>* newNode = new Node<T>();	// First pointer for the construction of the new node.
	newNode->setValue(data);
	newNode->setNext(0);

	Node<T>* tmp = head; // Second pointer for iterating through list to find end & append.

	if(tmp != 0) {
		while(tmp->getNext() != 0) {
			tmp = tmp->getNext();
		}
		tmp->setNext(newNode); // Appending new node to back of list.
	} else {
		head = newNode; // If there is no head, make it the first node. (Special case.)
	}
}

/* * * * * * * * * * * * * * * * * * * * * */
// Function: push_front
// Pushes a value to the front of the list.
// Wrote this one all myself, with no help from online sources.
/* * * * * * * * * * * * * * * * * * * * * */

template <class T>
void LList<T>::push_front(T data) {
	Node<T>* newNode = new Node<T>();
	newNode->setValue(data);
	newNode->setNext(head);

	head = newNode;

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// Function: del
// Deletes a node corresponding to a data element from the list.
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

template <class T>
void LList<T>::del(T data) {
	Node<T>* tmp = head;

	if(tmp == 0)
		return;

	if(tmp->getNext() == 0) {	// Deletes the head element if it is the only one.
		delete tmp;
		head = 0;
	} else {
		Node<T>* prev;	// Pointer for keeping track of previous node.
		do {
			if(tmp->getData() == data) break;
			prev = tmp;
			tmp = tmp->getNext();
		} while (tmp != 0);

		prev->setNext(tmp->getNext());	// Previous node's next pointer skips over current (tmp) node.

		delete tmp;
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// Function: is_empty
// Returns true if the linked list is empty.
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

template <class T>
bool LList<T>::is_empty() {
	Node<T>* tmp = head;
	if (tmp == 0) {
		return true;
	}
	return false;
}

/* * * * * * * * * * * * * * * * * * * * * */
// Function: print
// Prints out the entire list.
/* * * * * * * * * * * * * * * * * * * * * */

template <class T>
void LList<T>::print() {
	Node<T>* tmp = head;

	if(tmp == 0) {
		cout << "List is empty." << endl;
		return;
	}

	if(tmp->getNext() == 0) {
		cout << tmp->getData();
		cout << " --> ";
		cout << "NULL" << endl;
	} else {
		do {
			cout << tmp->getData();
			cout << " --> ";
			tmp = tmp->getNext();
		} while (tmp != 0);

//		cout << "NULL" << endl;
	}
}


