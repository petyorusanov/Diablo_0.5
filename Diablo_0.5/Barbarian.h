#pragma once
#include "Character.h"
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cassert>
#include<cstdlib>
using namespace std;

class Barbarian : public Character
{
private:
	double rage;
	double bonusRage;
	bool startOfBattle;
public:
	Barbarian();
	Barbarian(char*);
	double getRage() const;
	void attack(Enemy&);
	void defend(double);
	void levelUp();
};

