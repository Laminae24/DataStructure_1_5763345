#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc, free 사용

int main() {
    int N;
    printf("정수 n을 입력하시오 : ");
    scanf("%d", &N);

    if (N < 2) {
        printf("2 이상의 값을 입력하세요.\n");
        return 1;
    }

    // 동적 메모리 할당
    int* prime = (int*)malloc((N + 1) * sizeof(int));
    if (prime == NULL) {  // 메모리 할당 실패 시 종료
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 모든 수를 소수(true)로 설정
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
    printf("n이하의 소수:\n");
    for (int i = 2; i <= N; i++) {
        if (prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    // 동적 메모리 해제
    free(prime);

    return 0;
}
