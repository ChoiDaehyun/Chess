#pragma once
#include <string.h>
#include "util.h"

#ifndef __PIECE__
#define __PIECE__
typedef struct {
	char name;
	int pos[2];
	int exist;
	int castling;
	int en_passant;
} Piece;
#endif // !__PIECE__

Piece (*pieceInit())[8]; //기물 초기화
void SetPieceColor(Piece piece);
void userPos(int* x, int* y, Piece(*board)[8], int direction, int color);

//ysh
int Rook_move(Piece(*board)[8], Piece* catchPiece, int turn, char name, int* win);
void recurse_Rook(Piece(*board)[8], Piece catchPiece, Piece* catchPiece2, Piece catchPiece_2, int* success, char name);
int Bishop_move(Piece(*board)[8], Piece* catchPiece, int turn, char name, int* win);
void recurse_Bishop(Piece(*board)[8], Piece catchPiece, Piece* searching_Piece, Piece catchPiece_2, int* p_success, char name);
int Knight_move(Piece(*board)[8], Piece* catchPiece, int turn, int* win);
int Pawn_move(Piece(*board)[8], Piece* catchPiece, int turn, int* win);
int Queen_move(Piece(*board)[8], Piece* catchPiece, int turn, char name, int* win);
int King_move(Piece(*board)[8], Piece* catchPiece, int turn, int* win);

void promotion(Piece(*board)[8], Piece catchPiece2);
void en_passant_reset(Piece(*board)[8], int turn);