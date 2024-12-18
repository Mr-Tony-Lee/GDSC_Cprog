#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long 

char* getword(int* i , char * string , int size ){
    int index = 0 ;
    char *number = (char*)malloc(100*sizeof(char));
    memset(number , '\0' , 100);

    while( (*i) < size ){
        number[index++] = string[(*i)++];
        if(string[*i] == ' ' || string[*i] == '.'){
            return number;
        }
    }
    return number ; 
}

int main(){
    char string[1025];
    memset(string,  '\0' , 1025);
    ll max = -1 ; // only positive number in article 
    while(fgets(string, 1024 , stdin ) != NULL ){
        int i = 0 ; 
        char* number;
        while(i < strlen(string)){
            number = getword(&i , string , strlen(string)); // 用來取每一個字 
            ll now_num = atoll(number); // 把char array轉成 long long ，如果array裡面有不是數字的，會是0
            if(now_num > max ){
                max = now_num;
            }
            memset(number,'\0' , 100);
            i++;    //再i++ 跳過空白字符
        }
    }   
    printf("%llu\n" , max );
}

