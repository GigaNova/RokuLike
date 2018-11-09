#include "World.h"

World::World(int _worldID, int _width, int _height)
{
	worldID = _worldID;
	width = _width;
	height = _height;
}

World::~World()
{
}

int World::getWorldID() const
{
	return worldID;
}

int World::getWidth() const
{
	return width;
}

int World::getHeight() const
{
	return height;
}

void World::draw(Window * pWindow)
{
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			pWindow->drawChar(j, i, tiles[i][j]->getIcon(), tiles[i][j]->getColor());
		}
	}
}

bool World::canMove(int _x, int _y)
{
	return tiles[_y][_x]->isWalkable();
}
