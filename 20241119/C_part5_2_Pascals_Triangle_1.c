#include<stdio.h>

int main(){
    long long int  i , j ;
    while(1){
        long long  N ; 
        printf("Please input a layer number :");
        scanf("%lld" , &N);
        if(!( N <= 15 && N >= 0 )){
            printf("Wrong input, input again!");
            continue;
        }
        long long int  now = 0 ;
        while(now < N ){
            for( i = now ; i < N-1 ; i++ ){
                printf("%5c" , ' ');
            }
            for(i = 0 ; i <= now ; i++){
                unsigned long long int  n = 1 ; 
                unsigned long long int  k = 1 ;
                unsigned long long int  m = 1 ; // m = n-k;
                for(j = 1 ; j <= now ; j++ ){
                    n *= j;
                }
                for(j = 1 ; j <= i ; j++ ){
                    k *= j;
                }
                for(j = 1 ; j <= now-i ; j++ ){
                    m *= j;
                }
                printf("%5llu",n/(k*m));
                printf("%5c" , ' ');
            }
            printf("\n");
            now++;
        }        
    }
}


