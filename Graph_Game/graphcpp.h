/* * * * * * * * * * * * * * * * * * * * * * * * * * */
// graphcpp.h
// A graph implementation in C++.
// Author: Lauren E. Scott
// July 7, 2014
//
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include "linkedlistcpp.h"

using namespace std;

struct Enemy {
	string name;
	int health;
	int attack;
};

struct Item {
	string name;
	int healthPlus = 0, defPlus = 0, atkPlus = 0;
	bool is_end = false;
};

struct Player {
	int health = 10;
	int defense = 1;
	int attack = 1;
};

class Room {

public:
	Room(int i) { id = i, north = 0, south = 0, east = 0, west = 0, enemy = 0, item = 0; }
	~Room() {}

	int get_id() { return id; }
	Room* getNorth() { if (north != 0) { return north; } else { cout << "No North room."; } }
	Room* getSouth() { if (south != 0) { return south; } else { cout << "No South room."; } }
	Room* getEast() { if (east != 0) { return east; } else { cout << "No East room."; } }
	Room* getWest() { if (west != 0) { return west; } else { cout << "No West room."; } }
	Item* getItem() { if (item != 0) return item; }
	Enemy* getEnemy() { if (enemy != 0) return enemy; }
	void add_room(Room* r);
	void add_enemy(Enemy* e);
	void add_item(Item* i);
	void print_room();


private:
	int 		id;
	Room*		north; 
	Room*		south; 
	Room* 		east; 
	Room* 		west;
	Enemy*		enemy;
	Item*		item;

};

void Room::add_room(Room* r) {
	if (north == 0) { north = r; }
	else if (south == 0) { south = r; }
	else if (east == 0) { east = r; } 
	else if (west == 0) { west = r; } 
	else cout << "Can't insert room." << endl;
}

void Room::add_enemy(Enemy* e) {
	if (enemy == 0) { enemy = e; }
	else cout << "Can't insert enemy, already has enemy." << endl;
}

void Room::add_item(Item* i) {
	if (item == 0) { item = i; }
	else cout << "Can't insert item, already has item." << endl;
}

void Room::print_room() {
	cout << "----- Room  " << id << " ----- " << endl;
	if (north != 0) { cout << "North -> " << north->get_id() << endl; }
	if (south != 0) { cout << "South -> " << south->get_id() << endl; }
	if (east != 0) { cout << "East -> " << east->get_id() << endl; }
	if (west != 0) { cout << "West -> " << west->get_id() << endl; }

	if (enemy != 0) { cout << "Enemy: " << enemy->name << endl; }
	if (item != 0) { cout << "Item: " << item->name << endl; }

}
