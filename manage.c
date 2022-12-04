#include <stdio.h>
#include <string.h>
#include "book_info.h"

/*관리자 메뉴를 접근하기 위한 로비 입장 함수*/
int managerlobby() {
    int choice; //메뉴 선택을 위한 변수 선언
    system("cls"); //콘솔창을 비워준다.

    printf("\n'관리자 서버를 접근하기 위한 로비'에 입장합니다.\n\n");
    while (1) {
        //printf("\n");
        printf("┏━━━━━━━━━ [로비] ━━━━━━━━━━━━\n┃\n");
        printf("┃ 1. 관리자 코드를 입력하기\n");
        printf("┃ 2. 메인 메뉴로 돌아가기\n┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

        printf("어떤 것을 선택하겠습니까? : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
        case 1:
            managercode();
            return 0;
            break;
        case 2:
            system("cls"); //콘솔창을 비워준다.
            return 0;
            break;
        default: //다른 번호 선택했을 경우
            printf("다시 선택해주세요.\n\n");
            continue;
        }
    }
    return 0;
}

/*관리자 코드를 입력하는 함수*/
int managercode() {
    char input[20] = ""; //관리자 코드 입력받을 문자열
    static char code[20] = { '\0', }; //관리자 코드 저장할 문자열(static 선언), 배열의 모든 값을 '\0'으로 초기화 (NULL 역할)
    system("cls"); //콘솔창을 비워준다.

    if (code[0] == '\0') { //최초 관리자 서버 입장시, 문자열 code가 공백이므로 코드 등록
        printf("\n관리자 코드가 등록되어 있지 않습니다.\n");
        printf("코드 등록을 해주시기 바랍니다.\n");
        printf("관리자 코드 등록 : ");
        scanf(" %s", &code);

        system("cls"); //콘솔창을 비워준다.
        printf("\n등록이 완료되었습니다.\n\n");
    }

    for (i = 0; i < 10; i++){
        printf("관리자 코드를 입력하시오 : ");
        scanf(" %s", &input);

        if (!strcmp(code, input)) { //code와 input이 같으면 0이 출력, false이므로 !을 이용하여 true로 만들어줌
            system("cls"); //콘솔창을 비워준다.
            printf("\n코드가 일치합니다. 관리자 서버로 입장합니다.\n\n");
            managerguide();
            return 0;
        }
        else { //같지 않으면, 관리자 코드 다시 입력
            system("cls"); //콘솔창을 비워준다.
            printf("\n코드가 일치하지 않습니다. 다시 입력해주세요.\n\n");
            continue;
        }
    }
    printf("열 번 이상 일치하지 않았으므로 메인 메뉴로 이동합니다.\n\n");
    return 0;
}

/*관리자 전용 메뉴를 선택하는 함수*/
int managerguide() {
    int choice; //메뉴 선택을 위한 변수 선언
    while (1) {
        printf("┏━━━━━━ [관리자 서버] ━━━━━━━━━━\n┃\n");
        printf("┃ 1. 책 목록보기\n");
        printf("┃ 2. 책 검색하기\n");
        printf("┃ 3. 책 추가하기\n");
        printf("┃ 4. 책 삭제하기\n");
        printf("┃ 5. 메인 메뉴로 돌아가기\n┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("어떤 것을 선택하시겠습니까? : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            listbook(book, &num_total_book); //입력받은 책의 목록을 출력
            break;
        case 2:
            search(book, &num_total_book); //책 검색하는 함수 호출
            break;
        case 3:
            addbook(book, &num_total_book); //책 추가 함수 호출
            break;
        case 4:
            deletebook(book, &num_total_book);//목록에서 책 삭제하기
            break;
        case 5:
            system("cls"); //콘솔창을 비워준다.
            return 0; //메인 메뉴로 되돌아가기
            break;
        default: //다른 번호 선택했을 경우
            system("cls"); //콘솔창을 비워준다.
            printf("다시 선택해주세요.\n\n");
            continue;
        }
    }
    return 0;
}