#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

typedef struct Queue{
	Node* front;
    Node* rear;
}Queue;

Node* createNode(int value , Node* ptr ){
    Node* temp = (Node* )malloc(sizeof(Node));
    temp->data = value ;
    temp->next = ptr ;
    return temp ;
}

void enqueue(Queue* q , int value ){
    if(!q->rear){
        q->rear = createNode(value , NULL);
        q->front = q->rear;
    }
    else{
        q->rear->next = createNode(value , NULL );
        q->rear = q->rear->next ; 
    }
}
    
int dequeue(Queue* q ){
    if(!q->front) return -1; 
    else{
        Node* temp = q->front;
        int value = temp->data;
        if(q->front == q->rear ){
            q->front = q->rear = NULL;
        }
        else{
            q->front = q->front->next ;
        }
        free(temp);
        return value ;  
    }
}

void PrintQueue(Queue *q ){
    printf("Queue Now : ");
    Node* temp = q->front;
    while(temp){
        printf("%d " , temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Queue* queue = (Queue* )malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    enqueue(queue , 1); PrintQueue(queue);
    enqueue(queue , 2); PrintQueue(queue);
    enqueue(queue , 3); PrintQueue(queue);
    dequeue(queue); PrintQueue(queue);
    dequeue(queue); PrintQueue(queue);
    dequeue(queue); PrintQueue(queue); 
}

