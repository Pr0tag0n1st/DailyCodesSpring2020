#include "Monsters.h"

int Monsters::Gethealth() {
	return health;
}
void Monsters::TakeDamage(int hp) {
	health -= hp;
}