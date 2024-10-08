#include<stdio.h>
#include<math.h>

int main(){

    // PPT Page 4 ~ 16 

    int number_i = 20241022 ;   
    long number_l = 20241022 ;  
    long long number_ll = 20241022;
    unsigned int number_u = 20241022;
    unsigned long number_ul = 20241022;
    unsigned long long number_ull = 20241022; 
    printf("Integer : %d.\n", number_i);            //輸出int
    printf("long int : %ld.\n", number_l);          //輸出long int 
    printf("long long : %lld.\n", number_ll);       //輸出long long 
    printf("unsigned int : %u.\n", number_u);       //輸出unsigned int 
    printf("unsigned long : %lu.\n", number_ul);    //輸出unsigned long 
    printf("unsigned long long : %llu.\n", number_ull); //輸出unsigned long long

    printf("\n-------------------------------------------------------------\n\n");

    int positive_decimal = 11  , negative_decimal = -11;
    printf("The decimal number is : %d. \n" , positive_decimal );       //輸出integer 
    printf("The decimal number is : %5d. \n" , positive_decimal );      //保留5格輸出integer，向右對齊
    printf("The decimal number is : %05d. \n" , positive_decimal );     //保留5格輸出integer，數字位數小於5補零
    printf("The decimal number is : %+5d. \n" , positive_decimal );     //保留5格輸出integer，如果數字大於0就輸出+
    printf("The decimal number is : %+5d. \n" , negative_decimal );     //保留5格輸出integer，如果數字大於0就輸出+
    printf("The decimal number is : %-5d. \n" , positive_decimal );     //保留5格輸出integer，向左對齊
    printf("The decimal number is : %.5d. \n" , positive_decimal );     //如果數字位數小於5就自動補零
    printf("The decimal number is : %10.5d. \n" , positive_decimal );   //保留10格輸出integer，如果數字位數小於5就自動補零
    printf("The decimal number is : %+10.5d. \n" , positive_decimal );  //保留10格輸出integer，如果數字位數小於5就自動補零，如果數字大於0就輸出+
    printf("The decimal number is : %10.5d. \n" , negative_decimal );   //保留10格輸出integer，如果數字位數小於5就自動補零
    printf("The decimal number is : %-10.5d. \n" , positive_decimal );  //保留10格輸出integer，如果數字位數小於5就自動補零，向左對齊
    
    printf("\n-------------------------------------------------------------\n\n");

    float pi_f = 3.14159265359;     //單精度浮點數
    double pi_d = 3.14159265359;    //雙精度浮點數  精度、範圍較高
    printf("Float  pi : %f.\n" , pi_f );    //預設輸出小數點後6位 ， 最後會自己四捨五入
    printf("Double pi : %lf.\n" , pi_d);
    printf("Float  pi^2 : %f.\n" , pi_f * pi_f);
    printf("Double pi^2 : %lf.\n", pi_d * pi_d);
    
    printf("\n-------------------------------------------------------------\n\n");

    printf("%%.f : %.f\n" , pi_f);                  //因為小數點後沒數字，只輸出整數部分  
    printf("%%.0f : %.f\n" , pi_f);                 //因為.0f，只剩整數部分，會對小數點後第一位四捨五入
    printf("%%12f : %12f\n" , pi_f ) ;              //保留12格輸出float 
    printf("%%012f : %012f\n" , pi_f ) ;            //保留12格輸出float，不到12格就補0
    printf("%%-12f : %-12fend.\n" , pi_f ) ;        //保留12格輸出float，向左對齊 
    printf("%%5.f : %5.f\n" , pi_f);                //保留5格，因為.f，只輸出整數部分
    printf("%%.4f : %.4f\n" , 3.14);                //只輸出小數點後4個位數
    printf("%%.4f : %.4f\n" , pi_f);                //只輸出小數點後4個位數
    printf("%%.8f : %.8f\n" , pi_f);                //輸出小數點後8個位數(float)
    printf("%%.8lf : %.8lf\n" , pi_d);              //輸出小數點後8個位數(double) 
    
    printf("\n-------------------------------------------------------------\n\n");
    
    int int_A = 65 ;                                                // ascii code 65 = 'A' ， 要背65('A') + 26 , 97('a') + 26 , 48('0') + 10 
    char char_A = 'A';
    char char_array[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("Output character : %c.\n" , int_A ) ;                   // 輸出 A ， 會自動轉成char，因為%c
    printf("Output character : %c.\n" , 'A' ) ;                     // 輸出 A
    printf("Output character : %c.\n" ,  char_A ) ;                 // 輸出 A
    printf("Output character : %c.\n" ,  char_array[0] ) ;          //字元陣列裡面的每一個元素都是char
    printf("Output character : %5c.\n" , 'A');                      //保留5格
    printf("Output character : %-5c.\n" , 'A');                     //保留5格，向左對齊
    printf("Output string : %s.\n" , char_array);                   //輸出字串
    printf("Output string : %s.\n" , &char_array[0]);               //字串本身的位置就是字串第0個元素的位置
    printf("Output string : %29s.\n", char_array);                  //保留29格
    printf("Output string : %29.25s.\n", char_array);               //保留29格，最多輸出25個字元
    printf("Output string : %-29.25s.\n", char_array);              //保留29格，最多輸出25個字元，並向左對齊
    printf("Output string : %29.*s.\n", 25 ,char_array);            //可以用*代替25，只是在後面要告訴系統*是多少

    printf("\n-------------------------------------------------------------\n\n");
}
