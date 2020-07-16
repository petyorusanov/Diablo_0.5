#include "Character.h"


Character::Character()
{
	name = new char[strlen("empty") + 1];
	strcpy_s(name, strlen("empty") + 1, "empty");
	level = 0;
	HP = 0;
	strength = 0;
	intelligence = 0;
	enemiesKilled = 0;
};
Character::Character(char* characterName, int characterLevel, double characterHP, double characterStrength, double characterIntelligence)
{
	name = new char[strlen(characterName) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(characterName) + 1, characterName);
	level = characterLevel;
	HP = characterHP;
	strength = characterStrength;
	intelligence = characterIntelligence;
	enemiesKilled = 0;
};
Character::Character(int characterLevel, double characterHP, double characterStrength, double characterIntelligence)
{
	name = new char[strlen("empty") + 1];
	assert(name != NULL);
	strcpy_s(name, strlen("empty") + 1, "empty");
	level = characterLevel;
	HP = characterHP;
	strength = characterStrength;
	intelligence = characterIntelligence;
	enemiesKilled = 0;
};
Character::~Character()
{
	delete[] name;

};
Character::Character(Character& characterDomain)
{
	name = new char[strlen(characterDomain.name) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(characterDomain.name) + 1, characterDomain.name);
	level = characterDomain.level;
	HP = characterDomain.HP;
	strength = characterDomain.strength;
	intelligence = characterDomain.intelligence;
	enemiesKilled = characterDomain.enemiesKilled;
};
Character& Character::operator=(Character& characterDomain)
{
	delete[] name;
	name = new char[strlen(characterDomain.name) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(characterDomain.name) + 1, characterDomain.name);
	level = characterDomain.level;
	HP = characterDomain.HP;
	strength = characterDomain.strength;
	intelligence = characterDomain.intelligence;
	enemiesKilled = characterDomain.enemiesKilled;
	return *this;
};
char* Character::getName() const
{
	return name;
};
int Character::getLevel() const
{
	return level;
};
double Character::getHP() const
{
	return HP;
};
double Character::getStrength() const
{
	return strength;
};
double Character::getIntelligence() const
{
	return intelligence;
};
int Character::getEnemiesKilled() const
{
	return enemiesKilled;
}
void Character::increaseEnemiesKilled()
{
	enemiesKilled++;
};
void Character::defend(double enemyAttackPoints)
{
	if (strength < 100)
	{
		HP = HP - (enemyAttackPoints - (strength / 100.0) * enemyAttackPoints);
	}
};
