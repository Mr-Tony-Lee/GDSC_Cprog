#include<stdio.h>

int main(){
    
    // syntax of if/else  
    /*
        if(boolean_expression_1){
            當第一個表達式為真時會執行
        }
        else if( boolean_expression_2){
            當第二個表達式為真時會執行
        }
        else {
            當上面都不為真時會執行
        }
    */
    
    // int a = 5 , b = 10 ; 
    // if( a < b ){
    //     printf("a = %d , b = %d , a is less than b.\n", a , b );
    // }
    // else if ( a > b ){
    //     printf("a = %d , b = %d , a is larger than b.\n", a , b);
    // }
    // else{
    //     printf("a = %d , b = %d , a is equal to b.\n" , a , b );
    // }

    // syntax of switch 
    /*
        switch(變數名稱或運算式) {
            case 符合數字或字元:
                陳述句一;
                break;  // break is necessary!!!
            case 符合數字或字元:
                陳述句二;
                break;
            default:    //當以上都不符合時，就會執行default的內容
                陳述三;
                break;  
        }
    */
    // int variable = 1 ; 
    // switch(variable){
    //     case 1:
    //         printf("variable is : 1.\n");
    //         break;
    //     case 2:
    //         printf("variable is : 2.\n");
    //         break;
    //     default:
    //         printf("variable is : %d.\n", variable);
    // }

    int a = 5 , b = 10 ;  
    switch( a > b ){
        case (1) :
            printf("a = %d , b = %d , a is larger than b.\n", a , b );
            break;
        case (0) :
            switch (a == b){
                case(1):
                    printf("a = %d , b = %d , a is equal to b.\n", a , b );
                    break;
                case(0):
                    printf("a = %d , b = %d , a is less than b.\n", a , b );
                    break;
            }
            break;
    }
}