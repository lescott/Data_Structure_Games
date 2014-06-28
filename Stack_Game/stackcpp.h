/* * * * * * * * * * * * * * * * * * * * * * * * * * */
// stack.h
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
	Stack(int s) { array = new T[s+1]; size = s; contains = 0; }
	~Stack() {}

	void push(T data);
	T pop(); 
	bool isEmpty();
	bool isFull();
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
		return -1;
	}
	T result = array[contains];
	contains--;
	return result;
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
// Function: print
// Prints the contents of the stack.
/* * * * * * * * * * * * * * * * * * * * * */

template <class T>
void Stack<T>::print() {
	for(int i = contains; i >= 0; i--) {
		cout << " | " << array[i];
	}
	cout << " ||" << endl;
}


