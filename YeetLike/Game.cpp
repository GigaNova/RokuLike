#include "Game.h"
#include "EntityManager.h"
#include "Player.h"

Game::Game(Window* _pWindow)
{
	pWindow = _pWindow;

	//Add empty world for now.
	World* voidWorld = new World(0);
	EntityManager::getInstance().addWorld(voidWorld);

	Player* pPlayer = new Player(40, 40, '@');
	EntityManager::getInstance().registerPlayer(pPlayer);
}

Game::~Game()
{
}

void Game::handleInput()
{
	TCOD_key_t key = TCODConsole::waitForKeypress(true);
	EntityManager::getInstance().handleInput(key.c);
}

void Game::update()
{
	EntityManager::getInstance().update();
}

void Game::draw()
{
	EntityManager::getInstance().draw(pWindow);
}
