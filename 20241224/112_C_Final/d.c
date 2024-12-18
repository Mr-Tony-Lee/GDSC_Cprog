#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student{
    int ID ;
    char name[11];
    int chi ;
    int eng ;
    int math ;
}Node;

void swap(Node** p1 , Node** p2 ){
    //我要交換兩個Node的指標，不是交換值，所以是雙層指標，然後temp也是指標
    Node* temp = (Node *)malloc(sizeof(Node));  
    temp = *p1; // 指向p1的，現在 temp 也指向p1
    *p1 = *p2;  // 然後把 p1 指向 p2 
    *p2 = temp; // 最後再把 p2 指向 temp 指向的地方
}


void bubblesort(int size , Node ** array , int type){
    int i ; 
    if(size == 1 ) return ;
    else {
        for ( i = 0 ;  i < size-1 ; i++ ){
            if(type == 1 ){
                if(array[i]->ID > array[i+1]->ID ){
                    swap(&array[i] , &array[i+1]);
                }
            }
            else if ( type == 2 ){
                if(strcmp(array[i]->name ,array[i+1]->name) > 0  ){ 
                    // 大於0 是前面的大
                    swap(&array[i], &array[i+1]);
                }
            }
            else if ( type == 3 ){
                if(array[i]->chi < array[i+1]->chi ){
                    swap(&array[i] , &array[i+1]);
                }
            }
            else if ( type == 4 ){
                if(array[i]->eng < array[i+1]->eng ){
                    swap(&array[i] , &array[i+1]);
                }
            }
            else if ( type == 5 ){
                if(array[i]->math < array[i+1]->math ){
                    swap(&array[i] , &array[i+1]);
                }
            }
        }
    }
    bubblesort(size-1 , array , type);
}

int main(){
    int i ;
    FILE* f = fopen("Student.txt" , "r");

    char string[100];
    memset(string, '\0' , 100);

    Node* array[20];
    for(i = 0 ; i < 20 ; i++ ){
        array[i] = (Node* )malloc (sizeof(Node));
    }

    int count = 0; // 計算讀入幾筆

    while(fgets(string , 100 , f) != NULL ){
        int k = 0 ; // 用來跑每個 temp 的 index
        int index = 0 ; // 用來跑 string 的 index 

        char temp_id[6];
        memset(temp_id , '\0' , 6); // 初始化陣列
        k = 0 ;
        while(string[index] != ' '){
            temp_id[k++] = string[index++];
        }
        array[count]->ID = atoi(temp_id);
        index++;

        char temp_name[15] ; 
        memset(temp_name , '\0' , 15);  // 其他memset可以不用，但這個一定要
        k = 0 ;
        while(string[index] != ' '){
            temp_name[k++] = string[index++];
        }
        strcpy(array[count]->name , temp_name);
        index++;
        
        char temp_chi[4] ;
        k = 0 ;
        memset(temp_chi , '\0' , 4); 
        while(string[index] != ' '){
            temp_chi[k++] = string[index++];
        }
        array[count]->chi = atoi(temp_chi);
        index++;

        char temp_eng[4] ;
        k = 0 ;
        memset(temp_eng , '\0' , 4); 
        while(string[index] != ' '){
            temp_eng[k++] = string[index++];
        }
        array[count]->eng = atoi(temp_eng);
        index++;

        char temp_math[4] ;
        k = 0 ;
        memset(temp_math , '\0' , 4);
        while(string[index] != ' '){
            temp_math[k++] = string[index++];
        }
        array[count]->math = atoi(temp_math);
        index++;
        count++;
    }
    printf("%6s%12s%5s%5s%5s\n" , "ID" , "Name" , "Chi" , "Eng" , "Math");
    for( i = 0 ; i < 20 ; ++i ){
        printf("%6d%12s%5d%5d%5d\n" , array[i]->ID , array[i]->name , array[i]->chi 
                                    , array[i]->eng , array[i]->math );
    }

    while(1){
        printf("Choose sorting method\n");
        printf("1. ID 2. Name 3.Chinese 4.English 5.Math 6.Exit: ");
        int choice ;
        scanf("%d", &choice );
        if(choice >= 1 && choice <= 5 ){
            bubblesort(count , &array ,choice );
        }
        else if (choice == 6){
            break;
        }
        else{
            printf("Invalid input, input again!\n");
            continue;
        }
        printf("%6s%12s%5s%5s%5s\n" , "ID" , "Name" , "Chi" , "Eng" , "Math");
        for( i = 0 ; i < 20 ; ++i ){
            printf("%6d%12s%5d%5d%5d\n" , array[i]->ID , array[i]->name , array[i]->chi 
                                        , array[i]->eng , array[i]->math );
        }
    }
}