#pragma once
#include "Entity.h"
#include <vector>
#include <deque>

class EntityManager
{
public:
	static EntityManager& getInstance()
	{
		static EntityManager instance;		
		return instance;
	}

	EntityManager();
	EntityManager(EntityManager const&) = delete;
	void operator=(EntityManager const&) = delete;

	void registerEntity(Entity* _pEntity, bool _recieveInput);
	void handleInput(char _input);
	void update();
	void draw(Window* _pWindow);

	void addWorld(World* _pWorld);
private:
	std::vector<Entity*> entities;
	std::vector<Entity*> inputEntities;

	std::deque<World*> worldLayers;
};

