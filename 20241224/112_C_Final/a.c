#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int GCD (int x , int y ){
    if( x % y == 0 ){
        return y ;
    }
    
    if ( x > y ){
        return GCD (y , x % y );
    }
    else{
        return GCD(x , y % x );
    }
}

int main(){
    FILE * f = fopen("GCD.txt" , "r");  // 注意路徑，每個人放檔案的位置不一樣
    int x , y ;
    char string[20];
    while(fgets( string , 20 , f) != NULL ){
        int i = 0 ;
        char temp1[4] , temp2[4];
        while(string[i] != ' '){
            temp1[i] = string[i];
            i++;
        }
        i++;    // ' '
        while( i < strlen(string)){
            temp2[i-4] = string[i];
            i++;
        }
        x = atoi(temp1);
        y = atoi(temp2);
        printf("The GCD of (%d, %d) is %d.\n", x , y , GCD(x,y));
    }
}