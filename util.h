#pragma once
#include "main.h"

#ifndef __COLOR_LIST_
#define __COLOR_LIST_

enum {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yello,
	white
};

#endif // !__COLOR_LIST_

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

#define Black -1
#define White 1
#define Noting 0

int keyControl();
void gotoxy(int x, int y);
void init();
void setColor(int forground, int background);
