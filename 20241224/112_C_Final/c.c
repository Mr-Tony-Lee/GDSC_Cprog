#include<stdio.h>

int main(){

    int map[15][15] = {};
    map[0][0] = 1 ;
    int i , j ;
    for(i = 0 ; i < 15 ; i++ ){
        map[i][0] = 1 ;
        map[i][i] = 1 ;       
        for(j = 1 ; j < i ; j++ ){
            map[i][j] = map[i-1][j-1] + map[i-1][j];
        }
    }
    while(1){
        long long  N ; 
        printf("Please input a layer number :");
        scanf("%lld" , &N);
        if(!( N <= 15 && N >= 0 )){
            printf("Wrong input, input again!");
            continue;
        }
        for( i = 0 ; i < N ; i++ ){
            for( j = i ; j < N-1 ; j++ ){
                printf("%5c" , ' ');
            }
            for( j = 0 ; j <= i ; j++ ){
                printf("%5d%5c" , map[i][j] , ' ');
            }
            printf("\n");
        }
    }
}