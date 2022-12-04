
/*>>>>>>>>>>>>>>>>>>>>>>>>>>시작 화면 관련 함수 선언>>>>>>>>>>>>>> */
void gotoxy(int x, int y); //원하는 위치로 커서 이동 함수
void removeCursor(void); //커서를 안보이게 하는 함수
void draw_box(int x1, int y1, int x2, int y2); //메뉴의 커서를 나타내는 박스를 그리는 함수
void remove_box(int x1, int y1, int x2, int y2); //메뉴의 커서를 나타내는 박스를 지우는 함수
void draw_main_menu(); //메인 메뉴를 그리는 함수
int select_main_menu(); //메인창에서 메뉴를 선택하는 함수
void animated(); //시작창 사라지는 애니메이션 효과 함수
