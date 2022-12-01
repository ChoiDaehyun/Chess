#pragma once
#include "chess.h"
#include "util.h"

#ifndef __GiboAddress__
#define __GiboAddress__
#define addressA "./chessmemo/A.txt"
#define addressB "./chessmemo/B.txt"
#define addressC "./chessmemo/C.txt"
#define addressD "./chessmemo/D.txt"
#endif // !__GiboAddress__

//ysh
void push_Gibo(char(*Gibo)[7], char savewhere, int whatturn, char(*replay_GiboA)[7], char(*replay_GiboB)[7], char(*replay_GiboC)[7], char(*replay_GiboD)[7]);
void getGibofrom_txt(char(*replay_GiboA)[7], char(*replay_GiboB)[7], char(*replay_GiboC)[7], char(*replay_GiboD)[7]);
int txtf_to_chessboard(char (*got_Gibo)[7], int* whatturn);
int restartGame(char (*Gibo)[7], int* get_whatturn, Piece** board1);