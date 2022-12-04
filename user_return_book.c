#include "book_info.h"
#include <stdio.h>
#include <string.h>

/*å �ݳ��ϴ� �Լ�*/
int returnbook(BOOK* book, int* num_total_book)
{
    while (getchar() != '\n');
    char name[SIZE]; // ����ڰ� �Է��� ���ڿ�
    int count = 0; //��Ͽ� ������ å�� ��
    char user_input; //������ ���⿩�ο� ���� ���(Y&N)-�ҹ��� ����
    system("cls"); //�ܼ�â�� ����ش�.

    printf("\n'å �ݳ��ϱ�'�� �����ϼ̽��ϴ�.\n\n");
    printf("�ݳ��� å�� ������ �Է��ϼ��� : "); //scanf("%s", name);
    fgets(name, SIZE, stdin); name[strlen(name) - 1] = '\0';

    /*å�� ������ ���� ����� �����ش�.*/
    printf("\n[�ݳ��� å�� ����Դϴ�.]\n\n");
    for (i = 0; i <= (*num_total_book); i++)
    {
        if (compare(name, (book + i)->book_name) && (book+i)->borrowed == 1) {
            printf("%d. å �̸� : %-25s | ���� �̸� : %-25s | ���ǻ� �̸� : %-25s\n", (i + 1),
                (book + i)->book_name, (book + i)->auth_name, (book + i)->publ_name);
            count++;
        }
        if (i > (*num_total_book)) {
            printf("���� å�� ã�� �� �����ϴ�.\n");
            system("cls"); //�ܼ�â�� ����ش�.
            return 0;
        }
    }

    /*��Ͽ� 2�� �̻��� ������ ��� �ݳ��� å�� �����ϰ� �ϰ� �ݳ����θ� ���´�.*/
    if (count > 1) {
        printf("�ݳ��� å�� ��ȣ�� �Է��ϼ��� : "); //�ݳ��� å ��ȣ �Է�
    CHOICE:
        scanf("%d", &user_choice);

        if (user_choice > (*num_total_book) || user_choice < 1) { // ��ȣ�� [1,num_total_book]�ȿ� ���� �ʴ� ���(1~���� ����� å�� �� �� ���ڸ� �Է����� ���� ���)
            printf("������ ��� ��ȣ�Դϴ�.\n");
            system("cls"); //�ܼ�â�� ����ش�.
            return 0;
        }
        if (strcmp((book + user_choice - 1)->book_name, name) != 0) { //������ ������ ��ȣ�� ��Ͽ� ���� ��ȣ�� �� �ٽ� �����ϰ� �Ѵ�.
            printf("���� ��Ͽ� �ִ� ��ȣ�� �������ּ��� : "); goto CHOICE;
        }
            printf("\n���� å�� �ݳ��� �� �ֽ��ϴ�.\n");
            printf("�ݳ��Ͻðڽ��ϱ�? (Y �Ǵ� N �Է�) : ");
            while (1) {
                scanf(" %c", &user_input);
                switch (user_input)
                {
                case 'Y':
                case 'y':
                    (book + user_choice - 1)->borrowed = 0;
                    system("cls"); //�ܼ�â�� ����ش�.
                    printf("\n�ݳ��� �Ϸ�Ǿ����ϴ�.\n\n");
                    return 0;
                case 'N':
                case 'n':
                    system("cls"); //�ܼ�â�� ����ش�.
                    printf("\n�ݳ��� �����߽��ϴ�. ���� �޴��� ���ư��ϴ�.\n\n");
                    return 0;
                default:
                    printf("Y �Ǵ� N���� �Է����ּ���. : ");
                    continue;
                }
            }
    }
    /*��Ͽ� å�� 1���� ��� �ݳ����θ� ���´�.*/
    if (count == 1) {
        printf("\n���� å�� �ݳ��� �� �ֽ��ϴ�.\n");
        printf("�ݳ��Ͻðڽ��ϱ�? (Y �Ǵ� N �Է�) : ");
        while (1) {
            scanf(" %c", &user_input);
            switch (user_input)
            {
            case 'Y':
            case 'y':
                for (i = 0; i <= (*num_total_book); i++)
                {
                    if (compare(name, (book + i)->book_name) && (book + i)->borrowed == 1) {
                        (book + i)->borrowed = 0;
                        system("cls"); //�ܼ�â�� ����ش�.
                        printf("\n�ݳ��� �Ϸ�Ǿ����ϴ�.\n\n");
                        return 0;
                    }
                }
            case 'N':
            case 'n': {
                system("cls"); //�ܼ�â�� ����ش�.
                printf("\n�ݳ��� �����߽��ϴ�. ���� �޴��� ���ư��ϴ�.\n\n");
                return 0;
            }
            default:
                printf("Y �Ǵ� N���� �Է����ּ���. : ");
                continue;
            }
        }
        return 0;
    }
    return 0;
}