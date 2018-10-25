#pragma once
#include "Entity.h"

class Creature : public Entity
{
public:
	Creature(int _x, int _y, char _icon);
	~Creature();

	int getHealth();
	void changeHealth(int _amount);
protected:
	float health;
};

