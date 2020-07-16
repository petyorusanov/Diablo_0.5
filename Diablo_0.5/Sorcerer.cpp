#include "Sorcerer.h"

Sorcerer::Sorcerer() : Character()
{
	mana = 0;
	maximumMana = 100;
};
Sorcerer::Sorcerer(char* sorcererName) : Character(sorcererName, 0, 70, 4, 12)
{
	mana = 100;
	maximumMana = 100;
};
double Sorcerer::getMana() const
{
	return mana;
};
double Sorcerer::getMaximumMana() const
{
	return maximumMana;
}
void Sorcerer::attack(Enemy& enemyDefender)
{
	double attackPoints = 0;
	attackPoints = (0.5 + (mana / maximumMana) * 0.75) * intelligence;
	enemyDefender.defend(attackPoints);
	if (enemyDefender.getHP() <= 0)
	{
		mana = maximumMana;
		enemiesKilled++;
	}
	else if (mana >= 0.1 * maximumMana)
	{
		mana -= 0.1 * maximumMana;
	}
	else if (mana > 0 && mana < 0.1 * maximumMana)
	{
		mana = 0;
	}
};
void Sorcerer::levelUp()
{
	level++;
	strength = ((4.0 / 16.0) * 5.0) + strength;
	intelligence = ((12.0 / 16.0) * 5.0) + intelligence;
	HP = HP + (0.1 * HP);
	maximumMana = maximumMana + (0.2 * maximumMana);
}
