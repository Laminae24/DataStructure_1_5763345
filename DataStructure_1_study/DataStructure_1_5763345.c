#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

    unsigned int num;
    printf("������ �Է����ּ��� : ");
    scanf("%d", &num);

    printf("�Էµ� ������ 32��Ʈ ǥ�� : ");
    //������ ���
    if (num >= 0)
        for (int i = 31; i >= 0; --i) { //32��Ʈ���� ���������϶� ��Ʈ��
            int result = num >> i & 1;
            printf("%d", result);
        }
    else
        for (int i = 31; i >= 0; --i) { //32��Ʈ���� ���������϶� 2�Ǻ��� ��Ʈ��
            int result = num >> i & 1;

            printf("%d", 1 - result);
        }

    return 0;
}