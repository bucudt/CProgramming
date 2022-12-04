#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "login.h"
#pragma warning(disable:4996)

int idline, passline; //아이디와 비밀번호의 줄을 맞추기 위함
People s2;

/*텍스트 파일에 정보 저장 함수*/
void get_infor(People* s) {
	FILE* fp = fopen("info.txt", "a"); //내용 추가
	if (fp == NULL) {
		printf("파일을 열 수 없습니다.\n");
		exit(1);
	}
	fprintf(fp, "%s %s %s", s->ID, s->password, s->name);

	fputc('\n', fp);
	fclose(fp);
}

/*아이디 중복 검사 함수*/
int infor_ID(char* ID) {
	char line[1000] = "NULL";
	char sid[LOGINSIZE] = "NULL", spassword[LOGINSIZE] = "NULL", sname[LOGINSIZE] = "NULL"; //sid: 파일 안에 있는 id
	FILE* fp = fopen("info.txt", "rt"); //회원 정보 읽기
	if (fp == NULL) {
		printf("파일을 열 수 없습니다.\n");
		exit(1);
	}

	while (!feof(fp)) { //파일을 끝까지 읽음
		fgets(line, 1000, fp); //line에 한 줄씩 입력받음
		idline++;
		sscanf(line, "%s %s %s ", sid, spassword, sname);
		if (strcmp(sid, ID) == 0) { //이미 있는 아이디라면 0반환
			return 0;
		}
	}
	fclose(fp);
	return 1;
}

/*아이디와 비밀번호 일치 검사 함수*/
int infor_password(char* password, char* ID) {
	char line[1000] = "NULL";
	char sid[LOGINSIZE] = "NULL", spassword[LOGINSIZE] = "NULL", sname[LOGINSIZE] = "NULL"; //sid: 파일 내 id, spassword: 파일 내 password
	FILE* fp = fopen("info.txt", "rt"); //회원 정보 읽기
	if (fp == NULL) {
		printf("파일을 열 수 없습니다.\n");
		exit(1);
	}

	while (!feof(fp)) { //파일을 끝까지 읽음
		fgets(line, 1000, fp); //line에 한 줄씩 입력받음
		passline++;
		sscanf(line, "%s %s %s", sid, spassword, sname);
		if (idline == passline && strcmp(spassword, password) == 0) { //아이디와 비밀번호가 일치하는 경우
			return 0;
		}
	}
	fclose(fp);
	return 1;
}

/*회원가입 진행 함수*/
void sign_up() {
	char str[LOGINSIZE];
	FILE* fp = fopen("info.txt", "a"); //회원정보 파일에 새 아이디, 비밀번호, 이름 정보 추가 입력
	if (fp == NULL) {
		printf("파일을 열 수 없습니다.");
		exit(1);
	}

	printf("'회원가입'을 진행합니다.\n\n");
	printf("회원가입\n");
	printf("아이디:"); //회원가입 새 아이디 입력
	scanf("%s", str, sizeof(str));
	if (infor_ID(str) == 1)
	{
		strcpy(s2.ID, str);
		puts("사용이 가능한 아이디입니다");
		printf("비밀번호:"); //회원가입 새 비밀번호 입력
		scanf("%s", s2.password, sizeof(s2.password));
		printf("이름:"); //회원가입 이름 입력
		scanf("%s", s2.name, sizeof(s2.name));
		get_infor(&s2);
		system("cls"); //콘솔창을 비워준다.
	}
	else {
		printf("이미 있는 아이디입니다.\n");
		printf("다시 입력해주세요.\n\n");
		sign_up(); //회원가입 함수 실행
	}

	printf("\n가입을 환영합니다. 회원가입이 완료되었습니다.\n"); //회원가입 후 환영 문구 출력
	printf("로그인 메뉴로 이동합니다.\n\n");
	login(); //로그인 함수 실행
}

/*로그인 진행 함수*/
int login() {
	People info;
	int id, password; //x : 로그인시 아이디 정보 전달, y : 로그인시 비밀번호 정보 전달

	printf("'로그인'을 진행합니다.\n\n");
	printf("로그인\n");
	for (int i = 0; i < 5; i++)
	{
		printf("아이디:");
		scanf("%s", info.ID, sizeof(info.ID));
		printf("비밀번호:");
		scanf("%s", info.password, sizeof(info.password));
		id = infor_ID(&info.ID);
		password = infor_password(&info.password, &info.ID);

		if (id == 0 && password == 0) //아이디와 비밀번호가 파일에 있는 정보와 같을 때
		{
			system("cls"); //콘솔창을 비워준다.
			printf("\n로그인에 성공하였습니다.\n");
			printf("도서 관리 프로그램에 오신 것을 환영합니다.\n\n");
			guide(); //도서 관리 프로그램 메뉴로 이동
			return 0;
		}
		else if (id == 1) //아이디가 없는 경우
		{
			printf("\n아이디가 없거나 틀렸습니다. 다시 입력해주세요.\n");
			idline = 0;
			passline = 0;
		}
		else if (id == 0 && password == 1) //아이디는 존재하고 비밀번호가 틀린 경우
		{
			printf("\n비밀번호가 틀렸습니다. 다시 입력해주세요.\n");
			idline = 0;
			passline = 0;
		}
		else if (id == 1 && password == 1)
		{
			printf("\n가입이 되어 있지 않습니다.\n");
		}
	}
	printf("\n다섯 번 이상 틀려서 프로그램이 종료됩니다.\n");
	return 0;
}