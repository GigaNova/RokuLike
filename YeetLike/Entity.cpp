#include "Entity.h"

Entity::Entity(int _x, int _y, char _icon)
{
	x = _x;
	y = _y;
	icon = _icon;
}

Entity::~Entity()
{
}

int Entity::getX() const
{
	return x;
}

void Entity::setX(int x)
{
	this->x = x;
}

int Entity::getY() const
{
	return y;
}

void Entity::setY(int y)
{
	this->y = y;
}

void Entity::moveX(int inc)
{
	this->x += inc;
}

void Entity::moveY(int inc)
{
	this->y += inc;
}

void Entity::act()
{
	//Overwrite if needed
}

void Entity::handleInput(char _input)
{
	//Overwrite if needed
}

void Entity::draw(Window* pWindow)
{
	//Overwrite if needed
}

void Entity::setCurrentWorld(World* _pWorld)
{
	pWorld = _pWorld;
}
