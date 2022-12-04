#define SIZE    26
#define BOOKSIZE    100

typedef struct book {   //책에 관한 정보를  구조체로 표현
    char book_name[SIZE]; //책의 이름
    char auth_name[SIZE]; //저자 이름
    char publ_name[SIZE]; //출판사 이름
    int borrowed; //다음 책이 대출되었는 지를 나타내는 변수 0이면 대출되지 않은 상태
}BOOK;

BOOK book[BOOKSIZE]; //책 100권 저장
BOOK books[BOOKSIZE]; //book복사용 및 리스트 출력할 때 쓰는 구조체 변수

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>대부분의 함수에 쓰이는 변수들>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
int user_choice; //유저가 선택하는 번호
int i; //반복문에 쓰일 변수, 수를 나타내는 변수
int num_total_book; //현재 책의 수

/*>>>>>>>>>>>>>>>>>>>>>책에 관한 함수 선언>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
int guide(void); //처음 시스템 사용을 안내하는 함수
int addbook(BOOK* book, int* num_total_book); //책 추가 함수
int search(BOOK* books, int* num_total_book); //일부 문자열로 검색하는 함수
int borrowedbook(BOOK* book, int* num_total_book); //책 대출하는 함수
int returnbook(BOOK* book, int* num_total_book); //책 반납하는 함수
int listbook(BOOK* book, int* num_total_book); //입력한 책들의 목록을 출력하는 함수
int deletebook(BOOK* book, int* num_total_book); //목록에서 책을 삭제하는 함수

/*>>>>>>>>>>>>>>>>>>>>>>>>>그 이외의 함수>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
int compare(char* str1, char* str2); //문자열 비교함수

/*>>>>>>>>>>>>>>>>>>>>>>>>>관리자 서버 관련 함수>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
int managerlobby(); //관리자 메뉴를 접근하기 위한 로비 입장 함수
int managercode(); //관리자 코드를 입력받는 함수
int managerguide(); //관리자 전용 메뉴를 선택하는 함수