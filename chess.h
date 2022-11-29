#pragma once
#include "main.h"
#include "piece.h"


//ksy
void titleDraw();
int menuDraw();

void infoDraw();
int startGame(char(*Gibo)[7], int* get_whatturn);

void boardDraw(Piece **board);

void switchTurn(int* x, int* y, int* turn);

//ysh
int GiboDraw();

void push_Gibo(char(*Gibo)[7], char savewhere, int whatturn, char(*replay_GiboA)[7], char(*replay_GiboB)[7], char(*replay_GiboC)[7], char(*replay_GiboD)[7]);
void getGibofrom_txt(char(*replay_GiboA)[7], char(*replay_GiboB)[7], char(*replay_GiboC)[7], char(*replay_GiboD)[7]);
int txtf_to_chessboard(char(* got_Gibo)[7], int* whatturn);