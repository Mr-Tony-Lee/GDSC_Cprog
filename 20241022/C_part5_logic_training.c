#include<stdio.h>

int main(){
    // long long int number = 41 ;
    // int base = 2 ;
    // long long div = 1; 
    // // power要找出一個小於Number、且最大的base^power次方
    // int power = 0 ;
    // while(div <= number ){
    //     div *= base ;
    //     power++;
    // }

    // div /= base;
    // power--;
    // int i ;
    // for(i = power ; i >= 0 ; i--  ){
    //     printf("%lld", number / div );
    //     number %= div;
    //     div /= base ;
    // }
    // printf("\n");

    //  以下是用array做，但現在的範圍還沒有教，所以先以上面為主
    // int count = 0 ;
    // while(div <= number ){
    //     count++;
    //     div *= base ;
    // }
    // int array[count];
    // for(int i = 0 ; i < count ; i++ ){
    //     array[i] = number % base ;
    //     number /= base ;
    // }
    // for(int i = count-1 ; i >= 0 ; i--){
    //     printf("%d", array[i]);
    // }
    // printf("\n");

    // powerpoint p75 ~ p80 
    // while(1){
    //     printf("Please enter a pair of integers (M,N) : ");
    //     int M , N ;
    //     scanf(" (%d,%d)", &M , &N);
    //     if( M == 0 && M == N ){
    //         printf("Go to next question\n\n");
    //         break;
    //     }
    //     printf("%d in base %d system is ", M , N );
    //     int power = 0;
    //     int div = 1 ;
    //     while(div <= M ){
    //         div*= N ;
    //         power++;
    //     }
    //     power--;
    //     div /= N ;
    //     int i ; 
    //     for( i = power ; i >= 0 ; i--){
    //         int output = M / div ;
    //         M %= div;
    //         div /= N;
    //         if(output < 10 ){
    //             printf("%d", output );
    //         }
    //         else if (output == 10 ){
    //             printf("A");
    //         }
    //         else if (output == 11 ){
    //             printf("B");
    //         }
    //         else if (output == 12 ){
    //             printf("C");
    //         }
    //         else if (output == 13 ){
    //             printf("D");
    //         }
    //         else if (output == 14 ){
    //             printf("E");
    //         }
    //         else if (output == 15 ){
    //             printf("F");
    //         }
    //     }
    //     printf(".\n\n");
    // }

    // powerpoint p81 ~ p86 
    while(1){
        printf("Please input a pair of string and integer: ");
        char a , b , c , d;
        int base ;
        scanf(" (%c%c%c%c,%d)", &a, &b, &c, &d, &base);
        if(a == b && b == c && c == d && a == '0' && base == 0 ){
            printf("Go to next question\n\n");
            break;
        }
        int ans = 0 ; 
        int number ;
        if( '0' <= a  && a <= '9'){
            number = a-'0';
        }
        else{
            number = a - 'A' + 10 ;
        }
        if(number >= base ){
            printf("Wrong input, input again!\n\n");
            continue;
        }
        ans += number*base*base*base;
        if( '0' <=  b  && b <= '9'){
            number = b-'0';
        }
        else{
            number = b - 'A' + 10 ;
        }
        if(number >= base ){
            printf("Wrong input, input again!\n\n");
            continue;
        }
        ans += number*base*base;
        if( '0' <= c && c <= '9'){
            number = c - '0';
        }
        else{
            number = c - 'A' + 10 ;
        }
        if(number >= base ){
            printf("Wrong input, input again!\n\n");
            continue;
        }
        ans += number*base;
        if( '0' <= d  && d <= '9'){
            number = d-'0';
        }
        else{
            number = d - 'A' + 10 ;
        }
        if(number >= base ){
            printf("Wrong input, input again!\n\n");
            continue;
        }
        ans += number;
        printf("%c%c%c%c in base %d is %d.\n\n",a,b,c,d,base,ans);
    }

    // powerpoint p87 ~ p90 
    // long long int number1 = 6 ;
    // long long int number2 = 12 ;
    // long long int bound ;
    // if(number1 >= number2 ){
    //     bound = number2 ;
    // }
    // else{
    //     bound = number1 ;
    // }
    // long long i ;
    // long long int GCD = 0;
    // for( i = 1 ; i <= bound ; i++){
    //     if(number2 % i == 0 && number1 % i == 0 ){
    //         GCD = i ;
    //     }
    // }
    // printf("The GCD of %lld and %lld is %lld\n" , number1 , number2 , GCD );

    // long long int number1 = 6 ;
    // long long int number2 = 12 ;
    // long long int bound ;
    // if(number1 >= number2 ){
    //     bound = number1 ;
    // }
    // else{
    //     bound = number2 ;
    // }
    // long long int i ;
    // long long int ans = 0 ;
    // for(i = bound ; i <= number1*number2 ; i++){
    //     if(i % number1 == 0 && i % number2 == 0 ){
    //         ans = i ;
    //         break;
    //     }
    // }
    // printf("The LCM of %lld and %lld is %lld\n", number1 , number2 , ans );
    // printf("The LCM of %lld and %lld is %lld\n", number1 , number2 , number1 * number2 / GCD  );

    // prime number 
    // long long int number ;
    // for( number = 2 ; number <= 1000 ; number++ ){
    //     int flag = 1;
    //     int j ;
    //     for(j = 2 ; j * j <= number ; j++ ){
    //         if( number % j == 0 ){
    //             flag = 0 ;
    //             break;
    //         }
    //     }
    //     if(flag) printf("%lld is a prime number.\n" , number);
    // }
    
}
