#include "chess.h"
#include "util.h"

void titleDraw() {
	printf("\n\n\n\n");
	printf("        #####  ##   ##  ##### ##### #####\n");
	printf("        ##     ##   ##  ##    ##    ##   \n");
	printf("        ##     #######  ####  ##### #####\n");
	printf("        ##     ##   ##  ##       ##    ##\n");
	printf("        ####   ##   ##  ##### ##### #####\n");
}

int menuDraw() {
	int x = 20, y = 12;
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