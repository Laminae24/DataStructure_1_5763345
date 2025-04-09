#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ����� ������� �Ǻ���ġ ���� ���
int fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

// ��ȯ�� ������� �Ǻ���ġ ���� ���
int fibonacci_iterative(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        int a = 0, b = 1, temp;
        for (int i = 0; i < n - 1; i++) {
            temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }
}

int main() {
    int choice, n, result;

    while (1) {
        printf("�Ǻ���ġ ���� ��� ���� (1: �����, 2: ��ȯ��, 0: ����): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("���α׷��� ����Ǿ����ϴ�.\n");
            break;
        }
        else if (choice == 1 || choice == 2) {
            printf("���� N�� �Է��ϼ��� (�����Ϸ��� 0 �Է�): ");
            scanf("%d", &n);

            if (n == 0) {
                printf("���α׷��� ����Ǿ����ϴ�.\n");
                break;
            }

            if (choice == 1) {
                result = fibonacci_recursive(n);
                printf("F(%d) = %d (����� ���)\n", n, result);
            }
            else {
                result = fibonacci_iterative(n);
                printf("F(%d) = %d (��ȯ�� ���)\n", n, result);
            }
        }
        else {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
        }
    }

    return 0;
}