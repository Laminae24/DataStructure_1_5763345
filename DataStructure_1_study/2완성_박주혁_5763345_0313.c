#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    float num;

    // �Ǽ� �Է� �ޱ�
    printf("�Ǽ��� �Է��ϼ���: ");
    scanf("%f", &num);

    // float Ÿ���� 32��Ʈ�� �޸𸮿� ����
    unsigned int* i = (unsigned int*)&num;

    // ��ȣ ��Ʈ(1��Ʈ)
    int a_bit = (*i >> 31) & 1;
    // ���� ��Ʈ(8��Ʈ)
    int b_bits = (*i >> 23) & 0xFF;
    // ���� ��Ʈ(23��Ʈ)
    int c_bits = *i & 0x7FFFFF;

    // ���
    printf("��ȣ (1��Ʈ) : %d\n", a_bit);

    printf("���� (8��Ʈ) : ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (b_bits >> i) & 1);
    }
    printf("\n");

    printf("���� (23 ��Ʈ) : ");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (c_bits >> i) & 1);
    }
    printf("\n");

    return 0;
}