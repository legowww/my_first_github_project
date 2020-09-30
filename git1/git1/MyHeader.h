#pragma once
#include <iostream>
#include <array>
#include <algorithm>
#include <conio.h>

using namespace std;

class Position
{
private:
	int m_x;
	int m_y;

public:
	Position(const int& x = 0, const int& y = 0)
		:m_x(x), m_y(y)
	{}

	void setPos(const int& x = 0, const int& y = 0)
	{
		m_x = x;
		m_y = y;
	}

	int& xPos()
	{
		return m_x;
	}

	int& yPos()
	{
		return m_y;
	}

};

void setMaze(char(&maze)[10][21]);

void print(const char(&maze)[10][21], Position& userPos);

void moveUp(char(&maze)[10][21], Position& userPos);

void moveDown(char(&maze)[10][21], Position& userPos);

void moveRight(char maze[10][21], Position& userPos);

void moveLeft(char maze[10][21], Position& userPos);

void movePlayer(char(&maze)[10][21], Position& userPos, char& input);