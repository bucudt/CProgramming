#include <stdio.h>
#include "book_info.h"

/*ó�� �ý��� ����� �ȳ��ϴ� �Լ�*/
int guide() {
    while (1) {
        printf("- ���� ���� ���α׷�-\n");
        printf("�������������� [�޴�] ��������������\n��\n");
        printf("�� 1. å ��Ϻ���\n");
        printf("�� 2. å �˻��ϱ�\n");
        printf("�� 3. å �����ϱ�\n");
        printf("�� 4. å �ݳ��ϱ�\n");
        printf("�� 5. ���α׷� �����ϱ�\n��\n");
        printf("��������������������������������������������\n");

        printf("� ���� �����Ͻðڽ��ϱ�? : ");
        scanf("%d", &user_choice);
        printf("\n");
        switch (user_choice)
        {
        case 0:
            managerlobby(); //������ ������ �����ϱ� ���� �κ� ����
            break;
        case 1:
            listbook(book, &num_total_book); //�Է¹��� å�� ����� ���
            break;
        case 2:
            search(book, &num_total_book); //å �˻��ϴ� �Լ� ȣ��
            break;
        case 3:
            borrowedbook(book, &num_total_book); // å �����ϴ� �Լ� ȣ��
            break;
        case 4:
            returnbook(book, &num_total_book); // å �ݳ��ϴ� �Լ� ȣ��
            break;
        case 5:
            system("cls"); //�ܼ�â�� ����ش�.
            return 0; //���α׷� ����
        default: //�ٸ� ��ȣ �������� ���
            printf("�ٽ� �������ּ���.\n\n");
            continue;
        }
    }
    return 0;
}