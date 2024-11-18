#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int sum_1_to_n(int x ){
    if(x == 0 ) return 0 ;
    else return x + sum_1_to_n(x-1);
}

int fib(int x ){
    if(x == 1 ) return 1 ;
    else if ( x == 0 ) return 1 ;
    else return fib(x-1) + fib(x-2);
}

int main(){
    printf("%d\n" , sum_1_to_n(10));

    for(int i = 0 ; i <= 10 ; i++){
        printf("%d " , fib(i));
    }
    printf("\n");    
}