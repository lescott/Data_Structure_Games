/* * * * * * * * * * * * * * * * * * * * * * * * * * */
// stack_game.cpp
// A game using my stack implementation in C++.
// Author: Lauren E. Scott
// June 27, 2014
//
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "stackcpp.h"

int main() {
	Stack<int> s(10);
	s.push(3);
	s.push(5);
	s.push(10);
	s.push(10);
	s.push(10);
	s.push(10);
	s.push(10);
	s.push(10);
	s.push(10);
	s.push(10);
	s.push(10);
	s.push(10);
	s.push(10);
	cout << s.pop() << endl;
}