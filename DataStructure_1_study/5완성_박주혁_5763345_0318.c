#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//연산 함수 정의
int (add)(int, int);
int (subtract)(int, int);
int (multiply)(int, int);
double (divide)(int, int);


// 연산 함수 구현
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
double divide(int a, int b) { return (double)a / b; }

int main() {
    int num1, num2;
    printf("첫번째 정수를 입력하세요 : ");
    scanf("%d", &num1);
    printf("두번째 정수를 입력하세요 : ");
    scanf("%d", &num2);


    // 연산 결과 출력
    printf("덧셈 : %d\n", add(num1, num2));
    printf("뺄셈 : %d\n", subtract(num1, num2));
    printf("곱셈 : %d\n", multiply(num1, num2));

    if (num2 != 0) {
        printf("나눗셈 : %.2f\n", divide(num1, num2));
    }
    else {
        printf("0으로 나눌 수 없습니다."); //나눗셈은 0으로 나눌수 없어 예외 처리
    }



    return 0;
}
