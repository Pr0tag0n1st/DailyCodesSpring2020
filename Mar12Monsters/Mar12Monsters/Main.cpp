#include <iostream>
#include <ctime>
using namespace std;
#include "Monsters.h"
#include "Goomba.h"
#include "Koopa.h"
#include "Beetle.h"
enum {GOOMBA, KOOPA, BEETLE};

int Fight() {
	int atk = rand() % 26 + 15;
	return atk;
}

int main() {

	srand(time(NULL));
	int damage = 0;
	int dmgtaken = 0;
	int health = 100;
	int encounter = rand() % 4;
	cout << "You are being attacked!" << endl;
	Goomba g1;
	Koopa k1;
	Beetle b1;

	cout << "You must confront:" << endl;
	g1.draw();
	cout << "It has " << g1.Gethealth() << "health." << endl;
	k1.draw();
	cout << "It has " << k1.Gethealth() << "health." << endl;
	b1.draw();
	cout << "It has " << b1.Gethealth() << "health." << endl;
	cout << "Begin fighting now." << endl;
	while (health > 0) {
		cout << "Your health is at " << health<<"." << endl;
		encounter = rand() % 3;
		cout << encounter << endl;
		switch (encounter) {
		case GOOMBA:
			if (encounter == GOOMBA && g1.Gethealth() > 0) {
				g1.draw();
				cout << "It has " << g1.Gethealth() << " health." << endl;
				dmgtaken = g1.Attack();
				cout << "You take " << dmgtaken << " damage." << endl;
				health -= dmgtaken;
				damage = Fight();
				cout << "You retaliate for " << damage << " damage." << endl;
				g1.TakeDamage(damage);
			}
			else if (encounter == GOOMBA && g1.Gethealth() <= 0) {
				cout << "The goomba has already been defeated." << endl;
			}
			break;
		case KOOPA:
			if (encounter == KOOPA && k1.Gethealth() > 0) {
				k1.draw();
				cout << "It has " << k1.Gethealth() << " health." << endl;
				dmgtaken = k1.Attack();
				cout << "You take " << dmgtaken << " damage." << endl;
				health -= dmgtaken;
				damage = Fight();
				cout << "You retaliate for " << damage << " damage." << endl;
				k1.TakeDamage(damage);
			}
			else if (encounter == KOOPA && k1.Gethealth() <= 0) {
				cout << "The koopa has already been defeated." << endl;
			}
		case BEETLE:
			if (encounter == BEETLE && b1.Gethealth() > 0) {
				b1.draw();
				cout << "It has " << k1.Gethealth() << " health." << endl;
				dmgtaken = b1.Attack();
				cout << "You take " << dmgtaken << " damage." << endl;
				health -= dmgtaken;
				damage = Fight();
				cout << "You retaliate for " << damage << " damage." << endl;
				b1.TakeDamage(damage);
			}
			else if (encounter == BEETLE && b1.Gethealth() <= 0) {
				cout << "The buzzy beetle has already been defeated." << endl;
			}
		}


		system("Pause");
	}

	
}