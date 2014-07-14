/* * * * * * * * * * * * * * * * * * * * * * * * * * */
// hashtable_game.cpp
// A game using my hash table and linked list implementations in C++.
// Author: Lauren E. Scott
// June 30, 2014
//
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <vector>
#include "hashtablecpp.h"
#include <iostream>
#include <string>


// Borrowed string tokenizer function. 

void Tokenize(string str,
                      vector<string>& tokens,
                      const string& delimiters = " ")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);
    cout << "String: " << str << endl;

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

int main() {
	string input;
	int size, guess;
	vector<string> words;
	cout << "Input size of hash table. " << endl;
	cin >> size;
	HashTable ht(size); 
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "Input a sentence. It will be broken up into words that will be put into the hash table. " << endl;
	getline(cin, input);
	cout << "Input: " << input << endl;
	Tokenize(input, words);
	for(int i = 0; i < words.size(); i++) {
		ht.insert(words[i]);
	}

	ht.get_used_buckets();		// Check how many buckets in the hash table are used.

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