#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

    unsigned int num;
    printf("정수를 입력해주세요 : ");
    scanf("%d", &num);

    printf("입력된 정수의 32비트 표현 : ");
    //이진수 출력
    if (num >= 0)
        for (int i = 31; i >= 0; --i) { //32비트까지 양의정수일때 비트값
            int result = num >> i & 1;
            printf("%d", result);
        }
    else
        for (int i = 31; i >= 0; --i) { //32비트까지 음의정수일때 2의보수 비트값
            int result = num >> i & 1;

            printf("%d", 1 - result);
        }

    return 0;
}