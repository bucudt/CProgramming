#define LOGINSIZE 50

typedef struct people {
    char name[LOGINSIZE];
    char ID[LOGINSIZE];
    char password[LOGINSIZE];
}People;

/*>>>>>>>>>>>>>>>>>>>>>>>>>�α��� ���� �Լ�>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
void get_infor(People* s); //�ؽ�Ʈ ���Ͽ� ���� ���� �Լ�
int infor_ID(char* ID); //���̵� �ߺ� �˻� �Լ�
int infor_password(char* password, char* ID); //���̵� ��й�ȣ ��ġ �˻� �Լ�
void sign_up(); //ȸ������ �Լ�
int login(); //�α��� �Լ�
