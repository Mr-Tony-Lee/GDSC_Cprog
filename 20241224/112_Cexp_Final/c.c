#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int i , j ; 
    
    char string[1001];
    memset(string, '\0' , 1001);

    while(fgets(string,1000 , stdin ) != NULL ){
        char compare[1001][1001];   // 把所有的字都存進去
        for( i = 0 ; i < strlen(string)-1 ; i++ ){
            string[i] = toupper(string[i]); // 把所有字都變成大寫
        }
        int index = 0 ;
        int count = 0 ;
        int k = 0 ;
        memset(compare[0] , '\0' , 1001);
        while( index < strlen(string)-1){
            compare[count][k++] = string[index++];
            if(string[index] == ' '){
                count++;
                k = 0 ; 
                memset(compare[count] , '\0' , 1001);
                index++;    //因為現在string[index]是空格，所以要加1，下一次進while迴圈才會讀字元
            }
        }
        
        int unique_word[count+1];   // 把是 unique 的 word 的 index 丟進去 array 裡面
        int ans = 0 ;
        memset(unique_word , -1 , count+1);
        for( i = 0 ; i < count+1 ; i++ ){
            int same = 0;
            for( j = 0 ; j < ans ; j++ ){
                if(strcmp(compare[unique_word[j]] , compare[i]) == 0 ){
                    same = 1 ;
                }
            }
            if(!same){
                unique_word[ans++] = i ;
            } 
            
        }
        printf("Number of terms in the dictionary is %d.\n\n", ans );
    }
}