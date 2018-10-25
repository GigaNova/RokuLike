#include "World.h"

World::World(int _worldID)
{
	worldID = _worldID;
}

World::~World()
{
}

int World::getWorldID() const
{
	return worldID;
}
