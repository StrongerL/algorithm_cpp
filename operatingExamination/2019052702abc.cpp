/*
https://www.nowcoder.com/practice/912b15e237ef44148e44018d7b8750b6?tpId=40&tqId=21346&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

abc

时间限制：1秒 空间限制：65536K 热度指数：10613

题目描述
设a、b、c均是0到9之间的数字，abc、bcc是两个三位数，且有：abc+bcc=532。求满足条件的所有a、b、c的值。
输入描述:
题目没有任何输入。
输出描述:
请输出所有满足题目条件的a、b、c的值。
a、b、c之间用空格隔开。
每个输出占一行。

思路：随意

*/

#include <iostream>
using namespace std;
int main() {
    for (int a = 1; a < 5; a++) {
        for (int b = 5 - a; b >= 5 - a - 1 && b != 0; b--) {
            int abc = a * 100 + b * 10 + 1;
            int bcc = b * 100 + 1 * 11;
            if (abc + bcc == 532)
                cout << a << " " << b << " " << 1 << endl;
            
            abc = a * 100 + b * 10 + 6;
            bcc = b * 100 + 6 * 11;
            if (abc + bcc == 532)
                cout << a << " " << b << " " << 6 << endl;
        }
    }
}
