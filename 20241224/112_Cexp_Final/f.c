#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char string[1024];
    memset(string, '\0' , 1024);

    while(fgets(string , 1000 , stdin) != NULL){
        if(strcmp(string ,"0\n") == 0 ){
            printf("Finish!\n"); break;
        }
        int size = strlen(string)-1;
        int i , j , k ; 
        for( i = size/2 ; i >= 1  ; i-- ){  
            //由長到短 把字分成3個區塊 ____|____|____ ， 後面兩段長度固定，前面會慢慢變長
            int state = 1 ; 
            int lastword_index = size-1; //從後面開始讀
            int otherstring_begin_index = lastword_index-i;
            for( j = 0 ; j < i ; j++ ){
                if(string[lastword_index--] != string[otherstring_begin_index--]){
                    state = 0;
                    break;  //如果有一個不一樣就直接break掉
                }
            }
            if(state){  // 如果順利跑完，就直接印出
                printf("\n");
                for( k = strlen(string)-1-i; k < strlen(string)-1 ; k++){
                    printf("%c" , string[k]);
                }
                printf("\n%d\n\n" , i );
                break;  // 並進到下一輪
            }
        }
    }
}
