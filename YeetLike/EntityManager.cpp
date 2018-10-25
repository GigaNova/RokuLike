#include "EntityManager.h"

EntityManager::EntityManager()
{

}

void EntityManager::registerPlayer(Player* _pPlayer)
{
	if(!pPlayer)
	{
		pPlayer = _pPlayer;
		registerEntity(pPlayer, true);
	}
}

void EntityManager::registerEntity(Entity* _pEntity, bool _recieveInput)
{
	entities.push_back(_pEntity);
	if(_recieveInput)
	{
		inputEntities.push_back(_pEntity);
	}
	_pEntity->setCurrentWorld(worldLayers.front());
}

void EntityManager::handleInput(char _input)
{
	for (auto &entity : inputEntities) {
		entity->handleInput(_input);
	}
}

void EntityManager::update()
{
	for (auto &entity : entities) {
		entity->act();
	}
}

void EntityManager::draw(Window* _pWindow)
{
	for (auto &entity : entities) {
		entity->draw(_pWindow);
	}
}

void EntityManager::addWorld(World* _pWorld)
{
	worldLayers.push_front(_pWorld);
}