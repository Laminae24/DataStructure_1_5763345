#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100  // �Է� ������ �ִ� ����

// ��Ģ���� ���� �Լ�
double calculate(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return (b != 0) ? a / b : (printf("0���� ���� �� �����ϴ�.\n"), exit(1), 0);
    return 0;
}

// ���� ���� ������ ����ϴ� �Լ�
double evaluate(const char* expr) {
    double numbers[MAX_LEN];  // ���� ����
    char operators[MAX_LEN];  // ������ ����
    int num_top = -1, op_top = -1;

    const char* p = expr;
    while (*p) {
        if (isspace(*p)) {  // ���� ����
            p++;
            continue;
        }

        if (isdigit(*p) || (*p == '-' && (num_top == -1 || (!isdigit(*(p - 1)) && *(p - 1) != ')')))) {
            // ���� �Ǵ� ���� ó�� (��: -3+5)
            numbers[++num_top] = strtod(p, (char**)&p);
        }
        else if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
            while (op_top >= 0 &&
                ((operators[op_top] == '*' || operators[op_top] == '/') ||
                    ((*p == '+' || *p == '-') && (operators[op_top] == '+' || operators[op_top] == '-')))) {
                // ���ÿ��� ������ ������ ��� (�켱���� ���)
                double b = numbers[num_top--];
                double a = numbers[num_top--];
                numbers[++num_top] = calculate(a, b, operators[op_top--]);
            }
            operators[++op_top] = *p;  // ������ ���ÿ� �߰�
            p++;
        }
        else {
            printf("�߸��� �Է��Դϴ�: %c\n", *p);
            exit(1);
        }
    }

    // ���� ������ ó��
    while (op_top >= 0) {
        double b = numbers[num_top--];
        double a = numbers[num_top--];
        numbers[++num_top] = calculate(a, b, operators[op_top--]);
    }

    return numbers[0];  // ���� ��� ��ȯ
}

int main() {
    char expr[MAX_LEN];

    printf("������ �Է��ϼ��� (��: 3+4*2-1/5): ");
    fgets(expr, sizeof(expr), stdin);  // ���� ���� �Է� ����

    expr[strcspn(expr, "\n")] = '\0';  // ���� ���� ����

    printf("���: %.2f\n", evaluate(expr));
    return 0;
}
