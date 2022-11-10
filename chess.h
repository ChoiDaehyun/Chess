#pragma once
#include "main.h"
#include "piece.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4


void titleDraw();
int menuDraw();
int keyControl();
void infoDraw();
void startGame();
void boardDraw(Piece (*board)[8]);
void userPos(int *x, int *y, Piece (*board)[8], int direction);

int Rook_move(Piece(*board)[8], Piece catchPiece, int turn);
void recurse_Rook(Piece(*board)[8], Piece catchPiece, Piece* catchPiece2, Piece catchPiece_2, int* success);
