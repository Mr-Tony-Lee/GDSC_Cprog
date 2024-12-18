#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void hanoi(char init , char mid , char des , int number , int* count ){ // count要用指標，這樣才會更新到count的值
    if(number == 1 ){
        (*count)++;
        printf(" Move disk 1 from %c to %c\n", init , des);
        return ;
    } 

    hanoi(init , des , mid , number-1 , count);
    (*count)++;
    printf(" Move disk %d from %c to %c \n", number , init , des );
    hanoi(mid , init , des , number-1 , count);
}

int main(){
    while(1){
        printf("Enter the number of disks : ");
        int N;
        scanf("%d", &N);
        printf("The sequence of moves involved in the Tower of Hanoi are : \n\n");
        int ans = 0 ;
        hanoi('A', 'B' , 'C' , N , &ans);
        printf(" \nThe number of moves : %d\n\n" , ans );
    }
    
}