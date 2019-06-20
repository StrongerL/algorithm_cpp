/*
大整数的因子

https://www.nowcoder.com/practice/3d6cee12fbf54ea99bb165cbaba5823d?tpId=40&tqId=21370&rp=2&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

时间限制：1秒 空间限制：65536K 热度指数：3147

题目描述
已知正整数k满足2<=k<=9，现给出长度最大为30位的十进制非负整数c，求所有能整除c的k.
输入描述:
若干个非负整数c，c的位数<=30
每行一个c
输出描述:
每一个c的结果占一行
1) 若存在满足 c%k == 0 的k，输出所有这样的k，中间用空格隔开，最后一个k后面没有空格。
2) 若没有这样的k则输出"none"

注意整数溢出问题
不要对-1进行计算
示例1
输入
30
72
13
输出
2 3 5 6
2 3 4 6 8 9
none


思路：使用数组存储大数

 */

#include <iostream>
using namespace std;

int num[40];
int n;
string s;

string f() {
    string res = "";
    for (int i = 2; i <= 9; i++) {
        int remainder = 0;
        int dividend;
        for (int j = 0; j < n; j++) {
            dividend = remainder * 10 + num[j];
            remainder = dividend % i;
        }
        if (!remainder)
            res += i + 48;
    }
    return res;
}


int main() {
    while (cin >> s) {
        n = s.length();
        for (int i = 0; i < n; i++) {
            num[i] = s[i] - '0';
        }
        string res = f();
        if (res.length() == 0) {
            cout << "none" << endl;
            continue;
        }
        for (int i = 0; i < res.length(); i++) {
            cout << res[i];
            if (i != res.length() - 1)
                cout << " ";
        }
        cout << endl;
    }
}
