#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double calculate(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return (b != 0) ? a / b : (printf("0���� ���� �� �����ϴ�.\n"), exit(1), 0);
    return 0;
}

double evaluate(char* expr) {
    double num, result = 0, temp;
    char op = '+', prev_op = '+';

    while (*expr) {
        if (isdigit(*expr)) {
            num = strtod(expr, &expr); // ���� �б�

            // *, / �켱 ó��
            if (prev_op == '*') result *= num;
            else if (prev_op == '/') result /= num;
            else temp = num;

        }
        else { // ������ ó��
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

    printf("������ �Է��ϼ��� (��: 3+4*2-1/5): ");
    scanf("%s", expr);

    printf("���: %.2f\n", evaluate(expr));
    return 0;
}
