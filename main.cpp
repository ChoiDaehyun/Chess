#include "main.h"
#include "util.h"
#include "chess.h"

int main() {
	int menuCode;
	init();
	while (1) {
		titleDraw();
		menuCode = menuDraw();
		switch (menuCode)
		{
		case 0:; startGame(); break; //게임시작
		case 1: infoDraw(); break; //게임 정보
		case 2: return 0; //종료
		}
		system("cls");
	}

	return 0;
}
