#include "book_info.h"

/*�˻��� �� ���ڸ� ���ϴ� �Լ�*/
int compare(char* str1, char* str2) {
    while (*str1) {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    if (*str2 == 0)
        return 1;
    else
        return 0;
}