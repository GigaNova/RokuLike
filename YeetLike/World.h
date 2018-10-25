#pragma once
class World
{
public:
	World(int _worldID);
	~World();

	int getWorldID() const;
private:
	int worldID;
};

