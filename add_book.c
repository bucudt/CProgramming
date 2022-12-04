#include "book_info.h"
#include <stdio.h>
#include <string.h>

/*책 추가하는 함수*/
int addbook(BOOK* book, int* num_total_book)
{
    int num; // 입력할 책의 수
    system("cls"); //콘솔창을 비워준다.

    printf("\n'책 추가하기'를 선택하셨습니다.\n\n");
START:
    printf("몇 권을 추가하시겠습니까? : "); scanf("%d", &num);
    while (getchar() != '\n');//scanf함수사용하면 엔터('\n')가 입력버퍼에 남아 다음 fgets함수가 실행이 안되어 입력버퍼 제거

    /*입력한 책의 수가 0권 이하일 때 다시 선택하게 한다.*/
    if (num <= 0) {
        printf("적어도 1권 이상을 입력해야 합니다. 다시 선택해주세요.\n\n"); goto START;
    }

    /*입력한 책의 수가 현재 보관할 수 있는 책(또는 전체 책의 수)의 수보다 많을 때 다시 선택하게 한다.*/
    if (num > BOOKSIZE - (*num_total_book)) {
        printf("현재 입력할 수 있는 책의 권수는 최대 %d권 입니다. 다시 선택해주세요.\n", BOOKSIZE - (*num_total_book)); goto START;
    }

    /*추가할 책의 수만큼 입력한다.*/
    for (i = 0; i < num; i++)
    {
        printf("책 제목 : "); fgets((book + (*num_total_book))->book_name, SIZE, stdin);
        (book + (*num_total_book))->book_name[strlen((book + (*num_total_book))->book_name) - 1] = '\0';//개행문자 지우기 : list함수 출력시 개행되지 않도록 한다.
        printf("저자 이름 : "); fgets((book + (*num_total_book))->auth_name, SIZE, stdin); 
        (book + (*num_total_book))->auth_name[strlen((book + (*num_total_book))->auth_name) - 1] = '\0';//개행문자 지우기 : list함수 출력시 개행되지 않도록 한다.
        printf("출판사 이름 : "); fgets((book + (*num_total_book))->publ_name, SIZE, stdin); 
        (book + (*num_total_book))->publ_name[strlen((book + (*num_total_book))->publ_name) - 1] = '\0';//개행문자 지우기 : list함수 출력시 개행되지 않도록 한다.
        book[*num_total_book].borrowed = 0; // 추가했으므로 빌려지지 않은 상태(0)로 설정
        (*num_total_book)++; // 전체 책의 수(책번호) 증가
        printf("\n");
    }

    system("cls"); //콘솔창을 비워준다.
    printf("\n입력한 책 정보가 추가 완료되었습니다.\n\n");
    return 0;
}