#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char string[100];
    int i;

    printf("문자열을 입력하세요 : ");
    scanf("%[^\n]", string);  // 띄워쓰기 !등 모든 문자 입력받기

    // 문자열 길이 구하기
    int length = 0;
    while (string[length] != '\0') {
        length++;  
    }

    // 대소문자 변환
    for (i = 0; i < length; i++) {
        if (string[i] >= 65 && string[i] <= 90) {
            string[i] = string[i] + 32;  // 대문자를 소문자로 변환
        }
        else if (string[i] >= 97 && string[i] <= 122) {
            string[i] = string[i] - 32;  // 소문자를 대문자로 변환
        }
    }

    // 결과
    printf("문자열 길이 : %d\n", length);
    printf("변환된 문자열 : %s\n", string);

    return 0;
}