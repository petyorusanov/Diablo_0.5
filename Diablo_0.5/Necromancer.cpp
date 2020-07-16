#include "Necromancer.h"

Necromancer::Necromancer() :Enemy(), skeletonSlave()
{
	counterOfAttacker = 0;
};
Necromancer::Necromancer(char* necromancerName) :Enemy(necromancerName, 65, 2, 7), skeletonSlave(new Skeleton())
{
	counterOfAttacker = 1;
	/*skeletonSlave = new Skeleton(necromancerName);*/
};
void Necromancer::attack(Character& characterDefender)
{
	double attackPoints = 0;
	if (counterOfAttacker == 1 || counterOfAttacker == 9)
	{
		char slaveName[9] = "skeleton";
		skeletonSlave = new Skeleton(slaveName);
	}
	if (skeletonSlave->getHP() > 0)
	{
		attackPoints = skeletonSlave->getHP() / 10.0 + intelligence;
	}
	else
	{
		attackPoints = intelligence;
	}
	if (counterOfAttacker == 9)
	{
		counterOfAttacker = 2;
	}
	else
	{
		counterOfAttacker++;
	}
	characterDefender.defend(attackPoints);
};
void Necromancer::defend(double characterAttackPoints)
{
	if (skeletonSlave->getHP() > 0)
	{
		skeletonSlave->defend(characterAttackPoints);
		/*if (skeletonSlave->getHP() <= 0)
		{
			delete skeletonSlave;
		}*/
	}
	else
	{
		HP = HP - (characterAttackPoints - (strength / 100.0) * characterAttackPoints);
	}
};
