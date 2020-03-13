#pragma once
#include "Monsters.h"
class Koopa : public Monsters{
public:
	Koopa();
	void draw();
	int Attack();
	void TakeDamage(int hp);
private:
	int health;
	int enemyID;

};

