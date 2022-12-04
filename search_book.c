#include "book_info.h"
#include <string.h>
#include <stdio.h>


/*책을 검색하는 함수*/
int search(BOOK* book, int* num_total_book)
{
    int borrow_state; //대출 가능 여부를 표현(가능하면 o, 불가능하면 X표시(아스키코드))
    char str[SIZE]; //검색할 단어(최대 30자)
    system("cls"); //콘솔창을 비워준다.

    printf("\n'책 검색하기'를 선택하셨습니다.\n\n");
CHOISE:
    printf("다음 중 선택하세요.\n");
    printf("┏━━━━━━ [메뉴] ━━━━━━━\n┃\n");
    printf("┃ 1. 책 제목 검색\n");
    printf("┃ 2. 저자 이름 검색\n");
    printf("┃ 3. 출판사 이름 검색\n");
    printf("┃ 4. 뒤로가기\n┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━\n");
    printf("어떤 것을 선택하시겠습니까? : "); scanf("%d", &user_choice); while (getchar() != '\n');

    switch (user_choice)
    {
    case 1: // 책 제목을 검색하여 일치하는 책을 모두 출력(책 제목의 일부라도 포함해도 출력)
        printf("\n검색할 단어를 입력하세요 : "); fgets(str, SIZE, stdin); str[strlen(str) - 1] = '\0';
        system("cls"); //콘솔창을 비워준다.
        printf("검색 결과는 다음과 같습니다.\n");

        for (i = 0; i <= (*num_total_book); i++)
        {
            if (strstr((book + i)->book_name, str) != 0)
            {
                borrow_state = ((book + i)->borrowed == 0) ? 111 : 88;
                printf("%d. 책 이름 : %-25s | 저자 이름 : %-25s | 출판사 이름 : %-25s | 대출 상태 : %c\n", (i + 1),
                    (book + i)->book_name, (book + i)->auth_name, (book + i)->publ_name, borrow_state);
            }
        }
        printf("\n"); break;
    case 2: // 저자 이름을 검색하여 일치하는 책을 모두 출력
        printf("\n검색할 단어를 입력하세요 : "); //scanf("%s", str);
        fgets(str, SIZE, stdin); str[strlen(str) - 1] = '\0';
        system("cls"); //콘솔창을 비워준다.
        printf("검색 결과는 다음과 같습니다.\n");

        for (i = 0; i <= (*num_total_book); i++)
        {
            if (strstr((book + i)->auth_name, str) != 0)
            {
                borrow_state = ((book + i)->borrowed == 0) ? 111 : 88;
                printf("%d. 책 이름 : %-25s | 저자 이름 : %-25s | 출판사 이름 : %-25s | 대출 상태 : %c\n", (i + 1),
                    (book + i)->book_name, (book + i)->auth_name, (book + i)->publ_name, borrow_state);
            }
        }
        printf("\n"); break;
    case 3: // 출판사 이름을 검색하여 일치하는 책을 모두 출력
        printf("\n검색할 단어를 입력하세요 : "); //scanf("%s", str);
        fgets(str, SIZE, stdin); str[strlen(str) - 1] = '\0';
        system("cls"); //콘솔창을 비워준다.
        printf("검색 결과는 다음과 같습니다.\n");

        for (i = 0; i <= (*num_total_book); i++)
        {
            if (strstr((book + i)->publ_name, str) != 0)
            {
                borrow_state = ((book + i)->borrowed == 0) ? 111 : 88;
                printf("%d. 책 이름 : %-25s | 저자 이름 : %-25s | 출판사 이름 : %-25s | 대출 가능 : %c\n", (i + 1),
                    (book + i)->book_name, (book + i)->auth_name, (book + i)->publ_name, borrow_state);
            }
        }
        printf("\n"); break;
    case 4: // 처음 메뉴로 돌아감
        system("cls"); //콘솔창을 비워준다.
        return 0;
    default: // 1~4번 중에 선택하지 않을 때 다시 선택하게 한다.
        printf("(1~4)번중에 선택하세요 : \n"); goto CHOISE;
    }
    return 0;
}