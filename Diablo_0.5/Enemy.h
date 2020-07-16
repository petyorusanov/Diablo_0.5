#pragma once
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include "Character.h"
using namespace std;

class Character;

class Enemy
{
protected:
	char* name;
	double HP;
	double strength;
	double intelligence;
public:
	Enemy();
	Enemy(char*, double, double, double);
	~Enemy();
	Enemy(Enemy&);
	Enemy& operator=(Enemy&);
	char* getName() const;
	double getHP() const;
	double getStrength() const;
	double getIntelligence() const;
	virtual void attack(Character&) = 0;
	virtual void defend(double);
};

