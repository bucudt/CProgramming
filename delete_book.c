#include "book_info.h"
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

/*��Ͽ��� å�� �����ϴ� �Լ�*/
int deletebook(BOOK* book, int* num_total_book)
{
	system("cls"); //�ܼ�â�� ����ش�.
	printf("\n'å �����ϱ�'�� �����ϼ̽��ϴ�.\n\n");

	if (*num_total_book == 0) { //�Էµ� å�� ���� ��� 
		printf("���� ��ϵ� å�� �����ϴ�.\n"); return 0;
	}
	printf("<���� ��ϵ� å�� ����Դϴ�.>\n");
	while (1) {
		listbook(book, num_total_book); /*���� ��ϵ� å�� ����Ʈ�� �����ش�. */
		printf("������ å�� ��ȣ�� �Է��ϼ���(���Ḧ ���Ѵٸ� 0�� �Է��ϼ���) : ");
	CHOICE: scanf("%d", &user_choice);
		if (user_choice == 0) // �����ϴ� ���� ���߰� �޴��� ���ư���.
		{
			system("cls"); //�ܼ�â�� ����ش�.
			printf("> ���� �ڵ带 �Է��Ͽ� ����Ǿ����ϴ�.\n"); break;
		}
		if ((*num_total_book) == 0) //å�� ���� ��� 
		{
			printf("���� ��ϵ� å�� �����ϴ�.\n"); return 0;
		}
		if (user_choice > (*num_total_book) || user_choice < 1) { //����Ʈ�� ���� ��ȣ�� �Է��� �� �ٽ� �Է��ϰ� �Ѵ�.
			printf("����Ʈ�� �ִ� ��ȣ�� �Է����ּ��� : "); goto CHOICE;
		}
		/*������ ��ȣ�� å�� ������ �����Ѵ�*/
		for (i = user_choice; i < *num_total_book; i++)
		{
			strncpy((book + i - 1)->book_name, (book + i)->book_name, sizeof(book->book_name));
			strncpy((book + i - 1)->auth_name, (book + i)->auth_name, sizeof(book->auth_name));
			strncpy((book + i - 1)->publ_name, (book + i)->publ_name, sizeof(book->publ_name));
		}
		(*num_total_book)--; //��ü å�� ���� ���ҽ�Ų��.
	}
	system("cls"); //�ܼ�â�� ����ش�.
	printf("������ �Ϸ�Ǿ����ϴ�.\n\n");
	return 0;
}