/*
数字反转

https://www.nowcoder.com/practice/2687c5c174cb4f938bdae01f0a19490c?tpId=40&tqId=21428&tPage=5&rp=5&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

时间限制：1秒 空间限制：65536K 热度指数：3673

题目描述
    12翻一下是21,34翻一下是43,12+34是46,46翻一下是64，现在又任意两个正整数，问他们两个数反转的和是否等于两个数的和的反转。
输入描述:
每行两个正整数a和b（0<a,b<=10000）。
输出描述:
    如果满足题目的要求输出a+b的值，否则输出NO。
示例1
输入
12 34
99 1
输出
46
NO

 */

#include <iostream>
#include <string>
using namespace std;

string a, b, s1, s2;

void swapMethod(string& s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        char tmp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = tmp;
    }
}

int main() {
    while (cin >> a >> b) {
        int a1 = stoi(a);
        int b1 = stoi(b);
        int sum1 = a1 + b1;
        s1 = to_string(sum1);
        swapMethod(s1);
        
        swapMethod(a);
        swapMethod(b);
        int a2 = stoi(a);
        int b2 = stoi(b);
        int sum2 = a2 + b2;
        s2 = to_string(sum2);
        
        if (s1 == s2) {
            cout << a1 + b1 << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }
}
