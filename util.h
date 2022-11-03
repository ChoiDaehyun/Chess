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


void gotoxy(int x, int y);
void init();
void setColor(int forground, int background);
