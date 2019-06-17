/*

    进制转换

    被除数  dividend
    除数    divisor
    商      quotient
    余数    remainder

    参考网页： https://blog.csdn.net/sjf0115/article/details/8690581?utm_source=copy

    练习：
    operatingExamination\2019053101_10进制VS2进制.cpp
    operatingExamination\2019053103进制转换.cpp

*/

#include <iostream>
using namespace std;

// x进制转换为y进制
int conversion(int in[], int out[], int n, int x, int y) {
    // 转换为y进制之后的长度
    int size = 0;
    int i = 0;
    // 每次迭代是一次除法
    while (i < n) {
        int remainder = 0;
        int dividend;
        // 每次迭代是一位数字的除法
        for (int j = i; j < n; j++) {
            dividend = remainder * x + in[j];
            in[j] = dividend / y;
            remainder = dividend % y;
        }
        out[size++] = remainder;
        // 下一次除法开始的位置
        while (in[i] == 0) i++;
    }
    return size;
}


int main() {
    string s;
    int in[100];
    int out[100];
    while (cin >> s) {
        // 输入
        int n = s.length();
        for (int i = 0; i < n; i++) {
            in[i] = s[i] - '0';
        }

        // 10进制转换为2进制
        int size = conversion(in, out, n, 10, 2);

        // 输出
        for (int i = size - 1; i >= 0; i--) {
            cout << out[i];
        }
        cout << endl;
    }
}
