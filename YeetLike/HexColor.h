#pragma once
#include <string>

class HexColor
{
public:
	HexColor(std::string _hex);
	~HexColor();

	int r, g, b;
private:
	std::string hex;
};

