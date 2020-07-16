#include "BountyHunter.h"

BountyHunter::BountyHunter() : Character()
{
	agility = 0;
	counterOfAttacks = 0;
};
BountyHunter::BountyHunter(char* bountyHunterName) : Character(bountyHunterName, 0, 80, 9, 6)
{
	agility = 10;
	counterOfAttacks = 1;
}
double BountyHunter::getAgility() const
{
	return agility;
}
void BountyHunter::attack(Enemy& enemyDefender)
{
	double attackPoints = 0;
	if (counterOfAttacks == 3)
	{
		attackPoints = agility + 0.4 * intelligence + 0.6 * strength;
		counterOfAttacks = 1;
	}
	else
	{
		attackPoints = 0.8 * agility;
		counterOfAttacks++;
	}
	enemyDefender.defend(attackPoints);
	if (enemyDefender.getHP() <= 0)
	{
		counterOfAttacks = 1;
		enemiesKilled++;
	}
};
void BountyHunter::levelUp()
{
	level++;
	strength = ((9.0 / 15.0) * 5.0) + strength;
	intelligence = ((6.0 / 15.0) * 5.0) + intelligence;
	HP = HP + (0.2 * HP);
	agility += 4;
}
