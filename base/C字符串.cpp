#include <iostream>
#include <cstring>
using namespace std;

void base() {
    // 自动在尾部添加'\0'
    char s1[] = "hello";
    // 不要使用这种方式，末尾不会添加'\0'，会出现许多问题
    char s2[] = {'h', 'e', 'l', 'l', 'o'};
    // 可以使用这种方式
    char s3[] = {'h', 'e', 'l', 'l', 'o', '\0'}; 
    // 必须要为末尾的'\0'留出一个位置
    char s4[6] = "hello";

    cout << s1 << " " << strlen(s1) << endl;
    cout << s2 << " " << strlen(s2) << endl;
    cout << s3 << " " << strlen(s3) << endl;
    cout << s4 << " " << strlen(s4) << endl;

}


void input() {
    char s[3];
    // 输入方式1
    // cin.getline(char array[], int size, char delimitChar)，第三个参数默认为'\n'
    // 直到输入了size - 1个字符或者遇到终结字符停止输入，最后一个字符如果不是'\0'会被其替换
    cin.getline(s, 10, '\n');
    cout << s << endl;

    // 输入方式2，输入长度超出范围会自动扩充
    cin >> s;
    cout << s << " " << strlen(s) << endl;
    cout << endl;

}

// 操作函数之前要自己保证空间足够，不越界
// 在<cstring>头文件中
void functions1() {

    char s1[10] = "123";
    char s2[10] = "136";

    // 返回s1长度
    cout << strlen(s1) << endl;
    cout << endl;

    // 将s2复制到s1中，s1 = "126"会报错
    strcpy(s1, s2);
    cout << s1 << endl;
    strcpy(s1, "123");
    // 将s2的前2位复制到s1的前2位，如果s2的第二位是'\0'，也会复制
    strncpy(s1, s2, 2);
    cout << s1 << endl;
    strncpy(s1, "1234", 3);
    cout << endl;

    // 将S2拼接到s1上
    strcat(s1, s2);
    cout << s1 << endl;
    strcpy(s1, "123");
    // 将s2的前2位拼接到s1上
    strncat(s1, s2, 2);
    cout << s1 << endl;
    strcpy(s1, "123");
    cout << endl;

    // 比较s1和s2，s1大于、等于、小于s2分别返回正数、0、负数
    cout << strcmp(s1, s2) << endl;
    // 比较s1的前2位和s2的前2位，s1的前2位大于、等于、小于s2的前2位分别返回正数、0、负数
    cout << strncmp(s1, s2, 2) << endl;
    cout << endl;

    // 返回10进制100的16进制表示，不知道为什么会重复一次？？？
    char s[100];
    cout << itoa(100, s, 10);
    cout << s << endl;
}


void functions2() {

    // 返回字符串的int值，直到遇到不是数字的字符或者到了字符串尾部，第一个字符不是数字返回0
    char s1[] = "10";
    cout << -1 * atoi(s1) << endl;
    cout << endl;

    // 返回字符串的double值
    char s2[] = "10.4";
    cout << -1 * atof(s2) << endl;
    cout << endl;

    // 返回字符串对应的long值
    char s3[] = "111";
    cout << -1 * atol(s3) << endl;
    cout << endl;

}


int main() {

    // base();

    // input();

    // functions1();

    functions2();

}