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
void userPos(int *x, int *y, Piece (*board)[8], int direction, int color);

int Rook_move(Piece(*board)[8], Piece* catchPiece, int turn);
void recurse_Rook(Piece(*board)[8], Piece catchPiece, Piece* catchPiece2, Piece catchPiece_2, int* success);
int Bishop_move(Piece(*board)[8], Piece* catchPiece, int turn);
void recurse_Bishop(Piece(*board)[8], Piece catchPiece, Piece* searching_Piece, Piece catchPiece_2, int* p_success);
int Knight_move(Piece(*board)[8], Piece* catchPiece, int turn);
int Phone_move(Piece(*board)[8], Piece* catchPiece, int turn);

void switchTurn(int* x, int* y, int* turn);
