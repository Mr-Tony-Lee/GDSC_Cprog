#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data ;
    struct Node* next ;
}Node;

typedef struct Stack{
    Node* top ;
}Stack;

Node* createNode(int value , Node* ptr ){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value ;
    temp->next = ptr ;
    return temp ;
}

void push(Stack* s , int value ){
    Node* temp = createNode(value , s->top);
    s->top = temp ;
}

int pop( Stack* s ){
    if(!s->top){
        return -1 ;
    }
    else{
        Node *temp = s->top;
        int value = temp->data;
        s->top = temp->next ;
        free(temp);
        return value;
    }
}
void PrintStack(Stack *s ){
    printf("Stack Now : ");
    Node* temp = s->top;
    while(temp){
        printf("%d " , temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Stack* stack = (Stack* )malloc(sizeof(Stack));
    stack->top = NULL;
    push(stack , 1 ); PrintStack(stack);
    push(stack , 2 ); PrintStack(stack);
    push(stack , 3 ); PrintStack(stack);
    pop(stack); PrintStack(stack);
    pop(stack); PrintStack(stack);
    pop(stack); PrintStack(stack);
}