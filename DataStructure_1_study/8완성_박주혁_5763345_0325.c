#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int A[2][2], B[2][2], sum[2][2];


    printf("첫 번째 2×2 행렬 입력:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);

    // 두 번째 행렬 입력
    printf("두 번째 2×2 행렬 입력:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &B[i][j]);

    // 행렬 덧셈 및 출력
    printf("\n행렬 덧셈 결과:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sum[i][j] = A[i][j] + B[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
