#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("정수의 개수를 입력하세요 : ");
    scanf("%d", &n);

    // 동적 메모리 할당
    int* ary = (int*)malloc(n * sizeof(int));
    if (ary == NULL) {
        printf("메모리 할당 실패!\n");
        return 1; // 프로그램 종료
    }

    printf("%d개의 정수를 입력하세요 : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ary[i]);
    }

    // 버블 정렬 (오름차순)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ary[j] > ary[j + 1]) {
                int temp = ary[j];
                ary[j] = ary[j + 1];
                ary[j + 1] = temp;
            }
        }
    }

    printf("오름차순으로 정렬된 정수들 : ");
    for (int i = 0; i < n; i++)
        printf("%d ", ary[i]);

    printf("\n");

    // 동적 메모리 해제
    free(ary);

    return 0;
}
