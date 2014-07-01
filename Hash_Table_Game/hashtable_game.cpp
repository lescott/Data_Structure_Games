/* * * * * * * * * * * * * * * * * * * * * * * * * * */
// hashtable_game.cpp
// A game using my hash table and linked list implementations in C++.
// Author: Lauren E. Scott
// June 30, 2014
//
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <vector>
#include "hashtablecpp.h"

/*
vector<string> to_words(string input) {

}
*/


int main() {
	string input;
	int size, guess;
	vector<string> words;
	cout << "Input size of hash table. " << endl;
	cin >> size;
	HashTable ht(size);

//	cout << "Input a sentence. It will be broken up into words that will be put into the hash table. " << endl;
//	cin >> input;
//	words = to_words(input);
//	for(int i = 0; i < words.size(); i++) {
//		ht.insert(words[i]);
//	}
	ht.insert("Hi");
	ht.insert("stuff");
	ht.insert("and");
	ht.insert("yeah");
	ht.insert("hmmm");

	cout << "Guess the size of the hash table!" << endl;
	cin >> guess;

	ht.print_table();

	if (guess == ht.get_used_buckets()) {
		cout << "Correct! " << endl;
	} else {
		cout << "Incorrect! " << endl;
	}
	cout << "Correct answer is: " << ht.get_used_buckets() << endl;


}