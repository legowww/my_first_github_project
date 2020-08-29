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

	int &xPos()
	{
		return m_x;
	}

	int &yPos()
	{
		return m_y;
	}

};

void setMaze2(char(&maze)[10][21])
{
	strcpy_s(maze[0], 21, "21111111111111100000");
	strcpy_s(maze[1], 21, "00011000000011000000");
	strcpy_s(maze[2], 21, "00001111111011000000");
	strcpy_s(maze[3], 21, "00001000111001100000");
	strcpy_s(maze[4], 21, "00001100000001100000");
	strcpy_s(maze[5], 21, "00001100001000100000");
	strcpy_s(maze[6], 21, "00001111111101100000");
	strcpy_s(maze[7], 21, "00001100110101100000");
	strcpy_s(maze[8], 21, "00001100110301100000");
	strcpy_s(maze[9], 21, "00000000000000100000");
}

void print2(char(&maze)[10][21], Position &userPos)
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			if (userPos.xPos() == j && userPos.yPos() == i)
				cout << "♀";

			else if (maze[i][j] == '0')
				cout << "■";
			else if (maze[i][j] == '1')
				cout << "  ";
			else if (maze[i][j] == '2')
				cout << "★";
			else if (maze[i][j] == '3')
				cout << "◎";


		}
		cout << endl;
	}
	cout << endl;
}

void moveUp2(char (&maze)[10][21], Position &userPos)
{
	// 맨위에 칸에서는 더이상 위로 갈수 없기에
	if (userPos.yPos() - 1 >= 0)
	{
		// 벽(0)이 아니면
		if (maze[userPos.yPos() - 1][userPos.xPos()] != '0')
			userPos.yPos() = userPos.yPos() - 1;
	}
}

void moveDown2(char(&maze)[10][21], Position& userPos)
{
	if (userPos.yPos() + 1 < 10)
	{
		if (maze[userPos.yPos() + 1][userPos.xPos()] != '0')
			userPos.yPos()= userPos.yPos() + 1;
	}
}

void moveRight2(char maze[10][21], Position& userPos)
{
	if (userPos.xPos() + 1 < 20)
	{
		if (maze[userPos.yPos()][userPos.xPos() + 1] != '0')
			userPos.xPos() = userPos.xPos() + 1;
	}
}

void moveLeft2(char maze[10][21], Position& userPos)
{
	if (userPos.xPos() - 1 >= 0)
	{
		if (maze[userPos.yPos()][userPos.xPos() - 1] != '0')
			userPos.xPos() = userPos.xPos() - 1;
	}
}


void movePlayer2(char (&maze)[10][21], Position& userPos, char &input)
{
	switch (input)
	{
	case 'w':
	case 'W':
		moveUp2(maze, userPos);
		break;
	case 'a':
	case 'A':
		moveLeft2(maze, userPos);
		break;
	case 's':
	case 'S':
		moveDown2(maze, userPos);
		break;
	case 'd':
	case 'D':
		moveRight2(maze, userPos);
		break;
	}
}