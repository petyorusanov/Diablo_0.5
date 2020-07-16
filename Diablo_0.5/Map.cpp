#include "Map.h"


Map::Map() : playerCoordinates()
{
	map = new char* [10];
	for (int i = 0; i < 10; i++)
	{
		map[i] = new char[11];
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			map[i][j] = '0';
		}
		map[i][10] = '\0';
	}
	skeletonsAlive = 0;
	hereticsAlive = 0;
	necromancersAlive = 0;
	diablosAlive = 0;
}
Map::Map(int mapSize) : playerCoordinates()
{
	map = new char* [mapSize];
	for (int i = 0; i < mapSize; i++)
	{
		map[i] = new char[mapSize + 1];
	}
	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			map[i][j] = '0';
		}
		map[i][mapSize] = '\0';
	}
	skeletonsAlive = 0;
	hereticsAlive = 0;
	necromancersAlive = 0;
	diablosAlive = 0;
}
Map::~Map()
{
	for (unsigned int i = 0; i < strlen(*map); i++)
	{
		delete[] map[i];
	}
	delete[] map;
}
void Map::setMap(int mapSize)
{
	skeletonsAlive = (int)((mapSize * mapSize) * 0.25);
	hereticsAlive = (int)((mapSize * mapSize) * 0.15);
	necromancersAlive = (int)((mapSize * mapSize) * 0.05);
	diablosAlive = (int)((mapSize * mapSize) * 0.01);
	int rocks = (int)((mapSize * mapSize) * 0.05);
	int i;
	int j;
	int counter = 0;
	srand(time(NULL));
	while (counter < skeletonsAlive)
	{
		i = rand() / 100;
		j = rand() / 100;
		if (i < mapSize && j < mapSize && map[i][j] == '0')
		{
			map[i][j] = 's';
			counter++;
		}
	}
	counter = 0;
	while (counter < hereticsAlive)
	{
		i = rand() / 100;
		j = rand() / 100;
		if (i < mapSize && j < mapSize && map[i][j] == '0')
		{
			map[i][j] = 'h';
			counter++;
		}
	}
	counter = 0;
	while (counter < necromancersAlive)
	{
		i = rand() / 100;
		j = rand() / 100;
		if (i < mapSize && j < mapSize && map[i][j] == '0')
		{
			map[i][j] = 'n';
			counter++;
		}
	}
	counter = 0;
	while (counter < diablosAlive)
	{
		i = rand() / 100;
		j = rand() / 100;
		if (i < mapSize && j < mapSize && map[i][j] == '0')
		{
			map[i][j] = 'd';
			counter++;
		}
	}
	counter = 0;
	while (counter < rocks)
	{
		i = rand() / 100;
		j = rand() / 100;
		if (i < mapSize && j < mapSize && map[i][j] == '0')
		{
			map[i][j] = 'r';
			counter++;
		}
	}
	counter = 0;
	while (counter == 0)
	{
		i = rand() / 100;
		j = rand() / 100;
		if (i < mapSize && j < mapSize && map[i][j] == '0')
		{
			map[i][j] = 'U';
			playerCoordinates.setPlayerCoordinates(i, j);
			counter++;
		}
	}
}
void Map::printMap(int mapSize) const
{
	cout << "\n";
	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\nLegend:"
		<< "\nr - rock"
		<< "\ns - skeleton" << " (currently " << skeletonsAlive << " skeletons are alive)"
		<< "\nh - heretic" << " (currently " << hereticsAlive << " heretics are alive)"
		<< "\nn - necromancer" << " (currently " << necromancersAlive << " necromancers are alive)"
		<< "\nd - diablo" << " (currently " << diablosAlive << " diablos are alive)"
		<< "\nYour character's coordinates are: (" << playerCoordinates.getX() << ", " << playerCoordinates.getY() << ")" << endl;
	system("pause");
	cin.get();
	if (system("CLS")) system("clear");
}
char** Map::getMap() const
{
	return map;
};
void Map::movePlayer(int newX, int newY, int oldX, int oldY)
{
	map[newX][newY] = 'U';
	map[oldX][oldY] = '0';
}
int Map::getDiablosAlive() const
{
	return diablosAlive;
}
void Map::updateMap(int x, int y, char lastOneKilled)
{
	map[x][y] = '0';
	switch (lastOneKilled)
	{
	case 's':
	{
		skeletonsAlive--;
	}break;
	case 'h':
	{
		hereticsAlive--;
	}break;
	case 'n':
	{
		necromancersAlive--;
	}break;
	case 'd':
	{
		diablosAlive--;
	}break;
	default:
	{
		skeletonsAlive--;
	}break;
	};
}
PlayerCoordinates& Map::getPlayerCoordinates()
{
	return playerCoordinates;
}