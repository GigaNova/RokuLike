// YeetLike.cpp : Defines the entry point for the console application.
//
#include <libtcod/libtcod.h>
#include "Camera.h"
#include "Window.h"
#include "Game.h"
#include <ctime>

int main()
{
	Window* pWindow = new Window();
	Game* pGame = new Game(pWindow);

	while (!pWindow->isClosed()) {
		pWindow->clear();
		pGame->handleInput();
		pGame->update();
		pGame->draw();
		pWindow->flush();
	}

	return 0;
}

