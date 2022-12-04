#define LOGINSIZE 50

typedef struct people {
    char name[LOGINSIZE];
    char ID[LOGINSIZE];
    char password[LOGINSIZE];
}People;

/*>>>>>>>>>>>>>>>>>>>>>>>>>로그인 관련 함수>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
void get_infor(People* s); //텍스트 파일에 정보 저장 함수
int infor_ID(char* ID); //아이디 중복 검사 함수
int infor_password(char* password, char* ID); //아이디 비밀번호 일치 검사 함수
void sign_up(); //회원가입 함수
int login(); //로그인 함수
