/* * * * * * * * * * * * * * * * * * * * * * * * * * */
// stack_game.cpp
// A game using my stack implementation in C++.
// Author: Lauren E. Scott
// June 27, 2014
//
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "stackcpp.h"

int calculate(Stack<string>* s, string input) {
	int result = 0;
	size_t sz;
	if(input == "+" || input == "-" || input == "/" || input == "*") {
		string top = s->pop();
		cout << "Top :" << top << endl;
		string second = s->pop();
		cout << "Second :" << second << endl;
		if(input == "+") {
			result = stoi(top) + stoi(second);
			cout << "Result: " << result << endl;
			s->push(to_string(result));
		} else if(input == "-") {
			result = stoi(top) - stoi(second);
			cout << "Result: " << result << endl;
			s->push(to_string(result));
		} else if (input == "/") {
			if (second == "0") {
				cout << "Can't divide by 0. " <<endl;
			} else {
			result = stoi(top) / stoi(second);
			cout << "Result: " << result << endl;
			s->push(to_string(result));
			}
		} else if (input == "*") {
			result = stoi(top) * stoi(second);
			cout << "Result: " << result << endl;
			s->push(to_string(result));
		}
	} else if(stoi(input) >= 48 || stoi(input) < 58) {
		s->push(input);
	} else {
		cout << "Please input only an operator (+, -, *, /) or an integer!" << endl;
		return 1;
	}
	return 0;
}

int main() {
	Stack<string> s(10);
	string input;

	while(true) {
		cin >> input;
		cout << calculate(&s, input) << endl;
		s.print();
	}
}










