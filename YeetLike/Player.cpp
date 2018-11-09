#include "Player.h"

Player::Player(int _x, int _y, char _icon) : Creature(_x, _y, _icon)
{
	health = 100.0f;
	entityColor = new HexColor("#FFFFFF");
}

Player::~Player()
{
}

void Player::draw(Window* pWindow)
{
	pWindow->drawChar(x, y, icon, entityColor);
}

void Player::handleInput(char _input)
{
	switch (_input) {
		case 'w': 
			if (pWorld->canMove(x, y - 1)) {
				moveY(-1);
			}
			break;
		case 's': 
			if (pWorld->canMove(x, y + 1)) {
				moveY(1);
			}
			break;
		case 'a': 
			if (pWorld->canMove(x - 1, y))
			{
				moveX(-1);
			}
			break;
		case 'd': 
			if (pWorld->canMove(x + 1, y))
			{
				moveX(1);
			}
			break;
	default:break;
	}
}
