#include "book_info.h"
#include <string.h>
#include <stdio.h>


/*å�� �˻��ϴ� �Լ�*/
int search(BOOK* book, int* num_total_book)
{
    int borrow_state; //���� ���� ���θ� ǥ��(�����ϸ� o, �Ұ����ϸ� Xǥ��(�ƽ�Ű�ڵ�))
    char str[SIZE]; //�˻��� �ܾ�(�ִ� 30��)
    system("cls"); //�ܼ�â�� ����ش�.

    printf("\n'å �˻��ϱ�'�� �����ϼ̽��ϴ�.\n\n");
CHOISE:
    printf("���� �� �����ϼ���.\n");
    printf("�������������� [�޴�] ��������������\n��\n");
    printf("�� 1. å ���� �˻�\n");
    printf("�� 2. ���� �̸� �˻�\n");
    printf("�� 3. ���ǻ� �̸� �˻�\n");
    printf("�� 4. �ڷΰ���\n��\n");
    printf("��������������������������������������������\n");
    printf("� ���� �����Ͻðڽ��ϱ�? : "); scanf("%d", &user_choice); while (getchar() != '\n');

    switch (user_choice)
    {
    case 1: // å ������ �˻��Ͽ� ��ġ�ϴ� å�� ��� ���(å ������ �Ϻζ� �����ص� ���)
        printf("\n�˻��� �ܾ �Է��ϼ��� : "); fgets(str, SIZE, stdin); str[strlen(str) - 1] = '\0';
        system("cls"); //�ܼ�â�� ����ش�.
        printf("�˻� ����� ������ �����ϴ�.\n");

        for (i = 0; i <= (*num_total_book); i++)
        {
            if (strstr((book + i)->book_name, str) != 0)
            {
                borrow_state = ((book + i)->borrowed == 0) ? 111 : 88;
                printf("%d. å �̸� : %-25s | ���� �̸� : %-25s | ���ǻ� �̸� : %-25s | ���� ���� : %c\n", (i + 1),
                    (book + i)->book_name, (book + i)->auth_name, (book + i)->publ_name, borrow_state);
            }
        }
        printf("\n"); break;
    case 2: // ���� �̸��� �˻��Ͽ� ��ġ�ϴ� å�� ��� ���
        printf("\n�˻��� �ܾ �Է��ϼ��� : "); //scanf("%s", str);
        fgets(str, SIZE, stdin); str[strlen(str) - 1] = '\0';
        system("cls"); //�ܼ�â�� ����ش�.
        printf("�˻� ����� ������ �����ϴ�.\n");

        for (i = 0; i <= (*num_total_book); i++)
        {
            if (strstr((book + i)->auth_name, str) != 0)
            {
                borrow_state = ((book + i)->borrowed == 0) ? 111 : 88;
                printf("%d. å �̸� : %-25s | ���� �̸� : %-25s | ���ǻ� �̸� : %-25s | ���� ���� : %c\n", (i + 1),
                    (book + i)->book_name, (book + i)->auth_name, (book + i)->publ_name, borrow_state);
            }
        }
        printf("\n"); break;
    case 3: // ���ǻ� �̸��� �˻��Ͽ� ��ġ�ϴ� å�� ��� ���
        printf("\n�˻��� �ܾ �Է��ϼ��� : "); //scanf("%s", str);
        fgets(str, SIZE, stdin); str[strlen(str) - 1] = '\0';
        system("cls"); //�ܼ�â�� ����ش�.
        printf("�˻� ����� ������ �����ϴ�.\n");

        for (i = 0; i <= (*num_total_book); i++)
        {
            if (strstr((book + i)->publ_name, str) != 0)
            {
                borrow_state = ((book + i)->borrowed == 0) ? 111 : 88;
                printf("%d. å �̸� : %-25s | ���� �̸� : %-25s | ���ǻ� �̸� : %-25s | ���� ���� : %c\n", (i + 1),
                    (book + i)->book_name, (book + i)->auth_name, (book + i)->publ_name, borrow_state);
            }
        }
        printf("\n"); break;
    case 4: // ó�� �޴��� ���ư�
        system("cls"); //�ܼ�â�� ����ش�.
        return 0;
    default: // 1~4�� �߿� �������� ���� �� �ٽ� �����ϰ� �Ѵ�.
        printf("(1~4)���߿� �����ϼ��� : \n"); goto CHOISE;
    }
    return 0;
}