#pragma once
#include "Character.h"
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cassert>
#include<cstdlib>
using namespace std;

class Sorcerer : public Character
{
private:
	double mana;
	double maximumMana;
public:
	Sorcerer();
	Sorcerer(char*);
	double getMana() const;
	double getMaximumMana() const;
	void attack(Enemy&);
	void levelUp();
};

