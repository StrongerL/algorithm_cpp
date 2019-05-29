/*
https://www.nowcoder.com/practice/f54d8e6de61e4efb8cce3eebfd0e0daa?tpId=40&tqId=21355&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking&tPage=2

N的阶乘

时间限制：1秒 空间限制：65536K 热度指数：8090

题目描述
 输入一个正整数N，输出N的阶乘。
输入描述:
正整数N(0<=N<=1000)
输出描述:
 输入可能包括多组数据，对于每一组输入数据，输出N的阶乘
示例1
输入
4
5
15
输出
24
120
1307674368000


思路：大数阶乘
参考网址：https://blog.csdn.net/lisp1995/article/details/52403507#commentBox

*/

#include <iostream>
using namespace std;
int num[3000];
// place是位数，carry是进位
int n, place, tmp, carry;
int main() {
    while (cin >> n) {
        // 开始时位数为1，初始值为1，进位为0
        place = 1;
        num[0] = 1;
        carry = 0;
        // 从2开始计算阶乘
        for (int i = 2; i <= n; i++) {
            // 当前数的每一位分别与i相乘
            for (int j = 0; j < place; j++) {
                tmp = num[j] * i + carry;
                num[j] = tmp % 10;
                carry = tmp / 10;
            }
            // 如果计算完还有进位
            while (carry) {
                num[place++] = carry % 10;
                carry /= 10;
            }
        }
        // 逆序输出
        for (int i = place - 1; i >= 0; i--) {
            cout << num[i];
        }
    }
}
