#include "Beetle.h"

Beetle::Beetle() {
	health = 75;
}
void Beetle::draw() {
	std::cout << "You are attacked by a buzzy beetle!" << std::endl;
}
int Beetle::Attack() {
	int dmg = rand() % 21 + 10;
	std::cout << "You take " << dmg << " damage!" << std::endl;
	return dmg;
}
void Beetle::TakeDamage(int hp) {
	health -= hp;
}