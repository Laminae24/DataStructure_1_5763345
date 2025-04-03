#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 재귀적 방법으로 피보나치 수열 계산
int fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

// 순환적 방법으로 피보나치 수열 계산
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
        printf("피보나치 수열 방법 선택 (1: 재귀적, 2: 순환적, 0: 종료): ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("프로그램이 종료되었습니다.\n");
            break;
        }
        else if (choice == 1 || choice == 2) {
            printf("정수 N을 입력하세요 (종료하려면 0 입력): ");
            scanf("%d", &n);

            if (n == 0) {
                printf("프로그램이 종료되었습니다.\n");
                break;
            }

            if (choice == 1) {
                result = fibonacci_recursive(n);
                printf("F(%d) = %d (재귀적 방법)\n", n, result);
            }
            else {
                result = fibonacci_iterative(n);
                printf("F(%d) = %d (순환적 방법)\n", n, result);
            }
        }
        else {
            printf("잘못된 입력입니다. 다시 입력해주세요.\n");
        }
    }

    return 0;
}