#include "HexColor.h"
#include <regex>

HexColor::HexColor(std::string _hex)
{
	hex = _hex;

	std::regex pattern("#?([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})");

	std::smatch match;
	if (std::regex_match(_hex, match, pattern))
	{
		r = std::stoul(match[1].str(), nullptr, 16);
		g = std::stoul(match[2].str(), nullptr, 16);
		b = std::stoul(match[3].str(), nullptr, 16);
	}
}


HexColor::~HexColor()
{
}
