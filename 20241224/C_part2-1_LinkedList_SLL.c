#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct SinglyLinkedList {
    Node *head;
    Node *tail;
} SLL;

void InitializeList(SLL *list) {
    list->head = NULL;
    list->tail = NULL;
}

void AddHead(SLL *list, int value) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = list->head;
    list->head = temp;
    if (list->tail == NULL) {
        list->tail = temp;
    }
}

void AddTail(SLL *list, int value) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    if (list->tail != NULL) {
        list->tail->next = temp;
    }
    list->tail = temp;
    if (list->head == NULL) {
        list->head = temp;
    }
}

void Insert(SLL *list, int value, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        AddHead(list, value);
        return;
    }

    Node *current = list->head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }

    
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = current->next;
    current->next = temp;

    if (temp->next == NULL) {
        list->tail = temp;
    }
}

void PrintList(SLL *list) {
    Node *temp = list->head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ClearList(SLL *list) {
    Node *current = list->head;
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp); 
    }
    list->head = NULL;
    list->tail = NULL;
}

void RemoveHead(SLL *list) {
    if (list->head == NULL) {  // 檢查是否為空
        printf("List is empty.\n");
        return;
    }

    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);

    if (list->head == NULL) {  // 如果刪除後列表變空
        list->tail = NULL;
    }
}

void RemoveTail(SLL *list) {
    if (list->head == NULL) {  // 檢查是否為空
        printf("List is empty.\n");
        return;
    }

    if (list->head == list->tail) {  // 列表只有一個節點
        free(list->head);
        list->head = list->tail = NULL;
        return;
    }

    Node *cur = list->head;
    while (cur->next != list->tail) {  // 找到倒數第二個節點
        cur = cur->next;
    }

    free(list->tail);
    cur->next = NULL;
    list->tail = cur;
}

void DeleteNode(SLL *list, int position) {
    if (list->head == NULL) {  // 檢查是否為空
        printf("List is empty.\n");
        return;
    }

    if (position == 0) {  // 刪除頭節點
        RemoveHead(list);
        return;
    }

    Node *pre = list->head;
    for (int i = 0; i < position - 1 && pre->next != NULL; i++) {
        pre = pre->next;
    }

    if (pre->next == NULL) {  // 檢查位置是否超過範圍
        printf("Invalid position.\n");
        return;
    }

    Node *temp = pre->next;
    pre->next = temp->next;

    if (temp == list->tail) {  // 如果刪除的是tail
        list->tail = pre;
    }

    free(temp);
}

int main() {
    SLL list;
    InitializeList(&list);

    AddHead(&list, 1);
    AddTail(&list, 3);
    Insert(&list, 2, 1);
    PrintList(&list);

    ClearList(&list);
    return 0;
}
