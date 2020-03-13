#pragma once
#include <iostream>
#include <ctime>
class Monsters
{
public:
	int Gethealth();
	virtual void TakeDamage(int hp);
protected:
	int health;
};

