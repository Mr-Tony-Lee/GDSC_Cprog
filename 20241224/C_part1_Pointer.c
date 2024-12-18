#include<stdio.h>

void swap (int* a , int* b ){
    int temp = *a; 
    *a = *b ;
    *b = temp;
}

int main(){

    // int n ;
    // int *p ;                // int* p 或 int * p 都可以，只要 * 在 int 跟 p 之間就好
    // int *p1 , *p2 , *p3 ;   // 分開宣告每個指標前面都要有 * 

    // int n;			// n 是 int

    // // 指到一個整數 (int)，data type: int*
    // int *p;			// *p 是 int

    // // 指到一個指到整數的指標 (int*)，data type: int**
    // int **pp;		// **pp 是 int
    
    // int num = 1 , *ptr = &num, **ppr = &ptr;
    // printf("  num:%d &num:%p \n", num, &num);
    // printf(" *ptr:%d  ptr:%p &ptr:%p \n", *ptr, ptr, &ptr);
    // printf("**ppr:%d *ppr:%p  ppr:%p &ppr:%p \n", **ppr, *ppr, ppr, &ppr);


    // int x;
    // int *ip = &x;
    // *ip = 2;
    // printf("%d\n" , x);
    // float *fp = (float *) &x;
    // *fp = 2.0;
    // printf("%d\n" , x);     

    // // 再次以整數的方式讀取 x 的內容。
    // // 但此時 x 的記憶體內容實際上是浮點數 2.0 的 IEEE 754 編碼，而不是正常的整數值
    // // 2.0 的 IEEE 754 編碼為： 01000000 00000000 00000000 00000000
    // // 但以整數解釋就是 1073741824

    // char x, *p = &x, *q = p+1;
    // printf("p:%p\n" , p);
    // printf("q:%p\n" , q);
    // printf("sizeof(x) : %d\n" , (int)sizeof(x));

    // int x, *p = &x, *q = p+1;
    // printf("p:%p\n" , p);
    // printf("q:%p\n" , q);
    // printf("sizeof(x) : %d\n" , (int)sizeof(x));

    // int a = 1 , b = 2 ;
    // swap(&a , &b) ;
    // printf("a = %d , b = %d \n" , a, b );   

    
}