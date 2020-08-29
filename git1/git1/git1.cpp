#include "MyHeader.h"
using namespace std;


int main()
{
	char Maze[10][21] = {};

	Position userPos;
	Position userSta(0, 0);
	Position userEnd(11, 8);
	setMaze2(Maze);

	print2(Maze, userPos);

	while (1)
	{
		system("cls");
		print2(Maze, userPos);

		if (userPos.xPos() == userEnd.xPos() && userPos.yPos() == userEnd.yPos())
		{
			cout << "[clear!]" << endl;
			system("pause");
			break;
		}

		cout << "[move] W A S D [exit] Q : ";

		char Input = _getch();

		if (Input == 'q' || Input == 'Q')
			break;

		movePlayer2(Maze, userPos, Input);
	}
	


	
	
}
