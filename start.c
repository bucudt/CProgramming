#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <process.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#define SPECIAL1 0xe0 // Ư��Ű�� 0xe0 + key ������ ����
#define SPECIAL2 0x00 // keypad ��� 0x00 + key �� ����
#define UP  0x48 // Up key�� 0xe0 + 0x48 �ΰ��� ���� ����
#define ENTER 13

/*���� �޴��� ���� �ƽ�Ű��Ʈ*/
char LibraryProgram[19][200] = {
	    "                                                                                                           ",
		"                  ##       ######   ######    #####        ###     #####      ##  ##                       ",
		"                  ##         ##     ##   ##   ##   ##     #####    ##   ##    ##  ##                       ",
		"                  ##         ##     ##   ##   ##   ##    ##   ##   ##   ##    ##  ##                       ",
		"                  ##         ##     ######    ##   ##    ##   ##   ##   ##    ##  ##                       ",
		"                  ##         ##     ##  ##    ######     #######   ######      ####                        ",
		"                  ##         ##     ##   ##   ##   ##    ##   ##   ##   ##      ##                         ",
		"                  ##         ##     ##   ##   ##    ##   ##   ##   ##    ##     ##                         ",
		"                  ######   ######   ######    ##    ##   ##   ##   ##    ##     ##                         ",
		"                                                                                                           ",
		"                                    ######    #####       #####     #####       ###     #####      ##    ##",
		"                                    ##   ##   ##   ##    ##   ##   ##   ##     #####    ##   ##    ###  ###",
		"                                    ##   ##   ##   ##    ##   ##   ##         ##   ##   ##   ##    ###  ###",
		"                                    ##   ##   ##   ##    ##   ##   ##         ##   ##   ##   ##    ## ## ##",
		"                                    ######    ######     ##   ##   ##         #######   ######     ## ## ##",
		"                                    ##        ##   ##    ##   ##   ##   ###   ##   ##   ##   ##    ##    ##",
		"                                    ##        ##    ##   ##   ##   ##    ##   ##   ##   ##    ##   ##    ##",
		"                                    ##        ##    ##    #####     #####     ##   ##   ##    ##   ##    ##",
		"                                                                                                           " };

/*���ϴ� ��ġ�� Ŀ�� �̵� �Լ�*/
void gotoxy(int x, int y)
{
	COORD pos; //Windows.h �� ����, Ŀ���� ��ġ�� �����ϴ� ����ü
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //Ŀ���� ��ġ�� �̵���Ű�� �Լ�
	//GetStdHandle�� ǥ���ܼ������ �ڵ�, �ڵ�:�ü�� ���ο� �ִ� � ���ҽ��� �ּҸ� ������ ġȯ�� ��
}

/*Ŀ���� �Ⱥ��̰� �ϴ� �Լ�*/
void removeCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo; // CONSOLE_CURSOR_INFO��� Ŀ�� ����ü�� ����
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	//STD_OUTPUT_HANDLE�� ������ ���̽��� �⺻ ����� ���ϴ� ��ũ��, ��¿� �ڵ鷯�� ������ ���� ����
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

/*�޴��� Ŀ���� ��Ÿ���� �ڽ��� �׸��� �Լ�*/
void draw_box(int x1, int y1, int x2, int y2)
{
	int x, y;
	for (x = x1; x <= x2; x += 2)
	{
		gotoxy(x, y1);
		printf("��");
		gotoxy(x, y2);
		printf("��");
	}
	for (y = y1; y <= y2; y++)
	{
		gotoxy(x1, y);
		printf("��");
		gotoxy(x2, y);
		printf("��");
	}
	gotoxy(x1, y1);
	printf("��");
	gotoxy(x2, y1);
	printf("��");
	gotoxy(x1, y2);
	printf("��");
	gotoxy(x2, y2);
	printf("��");
}

/*�޴��� Ŀ���� ��Ÿ���� �ڽ��� ����� �Լ�*/
void remove_box(int x1, int y1, int x2, int y2)
{
	int x, y;
	for (x = x1; x <= x2; x += 2)
	{
		gotoxy(x, y1);
		printf("  "); // �������� ������
		gotoxy(x, y2);
		printf("  ");
	}
	for (y = y1; y <= y2; y++)
	{
		gotoxy(x1, y);
		printf("  ");
		gotoxy(x2, y);
		printf("  ");
	}
}

/*���� �޴��� �׸��� �Լ�*/
void draw_main_menu()
{
	int j;
	for (j = 0; j < 19; j++)
	{
		gotoxy(0, j + 2);
		printf("%s", LibraryProgram[j]);
	}
	//gotoxy(44, 24);
	gotoxy(54, 24);
	printf("ȸ������\n");
	gotoxy(55, 27);
	printf("�α���\n");
	gotoxy(55, 30);
	printf("������\n");
	//draw_box(30, 23, 64, 25);
	draw_box(40, 23, 74, 25);
}

/*����â���� �޴��� �����ϴ� �Լ�*/
int select_main_menu()
{
	int n = 0;
	unsigned char ch = 0;
	while (1) {
		if (_kbhit() == 1) // Ű���尡 ������ ������
		{
			ch = _getch();
			if (ch == SPECIAL1 || ch == SPECIAL2) // ���� Ư��Ű
			{ // ���� ��� UP key�� ��� 0xe0 0x48 �ΰ��� ���ڰ� ���´�.
				ch = _getch();
				//remove_box(30, 23 + n % 3 * 3, 64, 25 + n % 3 * 3);
				remove_box(40, 23 + n % 3 * 3, 74, 25 + n % 3 * 3);
				if (ch == UP) n += 2; // ��ĭ ����
				else if (ch == DOWN) n += 1; // ��ĭ �Ʒ���
				//draw_box(30, 23 + n % 3 * 3, 64, 25 + n % 3 * 3);
				draw_box(40, 23 + n % 3 * 3, 74, 25 + n % 3 * 3);
			}
			else if (ch == ENTER)
			{
				system("cls");
				return n % 3;  // ����Ű �Է��ϸ� ��ġ�� ����
			}
		}
	}
}

/*����â ������� �ִϸ��̼� ȿ�� �Լ�*/
void animated()
{
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19 - i; j++) {
			gotoxy(0, j + 3);
			printf("                                                                                             ");
			gotoxy(0, j + 2);
			printf("%s", LibraryProgram[j + i]);
		}
		Sleep(50);
	}
	system("cls");
	printf("\n");
}