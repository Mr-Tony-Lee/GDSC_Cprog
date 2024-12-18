#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student{
    int chinese;
    int english ;
    int math ;
    int physic;
    int social ;
}Node ; 

void swap(Node** p1 , Node** p2 ){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp = *p1 ;
    *p1 = *p2 ;
    *p2 = temp;
}

int sum (Node* array){
    return array->chinese+array->english+array->math+array->physic+array->social;
}

int main(){
    int i , j ;
    char string[20];
    memset(string,'\0' , 20);
    Node* array[10];
    for( i = 0 ; i < 10 ; i++ ){
        Node* temp = (Node* )malloc(sizeof(Node));
        array[i] = temp;
    }
    
    int count = 0 ; 
    while(fgets(string,20 , stdin) != NULL ){
        char t_c[4] , t_e[4] , t_m[4] , t_p[4] , t_s[4];
        memset(t_c , '\0' , 4 );
        memset(t_e , '\0' , 4 );
        memset(t_m , '\0' , 4 );
        memset(t_p , '\0' , 4 );
        memset(t_s , '\0' , 4 );

        int index = 0 ; 
        int k = 0 ;
        while(string[index] != ' ' && index < strlen(string)-1 ){
            t_c[k++] = string[index++];
        }
        index++;
        array[count]->chinese = atoi(t_c);

        k = 0 ;
        while(string[index] != ' ' && index < strlen(string)-1 ){
            t_e[k++] = string[index++];
        }
        index++;
        array[count]->english = atoi(t_e);

        k = 0 ;
        while(string[index] != ' ' && index < strlen(string)-1 ){
            t_m[k++] = string[index++];
        }
        index++;
        array[count]->math = atoi(t_m); 

        k = 0 ;
        while(string[index] != ' ' && index < strlen(string)-1 ){
            t_p[k++] = string[index++];
        }
        index++;
        array[count]->physic = atoi(t_p);

        k = 0 ;
        while(string[index] != ' ' && index < strlen(string)-1 ){
            t_s[k++] = string[index++];
        }
        index++;
        array[count]->social = atoi(t_s);
        count++;
    }
    for( i = 0 ; i < count ; i++ ){
        for( j = 0 ; j < count-1 ; j++ ){
            if(sum(array[j+1]) > sum(array[j])){
                swap(&array[j+1],&array[j]);
            }
        }
    }
    for( i = 0 ; i < count ; i++ ){
        printf("%d %d %d %d %d\n" , array[i]->chinese , array[i]->english , array[i]->math , array[i]->physic , array[i]->social );
    }
}