#include<stdio.h>

int main(){
       
    int number ;
    printf("N = ");
    while(scanf("%d",&number) != EOF){
        if(number == 0 ){
            printf("Finish!\n");
            break;
        }
        else if(number < 0 || number % 2 == 0 ){
            printf("Please enter a valid number.\n");
            printf("N = ");
            continue;
        }   

        // 如果 N = 13 
        // 先觀察空白 跟星星的數量 星星是 13 , 11 , .... , 1 , 3 , .... , 13 
        // 空白是 0,1,2,3,4,....,13-1/2 , ... , 0 ;
        // 總共會有13+13-1行 ， 分成上下部分去印

        int now_row = 0 ; 
        while(now_row <= number/2){
            int i ;
            for(i = 0 ; i < now_row ; i++ ){
                printf(" ");
            }
            for(i = 0 ; i < number-now_row*2 ; i++ ){
                printf("%d",now_row+1);
            }
            printf("\n");
            now_row++;
        }
        
        //下部分就是上部分然後扣回去
        now_row = number / 2 - 1;
        while(now_row >= 0 ){
            int i ;
            for(i = 0 ; i < now_row ; i++ ){
                printf(" ");
            }
            for(i = 0 ; i < number-now_row*2 ; i++ ){
                printf("%d",now_row+1);
            }
            printf("\n");
            now_row--;
        }
        printf("N = ");
    }
}