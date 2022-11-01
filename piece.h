#pragma once
#include <string.h>

typedef struct {
	char name;
	int pos[2];
	int exist;
} Piece;

Piece (*pieceInit())[8]; //기물 초기화