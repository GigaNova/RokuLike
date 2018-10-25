#include "Camera.h"

Camera::Camera()
{
	x = 0;
	y = 0;
}


Camera::~Camera()
{
}

int Camera::getX() const
{
	return x;
}

void Camera::setX(int x)
{
	this->x = x;
}

int Camera::getY() const
{
	return y;
}

void Camera::setY(int y)
{
	this->y = y;
}

void Camera::moveX(int inc)
{
	this->x += inc;
}

void Camera::moveY(int inc)
{
	this->y += inc;
}
