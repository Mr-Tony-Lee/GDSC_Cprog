#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int value ;
    struct Node *next ;
}Node;

typedef struct Stack{
    Node* top ;
}Stack;


void push( Stack* s , int value ){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = value ;
    temp->next = NULL;
    temp->next = s->top;
    s->top = temp;
}

int pop( Stack*s ){
    Node* temp = s->top ;
    int value = temp->value ;
    s->top = temp->next ;
    free(temp);
    return value ;
}

int search(Stack* s , int key ){
    Node* temp = s->top ;
    int index = 1; 
    while(temp != NULL ){
        if(temp->value == key ){
            return index ;
        }
        else{
            temp = temp->next ;
            index++;
        }
    }
    return 0 ;  // 0代表沒找到，因為No是從1開始的
}

void reverse(Stack* s ){    
    //這裡的作法是把原本的stack push進另一個stack，邊push邊刪原本的stack
    Stack* r = (Stack* )malloc(sizeof(Stack));
    r->top = NULL;
    while(s->top != NULL ){
        Node* temp =  s->top ; 
        push(r , s->top->value);
        s->top = temp->next ;
        free(temp);
    }
    s->top = r->top;    // 最後讓原本stack的top 指到新stack的top 
}

void print(Stack* s ){
    printf("\n");
    Node* temp = s->top;
    int count = 0 ;
    while(temp != NULL ){
        printf("%7d->", temp->value);
        temp = temp->next;
        count++;
        if(count % 5 == 0 ){
            printf("\n");
        }
    }
    printf("\n");
}

int main(){
    Stack * s = (Stack*) malloc(sizeof(Stack));
    s->top = NULL ; 
    FILE *f = fopen("Stack.txt", "r");
    char string[10];
    while(fgets(string , 10 , f) != NULL){
        int value ;
        value = atoi(string);
        push(s , value);
    }
    print(s);

    while(1){
        printf("Please select the action\n");
        printf("1. push 2. pop 3. reverse 4. search: ");
        int type ;
        scanf("%d" , &type);
        if(type == 1 ){
            printf("enter an integer : ");
            int value ;
            scanf("%d" , &value );
            push(s , value);
            print(s);
        }
        else if (type == 2 ){
            printf("The value at the top is %d.\n", pop(s));
            print(s);
        }
        else if (type == 3 ){
            reverse(s);
            print(s);
        }
        else if (type == 4 ){
            printf("enter an integer : ");
            int value ;
            scanf("%d", &value);
            if(search(s,value)){
                printf("No.%d node contains %d.\n\n" , search(s,value) , value);
            }
            else{
                printf("Stack did not exist a node contains %d.\n\n", value );
            }
        }
    }
}