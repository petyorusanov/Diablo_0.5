#include "Heretic.h"

Heretic::Heretic() : Enemy()
{

};
Heretic::Heretic(char* hereticName) :Enemy(hereticName, 20, 1, 4)
{

};
void Heretic::attack(Character& characterDefender)
{
	double attackPoints = 0;
	if (characterDefender.getStrength() <= characterDefender.getIntelligence())
	{
		attackPoints = characterDefender.getStrength() + intelligence;
	}
	else
	{
		attackPoints = characterDefender.getIntelligence() + intelligence;
	}
	characterDefender.defend(attackPoints);
};

