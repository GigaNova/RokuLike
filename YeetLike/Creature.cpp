#include "Creature.h"

Creature::Creature(int _x, int _y, char _icon) : Entity(_x, _y, _icon)
{
	x = _x;
	y = _y;
	icon = _icon;
}

Creature::~Creature()
{
}

int Creature::getHealth()
{
	return health;
}

void Creature::changeHealth(int _amount)
{
	this->health += _amount;
}