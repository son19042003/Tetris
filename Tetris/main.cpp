#include <iostream>
#include <Windows.h>

using namespace std;

const int height = 37;
const int width = 42;

void gotoXY(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hStdout, position);
}

class Board
{
private:
	int x, y;
	char wall;
public:
	Board();
	void input();
	void setColor();
};

Board::Board()
{
	x = y = 0;
	wall = 219;
}

void Board::input()
{
	for (int i = x; i <= width; i++)
	{
		gotoXY(i, y);
		cout << wall;
	}
	for (int i = x; i <= width; i++)
	{
		gotoXY(i, height);
		cout << wall;
	}
	for (int i = y; i <= height; i++)
	{
		gotoXY(x, i);
		cout << wall << wall;
	}
	for (int i = y; i <= height; i++)
	{
		gotoXY(width, i);
		cout << wall << wall;
	}
}

void color(int text)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, text);
}

void Board::setColor()
{
	x = 2;
	y = 1;
	int count = 0;
	for (int i = x; i < width; i=i+4)
	{
		if (count == 0)
		{
			for (int j = y; j < height; j = j + 4)
			{
				gotoXY(i, j);
				color(8);
				cout << wall << wall << wall << wall;
				gotoXY(i, j + 1);
				cout << wall << wall << wall << wall;
			}
			count++;
			continue;
		}
		if (count == 1)
		{
			for (int j = y; j < height; j = j + 4)
			{
				gotoXY(i, j + 2);
				cout << wall << wall << wall << wall;
				gotoXY(i, j + 3);
				cout << wall << wall << wall << wall;
			}
			count--;
			continue;
		}
	}
}

void teleCursor()
{
	gotoXY(10, 70);
}

int main()
{
	Board board;
	board.input();
	//board.setColor();
	teleCursor();
	return 0;
}
