#include "MyHeader.h"
using namespace std;


int main()
{
	char Maze[10][21] = {};

	Position userPos;
	Position userSta(0, 0);
	Position userEnd(11, 8);
	setMaze(Maze);

	print(Maze, userPos);

	while (1)
	{
		system("cls");
		print(Maze, userPos);

		if (userPos.xPos() == userEnd.xPos() && userPos.yPos() == userEnd.yPos())
		{
			cout << "[clear!]" << endl;
			break;
		}

		cout << "[�̵�] W A S D [����] Q " << endl;

		char Input = _getch(); // conio.h �߰�

		if (Input == 'q' || Input == 'Q')
			break;

		movePlayer(Maze, userPos, Input);
	}

	return 0;
}
