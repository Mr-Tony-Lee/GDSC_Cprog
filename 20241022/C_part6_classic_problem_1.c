#include<stdio.h>

int main(){
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
}