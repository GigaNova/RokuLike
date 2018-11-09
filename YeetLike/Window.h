#pragma once
#include <libtcod/libtcod.hpp>
#include "Camera.h"
#include "HexColor.h"

class Window
{
public:
	Window();
	~Window();
	
	void moveCamera(int _x, int _y);

	void clear();
	void drawChar(int _x, int _y, char _char, HexColor* _color);
	void flush();

	bool isClosed();
private:
	Camera* pCamera;
};

