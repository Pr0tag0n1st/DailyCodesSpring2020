#include <iostream>
#include <ctime>
using namespace std;

class monster {
public:
	void move();
	void takeDamage();
	int attack();
	void print();
	void initialize(int xpos, int ypos, int health);

private:
	int x;
	int y;
	int hp;

};

int main() {
	srand(time(NULL));
	int playerhealth = 200;
	char input = 'z';
	monster m1;
	m1.initialize(50, 50, 50);
	cout << "You are getting attacked by a monster!" << endl;
	
	while (input!='f') {
		m1.move();
		playerhealth -= m1.attack();
		cout << "After the attack, you have "<<playerhealth<< " health." << endl;
		cout << "You can either (s)can, (a)ttack, (h)eal, or (f)lee." << endl;
		cin >> input;
		if (input == 'a') {
			cout << "You attack back!" << endl;
			m1.takeDamage();
		}
		else if (input == 'h') {
			playerhealth += rand() % 16;
			cout << "After tending to your wounds, you have " << playerhealth << " health." << endl;
		}
		else if (input == 's') {
			m1.print();
		}
		else if (input == 'f') {
			cout << "You escape from the monster!" << endl;
		}
		system("Pause");

	}
}

void monster::move() {
	if (hp > 0) {
		y += rand() % 21 - 10;
		x += rand() % 21 - 10;
	}
	else {
		cout << "The monster can't move as it is dead." << endl;
	}
}

void monster::initialize(int xpos, int ypos, int health) {
	x = xpos;
	y = ypos;
	hp = health;
}

void monster::takeDamage() {
	if (hp > 0)
		hp -= rand() % 11;
	else
		cout << "The monster is dead." << endl;
}

int monster::attack() {
	if (hp > 0)
		return rand() % 11;
	else {
		cout << "The monster can't attack as it is dead." << endl;
		return 0;
	}
}

void monster::print() {
	cout << "The monster is at " << x << ", " << y << ", and has " << hp << " health." << endl;
}