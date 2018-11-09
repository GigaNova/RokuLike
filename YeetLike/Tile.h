#pragma once
#include <string>
#include "HexColor.h"

class Tile
{
public:
	Tile(char _icon, std::string _tilecolor);
	~Tile();

	HexColor* getColor() const;

	char getIcon() const;
	void setIcon(char icon);
	bool isWalkable() const;
	void setWalkable(bool walkable);
protected:
	char icon;
	bool walkable;
	HexColor* tileColor;
};

