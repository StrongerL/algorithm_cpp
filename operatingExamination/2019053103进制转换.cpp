/*
https://www.nowcoder.com/practice/0337e32b1e5543a19fa380e36d9343d7?tpId=40&tqId=21361&tPage=2&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking

进制转换

时间限制：1秒 空间限制：65536K 热度指数：8973

题目描述
将一个长度最多为30位数字的十进制非负整数转换为二进制数输出。
输入描述:
多组数据，每行为一个长度不超过30位的十进制非负整数。
（注意是10进制数字的个数可能有30个，而非30bits的整数）
输出描述:
每行输出对应的二进制数。
示例1
输入
0
1
3
8
输出
0
1
11
1000

思路：大数的进制转换，参考网页：https://blog.csdn.net/sjf0115/article/details/8690581?utm_source=copy

*/

#include <iostream>
using namespace std;

int n;
string s;
int in[40];
int out[120];

int conversion() {
    int size = 0;
    int i = 0;
    // 每次迭代是一次除法
    while (i < n) {
        int remainder = 0;
        int quotient;
        int dividend;
        // 每次迭代是一位数字的除法
        for (int j = i; j < n; j++) {
            dividend = remainder * 10 + in[j];
            remainder = dividend % 2;
            quotient = dividend / 2;
            in[j] = quotient;
        }
        out[size++] = remainder;
        // 下一次除法的开始位置
        while (in[i] == 0) i++;
    }
    return size;
}

int main() {
    while (cin >> s) {
        n = s.length();
        for (int i = 0; i < n; i++) {
            in[i] = s[i] - '0';
        }
        int size = conversion();
        for (int i = size - 1; i >= 0; i--) {
            cout << out[i];
        }
        cout << endl;
    }
}
