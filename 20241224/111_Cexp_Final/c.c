#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){
    char string[1000];
    memset(string , '\0' , 1000);

    while(1){
        gets(string);
        int i ;
        char string2[1000];
        memset(string2 ,'\0',1000);
        int k = 0 ; // index for string2 
        for(i = 0 ; i < strlen(string) ; i++ ){
            if( ('A' <= string[i] && string[i] <= 'Z') || 
                ('a' <= string[i] && string[i] <= 'z') || 
                ('0' <= string[i] && string[i] <= '9') ){
                string2[k++] = toupper(string[i]);
            }
        }
        int left = 0 , right = k-1;
        int state = 1 ; 
        while(left <= right ){
            if(string2[left] != string2[right]) {
                state = 0 ;
                break;
            }
        }
        if(state){
            printf("true\n");
        }
        else{
            printf("false\n");
        }
    }
}