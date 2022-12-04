#include "book_info.h"
#include <stdio.h>
#include <string.h>

/*å �߰��ϴ� �Լ�*/
int addbook(BOOK* book, int* num_total_book)
{
    int num; // �Է��� å�� ��
    system("cls"); //�ܼ�â�� ����ش�.

    printf("\n'å �߰��ϱ�'�� �����ϼ̽��ϴ�.\n\n");
START:
    printf("�� ���� �߰��Ͻðڽ��ϱ�? : "); scanf("%d", &num);
    while (getchar() != '\n');//scanf�Լ�����ϸ� ����('\n')�� �Է¹��ۿ� ���� ���� fgets�Լ��� ������ �ȵǾ� �Է¹��� ����

    /*�Է��� å�� ���� 0�� ������ �� �ٽ� �����ϰ� �Ѵ�.*/
    if (num <= 0) {
        printf("��� 1�� �̻��� �Է��ؾ� �մϴ�. �ٽ� �������ּ���.\n\n"); goto START;
    }

    /*�Է��� å�� ���� ���� ������ �� �ִ� å(�Ǵ� ��ü å�� ��)�� ������ ���� �� �ٽ� �����ϰ� �Ѵ�.*/
    if (num > BOOKSIZE - (*num_total_book)) {
        printf("���� �Է��� �� �ִ� å�� �Ǽ��� �ִ� %d�� �Դϴ�. �ٽ� �������ּ���.\n", BOOKSIZE - (*num_total_book)); goto START;
    }

    /*�߰��� å�� ����ŭ �Է��Ѵ�.*/
    for (i = 0; i < num; i++)
    {
        printf("å ���� : "); fgets((book + (*num_total_book))->book_name, SIZE, stdin);
        (book + (*num_total_book))->book_name[strlen((book + (*num_total_book))->book_name) - 1] = '\0';//���๮�� ����� : list�Լ� ��½� ������� �ʵ��� �Ѵ�.
        printf("���� �̸� : "); fgets((book + (*num_total_book))->auth_name, SIZE, stdin); 
        (book + (*num_total_book))->auth_name[strlen((book + (*num_total_book))->auth_name) - 1] = '\0';//���๮�� ����� : list�Լ� ��½� ������� �ʵ��� �Ѵ�.
        printf("���ǻ� �̸� : "); fgets((book + (*num_total_book))->publ_name, SIZE, stdin); 
        (book + (*num_total_book))->publ_name[strlen((book + (*num_total_book))->publ_name) - 1] = '\0';//���๮�� ����� : list�Լ� ��½� ������� �ʵ��� �Ѵ�.
        book[*num_total_book].borrowed = 0; // �߰������Ƿ� �������� ���� ����(0)�� ����
        (*num_total_book)++; // ��ü å�� ��(å��ȣ) ����
        printf("\n");
    }

    system("cls"); //�ܼ�â�� ����ش�.
    printf("\n�Է��� å ������ �߰� �Ϸ�Ǿ����ϴ�.\n\n");
    return 0;
}