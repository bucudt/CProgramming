#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "login.h"
#pragma warning(disable:4996)

int idline, passline; //���̵�� ��й�ȣ�� ���� ���߱� ����
People s2;

/*�ؽ�Ʈ ���Ͽ� ���� ���� �Լ�*/
void get_infor(People* s) {
	FILE* fp = fopen("info.txt", "a"); //���� �߰�
	if (fp == NULL) {
		printf("������ �� �� �����ϴ�.\n");
		exit(1);
	}
	fprintf(fp, "%s %s %s", s->ID, s->password, s->name);

	fputc('\n', fp);
	fclose(fp);
}

/*���̵� �ߺ� �˻� �Լ�*/
int infor_ID(char* ID) {
	char line[1000] = "NULL";
	char sid[LOGINSIZE] = "NULL", spassword[LOGINSIZE] = "NULL", sname[LOGINSIZE] = "NULL"; //sid: ���� �ȿ� �ִ� id
	FILE* fp = fopen("info.txt", "rt"); //ȸ�� ���� �б�
	if (fp == NULL) {
		printf("������ �� �� �����ϴ�.\n");
		exit(1);
	}

	while (!feof(fp)) { //������ ������ ����
		fgets(line, 1000, fp); //line�� �� �پ� �Է¹���
		idline++;
		sscanf(line, "%s %s %s ", sid, spassword, sname);
		if (strcmp(sid, ID) == 0) { //�̹� �ִ� ���̵��� 0��ȯ
			return 0;
		}
	}
	fclose(fp);
	return 1;
}

/*���̵�� ��й�ȣ ��ġ �˻� �Լ�*/
int infor_password(char* password, char* ID) {
	char line[1000] = "NULL";
	char sid[LOGINSIZE] = "NULL", spassword[LOGINSIZE] = "NULL", sname[LOGINSIZE] = "NULL"; //sid: ���� �� id, spassword: ���� �� password
	FILE* fp = fopen("info.txt", "rt"); //ȸ�� ���� �б�
	if (fp == NULL) {
		printf("������ �� �� �����ϴ�.\n");
		exit(1);
	}

	while (!feof(fp)) { //������ ������ ����
		fgets(line, 1000, fp); //line�� �� �پ� �Է¹���
		passline++;
		sscanf(line, "%s %s %s", sid, spassword, sname);
		if (idline == passline && strcmp(spassword, password) == 0) { //���̵�� ��й�ȣ�� ��ġ�ϴ� ���
			return 0;
		}
	}
	fclose(fp);
	return 1;
}

/*ȸ������ ���� �Լ�*/
void sign_up() {
	char str[LOGINSIZE];
	FILE* fp = fopen("info.txt", "a"); //ȸ������ ���Ͽ� �� ���̵�, ��й�ȣ, �̸� ���� �߰� �Է�
	if (fp == NULL) {
		printf("������ �� �� �����ϴ�.");
		exit(1);
	}

	printf("'ȸ������'�� �����մϴ�.\n\n");
	printf("ȸ������\n");
	printf("���̵�:"); //ȸ������ �� ���̵� �Է�
	scanf("%s", str, sizeof(str));
	if (infor_ID(str) == 1)
	{
		strcpy(s2.ID, str);
		puts("����� ������ ���̵��Դϴ�");
		printf("��й�ȣ:"); //ȸ������ �� ��й�ȣ �Է�
		scanf("%s", s2.password, sizeof(s2.password));
		printf("�̸�:"); //ȸ������ �̸� �Է�
		scanf("%s", s2.name, sizeof(s2.name));
		get_infor(&s2);
		system("cls"); //�ܼ�â�� ����ش�.
	}
	else {
		printf("�̹� �ִ� ���̵��Դϴ�.\n");
		printf("�ٽ� �Է����ּ���.\n\n");
		sign_up(); //ȸ������ �Լ� ����
	}

	printf("\n������ ȯ���մϴ�. ȸ�������� �Ϸ�Ǿ����ϴ�.\n"); //ȸ������ �� ȯ�� ���� ���
	printf("�α��� �޴��� �̵��մϴ�.\n\n");
	login(); //�α��� �Լ� ����
}

/*�α��� ���� �Լ�*/
int login() {
	People info;
	int id, password; //x : �α��ν� ���̵� ���� ����, y : �α��ν� ��й�ȣ ���� ����

	printf("'�α���'�� �����մϴ�.\n\n");
	printf("�α���\n");
	for (int i = 0; i < 5; i++)
	{
		printf("���̵�:");
		scanf("%s", info.ID, sizeof(info.ID));
		printf("��й�ȣ:");
		scanf("%s", info.password, sizeof(info.password));
		id = infor_ID(&info.ID);
		password = infor_password(&info.password, &info.ID);

		if (id == 0 && password == 0) //���̵�� ��й�ȣ�� ���Ͽ� �ִ� ������ ���� ��
		{
			system("cls"); //�ܼ�â�� ����ش�.
			printf("\n�α��ο� �����Ͽ����ϴ�.\n");
			printf("���� ���� ���α׷��� ���� ���� ȯ���մϴ�.\n\n");
			guide(); //���� ���� ���α׷� �޴��� �̵�
			return 0;
		}
		else if (id == 1) //���̵� ���� ���
		{
			printf("\n���̵� ���ų� Ʋ�Ƚ��ϴ�. �ٽ� �Է����ּ���.\n");
			idline = 0;
			passline = 0;
		}
		else if (id == 0 && password == 1) //���̵�� �����ϰ� ��й�ȣ�� Ʋ�� ���
		{
			printf("\n��й�ȣ�� Ʋ�Ƚ��ϴ�. �ٽ� �Է����ּ���.\n");
			idline = 0;
			passline = 0;
		}
		else if (id == 1 && password == 1)
		{
			printf("\n������ �Ǿ� ���� �ʽ��ϴ�.\n");
		}
	}
	printf("\n�ټ� �� �̻� Ʋ���� ���α׷��� ����˴ϴ�.\n");
	return 0;
}