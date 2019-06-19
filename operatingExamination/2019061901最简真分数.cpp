/*
https://www.nowcoder.com/practice/1f1db273eeb745c6ac83e91ff14d2ec9?tpId=40&tqId=21366&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking&tPage=2

最简真分数

时间限制：1秒 空间限制：65536K 热度指数：4417

题目描述
给出n个正整数，任取两个数分别作为分子和分母组成最简真分数，编程求共有几个这样的组合。
输入描述:
每组包含n（n<=600）和n个不同的整数，整数大于1且小于等于1000。
输出描述:
每行输出最简真分数组合的个数。
示例1
输入
7
3 5 7 9 11 13 15
输出
17



 */

#include <iostream>
using namespace std;

int nums[610];

bool check(int a, int b) {
    int large, small;
    if (a >= b) {
        large = a;
        small = b;
    } else {
        large = b;
        small = a;
    }
    for (int i = 2; i <= small; i++) {
        if (small % i == 0 && large % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(nums[i], nums[j]))
                    count++;
            }
        }
        
        cout << count << endl;
    }
}
