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
	s.push(2);
	s.push(54);
	s.push(4);
	s.push(13);
	s.pop();
	s.print();
}