#include "book_info.h"
#include <stdio.h>

/*���ݱ��� �Է¹��� å�� ����� �����ִ� �Լ�*/
int listbook(BOOK* book, int* num_total_book)
{
	system("cls"); //�ܼ�â�� ����ش�.
	printf("���� ��ϵ� å�� ����Դϴ�.\n");
	for (i = 0; i < (*num_total_book); i++)
	{
		printf("%d. å ���� : %-25s | ���� �̸� : %-25s | ���ǻ� �̸� : %-25s\n"
			, (i + 1), (book + i)->book_name, (book + i)->auth_name, (book + i)->publ_name);
	}
	printf("\n");
	return 0;
}