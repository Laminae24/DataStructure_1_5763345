#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char string[100];
    int i;

    printf("���ڿ��� �Է��ϼ��� : ");
    scanf("%[^\n]", string);  // ������� !�� ��� ���� �Է¹ޱ�

    // ���ڿ� ���� ���ϱ�
    int length = 0;
    while (string[length] != '\0') {
        length++;  
    }

    // ��ҹ��� ��ȯ
    for (i = 0; i < length; i++) {
        if (string[i] >= 65 && string[i] <= 90) {
            string[i] = string[i] + 32;  // �빮�ڸ� �ҹ��ڷ� ��ȯ
        }
        else if (string[i] >= 97 && string[i] <= 122) {
            string[i] = string[i] - 32;  // �ҹ��ڸ� �빮�ڷ� ��ȯ
        }
    }

    // ���
    printf("���ڿ� ���� : %d\n", length);
    printf("��ȯ�� ���ڿ� : %s\n", string);

    return 0;
}