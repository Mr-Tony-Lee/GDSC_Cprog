#include<stdio.h>
#include<string.h>

void Palindrome(char string[101] , int left , int right ){
    while(left < right ){
        if(string[left] != string[right]){
            printf("%s is not a palindrome.\n" , string);
            return;
        }
        left++;
        right--;
    }
    printf("%s is a palindrome.\n" , string);
}

int main(){
    char input[101] = "";
    printf("Please input a string :");
    //scanf("%s", input );
    fgets(input , 101 , stdin);     
    input[strlen(input)-1] = '\0'; // 吃掉\n
    int left = 0 , right = strlen(input)-1;
    Palindrome(input , left , right );
}
