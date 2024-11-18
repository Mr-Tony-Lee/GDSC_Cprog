#include<stdio.h>


void hanoi(char Init , char Mid , char Des , int num  ){
    if(num == 1 ){
        printf("Move disk %d from %c to %c \n", 1 , Init , Des );
        return ;
    }
    hanoi(Init , Des , Mid , num-1);
    printf("Move disk %d from %c to %c \n" , num , Init , Des);
    hanoi(Mid , Init , Des , num-1);
}

int main(){
    hanoi('A','B','C' , 3 );
}