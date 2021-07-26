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
int difficulty();

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
	system("mode con cols=80 lines=40 | title �����");
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
	/*if (GetAsyncKeyState(VK_LEFT) < 0)
	{

	}*/

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
	printf("> �� �� �� ��\n");
	gotoxy(x, y+1);
	printf("�� �� �� ��\n");
	gotoxy(x, y+2);
	printf("�� �� �� ��\n");
	while (1)
	{
		int menuSelect = control();
		switch (menuSelect)
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
	printf("                          ����ӿ� ���� ���� ȯ���մϴ�\n\n\n\n");
	printf("                                      ���۹�\n\n");
	printf("                          �̵� : ����Ű�� ����մϴ�. \n");
	printf("                          ���� : ����Ű�� ����մϴ�. \n");
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

	const int xStep = 2;
	const int yStep = 2;

	system("cls");
	gotoxy(x - xStep, y);
	printf("> ���� ���̵�\n");
	gotoxy(x, y + yStep);
	printf("�ڷΰ���");
	while (1)
	{
		int difficultySelect = control();
		switch (difficultySelect)
		{
		case UP:			//UP
			if (y > 13)
			{
				gotoxy(x - xStep, y);
				printf(" ");
				gotoxy(x - xStep, y -= yStep);
				printf(">");
			}break;
		case DOWN:			//DOWN
			if (y < 15)
			{
				gotoxy(x - xStep, y);
				printf(" ");
				gotoxy(x - xStep, y += yStep);
				printf(">");
			}break;
		case ENTER:			//ENTER
			if (y == 13)
			{
				gotoxy(x - xStep, y);
				printf(" ");
			}
			return y - 13;
		}
	}
}

int difficulty()
{
	int x = 49;
	int y = 13;
	gotoxy(x - 2, y);
	printf("> ����\n");
	gotoxy(x, y + 1);
	printf("����");
	gotoxy(x, y + 2);
	printf("�����");
	while (1)
	{
		int difficultymenu = control();
		switch (difficultymenu)
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
		case LEFT:			//LEFT
			gameStart();
			if (x == 49 || y == 13) {
				difficulty();
			}
		case ENTER:			//ENTER
			return y - 13;
		}
	}
}