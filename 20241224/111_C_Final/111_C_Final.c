#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
    struct Node* left ;
    struct Node* right ;
    struct Node* parent ;
    int value ;
}Node;

typedef struct Tree{
    struct Node* root ;
}Tree;

typedef struct  Node_s{
    struct Node* node ;
    struct Node_s* next ;
}Node_s;

typedef struct Stack{
    struct Node_s * top ;
}Stack ;

typedef struct Queue{
    Stack* first ;
    Stack* second;
}Queue;

Stack* createStack(){
    Stack * s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s ;
}

Node_s* createNode_s(Node* node ){
    Node_s* temp = (Node_s*)malloc(sizeof(Node_s));
    temp->next = NULL;
    temp->node = node;
    return temp;
}


Node* createNode(int value ){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = value ;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

void push(Stack * s , Node* node ){
    Node_s* temp = createNode_s(node);
    temp->next = s->top ;
    s->top = temp ;
}
Node* pop(Stack* s ){
    Node_s* temp = s->top ; 
    Node* node = temp->node;
    s->top = temp->next ;
    free(temp);
    return node ;
}

int Search(Tree*t , int value){
    Node* cur = t->root ;
    while(cur != NULL  ){
        if(cur->value == value) return 1 ;
        else if (cur->value < value ){
            cur = cur->right ;
        }
        else {
            cur = cur->left ;
        }
    }
    return 0 ; 
}

// 如果要作錯誤處理，需要額外寫search 去判斷有沒有相同的點 
void Insert(Tree* t , int value ){
    if(Search(t , value )){
        printf("There are same value in the tree.\n");
        return ;
    }
    // initialize 
    Node* temp = createNode(value);    
    if(t->root == NULL ) {
        t->root = temp ;
        return ;
    }
    Node* par = t->root ; 
    Node* cur = t->root ;
    while(cur){
        par = cur ;
        if(cur->value > value ){
            cur = cur->left;
        }
        else{
            cur = cur->right ;
        }
    }
    if(par->value > value ){
        par->left = temp ; 
    }
    else{
        par->right = temp ;
    }
    temp->parent = par;
}

Node* delete_recursion(Node* cur , int value ){
    if(cur == NULL ) return NULL;
    if(cur->value > value ){
        cur->left = delete_recursion(cur->left , value);
    }
    else if ( cur->value < value ){
        cur->right = delete_recursion(cur->right , value);
    }
    else {
        if(cur->left == NULL ){
            Node* temp = cur->right ; 
            free(cur);
            return temp ;
        }
        if(cur->right == NULL ){
            Node* temp = cur->left ;
            free(cur);
            return temp ;
        }
        Node* temp = cur->left ;
        while(temp && temp->right){
            temp = temp->right ;
        }
        cur->value = temp->value ;
        cur->left = delete_recursion(cur->left , value);
    }   
}

void Delete(Tree* t , int value ){
    if(!Search(t , value )){
        printf("No that value in the tree.\n");
        return ;
    }
    delete_recursion(t->root , value );
}

// 自由選擇要用 遞迴的方式 還是 iterative 的方式 ， 都可以
void Inorder(Tree* t){
    printf("In-order traversal: ");
    Stack *s = createStack(); 
    Node* cur = t->root ;
    while(cur || s->top ){
        if(cur){
            push(s,cur);
            cur = cur->left ;
        }
        else{
            cur = pop(s);
            printf("%d->",cur->value );
            cur = cur->right ; 
        }
    }
    printf("\n");
}

// 自由選擇要用 遞迴的方式 還是 iterative 的方式 ， 都可以
void Preorder(Tree* t){   
    printf("Pre-order traversal: ");
    Stack *s = createStack(); 
    Node* cur = t->root ;
    while( s->top || cur ){ // 如果stack 有東西 或是 cur 有東西，就一直跑
        if(cur != NULL ){   // 如果 cur 不是 NULL 那就輸出 (中間的節點)
            printf("%d->", cur->value ); 
            push( s , cur );  // 並把中間push進去
            cur = cur->left ;   // 往左走
        }
        else{   // 如果 cur 是空 ( 已經到頭了)
            cur = pop(s); // 就取出 stack 的 top (是中間的節點)
            cur = cur->right;   // 然後往右走   
        }
    }
    printf("\n");
}

// 自由選擇要用 遞迴的方式 還是 iterative 的方式 ， 都可以
void Postorder(Tree* t ){
    printf("Post-order traversal: ");
    Stack *s = createStack();
    Stack *traversal = createStack();
    Node* cur = t->root ; 
    while(cur || s->top ){
        if(cur != NULL ){
            push( s , cur );
            push( traversal ,cur);
            cur = cur->right;
        }
        else{
            cur = pop(s);
            cur = cur->left;
        }
    }
    while(traversal->top){
        Node* temp = pop(traversal);
        printf("%d->" , temp->value);
    }
    printf("\n");
}

void Clear(Stack* s){
    while(s->top){
        Node_s *cur = s->top ; 
        s->top = cur->next;
        free(cur);
    }
    s->top = NULL;
}

void enqueue(Queue* q , Node* node ){
    push(q->first,node);
    Clear(q->second);
    Node_s* cur = q->first->top;
    while(cur){
        push(q->second , cur->node);
        cur = cur->next ;
    }
}


Node* dequeue(Queue* q ){
    Node* ans = pop(q->second);
    Clear(q->first);
    Node_s* cur = q->second->top;
    while(cur){
        push(q->first , cur->node);
        cur = cur->next ;
    }
    return ans ;
}

void printQueue(Queue*q){
    if(q->first->top == NULL && q->second->top == NULL ){
        printf("Queue is empty.\n\n");
        return ;
    }
    Node_s* cur = q->first->top;
    int count = 0 ; 
    // 先計算有幾個Node_s
    while(cur){
        count++;
        cur = cur->next;
    }
    int i ;

    // 第一行
    printf("*");
    for( i = 0 ; i < count ; i++ ){
        printf("*******");
    }
    printf("\n");

    // 第二行
    printf("*");
    for( i = 0 ; i < count ; i++ ){
        printf("      *");
    }
    printf("\n");

    // 第三行
    printf("*");
    for( i = 0 ; i < count ; i++ ){
        printf("      *");
    }
    printf("\n");

    // 第四行
    printf("*");
    cur = q->second->top;
    while(cur){
        printf("   "); // 三個空格
        printf("%d",cur->node->value);
        printf("  *"); // 數字+ 兩個空格 + *
        cur = cur->next ;
    }
    printf("\n");

    // 第五行
    printf("*");
    for( i = 0 ; i < count ; i++ ){
        printf("      *");
    }
    printf("\n");

    // 第六行
    printf("*");
    for( i = 0 ; i < count ; i++ ){
        printf("      *");
    }
    printf("\n");

    // 第七行
    printf("*");
    for( i = 0 ; i < count ; i++ ){
        printf("*******");
    }
    printf("\n");
}

void ClearQueue(Queue*q){
    Clear(q->first);
    Clear(q->second);
}

Queue* createQueue(){
    Queue * q = (Queue*)malloc(sizeof(Queue));    
    q->first =  (Stack*)malloc(sizeof(Stack)); 
    q->second = (Stack*)malloc(sizeof(Stack)); 
    q->first->top = NULL;
    q->second->top = NULL ; ;
    return q ; 
}

void levelorder(Tree *t){
    printf("Level Order traversal of BST is : \n");
    Queue* q = createQueue();
    enqueue(q , t->root );
    while( q->second->top ){
        Node* temp = dequeue(q);
        printf("%d->" , temp->value); //每次都是取頭的元素
        if(temp->left){
            enqueue(q , temp->left);   // 先放進左邊
        }
        if(temp->right){
            enqueue(q, temp->right);    //再放進右邊
        }
    }
    printf("\n\n");
}

int main(){
    srand(1);
    // initialize 
    Tree * t = (Tree*) malloc(sizeof(Tree));
    t->root = NULL ; 
    int number[100] = {0};
    int i , j ; 
    int count = 0 ; 
    while(count != 15 ){
        int create = rand() % 100 + 1;
        int same = 0 ; 
        for( j = 0 ; j < count ; j++ ){
            if(create == number[j]){
                same = 1 ; 
            }
        }
        if(!same)
            number[count++] = create ;
    }
    for(i = 0 ; i < count ; i++ ){
        Insert(t,number[i]);
    }
    printf("\n");
    while(1){
        printf("Please choose what you want to do with tree : 1.Insert 2.Delete 3.Traversal 4.Exit\n");
        int choose;
        scanf("%d" , &choose);
        if(choose == 1 ){
            int data;
            printf("Please enter the value to insert : ");
            scanf("%d" , &data);
            Insert(t,data);
        }
        else if (choose == 2 ){
            int data;
            printf("Please enter the value to delete : ");
            scanf("%d" , &data);
            Delete(t,data);
        }
        else if (choose == 3 ){
            printf("\n");   
            Inorder(t);
            Preorder(t);
            Postorder(t);   
            printf("\n");
        }
        else if (choose == 4 ){
            break;   
        }
    }
    Queue* q = createQueue();
    while(1){
        printf("Please choose what you want to do with queue : ");
        printf("1.Enqueue 2.Dequeue 3.PrintQueue 4.ClearQueue 5.LevelOrder 6.Exit\n");
        int choose ;
        scanf("%d", &choose);
        if(choose == 1 ){
            int data;
            printf("Please enter the value to enqueue : ");
            scanf("%d" , &data);
            Node* temp = (Node*)malloc(sizeof(Node));
            temp->value = data ; 
            enqueue(q,temp);   
        }
        else if (choose == 2 ) {
            dequeue(q);
        }
        else if (choose == 3 ) {
            printQueue(q);
        }
        else if (choose == 4 ) {
            ClearQueue(q);
            printf("Queue is empty now.\n\n");
        }
        else if (choose == 5 ) {
            levelorder(t);
        }
        else if (choose == 6 ) {
            break;
        }
    }
}