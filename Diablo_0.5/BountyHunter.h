#pragma once
#include "Character.h"
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cassert>
#include<cstdlib>
using namespace std;

class BountyHunter : public Character
{
private:
	double agility;
	int counterOfAttacks;
public:
	BountyHunter();
	BountyHunter(char*);
	double getAgility() const;
	void attack(Enemy&);
	void levelUp();
};

