#pragma once

class PlayerCoordinates
{
private:
	int x;
	int y;
public:
	PlayerCoordinates()
	{
		x = 0;
		y = 0;
	};
	void setPlayerCoordinates(int xC, int yC)
	{
		x = xC;
		y = yC;
	};
	int getX() const
	{
		return x;
	};
	int getY() const
	{
		return y;
	};
	void decreaseX() { x--; };
	void decreaseY() { y--; };
	void increaseX() { x++; };
	void increaseY() { y++; };
};

