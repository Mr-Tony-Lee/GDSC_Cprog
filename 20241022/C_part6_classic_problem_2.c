#include<stdio.h>

int main(){
   while(1){
        int row ;
        int i , j  ;
        printf("Please input number of rows: ");
        scanf("%d" , &row);
        if(row == 0 ){
            printf("Go to next question.\n\n");
            break;
        }
        int now = 1 ;
        printf("1\n");
        while(now <= row ){
            for(i = 0 ; i <= now ; i++){
                if(i == 0 ){
                    printf("1\t");
                }
                else if(i == now){
                    printf("1\t");
                }
                else{
                    int n = 1 ; 
                    int k = 1 ;
                    int m = 1 ; // m = n-k;
                    for(j = 1 ; j <= now ; j++ ){
                        n *= j;
                    }
                    for(j = 1 ; j <= i ; j++ ){
                        k *= j;
                    }
                    for(j = 1 ; j <= now-i ; j++ ){
                        m *= j;
                    }
                    printf("%d\t",n/(k*m));
                }
            }
            printf("\n");
            now++;
        }
    }
}