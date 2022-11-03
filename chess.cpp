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
				gotoxy(x, y);
				SetPieceColor(board[y][x]);
				printf("%c", board[y][x].name);
				gotoxy(x, --y);
				setColor(red, lightgray);
				printf("%c", board[y][x].name);
			}
			break;
		case DOWN:
			if (y < 7) {
				gotoxy(x, y);
				SetPieceColor(board[y][x]);
				printf("%c", board[y][x].name);
				gotoxy(x, ++y);
				setColor(red, lightgray);
				printf("%c", board[y][x].name);
			}break;
		case LEFT:
			if (x > 0) {
				gotoxy(x, y);
				SetPieceColor(board[y][x]);
				printf("%c", board[y][x].name);
				gotoxy(--x, y);
				setColor(red, lightgray);
				printf("%c", board[y][x].name);
			}
			break;
		case RIGHT:
			if (x < 7) {
				gotoxy(x, y);
				SetPieceColor(board[y][x]);
				printf("%c", board[y][x].name);
				gotoxy(++x, y);
				setColor(red, lightgray);
				printf("%c", board[y][x].name);
			}
			break;
		case SUBMIT:
			catchPiece = board[x][y];
			if (turn == catchPiece.exist) //player에 맞는 색상의 기물 선택
			{

			}
			else {

				
			}
			return;
		}
		turn *= -1; //턴 전환
	}

	

}

void boardDraw(Piece (*board)[8]) {
	setColor(blue, lightgray);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j].exist == 1)
				setColor(white, lightgray);
			else setColor(black, lightgray);
			printf("%c", board[i][j].name);
		}
		printf("\n");
	}
	setColor(black, lightgray);
}