#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "book_info.h"

int main() {
	//system("color f0");
	system("mode con cols=150 lines=90 | title 도서관리");

	// 메인 메뉴 시작
	removeCursor();
	draw_main_menu();
	switch (select_main_menu())
	{
	case 0: //회원가입 진행
		animated();
		sign_up(); //회원가입 함수 실행
		//return 0;
		break;
	case 1: //로그인 진행
		animated();
		login(); //로그인 함수 실행
		//return 0;
		break;
	case 2:
		return 0; //시스템 종료
	}
	return 0;
}




