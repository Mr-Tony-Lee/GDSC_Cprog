#include<stdio.h>

int main(){
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
}