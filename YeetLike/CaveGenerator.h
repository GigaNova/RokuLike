#pragma once
#include "World.h"

class CaveGenerator
{
public:
	CaveGenerator();
	~CaveGenerator();

	World* generateWorld(int _width, int _height, int _seed = 0);
private:
	const int DEATH_LIMIT = 3;
	const int BIRTH_LIMIT = 5;
	const int POPULATION_ITERATIONS = 6;

	std::vector<std::vector<int>> binPresentation;

	void setupWorld(World* _pWorld);
	void populateWorld(World* _pWorld);
	int getAmountNeighbourWalls(World * _pWorld, int _x, int _y);
	void finalizeWorld(World* _pWorld);

	int filledPercentage;
};

