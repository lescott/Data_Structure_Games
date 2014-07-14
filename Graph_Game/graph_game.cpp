/* * * * * * * * * * * * * * * * * * * * * * * * * * */
// graph_game.cpp
// A game using my graph implementation in C++.
// Author: Lauren E. Scott
// July 7, 2014
//
/* * * * * * * * * * * * * * * * * * * * * * * * * * */


#include "graphcpp.h"


Room* init_game() {
	Room* r = new Room(1);
	Room* r2 = new Room(2);
	Room* r3 = new Room(3);
	Room* r4 = new Room(4);
	Room* r5 = new Room(5);
	Room* r6 = new Room(6);
	Room* r7 = new Room(7);
	Room* end_room = new Room(8);
	r->add_room(r2);
	r->add_room(r3);
	r2->add_room(r4);
	r2->add_room(r5);
	r5->add_room(r6);
	r5->add_room(r7);
	r6->add_room(end_room);


	Item* i = new Item();
	i->name = "Jewel";
	i->healthPlus = 4;
	r->add_item(i);

	Item* i2 = new Item();
	i2->name = "Axe";
	i2->atkPlus = 3;
	r4->add_item(i2);

	Item* i3 = new Item();
	i3->name = "Cape";
	i3->defPlus = 1;
	r6->add_item(i3);

	Item* i4 = new Item();
	i4->name = "Escape Crystal";
	i4->is_end = true;
	end_room->add_item(i4);

	Enemy* g = new Enemy();
	g->name = "Goblin";
	g->health = 3;
	g->attack = 1;
	r3->add_enemy(g);

	Enemy* d = new Enemy();
	d->name = "Dragon";
	d->health = 10;
	d->attack = 2;
	end_room->add_enemy(d);

	return r;
}

void play_room(Room& r, Player& p) {
	while (r.getEnemy()->name != "Dragon") {
	char answer,a2;
	Item* i;
	r.print_room();
	cout << "What would you like to do? " << endl;
	cout << "[F]ignt" << endl;
	cout << "[P]ick up item" << endl;
	cout << "[M]ove" << endl;

	cin >> answer;

	switch(answer) {
		case 'F':
			break;
		case 'P':
			i = r.getItem();
			cout << "You pick up the " << i->name << endl;
			p.attack = p.attack + i->atkPlus;
			p.defense = p.defense + i->defPlus;
			p.health = p.health + i->healthPlus;
			break;
		case 'M':
			cout << "Choose [N]orth, [S]outh, [E]ast or [W]est." << endl;
			cin >> a2;
			switch(a2) {
				case 'N':
					r = *(r.getNorth());
					break;
				case 'S':
					r = *(r.getSouth());
					break;
				case 'E':
					r = *(r.getEast());
					break;
				case 'W':
					r = *(r.getWest());
					break;
				default:
					cout << "Please enter a valid direction." << endl;
					break;
			}
			break;
		default:
			cout << "Please enter a valid answer (F, P, or M)." << endl;
			break;
	}
	}

}




int main() {
	bool end_game = false;
	Player player;

	Room* first_room = init_game();
	
	play_room(*first_room, player);

	cout << "You found the dragon!!" << endl;

}
