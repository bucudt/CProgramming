#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "book_info.h"

int main() {
	//system("color f0");
	system("mode con cols=150 lines=90 | title ��������");

	// ���� �޴� ����
	removeCursor();
	draw_main_menu();
	switch (select_main_menu())
	{
	case 0: //ȸ������ ����
		animated();
		sign_up(); //ȸ������ �Լ� ����
		//return 0;
		break;
	case 1: //�α��� ����
		animated();
		login(); //�α��� �Լ� ����
		//return 0;
		break;
	case 2:
		return 0; //�ý��� ����
	}
	return 0;
}




