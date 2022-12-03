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
			{
				fputc(replay_GiboA[i][j], giboA);
			}

			fputc('\n', giboA);
		}

	if (savewhere != 'B')
		for (int i = 0; i < 100; i++)
		{
			if (replay_GiboB[i][0] == -1)
				break;
			for (int j = 0; j < 7; j++)
			{
				fputc(replay_GiboB[i][j], giboB);
			}

			fputc('\n', giboB);
		}

	if (savewhere != 'C')
		for (int i = 0; i < 100; i++)
		{
			if (replay_GiboC[i][0] == -1)
				break;
			for (int j = 0; j < 7; j++)
			{
				fputc(replay_GiboC[i][j], giboC);
			}

			fputc('\n', giboC);
		}

	if (savewhere != 'D')
		for (int i = 0; i < 100; i++)
		{
			if (replay_GiboD[i][0] == -1)
				break;
			for (int j = 0; j < 7; j++)
			{
				fputc(replay_GiboD[i][j], giboD);
			}

			fputc('\n', giboD);
		}

	switch (savewhere)
	{
	case 'A': 
		for (int i = 0; i < (whatturn + 1); i++)
		{
			for (int j = 0; j < 7; j++)
			{
				fputc((Gibo[i][j]), giboA);
			}

			fputc('\n', giboA);
		} break;
	case 'B': 
		for (int i = 0; i < (whatturn + 1); i++)
		{
			for (int j = 0; j < 7; j++)
			{
				fputc((Gibo[i][j]), giboB);
			}

			fputc('\n', giboB);
		} break;
	case 'C':

		for (int i = 0; i < (whatturn + 1); i++)
		{
			for (int j = 0; j < 7; j++)
			{
				fputc((Gibo[i][j]), giboC);
			}

			fputc('\n', giboC);
		} break;
	case 'D': 
		for (int i = 0; i < (whatturn + 1); i++)
		{
			for (int j = 0; j < 7; j++)
			{
				fputc((Gibo[i][j]), giboD);
			}

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


int txtf_to_chessboard(char (*got_Gibo)[7], int* whatturn)
{
	system("cls");
	Piece** board;
	board = pieceInit(); //board 초기화
	boardDraw(board); //board 출력
	gotoxy(10, 6);
	printf("[→] key   : 다음");
	gotoxy(10, 7);
	printf("[spacebar] : 리플레이");

	int turn;
	int n = 0;
	int color;
	int get_enpassant;			//앙파상값 미리 참조.
	int get_exist;
	int get_name;

	char x1, y1;
	char x2, y2;
	char changed;
	--(*whatturn);

	while (1)
	{
		n = keyControl();
		switch (n)
		{
		case RIGHT:																// 오른쪽 키 누르면, 계속 진행
			++(*whatturn);
			break;
		case SUBMIT:															// 스페이스바 누르면 그 상황부터 게임 진행 가능.
			++(*whatturn);
			int win;
			win = restartGame(got_Gibo, whatturn, board);

			gotoxy(0, 15);

			if (win == 1)
			{
				printf("Replay Game : White Team Win!!");
			}
			else if (win == -1)
			{
				printf("Replay Game : Black Team Win!!");
			}
			return 0;
			break;
		default:
			continue;
		}


		turn = 1;
		if (*whatturn % 2 == 0)					// 턴 구현
			turn = -1;

		//printf("%d", board[2][2].en_passant);
		en_passant_reset(board, turn);


		x1 = (got_Gibo[*whatturn][2] - '0');
		y1 = (got_Gibo[*whatturn][3] - '0');
		x2 = (got_Gibo[*whatturn][4] - '0');
		y2 = (got_Gibo[*whatturn][5] - '0');
		changed = got_Gibo[*whatturn][6];
		get_enpassant = board[y2][x2].en_passant;		// 앙파상값 미리 참조.



		get_exist = board[y2][x2].exist;
		get_name = board[y2][x2].name;


		board[y2][x2] = { board[y1][x1].name, {y2,x2}, board[y1][x1].exist, 0, 0 };
		board[y1][x1] = { '-', {y1,x1},0,0,0 };
		
		pieceDraw(board, x1, y1);
		pieceDraw(board, x2, y2);
		color = white;



		if (got_Gibo[*whatturn][0] == 'B')
		{
			board[y2][x2] = { changed, {y2,x2}, board[y2][x2].exist, 0, 0 };			// 프로모션
			pieceDraw(board, x2, y2);
		}


		if (got_Gibo[*whatturn][1] == 'P')
		{
			if (((y2 - y1) == 2) || ((y2 - y1) == -2))							// 두칸을 이동(전진)하였다면
			{
				board[y1 + ((y2 - y1) / 2)][x1].en_passant = turn;				// 후방 한칸쪽에 앙파상값 설정.
			}

			if (get_enpassant != 0)									// 앙파상이었다면					// 여기 해결 안됨.
			{
				board[y1][x2] = { '-', {y1, x2}, 0,0,0 };						// 앙파상에 당한(?) 말 제거
				pieceDraw(board, x2, y1);


			}
		}
		if (got_Gibo[*whatturn][1] == 'K')
		{
			if ((x2 - x1) == 2)													// 킹이 오른쪽으로 두칸 이동하였다면
			{																	// -> 캐슬링
				board[y1][7] = { '-', {y1,7},0,0,0 };							// 처음 룩 위치 지우고
				board[y1][5] = { 'R', {y1,5},turn*(-1), 0,0};						// 이동될 위치에 룩 두기
				pieceDraw(board, 7, y1);
				pieceDraw(board, 5, y1);
			}
			else if ((x2 - x1) == -2)											// 킹이 왼쪽으로 두칸 이동하였다면
			{																	// -> 마찬가지로 캐슬링
				board[y1][0] = { '-', {y1,0},0,0,0 };							// 처음 룩 위치 지우고
				board[y1][3] = { 'R', {y1,3},turn*(-1), 0,0};						// 이동될 위치에 룩 두기
				pieceDraw(board, 0, y1);
				pieceDraw(board, 3, y1);
			}
		}


		if (get_name == 'K')
		{
			setColor(white, black);
			gotoxy(0, 8);
			printf("스페이스바를 누르면 종료됩니다");

			while (true) {
				if (keyControl() == SUBMIT)
					return 0;
			}
		}

	}

	return 0;
}

int restartGame(char (*Gibo)[7], int* get_whatturn, Piece** board1)
{

	setColor(white, black);
	system("cls");
	int turn = 1, key;
	int whatturn = *get_whatturn;						//몇번째 턴인지
	if (whatturn % 2 == 0)
		turn = -1;
	int x = 0, y = 0;

	Piece catchPiece;

	boardDraw(board1); //board 출력

	switchTurn(&x, &y, &turn);

	userPos(&x, &y, board1, -1, white); //초기 userpos(0,0)

	while (1)
	{
		int win = 0;
		int success = 0;
		//setColor(black, lightgray);
		key = keyControl();
		switch (key)
		{
		case UP:
			if (y > 0)
			{
				userPos(&x, &y, board1, UP, white);
			}
			break;
		case DOWN:
			if (y < 7)
			{
				userPos(&x, &y, board1, DOWN, white);
			}break;
		case LEFT:
			if (x > 0)
			{
				userPos(&x, &y, board1, LEFT, white);
			}
			break;
		case RIGHT:
			if (x < 7)
			{
				userPos(&x, &y, board1, RIGHT, white);
			}
			break;
		case SUBMIT:
			catchPiece = board1[y][x];
			if (turn == catchPiece.exist) //player에 맞는 색상의 기물 선택
			{
				switch (catchPiece.name)
				{
				case 'R':
					success = Rook_move(board1, &catchPiece, turn, 'R', &win, whatturn, Gibo);
					break;
				case 'B':
					success = Bishop_move(board1, &catchPiece, turn, 'B', &win, whatturn, Gibo);
					break;
				case 'N':
					success = Knight_move(board1, &catchPiece, turn, &win, whatturn, Gibo);
					break;
				case 'P':
					success = Pawn_move(board1, &catchPiece, turn, &win, whatturn, Gibo);
					break;
				case 'Q':
					success = Queen_move(board1, &catchPiece, turn, 'Q', &win, whatturn, Gibo);
					break;
				case 'K':
					success = King_move(board1, &catchPiece, turn, &win, whatturn, Gibo);
					break;
				}
				setColor(white, black);
				break;
			}
			else continue;				//player에 맞는 색상의 기물 선택 못할경우 다시 처음으로 돌아가기
		}
		if (success != 1)			//기물 움직임 구현에 성공하지 못할경우 다시 처음으로 돌아가기
			continue;

		en_passant_reset(board1, turn);

		if (win == 1)
		{
			*get_whatturn = whatturn;
			return 1;
		}
		else if (win == -1)
		{
			*get_whatturn = whatturn;
			return -1;
		}
		switchTurn(&x, &y, &turn); //turn 전환
		++whatturn;
		setColor(white, black);
	}
}