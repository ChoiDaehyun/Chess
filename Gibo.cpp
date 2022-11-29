#include "Gibo.h"

/*게임이 끝난 후 기보 저장하는 함수*/
void push_Gibo(char(*Gibo)[7], char savewhere, int whatturn, char(*replay_GiboA)[7], char(*replay_GiboB)[7], char(*replay_GiboC)[7], char(*replay_GiboD)[7])
{
	FILE* giboA = fopen(addressA, "wt");
	FILE* giboB = fopen(addressB, "wt");
	FILE* giboC = fopen(addressC, "wt");
	FILE* giboD = fopen(addressD, "wt");

	if (savewhere != 'A')
		for (int i = 0; i < 100; i++)
		{
			if (replay_GiboA[i][0] == -1)
				break;
			for (int j = 0; j < 7; j++)
				fputc((replay_GiboA[i][j]), giboA);
		}

	if (savewhere != 'B')
		for (int i = 0; i < 100; i++)
		{
			if (replay_GiboB[i][0] == -1)
				break;
			for (int j = 0; j < 7; j++)
				fputc((replay_GiboB[i][j]), giboB);
		}

	if (savewhere != 'C')
		for (int i = 0; i < 100; i++)
		{
			if (replay_GiboC[i][0] == -1)
				break;
			for (int j = 0; j < 7; j++)
				fputc((replay_GiboC[i][j]), giboC);
		}

	if (savewhere != 'D')
		for (int i = 0; i < 100; i++)
		{
			if (replay_GiboD[i][0] == -1)
				break;
			for (int j = 0; j < 7; j++)
				fputc((replay_GiboD[i][j]), giboD);
		}

	switch (savewhere)
	{
	case 'A': 
		for (int i = 0; i < (whatturn + 1); i++)
		{
			for (int j = 0; j < 7; j++)
				fputc((Gibo[i][j]), giboA);
			fputc('\n', giboA);
		} break;
	case 'B': 
		for (int i = 0; i < (whatturn + 1); i++)
		{
			for (int j = 0; j < 7; j++)
				fputc((Gibo[i][j]), giboB);
			fputc('\n', giboB);
		} break;
	case 'C':

		for (int i = 0; i < (whatturn + 1); i++)
		{
			for (int j = 0; j < 7; j++)
				fputc((Gibo[i][j]), giboC);
			fputc('\n', giboC);
		} break;
	case 'D': 
		for (int i = 0; i < (whatturn + 1); i++)
		{
			for (int j = 0; j < 7; j++)
				fputc((Gibo[i][j]), giboD);
			fputc('\n', giboD);
		} break;
	}

	fclose(giboA);
	fclose(giboB);
	fclose(giboC);
	fclose(giboD);

	return;
}


/*A,B,C,D에 있던 기보를 가져오는 함수*/
void getGibofrom_txt(char(*replay_GiboA)[7], char(*replay_GiboB)[7], char(*replay_GiboC)[7], char(*replay_GiboD)[7])
{

	FILE* gibo_codeA = fopen(addressA, "rt"); 

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			replay_GiboA[i][j] = fgetc(gibo_codeA);
			if (replay_GiboA[i][j] == -1)
				break;
		}
		fgetc(gibo_codeA);
		if (replay_GiboA[i][0] == -1)
			break;
	}

	fclose(gibo_codeA);

	FILE* gibo_codeB = fopen(addressB, "rt"); 

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			replay_GiboB[i][j] = fgetc(gibo_codeB);
			if (replay_GiboB[i][j] == -1)
				break;
		}
		fgetc(gibo_codeB);
		if (replay_GiboB[i][0] == -1)
			break;
	}

	fclose(gibo_codeB);

	FILE* gibo_codeC = fopen(addressC, "rt");

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			replay_GiboC[i][j] = fgetc(gibo_codeC);
			if (replay_GiboC[i][j] == -1)
				break;
		}
		fgetc(gibo_codeC);
		if (replay_GiboC[i][0] == -1)
			break;
	}

	fclose(gibo_codeC);

	FILE* gibo_codeD = fopen(addressD, "rt");


	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			replay_GiboD[i][j] = fgetc(gibo_codeD);
			if (replay_GiboD[i][j] == -1)
				break;
		}
		fgetc(gibo_codeD);
		if (replay_GiboD[i][0] == -1)
			break;
	}

	fclose(gibo_codeD);
}


int txtf_to_chessboard(char(*got_Gibo)[7], int* whatturn)
{
	system("cls");
	Piece** board;
	board = pieceInit(); //board 초기화
	boardDraw(board); //board 출력
	int turn = 1;
	int n = 0;
	int color;

	char x1, y1;
	char x2, y2;
	char changed;

	while (1)
	{
		turn = 1;
		if (*whatturn % 2 == 0)
			turn = -1;
		x1 = (got_Gibo[*whatturn][2] - '0');
		y1 = (got_Gibo[*whatturn][3] - '0');
		x2 = (got_Gibo[*whatturn][4] - '0');
		y2 = (got_Gibo[*whatturn][5] - '0');
		gotoxy(20, 20);
		changed = got_Gibo[*whatturn][6];
		board[y2][x2] = { board[y1][x1].name, {y2,x2}, board[y1][x1].exist, 0, 0 };
		board[y1][x1] = { '-', {y1,x1},0,0,0 };


		gotoxy(x2, y2);
		if (turn == 1)
			color = white;
		else 
			color = black;

		if ((x2 + y2) % 2 == 0) setColor(color, green); //set background color 
		else setColor(color, brown);
		printf("%c", board[y2][x2].name);


		gotoxy(x1, y1);
		if ((x1 + y1) % 2 == 0) setColor(black, green); //set background color 
		else setColor(black, brown);
		printf("%c", board[y1][x1].name);


		if (got_Gibo[*whatturn][0] == 'B')
		{
			board[y2][x2] = { changed, {y2,x2}, board[y1][x1].exist, 0, 0 };			// 프로모션
			gotoxy(x2, y2);
			if ((x2 + y2) % 2 == 0) setColor(color, green); //set background color 
			else setColor(color, brown);
			printf("%c", board[y2][x2].name);
		}


		if (got_Gibo[*whatturn][1] == 'P')
		{
			if (((y2 - y1) == 2) || ((y2 - y1) == -2))							// 두칸을 이동(전진)하였다면
				board[y1 + ((y2 - y1) / 2)][x1].en_passant = turn;				// 후방 한칸쪽에 앙파상값 설정.

			if (board[y2][x2].en_passant != 0)									// 앙파상이었다면					// 여기 해결 안됨.
			{
				board[y1][x2] = { '-', {y1, x2}, 0,0,0 };						// 앙파상에 당한(?) 말 제거
				gotoxy(x2, y1);
				if ((x2 + y1) % 2 == 0) setColor(black, green); //set background color 
				else setColor(black, brown);
				printf("%c", board[y1][x2].name);

			}
		}
		if (got_Gibo[*whatturn][1] == 'K')
		{
			if ((x2 - x1) == 2)													// 킹이 오른쪽으로 두칸 이동하였다면
			{																	// -> 캐슬링
				board[y1][7] = { '-', {y1,7},0,0,0 };							// 처음 룩 위치 지우고
				board[y1][5] = { 'R', {y1,5},turn, 0,0 };						// 이동될 위치에 룩 두기
				gotoxy(7, y1);
				if ((7 + y1) % 2 == 0) setColor(black, green); //set background color 
				else setColor(black, brown);
				printf("%c", board[y1][7].name);
				gotoxy(5, y1);
				if ((5 + y1) % 2 == 0) setColor(color, green); //set background color 
				else setColor(color, brown);
				printf("%c", board[y1][5].name);
			}
			else if ((x2 - x1) == -2)											// 킹이 왼쪽으로 두칸 이동하였다면
			{																	// -> 마찬가지로 캐슬링
				board[y1][0] = { '-', {y1,0},0,0,0 };							// 처음 룩 위치 지우고
				board[y1][3] = { 'R', {y1,3},turn, 0,0 };						// 이동될 위치에 룩 두기
				gotoxy(0, y1);
				if ((0 + y1) % 2 == 0) setColor(black, green); //set background color 
				else setColor(black, brown);
				printf("%c", board[y1][0].name);
				gotoxy(3, y1);
				if ((3 + y1) % 2 == 0) setColor(color, green); //set background color 
				else setColor(color, brown);
				printf("%c", board[y1][3].name);
			}
		}

		while(true){
			int n = keyControl();

			if (n == RIGHT || n == SUBMIT){
				switch (n)
				{
					case RIGHT:
						++(*whatturn);
						break;
					case SUBMIT:
						printf("@");
						break;
				}
				break;
			}
		}


		if (board[y2][x2].name == 'K') {
			setColor(white, black);
			printf("스페이스바를 누르면 메뉴화면으로 돌아갑니다");

			while (true) {
				if (keyControl() == SUBMIT) 
					return 0;
			}
		}
	}
	return 0;
}