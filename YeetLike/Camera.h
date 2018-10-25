#pragma once
class Camera
{
public:
	static const int HEIGHT = 50;
	static const int WIDTH = 80;

	Camera();
	~Camera();

	int getX() const;
	void setX(int x);
	int getY() const;
	void setY(int y);

	void moveX(int inc);
	void moveY(int inc);
private:
	int x, y;
};

