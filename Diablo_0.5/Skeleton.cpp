#include "Skeleton.h"

Skeleton::Skeleton() : Enemy()
{

};
Skeleton::Skeleton(char* skeletonName) : Enemy(skeletonName, 32, 3, 0)
{

};
void Skeleton::attack(Character& characterDefender)
{
	double attackPoints = 0;
	attackPoints = strength + 0.1 * characterDefender.getIntelligence();
	characterDefender.defend(attackPoints);
};
