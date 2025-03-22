#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc, free ���

int main() {
    int N;
    printf("���� n�� �Է��Ͻÿ� : ");
    scanf("%d", &N);

    if (N < 2) {
        printf("2 �̻��� ���� �Է��ϼ���.\n");
        return 1;
    }

    // ���� �޸� �Ҵ�
    int* prime = (int*)malloc((N + 1) * sizeof(int));
    if (prime == NULL) {  // �޸� �Ҵ� ���� �� ����
        printf("�޸� �Ҵ� ����\n");
        return 1;
    }

    // ��� ���� �Ҽ�(true)�� ����
    for (int i = 2; i <= N; i++) {
        prime[i] = 1;
    }

    // �����佺�׳׽��� ü �˰���
    for (int i = 2; i * i <= N; i++) {
        if (prime[i]) { // i�� �Ҽ��̸�
            for (int j = i * i; j <= N; j += i) { // i�� ������� 0���� ����
                prime[j] = 0;
            }
        }
    }

    // �Ҽ� ���
    printf("n������ �Ҽ�:\n");
    for (int i = 2; i <= N; i++) {
        if (prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // ���� �޸� ����
    free(prime);

    return 0;
}
