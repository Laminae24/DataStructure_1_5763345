#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double calculate(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return (b != 0) ? a / b : (printf("0으로 나눌 수 없습니다.\n"), exit(1), 0);
    return 0;
}

double evaluate(char* expr) {
    double num, result = 0, temp;
    char op = '+', prev_op = '+';

    while (*expr) {
        if (isdigit(*expr)) {
            num = strtod(expr, &expr); // 숫자 읽기

            // *, / 우선 처리
            if (prev_op == '*') result *= num;
            else if (prev_op == '/') result /= num;
            else temp = num;

        }
        else { // 연산자 처리
            if (*expr == '+' || *expr == '-') {
                result = calculate(result, temp, op);
                op = *expr;
            }
            prev_op = *expr;
            expr++;
        }
    }
    return calculate(result, temp, op);
}

int main() {
    char expr[100];

    printf("수식을 입력하세요 (예: 3+4*2-1/5): ");
    scanf("%s", expr);

    printf("결과: %.2f\n", evaluate(expr));
    return 0;
}
