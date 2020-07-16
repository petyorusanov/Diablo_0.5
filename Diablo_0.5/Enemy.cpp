#include "Enemy.h"


Enemy::Enemy()
{
	name = new char[13];
	strcpy_s(name, 13, "default name");
	HP = 0;
	strength = 0;
	intelligence = 0;
};
Enemy::Enemy(char* enemyName, double enemyHP, double enemyStrength, double enemyIntelligence)
{
	name = new char[strlen(enemyName) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(enemyName) + 1, enemyName);
	HP = enemyHP;
	strength = enemyStrength;
	intelligence = enemyIntelligence;
};
Enemy::~Enemy()
{
	delete[] name;
};
Enemy::Enemy(Enemy& enemyDomain)
{
	name = new char[strlen(enemyDomain.name) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(enemyDomain.name) + 1, enemyDomain.name);
	HP = enemyDomain.HP;
	strength = enemyDomain.strength;
	intelligence = enemyDomain.intelligence;
};
Enemy& Enemy::operator=(Enemy& enemyDomain)
{
	delete[] name;
	name = new char[strlen(enemyDomain.name) + 1];
	assert(name != NULL);
	strcpy_s(name, strlen(enemyDomain.name) + 1, enemyDomain.name);
	HP = enemyDomain.HP;
	strength = enemyDomain.strength;
	intelligence = enemyDomain.intelligence;
	return *this;
};
char* Enemy::getName() const
{
	return name;
};
double Enemy::getHP() const
{
	return HP;
};
double Enemy::getStrength() const
{
	return strength;
};
double Enemy::getIntelligence() const
{
	return intelligence;
};
void Enemy::defend(double characterAttackPoints)
{
	if (strength < 100)
	{
		HP = HP - (characterAttackPoints - (strength / 100.0) * characterAttackPoints);
	}
};
