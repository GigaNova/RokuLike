#pragma once
#include "Window.h"

class Game
{
public:
	Game(Window* _pWindow);
	~Game();

	void handleInput();
	void update();
	void draw();

private:
	Window* pWindow;
};

