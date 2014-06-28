/* * * * * * * * * * * * * * * * * * * * * * * * * * */
// linked_list_game.cpp
// A game using my linked list implementation in C++.
// Author: Lauren E. Scott
// June 27, 2014
//
/* * * * * * * * * * * * * * * * * * * * * * * * * * */


#include <iostream>
#include <stdbool.h>
#include <set>
#include "linkedlistcpp.h"
using namespace std;

/* * * * * * * * * * * * * * * * * * * * * */
// Function: initialize_riddles
// A convenient place to create all riddles used in each of the 10 levels.
/* * * * * * * * * * * * * * * * * * * * * */

void initialize_riddles(string riddle[10]) {
	riddle[0] = "I have wings, feathers, and I can fly. What am I?\n";
	riddle[1] = "I am something that you sit on every day, and I have a pretty dirty job. What am I?";
	riddle[2] = "I am on trees, bushes, flowers, and I help them soak up the sun. What am I?";
	riddle[3] = "There is nothing more heroic than carrying me and a shield into battle. What am I?";
	riddle[4] = "I cover lots of animals on this earth, and I am soft to the touch. What am I?";
	riddle[5] = "You don't want to be me, but I often make you cough and sneeze. What am I?";
	riddle[6] = "I give life to most beings on Earth, and I can be both freezing cold or boiling hot. What am I?";
	riddle[7] = "I am what makes up the game that you play right now.";
	riddle[8] = "Some say I am the tastiest food on the planet. What am I?";
	riddle[9] = "You have reachd me. What am I?";
}

/* * * * * * * * * * * * * * * * * * * * * */
// Function: initialize_answers
// A convenient place to create all answers used in each of the 10 levels.
/* * * * * * * * * * * * * * * * * * * * * */

void initialize_answers(string answer[10]) {
	answer[0] = "BIRD";
	answer[1] = "TOILET";
	answer[2] = "LEAF";
	answer[3] = "SWORD";
	answer[4] = "FUR";
	answer[5] = "SICK";
	answer[6] = "WATER";
	answer[7] = "CODE";
	answer[8] = "BACON";
	answer[9] = "END";
}

/* * * * * * * * * * * * * * * * * * * * * */
// Function: initialize_chars
// A convenient place to define the sets of characters used in each of the 10 levels.
/* * * * * * * * * * * * * * * * * * * * * */

void initialize_chars(string allowable_chars[10]) {
	allowable_chars[0] = "XOINBRSAD";
	allowable_chars[1] = "MWROIDTALE";
	allowable_chars[2] = "LTWDRAOIEGF";
	allowable_chars[3] = "XWTSQAIRDOL";
	allowable_chars[4] = "ERAFLU";
	allowable_chars[5] = "MSRICWKA";
	allowable_chars[6] = "DKRGWPATE";
	allowable_chars[7] = "GUOADEC";
	allowable_chars[8] = "AKRGDBWECNO";
	allowable_chars[9] = "IRGCDNRE";
}

/* * * * * * * * * * * * * * * * * * * * * */
// Function: win_check
// Checks to see if the list contents match the answer (which is in string form).
/* * * * * * * * * * * * * * * * * * * * * */

bool win_check(LList<char> l, string answer) {
	Node<char>* checker = l.getHead();			// We will use a node pointer to iterate through the list.
	int i = 0;

	while(checker != 0) {						// Loop checks list against answer.
		if(checker->getData() != answer[i])
			return false;
		cout << checker->getData() << " = " << answer[i] << " ? " << endl;
		i++;
		checker = checker->getNext();
	}
	if(i == answer.length()) 
		return true;
	return false;
}

/* * * * * * * * * * * * * * * * * * * * * */
// Function: serve_level
// The heavy lifting for the game. Takes in the player's input with regard to
// how they want to manipulate the list, and updates the list accordingly. Also
// checks for a win every time the list is manipulated.
/* * * * * * * * * * * * * * * * * * * * * */

int serve_level(string riddle, string answer, string allowable_chars) {
	bool correct_answer = false;
	int player_input_1;
	char player_input_2;
	LList<char> l;

	cout << riddle << endl;
	while(!correct_answer) {
		player_input_1 = 0;
		cout << "Available letters: " << allowable_chars << endl;
		cout << "Choose something to do to the list: " << endl;
		cout << "[1] to Append a letter to the back of the list. " << endl;
		cout << "[2] to Push a letter to the front of the list. " << endl;
		cout << "[3] to Delete a letter from the list. " << endl;
		cout << "The list will be printed out each time you modify it. " <<endl;
		cin >> player_input_1;
		if(player_input_1 == 1) {
			cout << "Select a letter to append. " << endl;
			cin >> player_input_2;
			if(allowable_chars.find(player_input_2) != string::npos) {
				l.append(player_input_2);
				cout << player_input_2 << " appended to the list! " << endl;
				l.print();
			} else {
				cout << "Please use a valid letter! ";
			}
		} else if(player_input_1 == 2) {
			cout << "Select a letter to push to the front of the list. " << endl;
			cin >> player_input_2;
			if(allowable_chars.find(player_input_2) != string::npos) {
				l.push_front(player_input_2);
				cout << player_input_2 << " pushed to the front of list! " << endl;
				l.print();
			} else {
				cout << "Please use a valid letter! ";
			}
		} else if(player_input_1 == 3) {
			cout << "Select a letter to delete. " << endl;
			cin >> player_input_2;
			if(allowable_chars.find(player_input_2) != string::npos) {
				l.del(player_input_2);
				cout << player_input_2 << " deleted from the list! " << endl;
				l.print();
			} else {
				cout << "Please use a valid letter! ";
			}
		} else {
			cout << "Please select a valid option (1, 2, or 3). " << endl;
		}
		if(win_check(l, answer) == true) {
			cout << "Nice job! The answer is " << answer << " ! " << endl;
			correct_answer = true;
		}
		cin.clear();
		cin.ignore(10000, '\n');
	}
	return 0;

}

/* * * * * * * * * * * * * * * * * * * * * */
// Function: main
// Starting point of the game, main method.
/* * * * * * * * * * * * * * * * * * * * * */

int main() {
	string riddle[10], answer[10];
	string allowable_chars[10];
	initialize_riddles(riddle);
	initialize_answers(answer);
	initialize_chars(allowable_chars);
	int curr_level = 0;

	cout << "------------ Welcome to the Linked List Game! -----------------" << endl;
	cout << " Your goal is to answer riddles by using the properties of linked lists!" << endl;
	cout << " Press Ctrl+C at any time to quit. " << endl;
	cout << " Press 1 to append to the list. " << endl;
	cout << " Press 2 to push to the front list. " << endl;
	cout << " Press 3 to delete from the list. " << endl;
	cout << " Here is your first riddle:" << endl;
	for ( curr_level = 0; curr_level <= 10; curr_level++) {
		cout << "------- Level " << curr_level << " ------- " << endl;
		serve_level(riddle[curr_level], answer[curr_level], allowable_chars[curr_level]);
	}
	cout << "Nice job! You've beaten the Linked List Game! :) ";

}

