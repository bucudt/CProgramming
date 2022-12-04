#include "book_info.h"
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

/*목록에서 책을 삭제하는 함수*/
int deletebook(BOOK* book, int* num_total_book)
{
	system("cls"); //콘솔창을 비워준다.
	printf("\n'책 삭제하기'를 선택하셨습니다.\n\n");

	if (*num_total_book == 0) { //입력된 책이 없을 경우 
		printf("현재 등록된 책이 없습니다.\n"); return 0;
	}
	printf("<현재 등록된 책의 목록입니다.>\n");
	while (1) {
		listbook(book, num_total_book); /*현재 등록된 책의 리스트를 보여준다. */
		printf("삭제할 책의 번호를 입력하세요(종료를 원한다면 0을 입력하세요) : ");
	CHOICE: scanf("%d", &user_choice);
		if (user_choice == 0) // 삭제하는 것을 멈추고 메뉴로 돌아간다.
		{
			system("cls"); //콘솔창을 비워준다.
			printf("> 종료 코드를 입력하여 종료되었습니다.\n"); break;
		}
		if ((*num_total_book) == 0) //책이 없을 경우 
		{
			printf("현재 등록된 책이 없습니다.\n"); return 0;
		}
		if (user_choice > (*num_total_book) || user_choice < 1) { //리스트에 없는 번호를 입력할 때 다시 입력하게 한다.
			printf("리스트에 있는 번호를 입력해주세요 : "); goto CHOICE;
		}
		/*선택한 번호의 책의 정보를 삭제한다*/
		for (i = user_choice; i < *num_total_book; i++)
		{
			strncpy((book + i - 1)->book_name, (book + i)->book_name, sizeof(book->book_name));
			strncpy((book + i - 1)->auth_name, (book + i)->auth_name, sizeof(book->auth_name));
			strncpy((book + i - 1)->publ_name, (book + i)->publ_name, sizeof(book->publ_name));
		}
		(*num_total_book)--; //전체 책의 수를 감소시킨다.
	}
	system("cls"); //콘솔창을 비워준다.
	printf("삭제가 완료되었습니다.\n\n");
	return 0;
}