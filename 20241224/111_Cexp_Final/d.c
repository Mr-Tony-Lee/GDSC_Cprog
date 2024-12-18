#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int value ;
    struct Node* next ;
    struct Node* pre ; 
}Node;

typedef struct Queue{
    Node* head;
    Node* rear ; 
}Queue ;

Node* createNode(int value ){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->value = value ;
    temp->next = NULL;
    temp->pre = NULL;
}

void enqueue(Queue* q , int value ){
    Node* temp = createNode(value);
    if(!q->rear){
        q->rear = temp ; 
        q->head = temp ; 
    }
    else{
        q->rear->next = temp ; 
        temp->pre = q->rear ; 
        q->rear = temp;
    }
}

void delete(Queue*q , int index ){
    Node* temp = q->rear;
    int i ;
    for(i = 1 ; i < index ; i++ ){
        temp = temp->pre;
    }       
    temp->pre->next = temp->next ;
    temp->next->pre = temp->pre;
    free(temp);
}

void print(Queue* q){
    printf("[");
    Node* cur = q->head;
    while(cur->next){
        printf("%d,", cur->value);
        cur = cur->next;
    }
    printf("%d]\n",cur->value);
}

int main(){
    char string[1000];
    memset(string , '\0' , 1000);
    while(1){
        Queue * q = (Queue*)malloc(sizeof(Queue));
        q->head = NULL ;
        q->rear = NULL;
        gets(string);
        // 偷吃步寫法，因為前面都是head = [ 
        int i ; 
        char num[20];
        memset(num , '\0', 20 );
        int number;
        int index = 0 ; 
        for(i = 8 ; i < strlen(string) ; i++ ){
            if (string[i] == ']'){
                number = atoi(num);
                memset(num , '\0', 20 );
                index = 0 ; 
                enqueue(q,number);
                break;
            }
            else if( string[i] < '0' || string[i] > '9'){
                number = atoi(num);
                memset(num , '\0', 20 );
                index = 0 ; 
                enqueue(q,number);
            }
            else{
                num[index++] = string[i];
            }
        }
        i += 7 ;    // ]後面一定是 , n = 
        
        int n ; 
        memset(num , '\0', 20 );
        index = 0 ; 
        for( ; i < strlen(string) ; i++ ){  //直接就是數字
            num[index++] = string[i];
        }
        n = atoi(num);

        delete(q,n);
        print(q);

    }
}