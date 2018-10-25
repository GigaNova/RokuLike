#include "Player.h"

Player::Player(int _x, int _y, char _icon) : Creature(_x, _y, _icon)
{
	health = 100.0f;
}

Player::~Player()
{
}

void Player::draw(Window* pWindow)
{
	pWindow->drawChar(x, y, icon);
}

void Player::handleInput(char _input)
{
	switch (_input) {
		case 'w': 
			moveY(-1);
			break;
		case 's': 
			moveY(1);
			break;
		case 'a': 
			moveX(-1);
			break;
		case 'd': 
			moveX(1);
			break;
	default:break;
	}
}
