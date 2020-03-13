#pragma once
#include "Monsters.h"
class Beetle : public Monsters{
public:
	Beetle();
	void draw();
	int Attack();
	void TakeDamage(int hp);
private:
	int health;
	int enemyID;

};

