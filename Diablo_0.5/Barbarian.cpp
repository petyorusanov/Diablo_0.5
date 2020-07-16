#include "Barbarian.h"

Barbarian::Barbarian() : Character(1, 100, 10, 3)
{
	rage = 0;
	bonusRage = 0;
	startOfBattle = false;
};
Barbarian::Barbarian(char* barbarianName) : Character(barbarianName, 0, 100, 10, 3)
{
	rage = 0;
	bonusRage = 0;
	startOfBattle = true;
};
double Barbarian::getRage() const
{
	return rage;
};
void Barbarian::attack(Enemy& enemyDefender)
{
	double attackPoints = 0;
	if (startOfBattle)
	{
		bonusRage = (double)rage / 5.0;
		rage = 0;
		startOfBattle = false;
	}
	attackPoints = (1.0 + (bonusRage / 100.0)) * (strength + 0.2 * intelligence);
	enemyDefender.defend(attackPoints);
	if (enemyDefender.getHP() <= 0)
	{
		startOfBattle = true;
		enemiesKilled++;
	}
	if (rage >= 0 && rage < 99)
	{
		rage += 2;
	}
	else if (rage == 99)
	{
		rage = 100;
	}
};
void Barbarian::defend(double enemyAttackPoints)
{
	if (strength < 100)
	{
		HP = HP - (enemyAttackPoints - (strength / 100.0) * strength);
	}
	if (rage >= 0 && rage < 98)
	{
		rage += 3;
	}
	else if (rage == 98 || rage == 99)
	{
		rage = 100;
	}
};
void Barbarian::levelUp()
{
	level++;
	strength = ((10.0 / 13.0) * 5.0) + strength;
	intelligence = ((3.0 / 13.0) * 5.0) + intelligence;
	HP = HP + (0.1 * HP);
};
