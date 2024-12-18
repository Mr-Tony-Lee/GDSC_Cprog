#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char string[1000];
    char string_s[1000];
    memset(string, '\0' , 1000);
    memset(string_s, '\0' , 1000);
    while(1){
        gets(string);
        gets(string_s);
        int index1= 0  , index2 = 0  ; 
        int count = 0 ; 
        int i ; 
        for( i = 0 ; i < strlen(string) ; i++ ){
            if(string[0] == string_s[i])
                break;
        }
        index2 = i ; 
        
        while( count < strlen(string)){
            index2 %= strlen(string);
            if(string[index1++] != string_s[index2++]){
                break;
            }
            count++;
        }
        if(count == strlen(string)){
            printf("true\n");
        }
        else{
            printf("false\n");
        }
    }
}