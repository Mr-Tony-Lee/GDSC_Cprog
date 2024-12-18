#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int judge_set(int* array){  
    int i = 0 , j;
    int ans = 0 ; 
    for( j = 0 ; j < 16 ; j++ ){    // 因為一定沒有2組三個的 ，所以可以先把3個的拿起來
        if(array[j] >= 3 ){
            ans++;
            array[j] -=3 ; 
        }
    }
    while(i < 7 ){  // 拿起來後，在跑順子的set
        while(array[i] >= 1 && array[i+1] >= 1 && array[i+2] >= 1 ){
            array[i]--;
            array[i+1]--;
            array[i+2]--;
            ans++;
        }
        i++;
    }
    return ans ;
}

int main(){
    char S[17] = "123456789ABCDEFG";
    char input[1025];
    memset(input,'\0' , 1025);
    while(fgets(input , 1024 , stdin) != NULL ){
        if(strlen(input) != 8 ) {   // 加上\n，要剛好等於8
            printf("-1\n\n");
            continue;
        }
        int i , j , k ; 
        int appear[16] = {0}; 
        int state = 1 ;     
        for( i = 0 ; i < strlen(input)-1 ; i++ ){
            for( j = 0  ; j < 16 ; j++ ){   // 迴圈跑過全部S
                if(S[j] == input[i]){   // 如果有出現在S裡面，就記錄，然後跳出
                    appear[j]++;
                    break;
                }
                if(appear[j] > 4 ){
                    state = 0 ;
                    break;
                }
            }
            if( j == 16 ) state = 0 ;   // 如果在中途都沒跳出， j會等於16，代表字不在裡面
        }
        if(!state ){
            printf("-1\n\n");
            continue;
        }
        //判斷是否再一張能胡牌，就是用我手上的排去組合，跑過16張牌就好了
        int count = 0 ; 
        int ans[16] = {0};
        for( i = 0 ; i < 16 ; i++ ){
            int ready = 0 ; 
            // 以下是判斷 先把eye 拿掉，再看有沒有set 
            // eye拿掉，就一定不會有兩組3個一樣的 像4445666 + 4 >> 44445666 >> eye拿掉 >> 445666 或 444456
            for( k = 0 ; k < 16 ; k++ ){
                int copy_appear[16];
                for( j = 0 ; j < 16 ; j++ ){
                    copy_appear[j] = appear[j];
                }
                copy_appear[i]++;   // 多放一個進去 
                if( copy_appear[k] >= 2 ){  // 如果大於2 那就試試看當eye 
                    copy_appear[k] -= 2 ;   
                    if(judge_set(copy_appear) == 2 ){
                        ready = 1 ;
                        break;
                    }
                }
            }
            if(ready ){
                ans[i]++;
                count++;
            }
        }
        if(count){
            printf("Ready for ");
            for( i = 0 ; i < 16 ; i++ ){
                if(ans[i]){
                    printf("%c ",S[i]);
                }
            }
            printf("\n\n");
        }
        else{
            printf("-1\n");
        }
    }
}