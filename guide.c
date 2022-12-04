#include <stdio.h>
#include "book_info.h"

/*처음 시스템 사용을 안내하는 함수*/
int guide() {
    while (1) {
        printf("- 도서 관리 프로그램-\n");
        printf("┏━━━━━━ [메뉴] ━━━━━━━\n┃\n");
        printf("┃ 1. 책 목록보기\n");
        printf("┃ 2. 책 검색하기\n");
        printf("┃ 3. 책 대출하기\n");
        printf("┃ 4. 책 반납하기\n");
        printf("┃ 5. 프로그램 종료하기\n┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━\n");

        printf("어떤 것을 선택하시겠습니까? : ");
        scanf("%d", &user_choice);
        printf("\n");
        switch (user_choice)
        {
        case 0:
            managerlobby(); //관리자 서버를 접근하기 위한 로비 입장
            break;
        case 1:
            listbook(book, &num_total_book); //입력받은 책의 목록을 출력
            break;
        case 2:
            search(book, &num_total_book); //책 검색하는 함수 호출
            break;
        case 3:
            borrowedbook(book, &num_total_book); // 책 대출하는 함수 호출
            break;
        case 4:
            returnbook(book, &num_total_book); // 책 반납하는 함수 호출
            break;
        case 5:
            system("cls"); //콘솔창을 비워준다.
            return 0; //프로그램 종료
        default: //다른 번호 선택했을 경우
            printf("다시 선택해주세요.\n\n");
            continue;
        }
    }
    return 0;
}