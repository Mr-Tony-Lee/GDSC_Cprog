#include<stdio.h>

int find_GCD(int a , int b ){
    if ( b == 0 ){
        return a ;
    }
    else if ( a > b ){
        return find_GCD( b , a % b );
    }
    else {
        return find_GCD( a , b % a );
    }
}

int main(){
    printf("The gcd of %d and %d is %d \n" , 72 , 48  , find_GCD( 72 , 48 ));
    printf("The gcd of %d and %d is %d \n" , 10958 , 1992  , find_GCD(10958 , 1992));
    printf("The gcd of %d and %d is %d \n" , 30 , 19  , find_GCD(30,19));
}