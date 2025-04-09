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

// ��� �߰� �Լ� (���� ����)
void insertSorted(Node** head, int row, int col, int value) {
    Node* current = *head;
    Node* prev = NULL;

    // �̹� �����ϴ� ������� Ȯ��
    while (current != NULL) {
        if (current->row == row && current->col == col) {
            current->value += value;
            return;
        }
        prev = current;
        current = current->next;
    }

    // �� ��� ����
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;

    // ���ĵ� ��ġ�� ����
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

// ��� ��� �Լ�
void printNodes(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d %d %d\n", current->row, current->col, current->value);
        current = current->next;
    }
}

// SIZE�� LAST �� ��� �Լ�
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

// �޸� ���� �Լ�
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

    printf("����� �Է��Ͻÿ� (-1 �Է½� ����):\n");
    while (1) {
        if (scanf("%d", &row) != 1 || row == -1) break;
        if (scanf("%d", &col) != 1 || col == -1) break;
        if (scanf("%d", &value) != 1 || value == -1) break;
        insertSorted(&head, row, col, value);
    }

    printf("����� �Է��Ͻÿ� (-1 �Է½� ����):\n");
    while (1) {
        if (scanf("%d", &row) != 1 || row == -1) break;
        if (scanf("%d", &col) != 1 || col == -1) break;
        if (scanf("%d", &value) != 1 || value == -1) break;
        insertSorted(&head, row, col, value);
    }

    printf("\n����� ��:\n");
    printSizeAndLast(head);  // SIZE, LAST ���
    printNodes(head);        // ��� ���

    freeList(head);
    return 0;
}
