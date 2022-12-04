#include "book_info.h"
#include <stdio.h>
#include <string.h>

/*책 반납하는 함수*/
int returnbook(BOOK* book, int* num_total_book)
{
    while (getchar() != '\n');
    char name[SIZE]; // 사용자가 입력할 문자열
    int count = 0; //목록에 나오는 책의 수
    char user_input; //유저의 대출여부에 대한 대답(Y&N)-소문자 가능
    system("cls"); //콘솔창을 비워준다.

    printf("\n'책 반납하기'를 선택하셨습니다.\n\n");
    printf("반납할 책의 제목을 입력하세요 : "); //scanf("%s", name);
    fgets(name, SIZE, stdin); name[strlen(name) - 1] = '\0';

    /*책의 유무를 묻고 목록을 보여준다.*/
    printf("\n[반납할 책의 목록입니다.]\n\n");
    for (i = 0; i <= (*num_total_book); i++)
    {
        if (compare(name, (book + i)->book_name) && (book+i)->borrowed == 1) {
            printf("%d. 책 이름 : %-25s | 저자 이름 : %-25s | 출판사 이름 : %-25s\n", (i + 1),
                (book + i)->book_name, (book + i)->auth_name, (book + i)->publ_name);
            count++;
        }
        if (i > (*num_total_book)) {
            printf("다음 책을 찾을 수 없습니다.\n");
            system("cls"); //콘솔창을 비워준다.
            return 0;
        }
    }

    /*목록에 2권 이상이 나왔을 경우 반납할 책을 선택하게 하고 반납여부를 묻는다.*/
    if (count > 1) {
        printf("반납할 책의 번호를 입력하세요 : "); //반납할 책 번호 입력
    CHOICE:
        scanf("%d", &user_choice);

        if (user_choice > (*num_total_book) || user_choice < 1) { // 번호가 [1,num_total_book]안에 들어가지 않는 경우(1~현재 저장된 책의 수 의 숫자를 입력하지 않은 경우)
            printf("범위가 벗어난 번호입니다.\n");
            system("cls"); //콘솔창을 비워준다.
            return 0;
        }
        if (strcmp((book + user_choice - 1)->book_name, name) != 0) { //유저가 선택한 번호가 목록에 없는 번호일 때 다시 선택하게 한다.
            printf("다음 목록에 있는 번호를 선택해주세요 : "); goto CHOICE;
        }
            printf("\n다음 책을 반납할 수 있습니다.\n");
            printf("반납하시겠습니까? (Y 또는 N 입력) : ");
            while (1) {
                scanf(" %c", &user_input);
                switch (user_input)
                {
                case 'Y':
                case 'y':
                    (book + user_choice - 1)->borrowed = 0;
                    system("cls"); //콘솔창을 비워준다.
                    printf("\n반납이 완료되었습니다.\n\n");
                    return 0;
                case 'N':
                case 'n':
                    system("cls"); //콘솔창을 비워준다.
                    printf("\n반납을 실패했습니다. 메인 메뉴로 돌아갑니다.\n\n");
                    return 0;
                default:
                    printf("Y 또는 N으로 입력해주세요. : ");
                    continue;
                }
            }
    }
    /*목록에 책이 1권인 경우 반납여부를 묻는다.*/
    if (count == 1) {
        printf("\n다음 책을 반납할 수 있습니다.\n");
        printf("반납하시겠습니까? (Y 또는 N 입력) : ");
        while (1) {
            scanf(" %c", &user_input);
            switch (user_input)
            {
            case 'Y':
            case 'y':
                for (i = 0; i <= (*num_total_book); i++)
                {
                    if (compare(name, (book + i)->book_name) && (book + i)->borrowed == 1) {
                        (book + i)->borrowed = 0;
                        system("cls"); //콘솔창을 비워준다.
                        printf("\n반납이 완료되었습니다.\n\n");
                        return 0;
                    }
                }
            case 'N':
            case 'n': {
                system("cls"); //콘솔창을 비워준다.
                printf("\n반납을 실패했습니다. 메인 메뉴로 돌아갑니다.\n\n");
                return 0;
            }
            default:
                printf("Y 또는 N으로 입력해주세요. : ");
                continue;
            }
        }
        return 0;
    }
    return 0;
}