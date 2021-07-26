#include "bam.h"

//enum selectnumber1
//{
//	a = 0,
//	gamestart = 0,
//};
// 한번에 주석 : ctrl + k + c , 주석풀기 : ctrl + k + u
// 
// 
// 더블버퍼링 <- cls

// 도서관리, node (c++ 연결리스트), (c++ 클래스 <--), (vector, list),  구글에 c++ stl    

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