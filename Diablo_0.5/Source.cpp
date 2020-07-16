#include<iostream>
#include<iomanip>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include "Character.h"
#include "Barbarian.h"
#include "BountyHunter.h"
#include "Sorcerer.h"
#include "Map.h"
#include "PlayerTurn.h"
using namespace std;

class Enemy;
class Character;

void pickCharacter(int& character)
{
	cout << "\nPlease select your character: " << endl;
	cout << "Type 1 for barbarian.\nType 2 for sorcerer.\nType 3 for bounty hunter.\n\n";
	cin >> character;
	while (character != 1 && character != 2 && character != 3)
	{
		cout << "Please type again!\n";
		cin >> character;
	}
}
void pickName(char* charName)
{
	cout << "\nPlease type character's name: " << endl;
	cin >> charName;
}
PlayerTurn player;

int main()
{
	cout << setw(60) << "Welcome summoner!\n\n\n\n";
	cout << "Are you ready to play Diabo?   -   Type yes or no\n\n";
	char playerReady[4];
	cin >> playerReady;
	while (strcmp(playerReady, "yes") && strcmp(playerReady, "no"))
	{
		cout << "Please type again!\n\n";
		cin >> playerReady;
	}
	if (!strcmp(playerReady, "no"))
	{
		system("pause");
		return 0;
	}
	if (system("CLS")) system("clear");
	Character* hero;
	int playerPick;
	pickCharacter(playerPick);
	if (system("CLS")) system("clear");
	char characterName[25];
	pickName(characterName);
	switch (playerPick)
	{
	case 1:
	{
		hero = new Barbarian(characterName);
	}
	break;
	case 2:
	{
		hero = new Sorcerer(characterName);
	}
	break;
	case 3:
	{
		hero = new BountyHunter(characterName);
	}
	break;
	default:
	{
		cout << "Your default character is Barbarian!" << endl;
		hero = new Barbarian(characterName);
	}
	}
	if (system("CLS")) system("clear");
	Map* gameMap;
	cout << "\nDo you want to set map size? - If no, default map size will be 10x10.\nType yes or no.\n";
	cin >> playerReady;
	while (strcmp(playerReady, "yes") && strcmp(playerReady, "no"))
	{
		cout << "Please type again!\n\n";
		cin >> playerReady;
	}
	int mapSize = 0;
	if (!strcmp(playerReady, "yes"))
	{
		cout << "\nPlease type map size:\n";
		cin >> mapSize;
		while (mapSize < 10)
		{
			cout << "\nPlease type an integer, greater than 9.\n";
			cin >> mapSize;
		}
		gameMap = new Map(mapSize);
	}
	else
	{
		gameMap = new Map();
		mapSize = 10;
	}
	if (system("CLS")) system("clear");
	gameMap->setMap(mapSize);
	gameMap->printMap(mapSize);

	while (player.turn() && hero->getHP() > 0 && gameMap->getDiablosAlive() > 0)
	{
		if (system("CLS")) system("clear");
		switch (player.getPlayerChoice())
		{
		case 'l':
		{
			player.moveLeft(*gameMap, *hero);
		}break;
		case 'r':
		{
			player.moveRight(*gameMap, *hero, mapSize);
		}break;
		case 'u':
		{
			player.moveUp(*gameMap, *hero);
		}break;
		case 'd':
		{
			player.moveDown(*gameMap, *hero, mapSize);
		}break;
		case 'm':
		{
			gameMap->printMap(mapSize);
		}break;
		case 'c':
		{
			player.printConsequences();
		}break;
		case 'h':
		{
			cout << hero->getHP() << endl;
		}
		}
	}
	if (hero->getHP() <= 0)
	{
		if (system("CLS")) system("clear");
		cout << "\n\n\n\n\n\n\n\n\n" << setw(60) << "Game over! You have died!" << "\n\n\n\n\n\n\n\n\n";
	}
	else if (gameMap->getDiablosAlive() == 0)
	{
		if (system("CLS")) system("clear");
		cout << "\n\n\n\n\n\n\n\n\n" << setw(60) << "You have won!" << "\n\n\n\n\n\n\n\n\n";
	}
	else
	{
		if (system("CLS")) system("clear");
		cout << "\n\n\n\n\n\n\n\n\n" << setw(60) << "Thanks for playing!" << "\n\n\n\n\n\n\n\n\n";
	}

	system("pause");
	delete hero;
	delete gameMap;
	return 0;
}