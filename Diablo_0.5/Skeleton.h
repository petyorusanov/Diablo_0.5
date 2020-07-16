#pragma once
#include "Enemy.h"
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cassert>
#include<cstdlib>
using namespace std;

class Skeleton : virtual public Enemy
{
private:

public:
	Skeleton();
	Skeleton(char*);
	void attack(Character&);
};

