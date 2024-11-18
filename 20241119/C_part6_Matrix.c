#include<stdio.h>

int main(){
    int row_A = 3 , col_A = 3 , row_B = 3 , col_B = 3 ;
    int A[3][3] = {{4,9,1},{1,4,4},{1,2,9}};
    int B[3][3] = {{1,2,3},{-4,7,4},{2,-5,1}};
    int result[3][3] = {};

    for(int i = 0 ; i < row_A ; i++ ){
        for(int j = 0 ; j < col_B ; j++  ){
            for(int k = 0 ; k < col_A ; k++ ){
                result[i][j] += A[i][k]*B[k][j];
            }
            printf("%d " , result[i][j]);
        }
        printf("\n");
    }
}
