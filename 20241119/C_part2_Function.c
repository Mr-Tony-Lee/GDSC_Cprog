#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

double f (double x ){
    double numerator = 3 * x + pow(7 , x);
    double denominator = sqrt(sqrt(x));
    return numerator/denominator;
}

void drawsquare(){
    printf("*******\n");
    printf("*******\n");
    printf("*******\n");
    printf("*******\n");
    printf("*******\n");
    printf("*******\n");
    printf("*******\n");
    printf("\n");
    return ;
}

int my_power(int a , int x ){   // a ^ x
    int sum = 1 ; // 能把 x 用二進位表示 Ex : 5 = 101 
    while(x){   //如果 x > 0 ， 就代表還沒結束
        if(x & 1) sum *= a  ;   //如果x最右邊那位是1 ， 那就乘一次現在的a
        a *= a ;    //那每經過一次while，都把現在的 a 平方
        x >>= 1 ;   //把 x 右移 ( 101 >> 10 )  >> 2 ^ 5 = 2 ^ 1 * 2 ^ 4;
    }
    return sum ; 
}

int main(){
    printf("%lf" , f(2));
    
    drawsquare();
    drawsquare();
    drawsquare();   

    printf("%d\n" , my_power(2,5));
    
}