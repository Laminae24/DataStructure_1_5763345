#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int A[2][2], B[2][2], sum[2][2];


    printf("ù ��° 2��2 ��� �Է�:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);

    // �� ��° ��� �Է�
    printf("�� ��° 2��2 ��� �Է�:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &B[i][j]);

    // ��� ���� �� ���
    printf("\n��� ���� ���:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sum[i][j] = A[i][j] + B[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
