#pragma once
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include "PlayerCoordinates.h"
using namespace std;

class Map
{
private:
	char** map;
	int skeletonsAlive;
	int hereticsAlive;
	int necromancersAlive;
	int diablosAlive;
	PlayerCoordinates playerCoordinates;
public:
	Map();
	Map(int mapSize);
	~Map();
	void setMap(int mapSize);
	void printMap(int mapSize) const;
	char** getMap()const;
	void movePlayer(int, int, int, int);
	int getDiablosAlive() const;
	PlayerCoordinates& getPlayerCoordinates();
	void updateMap(int, int, char lastOneKilled);
	void printPlayerCoordinates() const
	{
		cout << "\nYour character's coordinates are: (" << playerCoordinates.getX() << ", " << playerCoordinates.getY() << ")" << endl;
	};
};

