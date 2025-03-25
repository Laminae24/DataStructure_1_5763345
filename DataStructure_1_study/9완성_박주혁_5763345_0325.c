#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("������ ������ �Է��ϼ��� : ");
    scanf("%d", &n);

    // ���� �޸� �Ҵ�
    int* ary = (int*)malloc(n * sizeof(int));
    if (ary == NULL) {
        printf("�޸� �Ҵ� ����!\n");
        return 1; // ���α׷� ����
    }

    printf("%d���� ������ �Է��ϼ��� : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ary[i]);
    }

    // ���� ���� (��������)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ary[j] > ary[j + 1]) {
                int temp = ary[j];
                ary[j] = ary[j + 1];
                ary[j + 1] = temp;
            }
        }
    }

    printf("������������ ���ĵ� ������ : ");
    for (int i = 0; i < n; i++)
        printf("%d ", ary[i]);

    printf("\n");

    // ���� �޸� ����
    free(ary);

    return 0;
}
