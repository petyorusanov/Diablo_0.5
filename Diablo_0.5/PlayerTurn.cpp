#include "PlayerTurn.h"

bool PlayerTurn::turn()
{
	cout << "\nCommand board:" << "\ntype l to go left" << "\ntype r to go right" << "\ntype u to go up"
		<< "\ntype d to go down" << "\ntype m to print map"
		<< "\ntype c to see the consequences of your last turn"
		<< "\ntype e to exit the game"
		<< "\ntype h to see your character's HP"
		<< endl;
	cin >> playerChoice;
	while (playerChoice != 'l' && playerChoice != 'r' && playerChoice != 'u' && playerChoice != 'd' && playerChoice != 'm' && playerChoice != 'c' && playerChoice != 'e' && playerChoice != 'h')
	{
		cout << "\nPlease type again!" << endl;
		cin >> playerChoice;
	}
	if (playerChoice == 'e')
	{
		return false;
	}
	else return true;
};
void PlayerTurn::battle(Map& gameMap, Character& myPlayer, int movedToX, int movedToY)
{
	switch (gameMap.getMap()[movedToX][movedToY])
	{
	case 's':
	{
		enemyName = new char[9];
		strcpy_s(enemyName, 9, "skeleton");
		currentEnemy = new Skeleton(enemyName);
	}break;
	case 'h':
	{
		enemyName = new char[8];
		strcpy_s(enemyName, 8, "heretic");
		currentEnemy = new Heretic(enemyName);
	}break;
	case 'n':
	{
		enemyName = new char[12];
		strcpy_s(enemyName, 12, "necromancer");
		currentEnemy = new Necromancer(enemyName);
	}break;
	case 'd':
	{
		enemyName = new char[7];
		strcpy_s(enemyName, 7, "diablo");
		currentEnemy = new Diablo(enemyName);
	}break;
	default:
	{
		enemyName = new char[9];
		strcpy_s(enemyName, 9, "skeleton");
		currentEnemy = new Skeleton(enemyName);
	}break;
	}
	while (myPlayer.getHP() > 0 && currentEnemy->getHP() > 0)
	{
		myPlayer.attack(*currentEnemy);
		if (currentEnemy->getHP() > 0)
		{
			currentEnemy->attack(myPlayer);
		}
		else if (currentEnemy->getHP() <= 0)
		{
			lastOneKilled = gameMap.getMap()[movedToX][movedToY];
			if (myPlayer.getEnemiesKilled() == pow(2, myPlayer.getLevel()))
			{
				myPlayer.levelUp();
			}
		}
		if (myPlayer.getHP() <= 0)
		{
			lastOneKilled = 'U';
		}
	}
	if (gameMap.getMap()[movedToX][movedToY] != '0')
	{
		delete[] enemyName;
	}
};
void PlayerTurn::moveLeft(Map& gameMap, Character& myPlayer)
{
	int x = gameMap.getPlayerCoordinates().getX();
	int y = gameMap.getPlayerCoordinates().getY();
	if (y - 1 < 0)
	{
		cout << "\nYou've gone outside the boarders of the map. Please type a command again." << endl;
	}
	else if (gameMap.getMap()[x][y - 1] == 'r')
	{
		cout << "\nThere's a rock on this field. Please type a command again." << endl;
	}
	else if (gameMap.getMap()[x][y - 1] == '0')
	{
		cout << "\nThere are no enemies on this field." << endl;
		gameMap.movePlayer(x, y - 1, x, y);
		gameMap.getPlayerCoordinates().decreaseY();
	}
	else
	{
		battle(gameMap, myPlayer, x, y - 1);
		gameMap.updateMap(x, y - 1, lastOneKilled);
		gameMap.movePlayer(x, y - 1, x, y);
		gameMap.getPlayerCoordinates().decreaseY();
	}
}
void PlayerTurn::moveRight(Map& gameMap, Character& myPlayer, int mapSize)
{
	int x = gameMap.getPlayerCoordinates().getX();
	int y = gameMap.getPlayerCoordinates().getY();
	if (y + 1 == mapSize)
	{
		cout << "\nYou've gone outside the boarders of the map. Please type a command again." << endl;
	}
	else if (gameMap.getMap()[x][y + 1] == 'r')
	{
		cout << "\nThere's a rock on this field. Please type a command again." << endl;
	}
	else if (gameMap.getMap()[x][y + 1] == '0')
	{
		cout << "\nThere are no enemies on this field." << endl;
		gameMap.movePlayer(x, y + 1, x, y);
		gameMap.getPlayerCoordinates().increaseY();
	}
	else
	{
		battle(gameMap, myPlayer, x, y + 1);
		gameMap.updateMap(x, y + 1, lastOneKilled);
		gameMap.movePlayer(x, y + 1, x, y);
		gameMap.getPlayerCoordinates().increaseY();
	}
}
void PlayerTurn::moveUp(Map& gameMap, Character& myPlayer)
{
	int x = gameMap.getPlayerCoordinates().getX();
	int y = gameMap.getPlayerCoordinates().getY();
	if (x - 1 < 0)
	{
		cout << "\nYou've gone outside the boarders of the map. Please type a command again." << endl;
	}
	else if (gameMap.getMap()[x - 1][y] == 'r')
	{
		cout << "\nThere's a rock on this field. Please type a command again." << endl;
	}
	else if (gameMap.getMap()[x - 1][y] == '0')
	{
		cout << "\nThere are no enemies on this field." << endl;
		gameMap.movePlayer(x - 1, y, x, y);
		gameMap.getPlayerCoordinates().decreaseX();
	}
	else
	{
		battle(gameMap, myPlayer, x - 1, y);
		gameMap.updateMap(x - 1, y, lastOneKilled);
		gameMap.movePlayer(x - 1, y, x, y);
		gameMap.getPlayerCoordinates().decreaseX();
	}
}
void PlayerTurn::moveDown(Map& gameMap, Character& myPlayer, int mapSize)
{
	int x = gameMap.getPlayerCoordinates().getX();
	int y = gameMap.getPlayerCoordinates().getY();
	if (x + 1 == mapSize)
	{
		cout << "\nYou've gone outside the boarders of the map. Please type a command again." << endl;
	}
	else if (gameMap.getMap()[x + 1][y] == 'r')
	{
		cout << "\nThere's a rock on this field. Please type a command again." << endl;
	}
	else if (gameMap.getMap()[x + 1][y] == '0')
	{
		cout << "\nThere are no enemies on this field." << endl;
		gameMap.movePlayer(x + 1, y, x, y);
		gameMap.getPlayerCoordinates().increaseX();
	}
	else
	{
		battle(gameMap, myPlayer, x + 1, y);
		gameMap.updateMap(x + 1, y, lastOneKilled);
		gameMap.movePlayer(x + 1, y, x, y);
		gameMap.getPlayerCoordinates().increaseX();
	}
}
void PlayerTurn::printConsequences() const
{

}