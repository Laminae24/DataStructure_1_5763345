#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//���� �Լ� ����
int (add)(int, int);
int (subtract)(int, int);
int (multiply)(int, int);
double (divide)(int, int);


// ���� �Լ� ����
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
double divide(int a, int b) { return (double)a / b; }

int main() {
    int num1, num2;
    printf("ù��° ������ �Է��ϼ��� : ");
    scanf("%d", &num1);
    printf("�ι�° ������ �Է��ϼ��� : ");
    scanf("%d", &num2);


    // ���� ��� ���
    printf("���� : %d\n", add(num1, num2));
    printf("���� : %d\n", subtract(num1, num2));
    printf("���� : %d\n", multiply(num1, num2));

    if (num2 != 0) {
        printf("������ : %.2f\n", divide(num1, num2));
    }
    else {
        printf("0���� ���� �� �����ϴ�."); //�������� 0���� ������ ���� ���� ó��
    }



    return 0;
}
