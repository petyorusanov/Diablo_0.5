#pragma once
#include "Enemy.h"
#include "Skeleton.h"
class Necromancer : public Enemy
{
private:
	Enemy* skeletonSlave;
	int counterOfAttacker;
public:
	Necromancer();
	Necromancer(char* necromancerName);
	void attack(Character&);
	void defend(double characterAttackPoints);
};

