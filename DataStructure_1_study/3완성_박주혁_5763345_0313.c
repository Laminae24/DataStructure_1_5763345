#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[100];
    int i;

    printf("���ڿ��� �Է��ϼ��� : ");
    fgets(string, sizeof(string), stdin);  // fgets�� �Է� �ޱ�

    // �Է¹��� ���ڿ����� ���๮�� ���� (fgets�� ���๮�ڸ� ������ �� �ֱ� ����)
    string[strcspn(string, "\n")] = '\0';

    // ��ҹ��� ��ȯ
    for (i = 0; i < strlen(string); i++) {
        if (string[i] >= 65 && string[i] <= 90) {
            string[i] = string[i] + 32;  // �빮�ڸ� �ҹ��ڷ� ��ȯ
        }
        else if (string[i] >= 97 && string[i] <= 122) {
            string[i] = string[i] - 32;  // �ҹ��ڸ� �빮�ڷ� ��ȯ
        }
    }

    // ��� ���
    printf("���ڿ� ���� : %d\n", strlen(string));
    printf("��ȯ�� ���ڿ� : %s\n", string);

    return 0;
}