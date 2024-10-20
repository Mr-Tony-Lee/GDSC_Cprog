#include<stdio.h>

int main(){

    // question 'a' begin
    int run = 1 ;
    while(run){
        int abcd ;
        printf("Please input an integer: ");
        scanf("%d" , &abcd);
        while( abcd < 0 || abcd > 3999 ){
            printf("Wrong input, input again!\n\n");
            printf("Please input an integer: ");
            scanf("%d",&abcd);
        }
        switch (abcd)
        {
            case 0:{
                printf("Go to next question\n\n");
                run = 0 ;
                break;
            }
            default:{
                int i ;
                printf("Roman numeral: ");


                int a = abcd / 1000;
                //是1000的多少倍數就print幾個M
                for(int i = 0 ; i < a ; i++ ){ 
                    printf("M");
                }
                
                // abcd / 100 拿到 ab  , ab % 10 拿到 b
                int b = (abcd/100) % 10 ;
                switch (b){
                    case 9:{
                        printf("CM");
                        break;
                    }
                    case 8:
                    case 7:
                    case 6:
                    case 5:{
                        printf("D");
                        for(int i = 0 ; i < (b-5) ; i++ ){
                            printf("C");
                        }
                        break;
                    }
                    case 4:{
                        printf("CD");
                        break;
                    }
                    default:{
                        for(int i = 0 ; i < b ; i++ ){
                            printf("C");
                        }
                        break;
                    }   
                }
                
                // abcd/10 = abc , abc % 10 = c 
                int c = (abcd/10) % 10 ;
                switch (c){
                    case 9:{
                        printf("XC");
                        break;
                    }
                    case 8:
                    case 7:
                    case 6:
                    case 5:{
                        printf("L");
                        for(int i = 0 ; i < (c-5) ; i++ ){
                            printf("X");
                        }
                        break;
                    }
                    case 4:{
                        printf("XL");
                        break;
                    }
                    default:{
                        for(int i = 0 ; i < c ; i++ ){
                            printf("X");
                        }
                        break;
                    }   
                }

                // abcd % 10 = d 
                int d = abcd % 10 ;
                switch (d){
                    case 9:{
                        printf("IX");
                        break;
                    }
                    case 8:
                    case 7:
                    case 6:
                    case 5:{
                        printf("V");
                        for(int i = 0 ; i < (d-5) ; i++ ){
                            printf("I");
                        }
                        break;
                    }
                    case 4:{
                        printf("IV");
                        break;
                    }
                    default:{
                        for(int i = 0 ; i < d ; i++ ){
                            printf("I");
                        }
                        break;
                    }   
                }
            }   
        }       
    }
    // question 'a' end.

    // question 'b' begin.
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
    // question 'b' end.

    // question 'c' begin.
    while(1){
        printf("Please input a date (yyyy/mm/dd): ");
        int year , month , day ;
        scanf("%d/%d/%d", &year , &month , &day);
        if(year == month && month == day && day == 0){
            printf("Go to next question.\n\n");
            break;
        }

        // check if the date is legal.
        if (month < 1 || month > 12 ){
            printf("The month is wrong, input again!\n\n");
            continue;
        }
        if (day < 1 || day > 31 ){
            printf("The date is wrong, input again!\n\n");
            continue;
        }
        if((month == 4 || month == 6 ||month == 9 ||month == 11 ) && day > 30 ){
            printf("The date is wrong, input again!\n\n");
            continue;
        }
        if(((year % 4 == 0 ) && (year % 100 != 0 )) || (year % 400 == 0) ){
            if(month == 2 && day > 29 ){
                printf("The date is wrong, input again!\n\n");
                continue;
            }
        }
        else{
            if(month == 2 && day > 28 ){
                printf("The date is wrong, input again!\n\n");
                continue;
            }
        }

        int week ;  //表示當天是星期幾
        int all_day = 0 ; // 到前一年底的總天數是多少
        int i ;
        if(year == 1 ){
            week = 1 ; // 0001/01/01 is Monday.
        }
        else{
            // careful >> 'i' is start from 1 
            for(i = 1 ; i < year ; i++ ){
                if(((year % 4 == 0 ) && (year % 100 != 0 )) || (year % 400 == 0) ){
                    all_day += 366;
                }
                else{
                    all_day += 365;
                }
            }
            week = (all_day+1) % 7 ;

            printf("\n%04d/01/01 is " , year );
            if( week == 0 ){
                printf("Sunday.\n");
            }
            else if (week == 1 ){
                printf("Monday.\n");
            }
            else if (week == 2 ){
                printf("Tuesday.\n");
            }
            else if (week == 3 ){
                printf("Wednesday.\n");
            }
            else if (week == 4 ){
                printf("Thursday.\n");
            }
            else if (week == 5 ){
                printf("Friday.\n");
            }
            else if (week == 6 ){
                printf("Saturday.\n");
            }

            // 因為沒學過array , 所以接下來比較麻煩
            if(month == 2 ){
                all_day += 31 ;
            }
            else if (month == 3 ) {
                all_day += 31+28;
            }
            else if (month == 4 ) {
                all_day += 31+28+31;
            }
            else if (month == 5 ) {
                all_day += 31+28+31+30;
            }
            else if (month == 6 ) {
                all_day += 31+28+31+30+31;
            }
            else if (month == 7 ) {
                all_day += 31+28+31+30+31+30;
            }
            else if (month == 8 ) {
                all_day += 31+28+31+30+31+30+31;
            }
            else if (month == 9 ) {
                all_day += 31+28+31+30+31+30+31+31;
            }
            else if (month == 10 ) {
                all_day += 31+28+31+30+31+30+31+31+30;
            }
            else if (month == 11 ) {
                all_day += 31+28+31+30+31+30+31+31+30+31;
            }
            else if (month == 12 ) {
                all_day += 31+28+31+30+31+30+31+31+30+31+30;
            }


            // 如果用array 可以直接 day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
            // 然後用for迴圈去加到現在的前一個月總共有幾天
            // day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
            // int i = 0 ;
            // for(i = 2 ; i <= month ; i++ ){
            //     all_day += day[i-1];
            // }
            // if month = 5 , all_day += day[1] + day[2] + day[3] + day[4];

            if((((year % 4 == 0 ) && (year % 100 != 0 )) || (year % 400 == 0) ) && month > 2 ){
                all_day++;
            }
            week = (all_day+1) % 7 ;          
            printf("%04d/%02d/01 is " , year , month);


            if( week == 0 ){
                printf("Sunday.\n");
            }
            else if (week == 1 ){
                printf("Monday.\n");
            }
            else if (week == 2 ){
                printf("Tuesday.\n");
            }
            else if (week == 3 ){
                printf("Wednesday.\n");
            }
            else if (week == 4 ){
                printf("Thursday.\n");
            }
            else if (week == 5 ){
                printf("Friday.\n");
            }
            else if (week == 6 ){
                printf("Saturday.\n");
            }   


            all_day += day-1;
            week = (all_day+1) % 7 ;
            printf("%04d/%02d/%02d is " , year , month , day );
            if( week == 0 ){
                printf("Sunday.\n");
            }
            else if (week == 1 ){
                printf("Monday.\n");
            }
            else if (week == 2 ){
                printf("Tuesday.\n");
            }
            else if (week == 3 ){
                printf("Wednesday.\n");
            }
            else if (week == 4 ){
                printf("Thursday.\n");
            }
            else if (week == 5 ){
                printf("Friday.\n");
            }
            else if (week == 6 ){
                printf("Saturday.\n");
            }
        }
        printf("\n");
    }
    // question 'c' end.

    
    // question 'd' begin.
    while(1){
        printf("Please enter a pair of integers (M,N) : ");
        int M , N ;
        scanf(" (%d,%d)", &M , &N);
        if( M == 0 && M == N ){
            printf("Go to next question\n\n");
            break;
        }
        if(!(1 <= M && M <= 65535) || !(2 <= N && N <= 16)){
            printf("Wrong input, input again!\n\n");
            continue;
        }
        printf("%d in base %d system is ", M , N );
        int power = 0;
        int div = 1 ;
        while(div <= M ){
            div*= N ;
            power++;
        }
        power--;
        div /= N ;
        int i ; 
        for( i = power ; i >= 0 ; i--){
            int output = M / div ;
            M %= div;
            div /= N;
            if(output < 10 ){
                printf("%d", output );
            }
            else if (output == 10 ){
                printf("A");
            }
            else if (output == 11 ){
                printf("B");
            }
            else if (output == 12 ){
                printf("C");
            }
            else if (output == 13 ){
                printf("D");
            }
            else if (output == 14 ){
                printf("E");
            }
            else if (output == 15 ){
                printf("F");
            }
        }
        printf(".\n\n");
    }
    // question 'd' end.

    // question 'e' begin.
    while(1){
        printf("Please input a pair of string and integer: ");
        char a , b , c , d;
        int base ;
        scanf(" (%c%c%c%c,%d)", &a, &b, &c, &d, &base);
        if(a == b && b == c && c == d && a == '0'  && base == 0 ){
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
    // question 'e' end.

    // question 'f' begin.
    while(1){
        printf("Please input a number: ");
        double number ;
        scanf("%lf" , &number);
        if(number == 0 ){
            break;
        }
        if( number == (int)number ){
            printf("%d is an integer.\n\n", (int)number);
        }
        else{
            printf("%lf is a float-point number.\n\n", number);
        }
    }
    // question 'f' end.
}