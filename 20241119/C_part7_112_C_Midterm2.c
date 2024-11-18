#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

void question_a(){
    while(1){
        int i , j , k ;
        char string[101];
        printf("Please input a string: ");
        gets(string);
        int len = strlen(string);
        int illegal = 0 ;
        for( i = 0 ; i < len ; i++ ){
            if(!((string[i] >= 'A' && string[i] <='Z') || (string[i] >= 'a' && string[i] <= 'z'))){
                printf("The string includes illegal character!\n");
                illegal = 1 ;
                break;
            }
        }
        if(illegal) continue;

        int ascii[26] = {};
        for( i = 0 ; i < len ; i++ ){
            if(string[i] <= 'Z') ascii[string[i]-'A']++;
            else ascii[string[i]-'a']++;
        }
        printf("\n\nCount result:\n");
        for( i = 0 ; i < 26 ; i++ ){
            printf(" %c : %d " , 65+i , ascii[i]);
            if( (i + 1) % 6 == 0 ){
                printf("\n");
            }
        }
        printf("\n\n");
    }
}
void question_b(){
    int map[15][15] = {};
    map[0][0] = 1 ;
    int i , j ;
    for(i = 0 ; i < 15 ; i++ ){
        map[i][0] = 1 ;
        map[i][i] = 1 ;       
        for(j = 1 ; j < i ; j++ ){
            map[i][j] = map[i-1][j-1] + map[i-1][j];
        }
    }
    while(1){
        long long  N ; 
        printf("Please input a layer number :");
        scanf("%lld" , &N);
        if(!( N <= 15 && N >= 0 )){
            printf("Wrong input, input again!");
            continue;
        }
        for( i = 0 ; i < N ; i++ ){
            for( j = i ; j < N-1 ; j++ ){
                printf("%5c" , ' ');
            }
            for( j = 0 ; j <= i ; j++ ){
                printf("%5d%5c" , map[i][j] , ' ');
            }
            printf("\n");
        }
    }
}

void swap(int *a , int *b ){    // Pointer ， 傳入的a , b 是位址(address )
    int temp = *a ;           // 用Pointer swap 的話，會直接改變 a , b 位址上的值
    *a = *b ;                   // *a 代表的是 a 的值 
    *b = temp ;
}

void question_c(){  
    int i , j , k ; 
    while(1){
        srand(time(NULL));
        int size; 
        printf("Please input hte length: ");
        scanf("%d" , &size);
        int array[size];
        if(!(size >= 1 && size <= 25 )){
            printf("Wrong input, input again!\n\n");
            continue;
        }
        printf("Original array: \n");
        for( i = 0 ; i < size ; i++ ){
            array[i] = rand() % 199 - 99 ; // max -99 ~ 99 
            printf("%4d" , array[i]);
        }
        printf("\n\nSelect sorting method 1. insertion sort 2. selection sort : ");
        int type;
        scanf("%d" , &type);
        if( type == 1 ){    // insertion
            for( i = 1 ; i < size ; i++ ){
                int temp = array[i];
                for( j = i - 1 ; j >= 0 ; j-- ){
                    if(temp < array[j]){
                        array[j+1] = array[j];
                    }
                    else break;
                }
                array[j+1] = temp ;
            }
        }
        else{
            for( i = 0 ; i < size-1 ; i++ ){
                int min = array[i] , min_index = i ;
                for( j = i+1 ; j < size ; j++ ){
                    if( array[j] < min ){
                        min = array[j];
                        min_index = j ;
                    }
                }
                swap(&array[i] , &array[min_index]);    //如果不會的話，可以先看看註解，看完還是不會，那就用上課教的寫法
            }
        }
        printf("\n\nAfter sorted: \n" );
        for( i = 0 ; i < size ; i++ ){
            printf("%4d" , array[i]);
        }
        while(1){
            printf("\nPlease input a number to search: ");
            int key ;
            scanf("%d" , &key);
            if(key == 100 ){
                printf("Return to the beginning.\n\n");
                break;
            }
            int left = 0 , right = size-1;
            int find = -1 ;
            while(left  <= right){
                int middle = (left + right) /2 ;
                if( array[middle] == key ){
                    printf("%d is No.%d element in array.\n\n" , key , middle );
                    find = 1 ;
                    break;
                }
                else if (key < array[middle]){
                    right = middle - 1 ;
                }
                else{
                    left = middle + 1 ;
                }
            }
            if(find == -1 ){
                printf("%d is not element in array.\n\n", key );
            }
        }
    }
}

void question_d(){
    while(1){
        int i , j , k ;
        int Image[5][5] = {{8,-9,-7,-5,-1} , {7,5,6,-3,-9}, {-7,8,-6,-8,6}, {-2,-9,-10,4,-7} , {4,5,-7,5,-5}}; 
        for( i = 0 ; i < 5 ; i++){
            for( j = 0 ; j < 5 ; j++ ){
                printf("%4d" , Image[i][j]);
            }
            printf("\n");
        }
        int filter1[3][3] = { {0,0,0} , {0,1,0} , {0,0,0}};
        int filter2[3][3] = { {-1,0,1} , {-1,0,1} , {-1,0,1}};
        int filter3[3][3] = { {-1,-1,-1} , {-1,8,-1} , {-1,-1,-1}};
        while(1){
            int type ;
            printf("Please select a filter: ");
            scanf("%d" , &type);
            int use_filter[3][3] ;
            if ( type > 3 || type < 1 ){
                printf("Please select from 1 to 3.\n\n");
                continue;
            }
            else if( type == 1 ){
                printf("Filter 1 : \n");
                for(i = 0 ; i < 3 ; i++ ){
                    for( j = 0 ; j < 3 ; j++ ){
                        use_filter[i][j] = filter1[i][j];
                        printf("%4d", use_filter[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else if (type == 2 ){
                printf("Filter 2 : \n");
                for(i = 0 ; i < 3 ; i++ ){
                    for( j = 0 ; j < 3 ; j++ ){
                        use_filter[i][j] = filter2[i][j];
                        printf("%4d", use_filter[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else {
                printf("Filter 3 : \n");
                for(i = 0 ; i < 3 ; i++ ){
                    for( j = 0 ; j < 3 ; j++ ){
                        use_filter[i][j] = filter3[i][j];
                        printf("%4d", use_filter[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            int Feature[3][3] ; 
            int left = 0 , down = 0 ; 
            while( !(left == 0 && down == 3 )){
                int sum = 0 ;
                int result[3][3] = {};
                for( i = 0 ; i < 3 ; i++ ){
                    for( j = 0 ; j < 3 ; j++ ){
                        result[i][j] += Image[i+down][j+left] * use_filter[i][j];
                        sum += result[i][j];
                    }
                }
                Feature[down][left] = sum;
                left++;
                if(left == 3 ){
                    left = 0 ; 
                    down++;
                }
            }
            printf("Result:\n");
            for( i = 0 ; i < 3 ; i++ ){
                for( j = 0 ; j < 3 ; j++ ){
                    printf("%4d" , Feature[i][j]);
                }
                printf("\n");
            }
        }
    }
}

void question_e(){
    int times = 1 ;
    while(times){
        int i , j  ;
        int array[15];
        printf("Original array: \n");
        for( i = 0 ; i < 15 ; i++ ){
            array[i] = rand() % 21 - 10 ;
            printf("%d ",array[i]);
        }

        printf("\n\nResult: \n");
        
        int replace , replace_index ;
        for( i = 0 ; i < 15-1 ; i++ ){
            replace = array[i] ; 
            replace_index = i ;
            for( j = i+1 ; j < 15 ; j++ ){
                if( i % 2 == 1 ){ // 如果現在要放的是1 , 3 , 5 , 7 ... >> 放最小值
                    if(array[j] < replace ){
                        replace = array[j];
                        replace_index = j ; 
                    }
                }
                else{       // 如果現在要放的是0,2,4,6,8,.... >> 放最大值
                    if(array[j] > replace){
                        replace = array[j];
                        replace_index = j ;
                    }
                }
            }
            swap(&array[i] , &array[replace_index]);
            printf("%d " , array[i]);
        }
        printf("%d\n" , array[i]);       
        fflush(stdin);
        char stop_a_while ; //為了讓迴圈停下來，所以加一個scanf
        scanf("%c" , &stop_a_while);
    }
}

void question_f(){
    char string[101] = "";
    printf("Please input a string :");
    //scanf("%s", input );
    fgets(string , 101 , stdin);     
    string[strlen(string)-1] = '\0'; // 吃掉\n
    int left = 0 , right = strlen(string)-1;
    while(left < right ){
        if(string[left] != string[right]){
            printf("%s is not a palindrome.\n" , string);
            return;
        }
        left++;
        right--;
    }
    printf("%s is a palindrome.\n" , string);
}

int main(){
    srand(time(NULL));
    // question_a();
    // question_b();
    // question_c();
    // question_d();
    question_e();
    // question_f();
}