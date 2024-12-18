#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data ;
    struct Node* pre;
    struct Node* next;
}Node ;

typedef struct DoublyLinkedList{
    Node* tail ;
    Node* head ;
}DLL ; 

void InitializeList(DLL* list) {
    list->head = NULL;
    list->tail = NULL;
}

int listsize(DLL* list){
    int count = 0 ;
    Node* temp = list->head;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count ;
}

void AddHead(DLL* list, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->pre = NULL;
    temp->next = list->head;

    if (list->head == NULL) { // 如果List為空
        list->head = list->tail = temp;
    }
    else {
        list->head->pre = temp;
        list->head = temp;
    }
}

void AddTail(DLL* list, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;

    if (list->tail == NULL) { // 如果List為空
        list->head = list->tail = temp;
    }
    else {
        temp->pre = list->tail;
        list->tail->next = temp;
        list->tail = temp;
    }
}

void Insert(DLL* list, int value, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }
    else if (position == 0) { // insert to head
        AddHead(list, value);
        return;
    }
    else if (position >= listsize(list)){
        AddTail(list, value);
    }

    Node* cur = list->head;
    for ( int i = 0 ; i < position - 1; i++) {
        cur = cur->next;
    }

    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;

    temp->next = cur->next;
    temp->pre = cur;
    cur->next->pre = temp;
    cur->next = temp;
}


void RemoveHead(DLL* list){
    if (list->head == NULL) {  // 檢查是否為空
        printf("List is empty.\n");
        return;
    }
    Node* temp = list->head;
    list->head = list->head->next;
    if(list->head){ //下一個非空的話
        list->head->pre = NULL;
    }
    else{  // 下一個空的話
        list->tail = NULL;
    }
    free(temp);
}

void RemoveTail(DLL* list){
    if (list->head == NULL) {  // 檢查是否為空
        printf("List is empty.\n");
        return;
    }
    Node* temp = list->tail;
    list->tail= list->tail->pre;
    if(list->tail){
        list->tail->next = NULL;
    }
    else{
        list->head = NULL;
    }
    free(temp);
}

void DeleteNode(DLL* list, int position) {
    if(position >= listsize(list) || position < 0 ){
        printf("Invalid position.\n");
        return;
    }
    else if (position == 0) { // 刪除頭節點
        RemoveHead(list);
        return;
    }
    else if ( position == listsize(list)-1){
        RemoveTail(list);
        return;
    }

    Node* cur = list->head;
    for (int i = 0; i < position ; i++) {
        cur = cur->next;
    }
    cur->next->pre = cur->pre;
    cur->pre->next = cur->next;
    free(cur);
}

void Clear(DLL* list){
    while(list->head){
        Node* temp = list->head ;
        list->head = list->head->next;
        free(temp);
    }
    list->head = list->tail = NULL;
}

void PrintDLL(DLL* list){
    printf("Now List : ");
    Node* temp = list->head;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    DLL* list = (DLL* )malloc(sizeof(DLL));
    InitializeList(list);

    AddHead(list , 1); PrintDLL(list);
    AddTail(list , 3); PrintDLL(list);
    AddHead(list , 0); PrintDLL(list);
    Insert(list , 2 , 2); PrintDLL(list);
    Insert(list , 2 , 2); PrintDLL(list);
    DeleteNode(list , 2); PrintDLL(list);

    Clear(list); PrintDLL(list);

    
}