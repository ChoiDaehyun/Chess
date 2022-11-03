#include "main.h"
#include "util.h"
#include "chess.h"
//#include <tchar.h>
//#include <locale.h>


int main() {
	int menuCode;
	init();

	//printf("\u2654");
	//_wsetlocale(LC_ALL, L"Korea");
	//wchar_t ch = _T('♖');
	//printf("%wc", ch);

	while (1) {
		setColor(white, black);
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
