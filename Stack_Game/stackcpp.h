/* * * * * * * * * * * * * * * * * * * * * * * * * * */
// stackcpp.h
// A stack implementation in C++.
// Author: Lauren E. Scott
// June 27, 2014
//
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;

template <class T>
class Stack {
public:
	Stack(int s) { array = new T[s]; size = s; contains = 0; }
	~Stack() {}

	void push(T data);
	T pop(); 
	T top();
	bool isEmpty();
	bool isFull();
	bool hasTwoElements();
	void print();


private:
	T* array;
	int size, contains;
};

/* * * * * * * * * * * * * * * * * * * * * */
// Function: push
// Push an item onto the top of the stack.
/* * * * * * * * * * * * * * * * * * * * * */

template <class T>
void Stack<T>::push(T data) {

	if(isFull()) {
		cout << "Stack is full. " << endl;
		cout << "Size: " << size << endl;
		cout << "Contains: " << contains << endl;
		return;
	}
	array[contains] = data;
	contains++;
	cout << "Successfully pushed " << data << endl;
	
}

/* * * * * * * * * * * * * * * * * * * * * */
// Function: pop
// Pop an item off of the top of the stack, returning that item.
/* * * * * * * * * * * * * * * * * * * * * */

template <class T>
T Stack<T>::pop() {
	if(isEmpty()) {
		cout << "Stack is empty. " << endl;
	} else {
		T result = array[contains-1];
//		delete array[contains];			// Set current position to null.
//		[array]contains = 0;
		contains--;
		return result;
	}
}

/* * * * * * * * * * * * * * * * * * * * * */
// Function: top
// Access the top item of the stack without returning it.
/* * * * * * * * * * * * * * * * * * * * * */

template <class T>
T Stack<T>::top() {
	if(isEmpty()) {
		cout << "Stack is empty. " << endl;
//		return -1;
	} else {
		return array[contains-1];	
	}
}

/* * * * * * * * * * * * * * * * * * * * * */
// Function: isEmpty
// Checks to see whether the stack (thus, underlying array) is empty.
/* * * * * * * * * * * * * * * * * * * * * */

template <class T>
bool Stack<T>::isEmpty() {
	if (contains <= 0) {
		return true;
	}
	return false;
}

/* * * * * * * * * * * * * * * * * * * * * */
// Function: isFull
// Checks to see whether the stack (thus, underlying array) is full
/* * * * * * * * * * * * * * * * * * * * * */

template <class T>
bool Stack<T>::isFull() {
	if (contains >= size) {
		return true;
	}
	return false;
}

/* * * * * * * * * * * * * * * * * * * * * */
// Function: hasTwoElements
// Checks to see whether the stack has at least two elements.
// A specific function written for the stack game.
/* * * * * * * * * * * * * * * * * * * * * */

template <class T>
bool Stack<T>::hasTwoElements() {
	return (contains >= 2);
}

/* * * * * * * * * * * * * * * * * * * * * */
// Function: print
// Prints the contents of the stack.
/* * * * * * * * * * * * * * * * * * * * * */

template <class T>
void Stack<T>::print() {
	for(int i = contains-1; i >= 0; i--) {
		cout << " | " << array[i];
	}
	cout << " ||" << endl;
}

