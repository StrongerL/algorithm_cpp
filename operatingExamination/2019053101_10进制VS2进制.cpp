/*
https://www.nowcoder.com/practice/fd972d5d5cf04dd4bb4e5f027d4fc11e?tpId=40&tqId=21357&tPage=2&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking

10进制 VS 2进制

时间限制：1秒 空间限制：65536K 热度指数：5945

题目描述
    对于一个十进制数A，将A转换为二进制数，然后按位逆序排列，再转换为十进制数B，我们乘B为A的二进制逆序数。     例如对于十进制数173，它的二进制形式为10101101，逆序排列得到10110101，其十进制数为181，181即为173的二进制逆序数。
输入描述:
    一个1000位(即10^999)以内的十进制数。
输出描述:
    输入的十进制数的二进制逆序数。
示例1
输入
173
输出
181

思路：大数的进制转换

*/

#include <iostream>
#define N 4010
using namespace std;

int in1[N];
int out1[N];
int in2[N];
int out2[N];

// 将一个x进制大数转换成y进制
int conversion(int in[], int out[], int n, int x, int y) {
    int size = 0;
    int i = 0;
    // 每次迭代是一次除法
    while (i < n) {
        int remainder = 0;
        int dividend;
        // 每次迭代是一位数字的除法
        for (int j = 0; j < n; j++) {
            dividend = remainder * x + in[j];
            in[j] = dividend / y;
            remainder = dividend % y;
        }
        out[size++] = remainder;
        // 下一次除法的开始位置
        while (in[i] == 0) i++;
    }
    return size;
}


int main() {
    string s;
    while (cin >> s) {
        // 输入
        int n = s.length();
        for (int i = 0; i < n; i++) {
            in1[i] = s[i] - '0';
        }

        // 10进制转换为2进制
        int size = conversion(in1, out1, n, 10, 2);
        
        // 去掉多余的0
        int start = 0;
        while (out1[start] == 0) start++;
        for (int i = 0; i < size - start; i++) {
            in2[i] = out1[i + start];
        }
        
        // 2进制转换为10进制
        int size2 = conversion(in2, out2, size - start, 2, 10);

        // 输出
        for (int i = size2 - 1; i >= 0; i--) {
            cout << out2[i];
        }
        cout << endl;
    }
}
