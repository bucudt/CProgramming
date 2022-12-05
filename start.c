#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <process.h>
#include <Windows.h>
#include <mmsystem.h>
#include "start.h"
#pragma comment(lib, "winmm.lib")

<<<<<<< HEAD
=======
#define SPECIAL1 0xe0 // 특수키는 0xe0 + key 값으로 구성
#define SPECIAL2 0x00 // keypad 경우 0x00 + key 로 구성
#define UP  0x48 // Up key는 0xe0 + 0x48 두개의 값이 들어옴
#define DOWN 0x50 //Down key 정의
#define ENTER 13

/*메인 메뉴에 나올 아스키아트*/
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
>>>>>>> c77fc3c585e9f6c4464869ff5d47e0b14c93100e

/*원하는 위치로 커서 이동 함수*/
void gotoxy(int x, int y)
{
	COORD pos; //Windows.h 에 정의, 커서의 위치를 저장하는 구조체
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //커서의 위치를 이동시키는 함수
	//GetStdHandle은 표준콘솔출력의 핸들, 핸들:운영체제 내부에 있는 어떤 리소스의 주소를 정수로 치환한 값
}

/*커서를 안보이게 하는 함수*/
void removeCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo; // CONSOLE_CURSOR_INFO라는 커서 구조체를 선언
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	//STD_OUTPUT_HANDLE은 윈도우 베이스의 기본 출력을 뜻하는 매크로, 출력용 핸들러를 가지고 오는 역할
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

/*메뉴의 커서를 나타내는 박스를 그리는 함수*/
void draw_box(int x1, int y1, int x2, int y2)
{
	int x, y;
	for (x = x1; x <= x2; x += 2)
	{
		gotoxy(x, y1);
		printf("─");
		gotoxy(x, y2);
		printf("─");
	}
	for (y = y1; y <= y2; y++)
	{
		gotoxy(x1, y);
		printf("│");
		gotoxy(x2, y);
		printf("│");
	}
	gotoxy(x1, y1);
	printf("┌");
	gotoxy(x2, y1);
	printf("┐");
	gotoxy(x1, y2);
	printf("└");
	gotoxy(x2, y2);
	printf("┘");
}

/*메뉴의 커서를 나타내는 박스를 지우는 함수*/
void remove_box(int x1, int y1, int x2, int y2)
{
	int x, y;
	for (x = x1; x <= x2; x += 2)
	{
		gotoxy(x, y1);
		printf("  "); // 공백으로 덮어씌우기
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

/*메인 메뉴를 그리는 함수*/
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
	printf("회원가입\n");
	gotoxy(55, 27);
	printf("로그인\n");
	gotoxy(55, 30);
	printf("나가기\n");
	//draw_box(30, 23, 64, 25);
	draw_box(40, 23, 74, 25);
}

/*메인창에서 메뉴를 선택하는 함수*/
int select_main_menu()
{
	int n = 0;
	unsigned char ch = 0;
	while (1) {
		if (_kbhit() == 1) // 키보드가 눌려져 있으면
		{
			ch = _getch();
			if (ch == SPECIAL1 || ch == SPECIAL2) // 만약 특수키
			{ // 예를 들어 UP key의 경우 0xe0 0x48 두개의 문자가 들어온다.
				ch = _getch();
				remove_box(40, 23 + n % 3 * 3, 74, 25 + n % 3 * 3);
<<<<<<< HEAD
				if (ch == UP) n += 2; // ��ĭ ����
				else if (ch == DOWN) n += 1; // ��ĭ �Ʒ���
=======
				if (ch == UP) n += 2; // 한칸 위로
				else if (ch == DOWN) n += 1; // 한칸 아래로
				//draw_box(30, 23 + n % 3 * 3, 64, 25 + n % 3 * 3);
>>>>>>> c77fc3c585e9f6c4464869ff5d47e0b14c93100e
				draw_box(40, 23 + n % 3 * 3, 74, 25 + n % 3 * 3);
			}
			else if (ch == ENTER)
			{
				system("cls");
				return n % 3;  // 엔터키 입력하면 위치를 리턴
			}
		}
	}
}

/*시작창 사라지는 애니메이션 효과 함수*/
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
