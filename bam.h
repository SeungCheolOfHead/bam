#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>
#pragma once

int control();
void consoleSize();
void titleDraw();
void gotoxy(int x, int y);
int menu();
void gameInfo();
int gameStart();

enum {
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	SPACE = 32,
	ENTER = 13
};

void titleDraw()
{
	printf("\n\n\n\n");
	printf("                          #####       #      #       #\n");
	printf("                          #    #     # #     ##     ##\n");
	printf("                          ######    #####    # #   # #\n");
	printf("                          #    #   #     #   #  # #  #\n");
	printf("                          ######  #       #  #   #   #\n");
	printf("\n\n");
}

void consoleSize()
{
	system("mode con cols=80 lines=40 | title 뱀게임");
}

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int control()
{
	char temp = _getch();

	if (temp == '72')
		return UP;
	else if (temp == '80')
		return DOWN;
	else if (temp == '75')
		return LEFT;
	else if (temp == '77')
		return RIGHT;
	else if (temp == '13')
		return ENTER;
}

int menu()
{
	int x = 35;
	int y = 13;
	gotoxy(x-2, y);
	printf("> 게 임 시 작\n");
	gotoxy(x, y+1);
	printf("게 임 정 보\n");
	gotoxy(x, y+2);
	printf("게 임 종 료\n");
	while (1)
	{
		int n = control();
		switch (n) 
		{
			case UP:			//UP
				if (y > 13)
				{
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, --y);
					printf(">");
				}break;
			case DOWN:			//DOWN
				if (y < 15)
				{
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, ++y);
					printf(">");
				}break;
			case ENTER:			//ENTER
				return y - 13;
		}
	}
}

void gameInfo()
{
	system("cls");
	printf("\n\n\n");
	printf("                         뱀게임에 오신 것을 환영합니다\n\n\n\n");
	printf("                                      조작법\n\n");
	printf("                          이동 : 방향키를 사용합니다. \n");
	printf("                          선택 : 엔터키를 사용합니다. \n");
	printf("                                  made in korea   \n");
	while (1) {
		if (control() == ENTER)
			break;
	}
}

int gameStart()
{
	int x = 35;
	int y = 13;
	system("cls");
	gotoxy(x - 2, y);
	printf("> 게임 난이도\n");
	gotoxy(x, y + 4);
	printf("뒤로가기");
	while (1)
	{
		int n = control();
		switch (n)
		{
		case UP:			//UP
			if (y > 13)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, y - 4);
				printf(">");
			}break;
		case DOWN:			//DOWN
			if (y < 17)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, y + 4);
				printf(">");
			}break;
		case ENTER:			//ENTER
			return y - 13;
		}
	}
}