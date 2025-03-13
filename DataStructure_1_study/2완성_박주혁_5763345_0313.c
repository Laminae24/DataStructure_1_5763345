#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    float num;

    // 실수 입력 받기
    printf("실수를 입력하세요: ");
    scanf("%f", &num);

    // float 타입을 32비트로 메모리에 저장
    unsigned int* i = (unsigned int*)&num;

    // 부호 비트(1비트)
    int a_bit = (*i >> 31) & 1;
    // 지수 비트(8비트)
    int b_bits = (*i >> 23) & 0xFF;
    // 가수 비트(23비트)
    int c_bits = *i & 0x7FFFFF;

    // 출력
    printf("부호 (1비트) : %d\n", a_bit);

    printf("지수 (8비트) : ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (b_bits >> i) & 1);
    }
    printf("\n");

    printf("가수 (23 비트) : ");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (c_bits >> i) & 1);
    }
    printf("\n");

    return 0;
}