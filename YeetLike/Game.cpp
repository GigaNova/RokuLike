#include "Game.h"
#include "EntityManager.h"
#include "Player.h"

Game::Game(Window* _pWindow)
{
	pWindow = _pWindow;

	Player* pPlayer = new Player(40, 40, '@');
	EntityManager::getInstance().registerEntity(pPlayer, true);
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
