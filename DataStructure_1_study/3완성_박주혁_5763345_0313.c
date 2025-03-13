#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[100];
    int i;

    printf("문자열을 입력하세요 : ");
    fgets(string, sizeof(string), stdin);  // fgets로 입력 받기

    // 입력받은 문자열에서 개행문자 제거 (fgets는 개행문자를 포함할 수 있기 때문)
    string[strcspn(string, "\n")] = '\0';

    // 대소문자 변환
    for (i = 0; i < strlen(string); i++) {
        if (string[i] >= 65 && string[i] <= 90) {
            string[i] = string[i] + 32;  // 대문자를 소문자로 변환
        }
        else if (string[i] >= 97 && string[i] <= 122) {
            string[i] = string[i] - 32;  // 소문자를 대문자로 변환
        }
    }

    // 결과 출력
    printf("문자열 길이 : %d\n", strlen(string));
    printf("변환된 문자열 : %s\n", string);

    return 0;
}