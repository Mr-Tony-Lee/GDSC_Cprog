#include<stdio.h>
#include<stdlib.h>

void swapI (int* a , int* b ){
    int temp = *a; 
    *a = *b ;
    *b = temp;
}

void swapF(float *a , float *b ){
    float temp = *a; 
    *a = *b ;
    *b = temp;
}

void swapL (long *a , long *b ){
    long temp = *a ;
    *a = *b ;
    *b = temp ;
}

void swap (void *a , void *b , size_t size ){
    char *p = (char *) a , *q = (char*)b , temp ; 
    while(size){
        temp = *p ;
        *p = *q ;
        *q = temp ;
        p++ ; q++ ; size--;
    }
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

    // int i ; 
    // int a[10] = {1,2,3,4,5,6,7,8,9,10};
    // printf("a[i]\t: ");
    // for(i = 0 ; i < 10 ; i++ ){
    //     printf("%d " , a[i]);
    // }
    // printf("\n");
    
    // printf("*(a+i)\t: ");
    // for(i = 0 ; i < 10 ; i++ ){
    //     printf("%d " , *(a+i));
    // }
    // printf("\n");
    
    // printf("*(i+a)\t: ");
    // for(i = 0 ; i < 10 ; i++ ){
    //     printf("%d " , *(i+a));
    // }
    // printf("\n");
    
    // printf("i[a]\t: ");
    // for(i = 0 ; i < 10 ; i++ ){
    //     printf("%d " , i[a]);
    // }
    // printf("\n");
    
    // int a = 1 , b = 2 ;
    // swap(&a , &b , sizeof(int));
    // printf(" a = %d , b = %d\n" , a , b  );

    // int n = 10000000 ; 
    // int *a = malloc( n * sizeof(int) ); // 分配 n 個可以放int的空間給 a
    // for(int i = 0 ; i < n ; i++ ){
    //     a[i] = i;
    // }
    // printf("OK\n");
    // free(a);    // 釋放記憶體空間，避免memory leak

    // int count = 0 ;
    // int row = 3 , column = 4 ;
    // int ** twoD_array = (int**)malloc(row * sizeof(int*));
    // for(int i = 0 ; i < row ; i++ ){
    //     twoD_array[i] = (int*)malloc(column * sizeof(int));
    //     for(int j = 0 ; j < column ; j++ ){
    //         twoD_array[i][j] = count++;
    //         printf("%2d " , twoD_array[i][j]);
    //     }
    //     printf("\n");
    // }
    // for(int i = 0 ; i < row ; i++ ){
    //     free(twoD_array[i]);
    // }
    // free(twoD_array);
}