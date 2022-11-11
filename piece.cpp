#include "piece.h"

Piece (*pieceInit())[8]
{
	Piece pieces[8][8];
	Piece piece;
	int i,j ;
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++) {
			pieces[i][j].name = '-';
			pieces[i][j].exist = 0;
		}

	//Rook
	piece.name = 'R'; 
	piece.exist = -1; //Èæ
	pieces[0][0] = piece; pieces[0][7] = piece;
	piece.exist = 1; //¹é
	pieces[7][0] = piece; pieces[7][7] = piece;

	//Knight
	piece.name = 'N'; 
	piece.exist = -1;
	pieces[0][1] = piece; pieces[0][6] = piece;
	piece.exist = 1;
	pieces[7][1] = piece; pieces[7][6] = piece;

	//Bishop
	piece.name = 'B'; 
	piece.exist = -1;
	pieces[0][2] = piece; pieces[0][5] = piece;
	piece.exist = 1;
	pieces[7][2] = piece; pieces[7][5] = piece;

	//Queen
	piece.name = 'Q'; 
	piece.exist = -1;
	pieces[0][3] = piece;
	piece.exist = 1;
	pieces[7][3] = piece;

	//King
	piece.name = 'K';
	piece.exist = -1;
	pieces[0][4] = piece;
	piece.exist = 1;
	pieces[7][4] = piece;

	
	//Pawn
	piece.name = 'P';
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

void SetPieceColor(Piece piece)
{
	int x = piece.pos[0], y = piece.pos[1];
	int forground, background;
	if (piece.exist == 1) //¹é
		forground = white;
	else //if (piece.exist == -1) //Èæ
		forground = black;
	if((x+y)%2 == 0)
		setColor(forground, green);
	else setColor(forground, brown);
}


