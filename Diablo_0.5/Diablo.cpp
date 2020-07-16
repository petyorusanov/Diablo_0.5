#include "Diablo.h"

Diablo::Diablo()
{
	counterOfAttacks = 0;
};
Diablo::Diablo(char* diabloName) : Enemy(diabloName, 350, 8, 4), Heretic(diabloName), Skeleton(diabloName)
{
	counterOfAttacks = 1;
};
void Diablo::attack(Character& characterDefender)
{
	if (counterOfAttacks % 2 == 1)
	{
		Skeleton::attack(characterDefender);
	}
	else
	{
		Heretic::attack(characterDefender);
	}
	counterOfAttacks++;
};
