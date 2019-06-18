/**
 * ASCII（American Standard Code for Information Interchange，美国信息互换标准代码），一种8位的编码方案来表示所有的大小写字母、数字、标点符号和控制字符，目前共定义了128个字符（0 - 127共128个标准ASCII码，128 - 255是扩展字符）。大多数计算机使用ASCII码作为字符的编码方案。
 * 常用的ASCII码
 * '0' - '9'    48 - 57
 * 'A' - 'Z'    65 - 90
 * 'a' - 'z'    97 - 122
 * 
 * 常用的转义字符
 * '\n'     换行符
 * '\r'     回车符
 * '\t'     制表符
 * '\"'     双引号
 * '\\'     反斜线
 * 
 */

#include <iostream>
using namespace std;

// 字符的基本操作
void testBase() {
 
    cout << "字符的赋值可以使用单引号包含字符，或者直接使用整数或者浮点数（会首先自动截取为整数），" << endl;
    cout << "如果使用整数，那么字符的值为整数对应的ASCII字符，如果整数的值超过了8位（2进制），那么截取低8位" << endl;
    // 疑问：如果低8位的值超过了127呢？
    // 回答：127 - 255的部分是扩展ASCII字符集
    char c = 'a';
    cout << c << endl;
    c = 122;
    cout << c << endl;
    c = 97.6;
    cout << c << endl;
    c = 0xff61; // 16进制，低八位为0x61，也就是10进制的97，对应'a'
    cout << c << endl;
    cout << endl;

    cout << "字符的自增与自减，转换成相邻的字母" << endl;
    char c0 = 'b';
    cout << ++c0 << endl;
    cout << --c0 << endl;
    cout << endl;

    cout << "字符之间的运算，会自动转成字符对应的ASCII码值之间的运算" << endl;
    char c1 = 'a';
    char c2 = 'b';
    cout << (c1 > c2) << endl;
    cout << (c1 == c2) << endl;
    cout << (c1 < c2) << endl;
    cout << (c1 - c2) << endl;
    cout << (c1 + c2) << endl;
    cout << (c1 * c2) << endl;
    cout << endl;

    cout << "字符与数值之间的运算，自动转换成字符对应的ASCII码值与数值之间的运算" << endl;
    char c3 = 'a' + 2; // 首先转换为 97 + 2，然后c3 = 97
    cout << c3 << endl;
    int i = 'a' + 2;
    cout << i << endl;
    double d = 'a' + 0.5;
    cout << d << endl;
    cout << endl;

}

// 关于字符的函数
void testFunction() {
    // 需要头文件<cctype>
    char c = 'c';
    char C = 'C';
    char i = '1';
    char b = ' ';

    cout << "isdigit(char c) 判断是否为数字" << endl;
    cout << isdigit(c) << endl;
    cout << isdigit(C) << endl;
    cout << isdigit(i) << endl;
    cout << isdigit(b) << endl;
    cout << endl;

    cout << "isalpha(char c) 判断是否为字母" << endl;
    cout << isalpha(c) << endl;
    cout << isalpha(C) << endl;
    cout << isalpha(i) << endl;
    cout << isalpha(b) << endl;
    cout << endl;

    cout << "isalnum(char c) 判断是否为字母或者数字" << endl;
    cout << isalnum(c) << endl;
    cout << isalnum(C) << endl;
    cout << isalnum(i) << endl;
    cout << isalnum(b) << endl;
    cout << endl;

    cout << "islower(char c) 判断是否为小写字母" << endl;
    cout << islower(c) << endl;
    cout << islower(C) << endl;
    cout << islower(i) << endl;
    cout << islower(b) << endl;
    cout << endl;

    cout << "isupper(char c) 判断是否为大写字母" << endl;
    cout << isupper(c) << endl;
    cout << isupper(C) << endl;
    cout << isupper(i) << endl;
    cout << isupper(b) << endl;
    cout << endl;

    cout << "isblank(char c) 判断是否为空" << endl;
    cout << isblank(c) << endl;
    cout << isblank(C) << endl;
    cout << isblank(i) << endl;
    cout << isblank(b) << endl;
    cout << endl; 

    cout << "tolower(char c) 返回字符的小写形式对应的ASCII码值，非字母的字符返回其ASCII码值" << endl;
    cout << tolower(c) << endl;
    cout << tolower(C) << endl;
    cout << tolower(i) << endl;
    cout << tolower(b) << endl;
    cout << endl;

    cout << "toupper(char c) 返回字符的大写形式对应的ASCII码值，非字母的字符返回其ASCII码值" << endl;
    cout << toupper(c) << endl;
    cout << toupper(C) << endl;
    cout << toupper(i) << endl;
    cout << toupper(b) << endl;
    cout << endl;

    cout << "iscntrl(char c) 判断是否为控制字符，控制字符是不占据显示器上的打印位置的字符，即ASCII代码0x00（NUL）和0x1f（US）之间的字符加上0x7f（DEL）" << endl << endl;

    cout << "isprint(char c) 判断是否为可打印字符，打印字符都具有大于0x1f（US）的ASCII码，但0x7f（DEL）除外。" << endl << endl;

    cout << "isgraph(char c) 判断是否为除了空格' '之外的可打印字符" << endl << endl;

    cout << "ispunct(char c) 判断是否为标点符号" << endl << endl;
    
    cout << "isspace(char c) 判断是否为空字符" << endl << endl;

    cout << "isxdigit(char c) 判断是否为16进制数字，包括0 1 2 3 4 5 6 7 8 9 a b c d e f A B C D E F" << endl << endl;

}


int main() {

    // 字符的基本操作
    // testBase();

    // 关于字符的函数
    testFunction();

}
