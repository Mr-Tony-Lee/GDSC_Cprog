#include<stdio.h>

//用輾轉相除法找GCD，如果用線性的找，遇到太大的數字就會超時，算不出來 (應該不會考 畢竟還沒教function)
unsigned long long find_GCD(unsigned long long a , unsigned long long b ){
    if( b == 0 ){
        return a ;
    }
    else if ( a >= b ){
        return find_GCD(b, a % b);
    }
    else{
        return find_GCD(a, b % a);
    }
}
// f 的遞迴式， 其實就是算費波納氣數列 (應該不會考 畢竟還沒教function)
unsigned long long fib(int n ){
    if(n == 1){
        return 1 ;
    }
    else if (n == 2 ){
        return 2 ;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}
int main(){
    // question 'a' begin.
    printf("My name is: 合力\n");
    printf("My student ID is: %d\n" ,113040076);
    printf("My secret code is: %d\n\n" , (1+1+3+4+7+6)*5);
    // question 'a' end.

    // question 'b' begin.
    int number ;
    printf("N = ");
    while(scanf("%d",&number) != EOF){
        if(number == 0 ){
            printf("Finish!\n");
            break;
        }
        else if(number < 0 || number % 2 == 0 ){
            printf("Please enter a valid number.\n");
            printf("N = ");
            continue;
        }   
        // 如果 N = 13 
        // 先觀察空白 跟星星的數量 星星是 13 , 11 , .... , 1 , 3 , .... , 13 
        // 空白是 0,1,2,3,4,....,13-1/2 , ... , 0 ;
        // 總共會有13+13-1行 ， 分成上下部分去印
        int now_row = 0 ; 
        while(now_row <= number/2){
            int i ;
            for(i = 0 ; i < now_row ; i++ ){
                printf(" ");
            }
            for(i = 0 ; i < number-now_row*2 ; i++ ){
                printf("*");
            }
            printf("\n");
            now_row++;
        }
        //下部分就是上部分然後扣回去
        now_row = number / 2 - 1;
        while(now_row >= 0 ){
            int i ;
            for(i = 0 ; i < now_row ; i++ ){
                printf(" ");
            }
            for(i = 0 ; i < number-now_row*2 ; i++ ){
                printf("*");
            }
            printf("\n");
            now_row--;
        }
        printf("N = ");
    }
    // question 'b' end.

    // question 'c' begin.
    unsigned long long a , b;
    while(scanf("%llu %llu", &a, &b) != EOF ){
        if(a == b && b == 0 ){
            printf("Finish!\n\n");
            break;
        }
        unsigned long long GCD = find_GCD(a,b);
        unsigned long long LCM = (a/GCD) * b ;
        printf("LCM of %llu and %llu is: %llu\n", a, b, LCM); // 範例測資大於unsigned long long 範圍
    }
    // question 'c' end.

    // question 'd' begin.
    // 先找出上底跟下底 (平行的兩條邊)
    int x1,y1,x2,y2,x3,y3,x4,y4 ;
    printf("Enter four points (x1 y1 x2 y2 x3 y3 x4 y4):");
    while(scanf("%d %d %d %d %d %d %d %d", &x1 , &y1, &x2, &y2 , &x3, &y3 , &x4, &y4) != EOF){
        if( !(-1000000 <= x1 && x1 <= 1000000) || !(-1000000 <= y1 && y1 <= 1000000) || 
            !(-1000000 <= x2 && x2 <= 1000000) || !(-1000000 <= y2 && y2 <= 1000000) || 
            !(-1000000 <= x3 && x3 <= 1000000) || !(-1000000 <= y3 && y3 <= 1000000) || 
            !(-1000000 <= x4 && x4 <= 1000000) || !(-1000000 <= y4 && y4 <= 1000000) ){
                printf("Invalid input.\n");
                printf("Enter four points (x1 y1 x2 y2 x3 y3 x4 y4):");
                continue;
            }
        if(x1 == y1 && y1 == x2 && x2 == y2 && y2 == x3 && x3 == y3 && y3 == x4 && x4 == y4 && x1 == 0 ){
            printf("Finish!\n\n");
            break;
        }

        //找出平行的兩條邊 一定是某兩個點的 x一樣 或 y一樣 才會平行 
        int upper , lower;
        int high;
        if(y1 == y2 && y3 == y4 ){
            upper = x1-x2;
            lower = x3-x4;
            high = y1-y3;
            if(upper < 0 ){
                upper *= -1;
            }
            if(lower < 0 ){
                lower *= -1;
            }
            if(high < 0 ){
                high *= -1;
            }
        }
        else if (y1 == y3 && y2 == y4 ){
            upper = x1-x3;
            lower = x2-x4;
            high = y1-y4;
            if(upper < 0 ){
                upper *= -1;
            }
            if(lower < 0 ){
                lower *= -1;
            }
            if(high < 0 ){
                high *= -1;
            }
        }
        else if (y1 == y4 && y2 == y3 ){
            upper = x1-x4;
            lower = x2-x3;
            high = y1-y3;
            if(upper < 0 ){
                upper *= -1;
            }
            if(lower < 0 ){
                lower *= -1;
            }
            if(high < 0 ){
                high *= -1;
            }
        }
        else if(x1 == x2 && x3 == x4 ){
            upper = y1-y2;
            lower = y3-y4;
            high = x1-x3;
            if(upper < 0 ){
                upper *= -1;
            }
            if(lower < 0 ){
                lower *= -1;
            }
            if(high < 0 ){
                high *= -1;
            }
        }
        else if (x1 == x3 && x2 == x4 ){
            upper = y1-y3;
            lower = y2-y4;
            high = x1-x2;
            if(upper < 0 ){
                upper *= -1;
            }
            if(lower < 0 ){
                lower *= -1;
            }
            if(high < 0 ){
                high *= -1;
            }
        }
        else if (x1 == x4 && x2 == x3 ){
            upper = y1-y4;
            lower = y2-y3;
            high = x1-x3;
            if(upper < 0 ){
                upper *= -1;
            }
            if(lower < 0 ){
                lower *= -1;
            }
            if(high < 0 ){
                high *= -1;
            }
        }
        else{
           printf("Invalid input.\n");
                printf("Enter four points (x1 y1 x2 y2 x3 y3 x4 y4):");
                continue; 
        }
        double ans = 0.5*(upper+lower) * high ;
        printf("The area of the trapezoid is: %.2lf\n",ans);    //輸出符合規定
    }

    // question 'd' end.

    // question 'e' begin.
    int x , y;
    while(scanf("%d %d", &x , &y) != EOF){
        if(x == 0 && y == 0 ){
            break;
        }
        if(!(x <= y )){
            printf("Invalid input\n");
            continue;
        }
        int i ,j;
        for(i = x ; i <= y ; i++ ){
            int flag = 1;
            for(j = 2 ; j * j <= i ; j++ ){
                if( i % j == 0 ){
                    flag = 0;
                    break;
                }
            }
            if(flag ) printf("%d\n",i);
        }
    }
    // question 'e' end.    

    // question 'f' begin.
    int n ; 
    printf("N = ");
    while(scanf("%d",&n) != EOF ){
        if(n == 0 ){
            printf("Finish!\n\n");
            break;
        }
        else if (!(0 < n && n < 45 )){
            printf("Invalid input.\n\n");
            printf("N = ");
            continue;
        }
        printf("%llu",fib(n));
        printf("N = ");
    }
    // question 'f' end.

    // question 'g' begin.
    int now_state = 1;
    int input ;
    int now ;
    while(scanf("%d", &input) != EOF){
        if(now_state == 1 ){
            now = input ;
            printf("(State RST) => %d\n",now);
            now_state++;
        }
        else if (now_state == 2 ){
            now += input;
            printf("(State ADD) => %d\n",now);
            now_state++;
        }
        else if (now_state == 3 ){
            now -= input;
            printf("(State SUB) => %d\n",now);
            now_state++;
        }
        else if (now_state == 4 ){
            now *= input;
            printf("(State MUL) => %d\n",now);
            now_state++;
        }
        else if (now_state == 5 ){
            if(now == 0 ){
                now_state = 1 ;
                printf("(State DIV) => division by zero => reset\n");
                continue;
            }
            else{
                now = input / now;
                printf("(State DIV) => %d\n",now);
                now_state = 2 ;
            }
        }   
    }
    // question 'g' end.
}