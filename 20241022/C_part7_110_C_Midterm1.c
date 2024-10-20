#include<stdio.h>

int main(){
    // question '1' begin.
    printf("Name: 胡小清\n");
    printf("Student ID: 103040023\n");
    printf("My secret code is %d\n\n" ,103040 * 023 % 1000);
    // question '1' end.

    // question '2' begin.
    double x ,y,z;
    printf("x = ");
    scanf("%lf",&x);
    printf("y = ");
    scanf("%lf",&y);
    printf("z = ");
    scanf("%lf",&z);
    printf("(%.4lf+%.4lf*%.4lf) / %.4lf = %.4lf\n\n" ,x,y,x,z ,(x+y*x)/z);
    // question '2' end.
    
    // question '3' begin.
    while(1){
        int m , d ;
        scanf("%d %d" , &m , &d);
        if(m == d && d == 0 ){
            break;
        }
        if( (m == 1 && d >= 21)  || (m == 2 && d <= 19) ){
            printf("Aquarius\n");
        }
        else if ( (m == 2 && d >= 20)  || (m == 3 && d <= 20) ){
            printf("Pisces\n");
        }
        else if ( (m == 3 && d >= 21)  || (m == 4 && d <= 20) ){
            printf("Aris\n");
        }
        else if ( (m == 4 && d >= 21)  || (m == 5 && d <= 21) ){
            printf("Taurus\n");
        }
        else if ( (m == 5 && d >= 22)  || (m == 6 && d <= 21) ){
            printf("Gemini\n");
        }
        else if ( (m == 6 && d >= 22)  || (m == 7 && d <= 22) ){
            printf("Cancer\n");
        }
        else if ( (m == 7 && d >= 23)  || (m == 8 && d <= 21) ){
            printf("Leo\n");
        }
        else if ( (m == 8 && d >= 22)  || (m == 9 && d <= 23) ){
            printf("Virgo\n");
        }
        else if ( (m == 9 && d >= 24)  || (m == 10 && d <= 23) ){
            printf("Libra\n");
        }
        else if ( (m == 10 && d >= 24)  || (m == 11 && d <= 22) ){
            printf("Scorpio\n");
        }
        else if ( (m == 11 && d >= 23)  || (m == 12 && d <= 22) ){
            printf("Sagittarius\n");
        }
        else if ( (m == 12 && d >= 23)  || (m == 1 && d <= 20) ){
            printf("Capricorn\n");
        }
    }
    // question '3' end.
    
    // question '4' begin.
    while(1){
        int row ;
        int i , j  ;
        printf("Please input number of rows: ");
        scanf("%d" , &row);
        if(row == 0 ){
            printf("Go to next question.\n\n");
            break;
        }
        int now = 0 ;
        while(now <= row ){
            for(i = 0 ; i <= now ; i++){
                    int n = 1 ; 
                    int k = 1 ;
                    int m = 1 ; // m = n-k;
                    for(j = 1 ; j <= now ; j++ ){
                        n *= j;
                    }
                    for(j = 1 ; j <= i ; j++ ){
                        k *= j;
                    }
                    for(j = 1 ; j <= now-i ; j++ ){
                        m *= j;
                    }
                    printf("%d\t",n/(k*m));
            }
            printf("\n");
            now++;
        }
    }
    // question '4' end.
    
    // question '5' begin.
    int row ;
    int time ;
    printf("Please input amplitude: " );
    scanf("%d",&row);
    printf("Please input frequency: " );
    scanf("%d",&time);
    while(time--){
        int now_row = 0;
        while(now_row <= row / 2 + 1){
            int i ; 
            for(i = 0; i <= now_row ; i++ ){
                printf("%d",now_row+1);
            }
            printf("\n");
            now_row++;
        }
        now_row = row/2;
        while(now_row >= 0){
            int i ; 
            for(i = 0; i <= now_row ; i++ ){
                printf("%d",now_row+1);
            }
            printf("\n");
            now_row--;
        }
        printf("\n");
    }    
    // question '5' end.

    // question '6' begin.
    int a , b , c;
    scanf("%d %d %d", &a,&b,&c);
    int count = 0 ;
    if(a && b ){
        if(c == 1 ){
            printf("AND\n");
            count++;
        }
    }
    else{
        if(c == 0 ){
            printf("AND\n");
            count++;
        }
    }
    if(a || b ){
        if(c == 1 ){
            printf("OR\n");
            count++;
        }
    }
    else{
        if(c == 0 ){
            printf("OR\n");
            count++;
        }
    }
    if(a ^ b ){
        if(c == 1 ){
            printf("XOR\n");
            count++;
        }
    }
    else{
        if(c == 0 ){
            printf("XOR\n");
            count++;
        }
    }
    if(count == 0 ){
        printf("IMPOSSIBLE\n");
    }
    // question '6' end.
}