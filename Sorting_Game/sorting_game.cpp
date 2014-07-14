/* * * * * * * * * * * * * * * * * * * * * * * * * * */
// sorting_game.cpp
// A game using my sorting algorithm implementations in C++.
// Author: Lauren E. Scott
// July 3, 2014
//
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


vector<int> insertion_sort(vector<int> input) {
	for (int i = 0; i < input.size(); i++) {
		int x = input[i];
		int j = i;
		while (j > 0 && input[j - 1] > x) {
			input[j] = input[j-1];
			j = j - 1;
		}
		input[j] = x;
	}
	return input;
}

void print_vec(vector<int> input) {
	for (int i = 0; i < input.size(); i++) {
		cout << input.at(i) << " , ";
	}
}

int main() {
	srand (time(NULL));
	cout << "This is the sorting game." << endl;
	vector<int> vec, result;
	for (int i = 0; i < 10; i++) {
		vec.push_back(rand() % 10 + 1);
	}
	cout << "Size of vector " << vec.size() << endl;
	cout << "Unsorted vector: " << endl;
	print_vec(vec);
	cout << endl;
	result = insertion_sort(vec);
	cout << "Sorted vector: " << endl;
	print_vec(result);
	cout << endl;
}