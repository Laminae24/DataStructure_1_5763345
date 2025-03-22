#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100  // 입력 가능한 최대 길이

// 사칙연산 수행 함수
double calculate(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return (b != 0) ? a / b : (printf("0으로 나눌 수 없습니다.\n"), exit(1), 0);
    return 0;
}

// 중위 연산 수식을 계산하는 함수
double evaluate(const char* expr) {
    double numbers[MAX_LEN];  // 숫자 스택
    char operators[MAX_LEN];  // 연산자 스택
    int num_top = -1, op_top = -1;

    const char* p = expr;
    while (*p) {
        if (isspace(*p)) {  // 공백 무시
            p++;
            continue;
        }

        if (isdigit(*p) || (*p == '-' && (num_top == -1 || (!isdigit(*(p - 1)) && *(p - 1) != ')')))) {
            // 숫자 또는 음수 처리 (예: -3+5)
            numbers[++num_top] = strtod(p, (char**)&p);
        }
        else if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
            while (op_top >= 0 &&
                ((operators[op_top] == '*' || operators[op_top] == '/') ||
                    ((*p == '+' || *p == '-') && (operators[op_top] == '+' || operators[op_top] == '-')))) {
                // 스택에서 연산자 꺼내서 계산 (우선순위 고려)
                double b = numbers[num_top--];
                double a = numbers[num_top--];
                numbers[++num_top] = calculate(a, b, operators[op_top--]);
            }
            operators[++op_top] = *p;  // 연산자 스택에 추가
            p++;
        }
        else {
            printf("잘못된 입력입니다: %c\n", *p);
            exit(1);
        }
    }

    // 남은 연산자 처리
    while (op_top >= 0) {
        double b = numbers[num_top--];
        double a = numbers[num_top--];
        numbers[++num_top] = calculate(a, b, operators[op_top--]);
    }

    return numbers[0];  // 최종 결과 반환
}

int main() {
    char expr[MAX_LEN];

    printf("수식을 입력하세요 (예: 3+4*2-1/5): ");
    fgets(expr, sizeof(expr), stdin);  // 띄어쓰기 포함 입력 가능

    expr[strcspn(expr, "\n")] = '\0';  // 개행 문자 제거

    printf("결과: %.2f\n", evaluate(expr));
    return 0;
}
