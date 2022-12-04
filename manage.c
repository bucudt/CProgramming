#include <stdio.h>
#include <string.h>
#include "book_info.h"

/*������ �޴��� �����ϱ� ���� �κ� ���� �Լ�*/
int managerlobby() {
    int choice; //�޴� ������ ���� ���� ����
    system("cls"); //�ܼ�â�� ����ش�.

    printf("\n'������ ������ �����ϱ� ���� �κ�'�� �����մϴ�.\n\n");
    while (1) {
        //printf("\n");
        printf("�������������������� [�κ�] ������������������������\n��\n");
        printf("�� 1. ������ �ڵ带 �Է��ϱ�\n");
        printf("�� 2. ���� �޴��� ���ư���\n��\n");
        printf("������������������������������������������������������������\n");

        printf("� ���� �����ϰڽ��ϱ�? : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
        case 1:
            managercode();
            return 0;
            break;
        case 2:
            system("cls"); //�ܼ�â�� ����ش�.
            return 0;
            break;
        default: //�ٸ� ��ȣ �������� ���
            printf("�ٽ� �������ּ���.\n\n");
            continue;
        }
    }
    return 0;
}

/*������ �ڵ带 �Է��ϴ� �Լ�*/
int managercode() {
    char input[20] = ""; //������ �ڵ� �Է¹��� ���ڿ�
    static char code[20] = { '\0', }; //������ �ڵ� ������ ���ڿ�(static ����), �迭�� ��� ���� '\0'���� �ʱ�ȭ (NULL ����)
    system("cls"); //�ܼ�â�� ����ش�.

    if (code[0] == '\0') { //���� ������ ���� �����, ���ڿ� code�� �����̹Ƿ� �ڵ� ���
        printf("\n������ �ڵ尡 ��ϵǾ� ���� �ʽ��ϴ�.\n");
        printf("�ڵ� ����� ���ֽñ� �ٶ��ϴ�.\n");
        printf("������ �ڵ� ��� : ");
        scanf(" %s", &code);

        system("cls"); //�ܼ�â�� ����ش�.
        printf("\n����� �Ϸ�Ǿ����ϴ�.\n\n");
    }

    for (i = 0; i < 10; i++){
        printf("������ �ڵ带 �Է��Ͻÿ� : ");
        scanf(" %s", &input);

        if (!strcmp(code, input)) { //code�� input�� ������ 0�� ���, false�̹Ƿ� !�� �̿��Ͽ� true�� �������
            system("cls"); //�ܼ�â�� ����ش�.
            printf("\n�ڵ尡 ��ġ�մϴ�. ������ ������ �����մϴ�.\n\n");
            managerguide();
            return 0;
        }
        else { //���� ������, ������ �ڵ� �ٽ� �Է�
            system("cls"); //�ܼ�â�� ����ش�.
            printf("\n�ڵ尡 ��ġ���� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n\n");
            continue;
        }
    }
    printf("�� �� �̻� ��ġ���� �ʾ����Ƿ� ���� �޴��� �̵��մϴ�.\n\n");
    return 0;
}

/*������ ���� �޴��� �����ϴ� �Լ�*/
int managerguide() {
    int choice; //�޴� ������ ���� ���� ����
    while (1) {
        printf("�������������� [������ ����] ��������������������\n��\n");
        printf("�� 1. å ��Ϻ���\n");
        printf("�� 2. å �˻��ϱ�\n");
        printf("�� 3. å �߰��ϱ�\n");
        printf("�� 4. å �����ϱ�\n");
        printf("�� 5. ���� �޴��� ���ư���\n��\n");
        printf("����������������������������������������������������������������\n");
        printf("� ���� �����Ͻðڽ��ϱ�? : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            listbook(book, &num_total_book); //�Է¹��� å�� ����� ���
            break;
        case 2:
            search(book, &num_total_book); //å �˻��ϴ� �Լ� ȣ��
            break;
        case 3:
            addbook(book, &num_total_book); //å �߰� �Լ� ȣ��
            break;
        case 4:
            deletebook(book, &num_total_book);//��Ͽ��� å �����ϱ�
            break;
        case 5:
            system("cls"); //�ܼ�â�� ����ش�.
            return 0; //���� �޴��� �ǵ��ư���
            break;
        default: //�ٸ� ��ȣ �������� ���
            system("cls"); //�ܼ�â�� ����ش�.
            printf("�ٽ� �������ּ���.\n\n");
            continue;
        }
    }
    return 0;
}