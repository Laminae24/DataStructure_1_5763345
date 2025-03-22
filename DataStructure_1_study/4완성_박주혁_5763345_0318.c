#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//정수 n을 입력받는다 모든수를 소수라고 가정하는데 0,1은 제외하고 입력받은 정수를 에스토스테네스의 체(소수 n은 2~n-1로 나누었을때 모든 나머지가 1)를 반복하여 정수이하의 소수하고 소수배열로 저장 그리고 소수 배열을 모두 표시하기


#define MAX_N 10000

int main() {
    int N;
    printf("정수 n을 입력하시오 : ");
    scanf("%d", &N);

    if (N > MAX_N) {  // 배열 크기 초과 방지
        printf("N은 %d 이하로 입력해야 합니다.\n", MAX_N);
        return 1;
    }

    int prime[MAX_N + 1] = { 0 };  // 정적 배열 선언 및 0으로 초기화

    // 모든 수를 소수(true)로 설정 (0: 합성수, 1: 소수)
    for (int i = 2; i <= N; i++) {
        prime[i] = 1;
    }

    // 에라토스테네스의 체 알고리즘
    for (int i = 2; i * i <= N; i++) {
        if (prime[i]) { // i가 소수이면
            for (int j = i * i; j <= N; j += i) { // i의 배수들을 0으로 설정
                prime[j] = 0;
            }
        }
    }

    // 소수 출력
    printf("n이하의 소수:\n", N);
    for (int i = 2; i <= N; i++) {
        if (prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}



이 함수에서 배열의 크기를 정해놓고 시작하는데 배열의 크기가 일정이상 넘어가면 코드가 작동을 안하는데 해결할수있는 방법이 있을까 ?