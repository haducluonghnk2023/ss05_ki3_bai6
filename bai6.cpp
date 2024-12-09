#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(Node** head, int value) {
    Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    Node* temp = head;
    printf("NULL");
    while (temp != NULL) {
        printf(" <--> %d", temp->data);
        temp = temp->next;
    }
    printf(" <--> NULL\n");
}
//thay the gia tri
void replaceValue(Node* head, int oldValue, int newValue) {
    Node* temp = head;
    int found = 0;

    while (temp != NULL) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            found = 1;
        }
        temp = temp->next;
    }

    if (found) {
        printf("Gia tri %d da duoc thay the bang %d.\n", oldValue, newValue);
    } else {
        printf("Khong tim thay gia tri %d trong danh sach.\n", oldValue);
    }
}

int main() {
    Node* head = NULL;
    int n, value, oldValue, newValue;
    printf("Nhap so luong phan tu ban dau: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }
    printf("Danh sach ban dau: ");
    printList(head);
    printf("Nhap gia tri can thay the: ");
    scanf("%d", &oldValue);
    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);
    replaceValue(head, oldValue, newValue);
    printf("Danh sach sau khi thay the: ");
    printList(head);

    return 0;
}

