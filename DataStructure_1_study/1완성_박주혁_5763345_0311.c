#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

    int num;
    printf("������ �Է����ּ��� : ");
    scanf("%d", &num);

    printf("�Էµ� ������ 32��Ʈ ǥ�� : ");
    //������ ���
    for (int i = 31; i >= 0; --i) { //
        int result = num >> i & 1;
        printf("%d", result);
    }
    return 0;
}
