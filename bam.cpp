#include "bam.h"

int main(void)
{
	consoleSize();
	while (1) {
		titleDraw();
		int menuSelect = menu();
		if (menuSelect == 0)		//게임시작
		{
			int startmenu = gameStart();
			if (startmenu == 0)
			{

			}
			else if (startmenu == 4)
			{
				break;
			}
		}
		else if (menuSelect == 1)	//게임정보
		{
			gameInfo();
		}
		else if (menuSelect == 2)	//게임종료
		{
			return 0;
		}
		system("cls");
	}
}