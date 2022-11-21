#include "util.h"

void gotoxy(int x, int y) {
	HANDLE consolhandel = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consolhandel, pos);
};

void init() {
	system("mode con cols=56 lines=20 | title Chess Game");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void setColor(int forground, int background)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

int keyControl() {
	int i = _getch();
	if (i == 224) {
		i = _getch();
		switch (i) {
		case 72: return UP;
		case 80: return DOWN;
		case 75: return LEFT;
		case 77: return RIGHT;
		}
	}
	else if (i == ' ') return SUBMIT;
}
