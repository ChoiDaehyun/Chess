#pragma once
#include "main.h"
#include "piece.h"


//ksy
void titleDraw();
int menuDraw();
void infoDraw();
int startGame();
void boardDraw(Piece (*board)[8]);

void switchTurn(int* x, int* y, int* turn);
void writeNotation(int x, int y);


