#pragma once
#include "Monsters.h"
class Goomba : public Monsters{
public:
	Goomba();
	void draw();
	int Attack();
	void TakeDamage(int hp);
private:
	int health;
	int enemyID;

};

