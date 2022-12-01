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



//ksy
Piece** pieceInit(); //기물 초기화
void SetPieceColor(Piece piece);
void userPos(int* x, int* y, Piece** board, int direction, int color);
void pieceDraw(Piece** board, int x, int y);
void printPosition(int x, int y);

//ysh
int Rook_move(Piece** board, Piece* catchPiece, int turn, char name, int* win, int whatturn, char(*Gibo)[7]);
void recurse_Rook(Piece** board, Piece catchPiece, Piece* catchPiece2, Piece catchPiece_2, int* success, char name, int whatturn, char(*Gibo)[7]);
int Bishop_move(Piece** board, Piece* catchPiece, int turn, char name, int* win, int whatturn, char(*Gibo)[7]);
void recurse_Bishop(Piece** board, Piece catchPiece, Piece* searching_Piece, Piece catchPiece_2, int* p_success, char name, int whatturn, char(*Gibo)[7]);
int Knight_move(Piece** board, Piece* catchPiece, int turn, int* win, int whatturn, char(*Gibo)[7]);
int Pawn_move(Piece** board, Piece* catchPiece, int turn, int* win, int whatturn, char(*Gibo)[7]);
int Queen_move(Piece** board, Piece* catchPiece, int turn, char name, int* win, int whatturn, char(*Gibo)[7]);
int King_move(Piece** board, Piece* catchPiece, int turn, int* win, int whatturn, char(*Gibo)[7]);

void promotion(Piece** board, Piece catchPiece2, char (*Gibo)[7], int whatturn);
void en_passant_reset(Piece** board, int turn);



void printGibofor_txtf(char (*Gibo)[7], int whatturn, char type, char moved_thing, int x1, int y1, int x2, int y2, char changed);
void printGibofor_console(int whatturn, char moved_thing, int x1, int y1, int x2, int y2, char changed);