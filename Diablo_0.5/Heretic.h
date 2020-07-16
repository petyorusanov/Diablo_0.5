#pragma once
#include "Enemy.h"
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cassert>
#include<cstdlib>
using namespace std;

class Heretic : virtual public Enemy
{
private:

public:
	Heretic();
	Heretic(char*);
	void attack(Character&);
};

