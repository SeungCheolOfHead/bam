#include "bam.h"

//enum selectnumber1
//{
//	a = 0,
//	gamestart = 0,
//};
// �ѹ��� �ּ� : ctrl + k + c , �ּ�Ǯ�� : ctrl + k + u
// 
// 
// ������۸� <- cls

// ��������, node (c++ ���Ḯ��Ʈ), (c++ Ŭ���� <--), (vector, list),  ���ۿ� c++ stl    

int main(void)
{
	consoleSize();
	while (1) {
		titleDraw();
		int menuSelect = menu();
		switch (menuSelect)
		{
			case 0:
			{
				int startmenu = gameStart();
				if (startmenu == 0)
				{
					int diff = difficulty();
					switch (diff)
					{
					case 0:
						break;
					case 1:
						break;
					case 2:
						break;
					}
				}
				break; 
			}
			case 1:
			{
				gameInfo();
				break;
			}
			case 2:
			{
				return 0;
			}
		}
		system("cls");
	}
}