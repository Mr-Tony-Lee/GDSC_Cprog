#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void swap(int * a , int * b ){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

void question_a(){
    int i , j , k ;
    char string[8][5] = {"abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
    char string_s[102];

    while(fgets(string_s , 100 , stdin ) != NULL ){
        for( k = 0 ; k < strlen(string_s) - 1 ; k++ ){
            for( i = 0 ; i < 8 ; i++ ){
                for( j = 0 ; j < 5 ; j++ ){
                    if(string_s[k] == string[i][j] ){
                        printf("%c%d" , string_s[k], j+1 );
                    }
                }
            }
        }
        printf("\n");
    }
}

void question_b(){
    char input[1024+2];//\n\0
    char tempstr[1024+2];//\n\0
    double sum=0.0;
    int correct=0;
    int start,end;
    char op;

    while(fgets(input,1024+2,stdin)!=NULL){
        if(input[strlen(input)-1]=='\n'){
            input[strlen(input)-1]='\0';
        }
        sum=0.0;
        start=0,end=0;
        int i;
        while(end < strlen(input) && start < strlen(input)){
            for(i = start ; i < strlen(input) ; i++){
                if(input[i] == ' '){
                    end = i - 1 ;
                    break;
                }else if( i == strlen(input)-1){
                    end = i;
                    break;
                }
            }

            for(i = 0; i < 1024+2 ; i++){
                tempstr[i] = '\0';
            }
            for(i = start ; i <= end ; i++){
                int sizetemp = strlen(tempstr);
                tempstr[sizetemp] = input[i];
            }
            double temp = atof(tempstr);

            if(start-2 >= 0){
                op = input[start-2];
                if(op == '+'){
                    sum += temp;
                }else if(op == '-'){
                    sum -= temp;
                }else if(op == '='){
                    if(sum == temp){
                        correct++;
                        break;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                sum = temp;
            }
            start = end + 4;
        }
    }
    printf("Correct: %d\n",correct);  
}

void question_c(){
    int i , j , k ; 
    char string[130];

    while(fgets(string , 128 , stdin ) != NULL ){
        char answer[130];
        memset(answer , '\0' , 130);
        int k = 0 ;
        int count = 0 ;
        int state = 0 ;
        for ( i = 0 ; i < strlen(string) - 1 ; i++ ){
            if ( string[i] != ' '){
                answer[k] = string[i];
                k++ ;
                state = 1 ;
            }
            else{
                if(state == 0 ){
                    count ++ ;
                }
                else{
                    break;
                }
            }
        }
        int state2 = 0 ;
        int k_copy = k ;
        for( i = count + k_copy ; i < strlen(string)-1 ; i++ ){
            if( string[i] == ' ' && !state2 ){
                answer[k] = ' ';
                k++;
                state2 = 1 ;
            }
            else if ( string[i] != ' '){
                answer[k] = string[i];
                k++;
                state2 = 0 ;
            }
        }
        printf("%s\n" , answer);
    }
}

void question_d(){
    int i ;
    char string[42] ; 
    while( fgets(string , 40 , stdin ) != NULL  ){
        int index[42];
        char invalid[42] ; 
        int k = 0 ; 
        int fall = 0 ;
        int count = 0 ;
        int l = 0 ;
        char answer[42];
        memset( answer , '\0' , 42 );
        char string_number[42] ;
        memset( string_number , '\0' , 42 );
        for(i = 0 ; i < strlen(string)-1 ; i++ ){
            if( string[i] >= '0' && string[i] <= '9'){
                string_number[l] = string[i];
                l++;
            }
            else{
                invalid[k] = string[i];
                index[k] = i;
                fall = 1 ;
                count++;
                k++;
            }
        }
        if(!fall){
            printf("Parsing successfully: ");
        }
        else{
            for( i = 0 ; i < l ; i++ ){
                answer[i] = string_number[i];
            }
            printf("Panic: %d Error was detected.\n" , count ) ;
            printf("The input was following invalid character: \n");
            for( i = 0 ; i < count ; i++ ){
                printf("[%d] Position: %d, Invalid character: %c\n" , i+1 , index[i]+1 ,invalid[i] );
            }
            printf("Repaired result is ");
        }
        int state = 0 ; // 看是不是開頭的0
        for( i = 0 ; i < strlen(string_number) ; i++ ){
            if(string_number[i] != '0'){
                state = 1 ;
            }
            if(!state && string_number[i] >= '1') printf("%c" , string_number[i]);
            else if (state) printf("%c" , string_number[i]);
        }
        printf("\n");
        printf("---\n");
        fflush(stdin);
    } 
}

void bubble_descending ( int * array , int size ){
    int i , j ;
    for( i = 0 ; i < size ; i++ ){
        for( j = 0 ; j < size-1 ; j++ ){
            if(array[j] < array[j+1]){
                swap(&array[j] , &array[j+1]);
            }
        }
    }
}
void question_e(){
    int i , j ;
    int array[1026];
    while(1){
        int array1[1026] = {};
        for( i = 0 ; i < 1026 ; i++ ){
            array1[i] = -1;
        }
        int size = 0 ;
        int stop = 0 ;
        printf("Input Array: ");
        while(scanf("%d" , &array[size]) != EOF ){
            if ( array[size] == 0 && size == 0 ){
                stop = 1 ;
                printf("Finish!\n");
                break;
            }
            size++;
        }
        if(stop) break;
        for( i = 0 ; i < size ; i++ ){
            int prime = 1 ;
            for( j = 2 ; j < sqrt(array[i]) ; j++ ){
                if( array[i] % j == 0 ) {
                    prime = 0 ;
                    break;
                }
            }
            if(prime == 0 || array[i] == 1 ){
                array1[i] = array[i];
            }
        }
        bubble_descending(array,size);
        printf("Prime sorted Array: ");
        for( i = 0 ; i < size ; i++ ){
            int prime = 1 ;
            for( j = 2 ; j < sqrt(array[i]) ; j++){
                if(array[i] % j == 0 ){
                    prime = 0 ;
                    break;
                }
            }
            if(prime == 1 ){
                for( j = 0 ; j < size ; j++ ){
                    if(array1[j] == -1 ){
                        array1[j] = array[i];
                        break;
                    }
                }
            }
            printf("%d " , array1[i]);
        }
        printf("\n\n");
    }
}
void bubble (int *array,  int size ){
    int i , j ;
    for( i = 0 ; i < size ; i++ ){
        for( j = 0 ; j < size -1 ; j++ ){
            if(array[j] > array[j+1]){
                swap(&array[j] , &array[j+1]);
            }
        }
    }
}
void question_f(){
    while(1){
        int stop = 0 ;
        int array[1026] = {};
        int size = 0 ;
        while( scanf("%d" , &array[size]) != EOF) {
            if ( array[size] == 0 ){
                stop = 1 ;
                printf("Finish!\n");
                break;
            }
            size++;
        }
        if(stop) break;
        bubble(array,size);
        int left = 0 , right = size-1;
        int key = 10000;
        int min = 100000;
        int find = -1 ;
        int distance ;
        int number ;
        while(left <= right ){
            int middle = (left + right ) / 2 ;
            if ( array[middle] == key ){
                printf("%d\n" , key);
            }
            else if ( array[middle] < key ){
                left = middle+1;
            }
            else {
                right = middle-1;
            }
        }
        left = 0 , right = size-1;
        if( find == -1 ){
            while(left <= right ){
                int middle = (left+right) / 2 ;
                distance = abs( array[middle] - key );
                if ( distance <= min ){
                    min = distance;
                    number = array[middle];
                }
                if ( array[middle] < key ){
                    left = middle + 1 ;
                }
                else {
                    right = middle - 1 ;
                }
            }
            printf("%d\n" , number );
        }
    }
}

int main(){
    // question_a();
    // question_b();
    // question_c();
    // question_d();
    // question_e();
    // question_f();
}