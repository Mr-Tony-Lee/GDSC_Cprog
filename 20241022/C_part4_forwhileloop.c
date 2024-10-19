#include<stdio.h>

int main(){
    // int i ;             //迴圈變數
    // int begin = 0 ;     //起始值
    // int end = 10;       //結束的值
    // int increase = 1  ; //遞增或遞減的值
    // for(i = begin ; i < end ; i += increase ){  //for迴圈，從begin跑到end，可是不含end，因為當 i = end 的時候就結束了 
    //     printf("i = %d now.\n", i );
    // }
    
    // i = begin;
    // while(i != end ){
    //     printf("i = %d now.\n", i );
    //     i += increase;
    // }

    // i = begin;
    // do{
    //     printf("i = %d now.\n", i );
    //     i += increase;
    // } while (i != end );

    // i = end ; 
    // while( i != end ){
    //     printf("i = %d now.\n", i );
    // }
    // printf("While End.\n");
    
    // do{
    //     printf("i = %d now.\n" , i );
    // }while( i != end );
    // printf("Do While End.\n");

    int row ;
    int col ;
    for(row = 1 ; row <= 9 ; row++ ){
        for(col = 1 ; col <= 9 ; col++ ){
            printf("%d * %d = %2d ", col , row , row*col);
        }
        printf("\n");
    }
}