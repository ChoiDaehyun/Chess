#include "piece.h"

Piece (*pieceInit())[8]
{
	Piece pieces[8][8];
	Piece piece;
	int i,j ;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			pieces[i][j].name = '-';

	//Rook
	piece.name = 'r'; 
	piece.exist = -1;
	pieces[0][0] = piece; pieces[0][7] = piece;
	piece.exist = 1;
	pieces[7][0] = piece; pieces[7][7] = piece;

	//Knight
	piece.name = 'n'; 
	piece.exist = -1;
	pieces[0][1] = piece; pieces[0][6] = piece;
	piece.exist = 1;
	pieces[7][1] = piece; pieces[7][6] = piece;

	//Bishop
	piece.name = 'b'; 
	piece.exist = -1;
	pieces[0][2] = piece; pieces[0][5] = piece;
	piece.exist = 1;
	pieces[7][2] = piece; pieces[7][5] = piece;

	//Queen
	piece.name = 'q'; 
	piece.exist = -1;
	pieces[0][3] = piece;
	piece.exist = 1;
	pieces[7][3] = piece;

	//King
	piece.name = 'k';
	piece.exist = -1;
	pieces[0][4] = piece;
	piece.exist = 1;
	pieces[7][4] = piece;

	//Pawn
	piece.name = 'p';
	piece.exist = -1;
	for (i = 0; i < 8; i++)
		pieces[1][i] = piece;
	piece.exist = 1;
	for (i = 0; i < 8; i++)
		pieces[6][i] = piece;

	//position
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if(pieces[i][j].name )
			pieces[i][j].pos[0] = i;
			pieces[i][j].pos[1] = j;
		}
	}

	return pieces;
}
