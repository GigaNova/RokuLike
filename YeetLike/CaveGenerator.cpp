#include "CaveGenerator.h"
#include <ctime>
#include "CaveWall.h"
#include "Dirt.h"
#include <iostream>

CaveGenerator::CaveGenerator()
{
}


CaveGenerator::~CaveGenerator()
{
}

World* CaveGenerator::generateWorld(int _width, int _height, int _seed)
{
	World* pNewWorld = new World(0, _width, _height);

	int seed = _seed == 0 ? time(nullptr) : _seed;
	srand(seed);
	filledPercentage = rand() % 20 + 40;

	setupWorld(pNewWorld);

	for(int i = 0; i < POPULATION_ITERATIONS; ++i)
	{
		populateWorld(pNewWorld);
	}

	finalizeWorld(pNewWorld);

	return pNewWorld;
}

void CaveGenerator::setupWorld(World* _pWorld)
{
	for(int i = 0; i < _pWorld->getWidth(); ++i)
	{
		binPresentation.push_back(std::vector<int>());
		for (int j = 0; j < _pWorld->getHeight(); ++j)
		{
			if(i == 0 || j == 0 || i == _pWorld->getWidth() - 1 || j == _pWorld->getHeight() - 1)
			{
				binPresentation[i].push_back(1);
			}
			else {
				binPresentation[i].push_back(rand() % 101 < filledPercentage ? 1 : 0);
			}
		}
	}
}

void CaveGenerator::populateWorld(World * _pWorld)
{
	std::vector<std::vector<int>> newMap;
	for (int x = 0; x < _pWorld->getWidth(); ++x)
	{
		newMap.push_back(std::vector<int>());
		for (int y = 0; y < _pWorld->getHeight(); ++y)
		{
			int nbs = getAmountNeighbourWalls(_pWorld, x, y);

			if (binPresentation[x][y] == 1) {
				if (nbs < DEATH_LIMIT) {
					newMap[x].push_back(0);
				}
				else {
					newMap[x].push_back(1);
				}
			}
			else {
				if (nbs > BIRTH_LIMIT) {
					newMap[x].push_back(1);
				}
				else {
					newMap[x].push_back(0);
				}
			}
		}
	}
	binPresentation = newMap;
}

int CaveGenerator::getAmountNeighbourWalls(World * _pWorld, int _x, int _y)
{
	int count = 0;
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			signed int neighbour_x = _x + i;
			signed int neighbour_y = _y + j;

			if (neighbour_x != _x || neighbour_y != _y)
			{
				if (neighbour_x >= 0 && neighbour_y >= 0 && neighbour_x < _pWorld->getWidth() && neighbour_y < _pWorld->getHeight()) {
					count += binPresentation[neighbour_x][neighbour_y];
				}
				else {
					++count;
				}
			}
		}
	}
	return count;
}

void CaveGenerator::finalizeWorld(World* _pWorld)
{
	for (int x = 0; x < _pWorld->getWidth(); ++x)
	{
		_pWorld->tiles.push_back(std::vector<Tile*>());
		for (int y = 0; y < _pWorld->getHeight(); ++y)
		{
			if (binPresentation[x][y] == 1) _pWorld->tiles[x].push_back(new CaveWall());
			else _pWorld->tiles[x].push_back(new Dirt());
		}
	}
}

