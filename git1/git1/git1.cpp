#include <iostream>
#include <array>
#include <algorithm>
#include <conio.h>

using namespace std;

// 플레이어 위치

class pPoint
{
public:
	int x;
	int y;
	
};

typedef pPoint POINT;
typedef pPoint* PPOINT;



// 0 벽
// 1 길
// 2 시작
// 3 도착
void setMaze(char (&maze)[10][21], PPOINT playerPos, PPOINT playerSta, PPOINT playerEnd)
{
	playerPos->x = 0;
	playerPos->y = 0;

	playerEnd->x = 11;
	playerEnd->y = 8;

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

void print(char(&maze)[10][21], PPOINT playerPos)
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			if (playerPos->x == j && playerPos->y == i)
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

void moveUp(char maze[10][21], PPOINT playerPos)
{
		// 맨위에 칸에서는 더이상 위로 갈수 없기에
	if (playerPos->y - 1 >= 0)
	{
		// 벽(0)이 아니면
		if (maze[playerPos->y - 1][playerPos->x] != '0')
			--playerPos->y;
	}
}

void moveDown(char maze[10][21], PPOINT playerPos)
{
	if (playerPos->y + 1 < 10)
	{
		if (maze[playerPos->y + 1][playerPos->x] != '0')
			++playerPos->y;
	}
}

void moveRight(char maze[10][21], PPOINT playerPos)
{
	if (playerPos->x + 1 < 20)
	{
		if (maze[playerPos->y][playerPos->x + 1] != '0')
			++playerPos->x;
	}
}

void moveLeft(char maze[10][21], PPOINT playerPos)
{
	if (playerPos->x - 1 >= 0)
	{
		if (maze[playerPos->y][playerPos->x - 1] != '0')
			--playerPos->x;
	}
}


void movePlayer(char maze[10][21], PPOINT playerPos, char input)
{
	switch (input)
	{
	case 'w' :
	case 'W' :
		moveUp(maze, playerPos);
		break;
	case 'a':
	case 'A':
		moveLeft(maze, playerPos);
		break;
	case 's':
	case 'S':
		moveDown(maze, playerPos);
		break;
	case 'd':
	case 'D':
		moveRight(maze, playerPos);
		break;
	}
}




int main()
{
	char Maze[10][21] = {};

	POINT playerPos;
	POINT playerSta;
	POINT playerEnd;

	setMaze(Maze, &playerPos, &playerSta, &playerEnd);

	while (1) 
	{
		system("cls");
		print(Maze, &playerPos);

		if (playerPos.x == playerEnd.x && playerPos.y == playerEnd.y)
		{
			cout << "[도착!]" << endl;
			system("pause");
			break;
		}
		cout << "[이동] W A S D [종료] Q : ";

		char Input = _getch();

		if (Input == 'q' || Input == 'Q')
			break;

		movePlayer(Maze, &playerPos, Input);

	}
	
}
