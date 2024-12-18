#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{    // Node for Tree 
    int data ; 
    struct Node* left;
    struct Node* right ;
}Node;

typedef struct Node_s{  // Node for Stack and Queue 
    Node* node ;
    struct Node_s *next ; 
}Node_s;

/* ------------------------------------------------- Stack Area -------------------------------------------------*/

typedef struct Stack{
    struct Node_s* top ;
} Stack;


Stack* createStack(){
    Stack* s = malloc(sizeof(Stack));
    s->top = NULL;
    return s ; 
}


void Stack_push( Stack* s , Node* cur ){
    Node_s* temp = malloc(sizeof(Node_s));
    temp->node = cur ;
    temp->next = s->top ;
    s->top = temp ; 
}

Node* Stack_pop( Stack*s ){
    Node_s* temp = s->top ;
    Node* cur = temp->node;
    s->top = temp->next ;
    free(temp);
    return cur ;
}
/* ------------------------------------------------- Stack Area -------------------------------------------------*/

/* ------------------------------------------------- Queue Area -------------------------------------------------*/
typedef struct Queue{   
    struct Node_s* front ;
    struct Node_s* rear ;
}Queue;

Queue* createQueue(){
    Queue* q = malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q ;
}

Node_s* Queue_createNode(Node* cur , Node_s* ptr ){
    Node_s* temp = malloc(sizeof(Node_s));
    temp->next = ptr ;
    temp->node = cur ;
    return temp ; 
}

void enqueue(Queue* q , Node* cur ){
    if(!q->rear){
        q->rear = Queue_createNode(cur , NULL);
        q->front = q->rear;
    }
    else{
        q->rear->next = Queue_createNode(cur , NULL );
        q->rear = q->rear->next ; 
    }
}

Node* dequeue(Queue* q ){
    if(!q->front) return NULL; 
    else{
        Node_s* temp = q->front;
        Node* cur = temp->node;
        if(q->front == q->rear ){
            q->front = q->rear = NULL;
        }
        else{
            q->front = q->front->next ;
        }
        free(temp);
        return cur ;  
    }
}
/* ------------------------------------------------- Queue Area -------------------------------------------------*/

/* ---------------------------------------------- Create Tree Area -----------------------------------------------*/
typedef struct Tree{
    Node* root ;
}Tree;

Node* CreateNode(int value){
    Node* temp = (Node* )malloc(sizeof(Node));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = value ;
    return temp;
}

Tree* CreateTree(){
    Tree* temp = (Tree* )malloc(sizeof(Tree));
    temp->root = NULL;
    return temp;
}
/* ---------------------------------------------- Create Tree Area -----------------------------------------------*/

/* ---------------------------------------------- Search Area -----------------------------------------------*/
Node* SearchNode_Iterative(Tree* t , int value ){
    Node* temp = t->root ;
    while(temp && temp->data != value){
        if( value > temp->data )
            temp = temp->right;
        else 
            temp = temp->left ;
    }
    return temp ;
}

Node* SearchNode(Node* cur , int value){
    if(cur->data == value ) 
        return cur ;
    else if (value > cur->data ) 
        return SearchNode(cur->right , value);
    else 
        return SearchNode(cur->left , value);
}

Node* SearchNode_Recursive(Tree* t , int value ){
    return SearchNode(t->root, value);
}
/* ---------------------------------------------- Search Area -----------------------------------------------*/

/* ---------------------------------------------- Insert Area -----------------------------------------------*/
void InsertNode_Iterative(Tree* t , int value ){
    if(!t->root){
        t->root = CreateNode(value);
        return ;
    }
    if(SearchNode_Iterative(t, value)) return ;
    
    Node* temp = t->root ;
    while(temp){
        if(value > temp->data){
            if(!temp->right){
                temp->right = CreateNode(value);
                break;
            }
            else temp = temp->right;
        }
        else{
            if(!temp->left){
                temp->left = CreateNode(value);
                break;
            }
            else temp = temp->left;
        }
    }
}

void InsertNode(Node* cur , int value ){
    if( value > cur->data ){
        if(cur->right) InsertNode(cur->right , value);
        else cur->right = CreateNode(value);
    }
    else{
        if(cur->left) InsertNode(cur->left, value);
        else cur->left = CreateNode(value);
    }
}

void InsertNode_Recursive(Tree* t , int value ){
    if(SearchNode_Iterative(t , value)) return ;
    else if (!t->root){
        t->root = CreateNode(value);
    }
    else{
        InsertNode(t->root , value);
    }
}
/* ---------------------------------------------- Insert Area -----------------------------------------------*/

/* ---------------------------------------------- Delete Area -----------------------------------------------*/
//找inorder的下一個， Ex: 3 4 5 6 ， 要找4的Successor，就會找到5 
Node* Find_Inorder_Successor( Node* cur ){
    cur = cur->right ;

    while(cur != NULL && cur->left != NULL ){
        cur = cur->left ;
    }
    return cur ; 
}

//找inorder的前一個， Ex: 3 4 5 6 ， 要找4的Predecessor，就會找到3 
Node* Find_Inorder_Predecessor( Node* cur ){
    cur = cur->left ;
    while(cur != NULL && cur->right != NULL ){
        cur = cur->right ;
    }
    return cur ;
}

Node* DeleteNode( Node* cur , int value ){
    if ( cur == NULL ) return cur ;
    
    //要先找到要刪除的點
    if (cur->data > value ){
        cur->left = DeleteNode(cur->left , value );
    }
    else if ( cur->data < value ) {
        cur->right = DeleteNode (cur->right , value );
    }
    else{
        // 現在的右邊是空，左邊可能空可能有，但要做的事情是一樣的
        if(cur->right == NULL ){
            Node* temp = cur->left ;
            free(cur);
            return temp ;
        }
        // 現在的左邊是空，右邊可能空可能有，但要做的事情是一樣的
        if ( cur->left == NULL ){
            Node* temp = cur->right ;
            free(cur);
            return temp ;
        }
        
        //這是 Successor 的寫法
        Node* successor = Find_Inorder_Successor(cur);
        cur->data = successor->data ; 
        cur->right = DeleteNode(cur->right , successor->data);

        //這是 Predecessor 的寫法
        // Node* successor = Find_Inorder_Predecessor(cur);
        // cur->data = successor->data ; 
        // cur->left = DeleteNode(cur->left , successor->data);
    }
    return cur ;    
}
/* ---------------------------------------------- Delete Area -----------------------------------------------*/

/* ---------------------------------------------- Traversal Area -----------------------------------------------*/
void Preorder_Recursive(Node* root ){
    if ( root != NULL ){
        printf("%d ", root->data);      // 先走中間
        Preorder_Recursive(root->left); // 先走左邊
        Preorder_Recursive(root->right);// 最後走右邊
    }
}

void Preorder_Iterative(Node* root ){   
    Stack* s = createStack();   //用 stack 去存放每個Node
    Node* cur = root ;
    while( s->top || cur ){ // 如果stack 有東西 或是 cur 有東西，就一直跑
        if(cur != NULL ){   // 如果 cur 不是 NULL 那就輸出 (中間的節點)
            printf("%d ", cur->data ); 
            Stack_push( s , cur );  // 並把中間push進去
            cur = cur->left ;   // 往左走
        }
        else{   // 如果 cur 是空 ( 已經到頭了)
            cur = Stack_pop(s); // 就取出 stack 的 top (是中間的節點)
            cur = cur->right;   // 然後往右走   
        }
    }
}

void Inorder_Recursive(Node* root ){
    if(root != NULL ){
        Inorder_Recursive(root->left);  //先走左邊
        printf("%d " , root->data);     //在走中間
        Inorder_Recursive(root->right); //最後走右邊
    }
}

void Inorder_Iterative(Node* root ){
    Stack* s = createStack();
    Node* cur = root; 
    while( cur || s->top ){
        if(cur != NULL ){
            Stack_push(s,cur);  //一樣，先push中間的節點
            cur = cur->left;    //往左走
        }
        else{
            cur = Stack_pop(s); // 取出中間的節點 >> 
            // 第一次一定是最左下的節點( Stack 的 top )， 相當於兩個NULL節點的中間節點 
            printf("%d " , cur->data);  // 並輸出
            cur = cur->right;   // 然後往右
        }
    }
}

void Postorder_Recursive(Node* root ){
    if(root != NULL ){
        Postorder_Recursive(root->left);    // 先走左邊
        Postorder_Recursive(root->right);   // 再走右邊
        printf("%d " , root->data );        // 最後走中間
    }
}

// 這個比較麻煩， 左右中 不好直接透過stack去過， 那我們可以把 中右左 存進去stack ，然後最後輸出回來，
void Postorder_Iterative(Node* root ){
    Stack *s = createStack();  //一個用來記中右左的順序
    Stack *traversal = createStack();   // 跟上面有點像，只是我們不要直接輸出，要放進stack裡面
    Node* cur = root ; 
    while(cur || s->top ){
        if(cur != NULL ){
            Stack_push( s , cur );
            Stack_push( traversal ,cur);
            cur = cur->right;
        }
        else{
            cur = Stack_pop(s);
            cur = cur->left;
        }
    }
    while(traversal->top){
        Node*temp = Stack_pop(traversal);
        printf("%d " , temp->data);
    }
}
void Level_order_Recursive( Queue * q ){
    //Recursive的 level order 只要queue就好了 
    if(q->rear == NULL ) return ;   // Recursive的終止式

    Node* temp = dequeue(q);    // 每次都是從左到右，所以先放左邊再放右邊，
                                // 下一次就是左邊先執行，再執行右邊的節點
    if(temp != NULL ){
        printf("%d " , temp->data);
        enqueue(q , temp->left);
        enqueue(q , temp->right);
    }
    Level_order_Recursive(q);
}

void Level_order_Iterative (Tree* t ){
    Queue* q = createQueue();
    enqueue(q , t->root);
    while(t->root && q->front ){
        Node* temp = dequeue(q);
        printf("%d " , temp->data); //每次都是取頭的元素
        
        if(temp->left){
            enqueue(q , temp->left );   // 先放進左邊
        }
        if(temp->right){
            enqueue(q, temp->right);    //再放進右邊
        }
    }
}
/* ---------------------------------------------- Traversal Area -----------------------------------------------*/

/* ----------------------------------------- Choose what to use Area -------------------------------------------*/
void Insert(Tree* t , int value ){
    if( rand() % 2 ){
        InsertNode_Recursive(t , value );
    }
    else{
        InsertNode_Iterative(t , value );
    }
}
void Search(Tree* t , int value ){
    if(rand() % 2 ){
        SearchNode_Recursive(t , value);
    }
    else{
        SearchNode_Iterative(t , value);
    }
}

void Inorder(Tree* t){
    if(rand() % 2 ){
        printf("Inorder_R: ");
        Inorder_Recursive(t->root);
    }
    else{
        printf("Inorder_I: ");
        Inorder_Iterative(t->root);
    }
    printf("\n");
}  
void Preorder(Tree* t){
    if(rand()%2){
        printf("Preorder_R: ");
        Preorder_Recursive(t->root);
    }
    else{
        printf("Preorder_I: ");
        Preorder_Iterative(t->root);
    }
    printf("\n");
}
void Postorder(Tree* t ){
    if(rand() % 2 ){
        printf("Postorder_R: ");
        Postorder_Recursive(t->root);
    }
    else{
        printf("Postorder_I: ");
        Postorder_Iterative(t->root);
    }
    printf("\n");
}

void Level_order(Tree* t ){
    if(rand() % 2 ){
        printf("Levelorder_R: ");
        Queue *q = createQueue();
        enqueue(q,t->root);
        Level_order_Recursive(q);
    }
    else{
        printf("Levelorder_I: ");
        Level_order_Iterative(t);
    }
    printf("\n");
}

/* ----------------------------------------- Choose what to use Area -------------------------------------------*/

/* ----------------------------------------- Main Function -------------------------------------------*/
int main(){
    srand(time(NULL));

    /* Create Tree Like the PPT */
    Tree* tree = CreateTree();
    Insert(tree , 5 );
    Insert(tree , 2 );
    Insert(tree , 8 );
    Insert(tree , 1 );
    Insert(tree , 3 );
    Insert(tree , 7 );
    Insert(tree , 9 );
    /* Create Tree Like the PPT */
    
    /* Showing the traversal */
    Preorder(tree);
    Inorder(tree);
    Postorder(tree);
    Level_order(tree);    
    /* Showing the traversal */


    /* Showing the Delete */
    // tree->root = DeleteNode(tree->root , 7);
    // Level_order(tree);    
    // printf("\n");
    
    // tree->root = DeleteNode(tree->root , 5);
    // Level_order(tree);    
    // printf("\n");
    
    // tree->root = DeleteNode(tree->root , 3);
    // Level_order(tree);    
    // printf("\n");

    // tree->root = DeleteNode(tree->root , 9);
    // Level_order(tree);    
}

/* ----------------------------------------- Main Function -------------------------------------------*/