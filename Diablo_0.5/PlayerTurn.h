#pragma once
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include "Enemy.h"
#include "Map.h"
#include "Skeleton.h"
#include "Heretic.h"
#include "Necromancer.h"
#include "Diablo.h"
using namespace std;

class PlayerTurn
{
private:
	char playerChoice;
	char lastOneKilled;
	Enemy* currentEnemy;
	char* enemyName;
public:
	PlayerTurn()
	{
		playerChoice = '0';
		lastOneKilled = '0';
	};
	~PlayerTurn()
	{
		delete currentEnemy;
	};
	char getPlayerChoice() const
	{
		return playerChoice;
	};
	bool turn();
	void battle(Map&, Character&, int, int);
	void moveLeft(Map&, Character&);
	void moveRight(Map&, Character&, int);
	void moveUp(Map&, Character&);
	void moveDown(Map&, Character&, int);
	void printConsequences() const;
};

