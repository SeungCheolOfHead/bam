#include "bam.h"

int main(void)
{
	consoleSize();
	while (1) {
		titleDraw();
		int menuSelect = menu();
		if (menuSelect == 0)		//���ӽ���
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
		else if (menuSelect == 1)	//��������
		{
			gameInfo();
		}
		else if (menuSelect == 2)	//��������
		{
			return 0;
		}
		system("cls");
	}
}