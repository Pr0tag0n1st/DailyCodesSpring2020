#include "Goomba.h"

Goomba::Goomba() {
	health = 20;
}
void Goomba::draw() {
	std::cout << "You are attacked by a Goomba!" << std::endl;
}
int Goomba::Attack() {
	int dmg = rand() % 11;
	std::cout << "You take " << dmg << " damage!" << std::endl;
	return dmg;
}
void Goomba::TakeDamage(int hp) {
	health -= hp;
}