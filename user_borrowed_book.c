#include "book_info.h"
#include <stdio.h>
#include <string.h>

/*책 대출하는 함수*/
int borrowedbook(BOOK* book, int* num_total_book) {
    char name[SIZE]; //책 제목과 비교하기 위한 문자열
    int count = 0; //검색결과 나오는 책의 수(2 이상이면 책을 선택할 수 있는 선택창이 나오게 한다.)
    char user_input; //유저가 입력하는 문자(Y or N) / 소문자도 가능
    int num = 0;//임시로 사용할 책의 번호
    system("cls"); //콘솔창을 비워준다.

    printf("\n'책 대출하기'를 선택하셨습니다.\n\n");
    printf("다음 메뉴 중 선택하세요\n");
CHOISE:
    printf("┏━━━━━━ [메뉴] ━━━━━━━\n┃\n");
    printf("┃ 1. 책 제목을 입력하여 대출하기\n");
    printf("┃ 2. 메인 메뉴로 돌아가기\n┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━\n");
    printf("어떤 것을 선택하시겠습니까? : ");
    scanf("%d", &user_choice); while (getchar() != '\n');

    switch (user_choice)
    {
    case 1:
        system("cls"); //콘솔창을 비워준다.
        printf("\n대출할 책 제목을 입력하세요 : ");
        fgets(name, SIZE, stdin); name[strlen(name) - 1] = '\0';
        printf("\n[검색 결과는 다음과 같습니다.]\n");

        /*책의 유무를 판단하고 책의 목록을 출력한다.(여기서는 책의 제목과 완전히 일치해야 함)*/
        for (i = 0; i < (*num_total_book); i++)
        {
            if (compare(name, (book + i)->book_name)&& (book+i)->borrowed==0) {
                printf("%d. 책 이름 : %-25s | 저자 이름 : %-25s | 출판사 이름 : %-25s\n", (i + 1),
                    (book + i)->book_name, (book + i)->auth_name, (book + i)->publ_name);
                count++; // 검색결과 나오는 책의 수
            }
            if (i > (*num_total_book)) {
                system("cls"); //콘솔창을 비워준다.
                printf("\n다음 책을 찾지 못했습니다. 메인 메뉴로 이동합니다.\n");
                return 0; break;
            }
        }

        /*나오는 책이 2권 이상인 경우 그 목록을 출력하고 대출할 책을 선택하게 한다.*/
        if (count > 1) {
            printf("\n다음 중 빌리려 하는 책의 번호를 입력하세요 (단, 책의 번호는 왼쪽에 적힌 번호입니다.) : ");
        CHOICE1:
            scanf("%d", &user_choice);// 다음의 책의 목록 중 책의 번호를 입력한다.

            if (user_choice > (*num_total_book) || user_choice < 1) {               // 번호가 [1,num_total_book]안에 들어가지 않는 경우(1~현재 저장된 책의 수)
                system("cls"); //콘솔창을 비워준다.
                printf("범위가 벗어난 번호입니다. 메인 메뉴로 이동합니다.\n\n");
                return 0;
            }
            if (strcmp((book + user_choice - 1)->book_name, name) != 0) {         //유저가 선택한 번호가 목록에 없는 번호일 때 다시 선택하게 한다.
                printf("다음 목록에 있는 번호를 선택해주세요 : "); goto CHOICE1;
            }
                printf("\n다음 책을 대출할 수 있습니다.\n");
                printf("대출하시겠습니까? (Y 또는 N 입력) : ");     //대출할 경우 Y를 대출하지 않을 경우 N을 입력한다.(소문자 가능)
                while (1) {
                    scanf(" %c", &user_input); //유저가 대출할 지의 여부(scanf 속 %c 앞에 띄어쓰기 필수)
                    switch (user_input)
                    {
                    case 'Y':
                    case 'y':
                        (book + user_choice - 1)->borrowed = 1;
                        system("cls"); //콘솔창을 비워준다.
                        printf("\n대출이 완료되었습니다.\n\n");
                        return 0;
                    case 'N':
                    case 'n':
                        system("cls"); //콘솔창을 비워준다.
                        printf("\n대출을 실패했습니다. 메인 메뉴로 돌아갑니다.\n\n"); //처음 화면으로 돌아감
                        return 0;
                    default:
                        printf("Y 또는 N으로 입력해주세요 : "); //Y 또는 N을 입력하지 않을 경우 다시 입력창으로 돌아간다.
                        continue;
                    }
                }
        }
        /*검색한 책이 1권인 경우 : 대출하는 지 묻는다.*/
        else if (count == 1) {
            printf("\n다음 책을 대출할 수 있습니다.\n");
            printf("대출하시겠습니까? (Y 또는 N 입력) : "); //Y를 입력하면 대출, N을 입력하면 대출하지 않음
            while (1) {
                scanf(" %c", &user_input); //유저가 대출할 지의 여부(scanf 속 %c 앞에 띄어쓰기 필수)
                switch (user_input)
                {
                case 'Y':
                case 'y':
                    for (i = 0; i <= (*num_total_book); i++)//count가 2이상일 때와는 다르게 책의 번호에 대한 정보가 없어 다시 for문을 이용하여 대출한다.
                    {
                        if (compare(name, (book + i)->book_name) && (book + i)->borrowed == 0) {
                            (book + i)->borrowed = 1;
                            system("cls"); //콘솔창을 비워준다.
                            printf("\n대출이 완료되었습니다.\n\n"); return 0;
                        }
                        //num++; // 검색결과 나오는 책의 수
                    }
                case 'N':
                case 'n':
                    system("cls"); //콘솔창을 비워준다.
                    printf("\n대출을 실패했습니다. 메인 메뉴로 돌아갑니다.\n\n");
                    return 0;
                default:
                    printf("Y 또는 N으로 입력해주세요 : ");
                    continue;
                }
            }
        }
        break;
    case 2: // 처음 창으로 돌아간다.
        system("cls"); //콘솔창을 비워준다.
        return 0;
    default: //1,2 번중 선택하지 않을 경우 다시 선택하게 한다.
        printf("1~2번 중에 선택하세요.\n"); goto CHOISE;
    }
    return 0;
}
