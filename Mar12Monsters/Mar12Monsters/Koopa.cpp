#include "Koopa.h"

Koopa::Koopa() {
	health = 40;
}
void Koopa::draw() {
	std::cout << "You are attacked buy a Koopa!" << std::endl;
}
int Koopa::Attack() {
	int dmg = rand() % 16 + 5;
	std::cout << "You take " << dmg << " damage!" << std::endl;
	return dmg;
}
void Koopa::TakeDamage(int hp) {
	health -= hp;
}