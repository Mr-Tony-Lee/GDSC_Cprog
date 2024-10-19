#include<stdio.h>

int main(){
   while(1){
        int number ;
        printf("Please input an integer: ");
        scanf("%d" , &number);
        if(number == 0 ){
            printf("Go to next question\n\n");
            break;
        }
        else if(!( 1 <= number && number <= 214748364)){
            printf("Wrong input, input again!\n\n");
            continue;
        }
        int reverse = 0 ;
        int number_copy = number ;
        while(number_copy > 0 ){
            reverse = reverse*10 + number_copy % 10;
            number_copy /= 10;
        }
        if(number == reverse ){
            printf("%d is palindrome.\n\n" , number);
        }
        else{
            printf("%d is not palindrome.\n\n", number );
        }
    }
}