#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
S
typedef struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
} Node;

// 노드 추가 함수 (정렬 유지)
void insertSorted(Node** head, int row, int col, int value) {
    Node* current = *head;
    Node* prev = NULL;

    // 이미 존재하는 노드인지 확인
    while (current != NULL) {
        if (current->row == row && current->col == col) {
            current->value += value;
            return;
        }
        prev = current;
        current = current->next;
    }

    // 새 노드 생성
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;

    // 정렬된 위치에 삽입
    if (*head == NULL || (row < (*head)->row) || (row == (*head)->row && col < (*head)->col)) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        current = *head;
        while (current->next != NULL &&
            (current->next->row < row || (current->next->row == row && current->next->col < col))) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// 노드 출력 함수
void printNodes(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d %d %d\n", current->row, current->col, current->value);
        current = current->next;
    }
}

// SIZE와 LAST 값 출력 함수
void printSizeAndLast(Node* head) {
    int size = 0;
    int lastValue = 0;
    Node* current = head;

    while (current != NULL) {
        size++;
        lastValue = current->value;
        current = current->next;
    }

    printf("SIZE: %d\n", size);
    printf("LAST: %d\n", lastValue);
}

// 메모리 해제 함수
void freeList(Node* head) {
    Node* current;
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }
}

int main() {
    int row, col, value;
    Node* head = NULL;

    printf("행렬을 입력하시오 (-1 입력시 종료):\n");
    while (1) {
        if (scanf("%d", &row) != 1 || row == -1) break;
        if (scanf("%d", &col) != 1 || col == -1) break;
        if (scanf("%d", &value) != 1 || value == -1) break;
        insertSorted(&head, row, col, value);
    }

    printf("행렬을 입력하시오 (-1 입력시 종료):\n");
    while (1) {
        if (scanf("%d", &row) != 1 || row == -1) break;
        if (scanf("%d", &col) != 1 || col == -1) break;
        if (scanf("%d", &value) != 1 || value == -1) break;
        insertSorted(&head, row, col, value);
    }

    printf("\n행렬의 합:\n");
    printSizeAndLast(head);  // SIZE, LAST 출력
    printNodes(head);        // 행렬 출력

    freeList(head);
    return 0;
}
