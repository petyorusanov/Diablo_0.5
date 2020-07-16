#pragma once
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include "Character.h"
#include "Heretic.h"
#include "Skeleton.h"
using namespace std;

class Diablo : public Heretic, public Skeleton
{
private:
	int counterOfAttacks;
public:
	Diablo();
	Diablo(char* daibloName);
	void attack(Character&);
};
