#include "Game.h"
#include "EntityManager.h"
#include "Player.h"
#include "CaveGenerator.h"
#include <libtcod/libtcod/console_types.h>
#include <libtcod/libtcod/console.hpp>

Game::Game(Window* _pWindow)
{
	pWindow = _pWindow;

	//Add empty world for now.
	CaveGenerator caveGenerator;
	EntityManager::getInstance().addWorld(caveGenerator.generateWorld(50, 80));

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
