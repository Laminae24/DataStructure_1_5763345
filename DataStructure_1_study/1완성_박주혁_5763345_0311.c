#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

    int num;
    printf("정수를 입력해주세요 : ");
    scanf("%d", &num);

    printf("입력된 정수의 32비트 표현 : ");
    //이진수 출력
    for (int i = 31; i >= 0; --i) { //
        int result = num >> i & 1;
        printf("%d", result);
    }
    return 0;
}
