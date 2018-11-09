#include "Tile.h"

Tile::Tile(char _icon, std::string _tilecolor)
{
	icon = _icon;
	walkable = false;
	tileColor = new HexColor(_tilecolor);
}


Tile::~Tile()
{
}

char Tile::getIcon() const
{
	return icon;
}

HexColor* Tile::getColor() const
{
	return tileColor;
}

void Tile::setIcon(char icon)
{
	this->icon = icon;
}

bool Tile::isWalkable() const
{
	return walkable;
}

void Tile::setWalkable(bool walkable)
{
	this->walkable = walkable;
}
