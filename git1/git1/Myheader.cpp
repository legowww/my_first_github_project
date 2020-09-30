#include "MyHeader.h"

void setMaze(char(&maze)[10][21]) // [20]으로 하면 오류가나서 [21]로 안전하게 작성
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

void print(const char(&maze)[10][21], Position& userPos)
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			if (userPos.xPos() == j && userPos.yPos() == i)
				cout << "♀";

			else if (maze[i][j] == '0')
				cout << "■"; // 0은 벽
			else if (maze[i][j] == '1')
				cout << "  "; // 1은 통로
			else if (maze[i][j] == '2')
				cout << "★"; // 2는 시작지점
			else if (maze[i][j] == '3')
				cout << "◎"; // 3은 종료지점


		}
		cout << endl;
	}
	cout << endl;
}

void moveUp(char(&maze)[10][21], Position& userPos)
{
	// 맨위에 칸에서는   >= 0)
	if (userPos.yPos() - 1 >= 0) // y좌표 -1 : 위로 한칸 이동을 의미한다
	{
		// 벽(0)이 아니면
		if (maze[userPos.yPos() - 1][userPos.xPos()] != '0')
			userPos.yPos() = userPos.yPos() - 1;
	}
}

void moveDown(char(&maze)[10][21], Position& userPos)
{
	if (userPos.yPos() + 1 < 10)
	{
		if (maze[userPos.yPos() + 1][userPos.xPos()] != '0')
			userPos.yPos() = userPos.yPos() + 1;
	}
}

void moveRight(char maze[10][21], Position& userPos)
{
	if (userPos.xPos() + 1 < 20)
	{
		if (maze[userPos.yPos()][userPos.xPos() + 1] != '0')
			userPos.xPos() = userPos.xPos() + 1;
	}
}

void moveLeft(char maze[10][21], Position& userPos)
{
	if (userPos.xPos() - 1 >= 0)
	{
		if (maze[userPos.yPos()][userPos.xPos() - 1] != '0')
			userPos.xPos() = userPos.xPos() - 1;
	}
}


void movePlayer(char(&maze)[10][21], Position& userPos, char& input)
{
	switch (input)
	{
	case 'w':
	case 'W':
		moveUp(maze, userPos);
		break;
	case 'a':
	case 'A':
		moveLeft(maze, userPos);
		break;
	case 's':
	case 'S':
		moveDown(maze, userPos);
		break;
	case 'd':
	case 'D':
		moveRight(maze, userPos);
		break;
	}
}