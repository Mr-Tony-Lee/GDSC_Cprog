#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    // 遇到output結束program 並輸出，但不知道會不會在還沒insert完就結束掉，所以有個count看insert完了嗎
    int count = 0 ; 
    int row ;
    int i  ;
    scanf("%d" , &row);
    char** string = (char**)malloc(row*sizeof(char*));

    char* input = (char*)malloc(1024*sizeof(char));
    memset(input , '\0' , 1024);

    getchar();  // 吸收上次讀入row所留下來的 \n
    while(gets(input)){ //如果用fgets要注意最後會讀入\n ， 但用gets不會讀入反斜線n
        char* output = "OUTPUT";
        if(strcmp(input,output) == 0 ){
            break;
        }
        else{
            int index = 0 ;
            while(input[index] != ' '){
                index++;
            }
            index++;
            char* number = (char*)malloc(20*sizeof(char));
            int k = 0 ; 
            while(index < strlen(input)){
                number[k++] = input[index++];
            }
            int each_row_size = atoi(number);

            char* row_string = (char*)malloc((each_row_size+1)*sizeof(char)); // 要加上 \0 所以+1
            memset(row_string , '\0' , each_row_size+1); 
            gets(row_string);
            
            string[count] = row_string;
        }
        count++;
    }
    for(int i = count-1 ; i >= 0 ; i-- ){
        printf("%s\n" , string[i]);
    }
}