#pragma once
#include <vector>
#include "Tile.h"
#include "Window.h"

class World
{
public:
	World(int _worldID, int _width, int _height);
	~World();

	int getWorldID() const;

	int getWidth() const;
	int getHeight() const;

	virtual void draw(Window* pWindow);
	bool canMove(int _x, int _y);

	std::vector<std::vector<Tile*>> tiles;
private:
	int width;
	int height;
	int worldID;
};

