#include "book_info.h"
#include <stdio.h>
#include <string.h>

/*å �����ϴ� �Լ�*/
int borrowedbook(BOOK* book, int* num_total_book) {
    char name[SIZE]; //å ����� ���ϱ� ���� ���ڿ�
    int count = 0; //�˻���� ������ å�� ��(2 �̻��̸� å�� ������ �� �ִ� ����â�� ������ �Ѵ�.)
    char user_input; //������ �Է��ϴ� ����(Y or N) / �ҹ��ڵ� ����
    int num = 0;//�ӽ÷� ����� å�� ��ȣ
    system("cls"); //�ܼ�â�� ����ش�.

    printf("\n'å �����ϱ�'�� �����ϼ̽��ϴ�.\n\n");
    printf("���� �޴� �� �����ϼ���\n");
CHOISE:
    printf("�������������� [�޴�] ��������������\n��\n");
    printf("�� 1. å ������ �Է��Ͽ� �����ϱ�\n");
    printf("�� 2. ���� �޴��� ���ư���\n��\n");
    printf("��������������������������������������������\n");
    printf("� ���� �����Ͻðڽ��ϱ�? : ");
    scanf("%d", &user_choice); while (getchar() != '\n');

    switch (user_choice)
    {
    case 1:
        system("cls"); //�ܼ�â�� ����ش�.
        printf("\n������ å ������ �Է��ϼ��� : ");
        fgets(name, SIZE, stdin); name[strlen(name) - 1] = '\0';
        printf("\n[�˻� ����� ������ �����ϴ�.]\n");

        /*å�� ������ �Ǵ��ϰ� å�� ����� ����Ѵ�.(���⼭�� å�� ����� ������ ��ġ�ؾ� ��)*/
        for (i = 0; i < (*num_total_book); i++)
        {
            if (compare(name, (book + i)->book_name)&& (book+i)->borrowed==0) {
                printf("%d. å �̸� : %-25s | ���� �̸� : %-25s | ���ǻ� �̸� : %-25s\n", (i + 1),
                    (book + i)->book_name, (book + i)->auth_name, (book + i)->publ_name);
                count++; // �˻���� ������ å�� ��
            }
            if (i > (*num_total_book)) {
                system("cls"); //�ܼ�â�� ����ش�.
                printf("\n���� å�� ã�� ���߽��ϴ�. ���� �޴��� �̵��մϴ�.\n");
                return 0; break;
            }
        }

        /*������ å�� 2�� �̻��� ��� �� ����� ����ϰ� ������ å�� �����ϰ� �Ѵ�.*/
        if (count > 1) {
            printf("\n���� �� ������ �ϴ� å�� ��ȣ�� �Է��ϼ��� (��, å�� ��ȣ�� ���ʿ� ���� ��ȣ�Դϴ�.) : ");
        CHOICE1:
            scanf("%d", &user_choice);// ������ å�� ��� �� å�� ��ȣ�� �Է��Ѵ�.

            if (user_choice > (*num_total_book) || user_choice < 1) {               // ��ȣ�� [1,num_total_book]�ȿ� ���� �ʴ� ���(1~���� ����� å�� ��)
                system("cls"); //�ܼ�â�� ����ش�.
                printf("������ ��� ��ȣ�Դϴ�. ���� �޴��� �̵��մϴ�.\n\n");
                return 0;
            }
            if (strcmp((book + user_choice - 1)->book_name, name) != 0) {         //������ ������ ��ȣ�� ��Ͽ� ���� ��ȣ�� �� �ٽ� �����ϰ� �Ѵ�.
                printf("���� ��Ͽ� �ִ� ��ȣ�� �������ּ��� : "); goto CHOICE1;
            }
                printf("\n���� å�� ������ �� �ֽ��ϴ�.\n");
                printf("�����Ͻðڽ��ϱ�? (Y �Ǵ� N �Է�) : ");     //������ ��� Y�� �������� ���� ��� N�� �Է��Ѵ�.(�ҹ��� ����)
                while (1) {
                    scanf(" %c", &user_input); //������ ������ ���� ����(scanf �� %c �տ� ���� �ʼ�)
                    switch (user_input)
                    {
                    case 'Y':
                    case 'y':
                        (book + user_choice - 1)->borrowed = 1;
                        system("cls"); //�ܼ�â�� ����ش�.
                        printf("\n������ �Ϸ�Ǿ����ϴ�.\n\n");
                        return 0;
                    case 'N':
                    case 'n':
                        system("cls"); //�ܼ�â�� ����ش�.
                        printf("\n������ �����߽��ϴ�. ���� �޴��� ���ư��ϴ�.\n\n"); //ó�� ȭ������ ���ư�
                        return 0;
                    default:
                        printf("Y �Ǵ� N���� �Է����ּ��� : "); //Y �Ǵ� N�� �Է����� ���� ��� �ٽ� �Է�â���� ���ư���.
                        continue;
                    }
                }
        }
        /*�˻��� å�� 1���� ��� : �����ϴ� �� ���´�.*/
        else if (count == 1) {
            printf("\n���� å�� ������ �� �ֽ��ϴ�.\n");
            printf("�����Ͻðڽ��ϱ�? (Y �Ǵ� N �Է�) : "); //Y�� �Է��ϸ� ����, N�� �Է��ϸ� �������� ����
            while (1) {
                scanf(" %c", &user_input); //������ ������ ���� ����(scanf �� %c �տ� ���� �ʼ�)
                switch (user_input)
                {
                case 'Y':
                case 'y':
                    for (i = 0; i <= (*num_total_book); i++)//count�� 2�̻��� ���ʹ� �ٸ��� å�� ��ȣ�� ���� ������ ���� �ٽ� for���� �̿��Ͽ� �����Ѵ�.
                    {
                        if (compare(name, (book + i)->book_name) && (book + i)->borrowed == 0) {
                            (book + i)->borrowed = 1;
                            system("cls"); //�ܼ�â�� ����ش�.
                            printf("\n������ �Ϸ�Ǿ����ϴ�.\n\n"); return 0;
                        }
                        //num++; // �˻���� ������ å�� ��
                    }
                case 'N':
                case 'n':
                    system("cls"); //�ܼ�â�� ����ش�.
                    printf("\n������ �����߽��ϴ�. ���� �޴��� ���ư��ϴ�.\n\n");
                    return 0;
                default:
                    printf("Y �Ǵ� N���� �Է����ּ��� : ");
                    continue;
                }
            }
        }
        break;
    case 2: // ó�� â���� ���ư���.
        system("cls"); //�ܼ�â�� ����ش�.
        return 0;
    default: //1,2 ���� �������� ���� ��� �ٽ� �����ϰ� �Ѵ�.
        printf("1~2�� �߿� �����ϼ���.\n"); goto CHOISE;
    }
    return 0;
}
