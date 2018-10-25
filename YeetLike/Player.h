#pragma once
#include "Creature.h"
class Player : public Creature
{
public:
	Player(int _x, int _y, char _icon);
	~Player();

    void draw(Window* _pWindow) override;
	void handleInput(char _input) override;
};

