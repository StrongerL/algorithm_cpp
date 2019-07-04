#include <iostream>
using namespace std;

void cInput() {



}


/* 
    需要头文件<stdio.h> 或者 <iostream>

    %c	输出一个单一的字符

    %hd、%d、%ld	以十进制、有符号的形式输出 short、int、long 类型的整数
    %hu、%u、%lu	以十进制、无符号的形式输出 short、int、long 类型的整数
    %ho、%o、%lo	以八进制、不带前缀、无符号的形式输出 short、int、long 类型的整数
    %#ho、%#o、%#lo	以八进制、带前缀、无符号的形式输出 short、int、long 类型的整数
    %hx、%x、%lx
    %hX、%X、%lX	以十六进制、不带前缀、无符号的形式输出 short、int、long 类型的整数。如果 x 小写，那么输出的十六进制数字也小写；如果 X 大写，那么输出的十六进制数字也大写。
    %#hx、%#x、%#lx
    %#hX、%#X、%#lX	以十六进制、带前缀、无符号的形式输出 short、int、long 类型的整数。如果 x 小写，那么输出的十六进制数字和前缀都小写；如果 X 大写，那么输出的十六进制数字和前缀都大写。

    %f、%lf	以十进制的形式输出 float、double 类型的小数
    %e、%le
    %E、%lE	以指数的形式输出 float、double 类型的小数。如果 e 小写，那么输出结果中的 e 也小写；如果 E 大写，那么输出结果中的 E 也大写。
    %g、%lg
    %G、%lG	以十进制和指数中较短的形式输出 float、double 类型的小数，并且小数部分的最后不会添加多余的 0。如果 g 小写，那么当以指数形式输出时 e 也小写；如果 G 大写，那么当以指数形式输出时 E 也大写。

    %s	输出一个字符串

*/
void cOutput() {

    // 基本的输出 
    printf("hello, C output! \r\n");
    printf("\r\n");

    // 输出整数
    int a = 15;
    printf("输出整数a = %d\r\n", a);
    printf("输出两个整数 %d, %d\r\n", a, a);
    printf("8进制%o\r\n", a);
    printf("16进制%X\r\n", a);
    printf("\r\n");


    // 输出小数
    double d = 1.5;
    printf("输出小数d = %lf\r\n", d);




}


int main() {

    cOutput();


}