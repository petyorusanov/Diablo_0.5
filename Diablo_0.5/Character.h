#pragma once
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include "Enemy.h"
using namespace std;

class Enemy;

class Character
{
protected:
	char* name;
	int level;
	double HP;
	double strength;
	double intelligence;
	int enemiesKilled;
public:
	Character();
	Character(char*, int, double, double, double);
	Character(int, double, double, double);
	~Character();
	Character(Character&);
	Character& operator=(Character&);
	char* getName() const;
	int getLevel() const;
	double getHP() const;
	double getStrength() const;
	double getIntelligence() const;
	int getEnemiesKilled() const;
	void increaseEnemiesKilled();
	virtual void attack(Enemy&) = 0;
	virtual void defend(double);
	virtual void levelUp() = 0;
};

