#pragma once
#include "main.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

#define MAX_NAME 10

typedef struct {
	char name[MAX_NAME];
	int pos[2];
	int exist;
} Piece;

void titleDraw();
int menuDraw();
int keyControl();
void infoDraw();
void startGame();
