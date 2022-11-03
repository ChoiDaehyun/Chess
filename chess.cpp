#include "chess.h"
#include "util.h"
#include "piece.h"

void titleDraw() {
	printf("\n\n\n\n");
	printf("            #####  ##   ##  ##### ##### #####\n");
	printf("            ##     ##   ##  ##    ##    ##   \n");
	printf("            ##     #######  ####  ##### #####\n");
	printf("            ##     ##   ##  ##       ##    ##\n");
	printf("            ####   ##   ##  ##### ##### #####\n");
}

int menuDraw() {
	int x = 22, y = 12;
	gotoxy(x-2, y);
	printf("> 게임 시작");	
	gotoxy(x, y+1);
	printf("게임 방법");	
	gotoxy(x, y+2);
	printf("  종 료  ");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP:
			if (y > 12) {
				gotoxy(x-2, y);
				printf(" ");
				gotoxy(x-2, --y);
				printf(">");
			};
			break;
		case DOWN:
			if (y < 14) {
				gotoxy(x-2, y);
				printf(" ");
				gotoxy(x-2, ++y);
				printf(">");
			};
			break;
		case SUBMIT:
			return y-12;
		}
	}
	return 1;
}

int keyControl() {
	int i = _getch();
	if (i == 224) {
		i = _getch();
		switch (i) {
		case 72: return UP;
		case 80: return DOWN;
		case 75: return LEFT;
		case 77: return RIGHT;
		}
	} else if(i == ' ') return SUBMIT;
}

void infoDraw() {
	system("cls");
	printf("\n\n");
	printf("		 [ 조작법 ]\n\n");
	printf("		 이동 : 방향 키보드\n");
	printf("		 선택 : 스페이스바\n\n\n\n\n\n\n");
	printf("		 개발자 : ksy\n\n");
	printf("    스페이스바를 누르면 메인화면으로 이동합니다.");

	while (1) {
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}

void startGame() {
	system("cls");
	int turn = 1, key;
	int x = 0, y = 0;

	Piece (*board)[8]; //board 선언
	Piece catchPiece;
	board = pieceInit(); //board 초기화
	gotoxy(0,0);
	boardDraw(board); //board 출력

	while (1) {
		//setColor(black, lightgray);
		key = keyControl();
		switch (key)
		{
		case UP:
			if (y > 0) {
				userPos(&x, &y, board, UP);
			}
			break;
		case DOWN:
			if (y < 7) {
				userPos(&x, &y, board, DOWN);
			}break;
		case LEFT:
			if (x > 0) {
				userPos(&x, &y, board, LEFT);
			}
			break;
		case RIGHT:
			if (x < 7) {
				userPos(&x, &y, board, RIGHT);
			}
			break;
		case SUBMIT:
			catchPiece = board[x][y];
			if (turn == catchPiece.exist) //player에 맞는 색상의 기물 선택
			{

			}
			else {

				
			}
			setColor(white, black);
			return;
		}
		turn *= -1; //턴 전환
	}

	
	setColor(white, black);
}

void boardDraw(Piece (*board)[8]) {
	int forground, background;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) background = green; //set background color 
			else background = brown;
			if (board[i][j].exist == 1) //set forground color
				forground = white;
			else forground = black;

			setColor(forground, background);
			printf("%c", board[i][j].name); //출력
		}
		printf("\n");
	}
	setColor(white, black);
}

void userPos(int *x, int *y, Piece(*board)[8], int direction)
{
	int a = board[*x][*y].pos[0], b = board[*x][*y].pos[1];
	gotoxy(*x, *y);
	SetPieceColor(board[*y][*x]);
	printf("%c", board[*y][*x].name);
	switch (direction)
	{
	case UP: gotoxy(*x, --*y); break;
	case DOWN: gotoxy(*x, ++*y); break;
	case LEFT: gotoxy(--*x, *y); break;
	case RIGHT: gotoxy(++*x, *y); break;
	}
	if ((*x + *y) % 2 == 0) setColor(red, green); //set background color 
	else setColor(red, brown);
	printf("%c", board[*y][*x].name);
}
