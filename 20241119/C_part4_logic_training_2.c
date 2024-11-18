#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int i , j , N ;

void bubble_sort(){
    printf("Please enter the size of array: ");
    scanf("%d" , &N);

    int array[N];
    printf("Original array : ");
    for(i = 0 ; i < N ; i++ ){
        array[i] = rand() % 25; // 產生亂數介於0~24 >> rand()是產生亂數的函式，要有srand()
        printf("%d " , array[i] );
    }
    printf("\n");

    for( i = 0 ; i < N-1 ; i++ ){
        for( j = 0 ; j < N-1-i ; j++){
            if(array[j+1] < array[j]){
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp ;
            }
        }
    }

    printf("After sorting : ");
    for(i = 0 ; i < N ; i++ ){
        printf("%d " , array[i]);
    }
    printf("\n");
}

void selection_sort(){
    printf("Please enter the size of array: ");
    scanf("%d" , &N);

    int array[N];
    printf("Original array : ");
    for( i = 0 ; i < N ; i++ ){
        array[i] = rand() % 25;
        printf("%d " , array[i] );
    }
    printf("\n");

    for(i = 0 ; i < N-1 ; i++ ){
        int min = array[i];
        int min_index = i ; 
        for( j = i+1 ; j < N ; j++){
            if(array[j] < min ){
                min_index = j ; 
                min = array[j];
            }
        }
        int temp = array[i];
        array[i] = min ;
        array[min_index] = temp ;
    }


    printf("After sorting : ");
    for(int i = 0 ; i < N ; i++ ){
        printf("%d " , array[i]);
    }
    printf("\n");
}

void insertion_sort(){
    printf("Please enter the size of array: ");
    scanf("%d" , &N);

    int array[N];
    printf("Original array : ");
    for( i = 0 ; i < N ; i++ ){
        array[i] = rand() % 25;
        printf("%d " , array[i] );
    }
    printf("\n");

    for( i = 1 ; i < N ; i++ ){
        int temp = array[i];
        for( j = i-1 ; j >= 0 ; j-- ){
            if(temp < array[j]){
                array[j+1] = array[j];    
            }
            else{
                break;
            }
        }
        array[j+1] = temp;
    }

    printf("After sorting : ");
    for( i = 0 ; i < N ; i++ ){
        printf("%d " , array[i]);
    }
    printf("\n");
}

void Binary_search(){
    printf("Please enter the size of array: ");
    scanf("%d" , &N);

    int array[N];
    for( i = 0 ; i < N ; i++ ){
        array[i] = rand() % 25;
    }

    for( i = 0 ; i < N ; i++ ){
        for(j = 0 ; j < N-1; j++ ){
            if( array[j+1] < array[j]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp ;
            }
        }
    }

    printf("After sorting : ");
    for( i = 0 ; i < N ; i++ ){
        printf("%d " , array[i]);
    }
    printf("\n");

    int search ;
    printf("Input number : ");
    scanf("%d" , &search);

    int left = 0 , right = N-1 ;
    while(left < right ){
        int middle = (left+right)/2 ;
        if(array[middle] == search){
            printf("Find %d in array at position %d\n" , search , middle);
            return ;
        }
        else if ( search > array[middle] ){
            left = middle+1 ; 
        } 
        else{
            right = middle-1 ;
        }
    }
    printf("Not found.");
}

int main(){
    srand(time(NULL));
    bubble_sort();
    selection_sort();
    insertion_sort();
    Binary_search();
}