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
}