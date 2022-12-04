#include "book_info.h"
#include <stdio.h>

/*지금까지 입력받은 책의 목록을 보여주는 함수*/
int listbook(BOOK* book, int* num_total_book)
{
	system("cls"); //콘솔창을 비워준다.
	printf("현재 등록된 책의 목록입니다.\n");
	for (i = 0; i < (*num_total_book); i++)
	{
		printf("%d. 책 제목 : %-25s | 저자 이름 : %-25s | 출판사 이름 : %-25s\n"
			, (i + 1), (book + i)->book_name, (book + i)->auth_name, (book + i)->publ_name);
	}
	printf("\n");
	return 0;
}