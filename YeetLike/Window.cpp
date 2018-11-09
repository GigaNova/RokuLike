#include "Window.h"
#include <libtcod/libtcod/console.hpp>

Window::Window()
{
	pCamera = new Camera();
	TCODConsole::initRoot(Camera::WIDTH, Camera::HEIGHT, "RokuLike", false);
}

Window::~Window()
{
}

void Window::moveCamera(int _x, int _y)
{
	pCamera->moveX(_x);
	pCamera->moveY(_y);
}

void Window::clear()
{
	TCODConsole::root->clear();
}

void Window::drawChar(int _x, int _y, char _char, HexColor* _color)
{
	TCODConsole::root->putChar(_x - pCamera->getX(), _y - pCamera->getY(), _char);
	TCODConsole::root->setCharForeground(_x - pCamera->getX(), _y - pCamera->getY(), TCODColor(_color->r, _color->g, _color->b));
}

void Window::flush()
{
	TCODConsole::flush();
}

bool Window::isClosed()
{
	return TCODConsole::isWindowClosed();
}
