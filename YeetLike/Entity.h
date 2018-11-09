#pragma once
#include "Window.h"
#include "World.h"
#include "Direction.h"

class Entity
{
public:
	Entity(int _x, int _y, char _icon);
	virtual ~Entity();

	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);

	void moveX(int inc);
	void moveY(int inc);

	virtual void act();
	virtual void handleInput(char _input);
	virtual void draw(Window* pWindow);

	void setCurrentWorld(World* _pWorld);
protected:
	World* pWorld;
	HexColor* entityColor;
	int x, y;
	char icon;
};

