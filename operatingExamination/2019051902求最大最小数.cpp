/*
https://www.nowcoder.com/practice/82e5ff335eeb486aab359767895cc7b4?tpId=40&tqId=21344&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

时间限制：1秒 空间限制：65536K 热度指数：10024

题目描述
输入N个（N<=10000）数字，求出这N个数字中的最大值和最小值。每个数字的绝对值不大于1000000。
输入描述:
输入包括多组测试用例，每组测试用例由一个整数N开头，接下去一行给出N个整数。
输出描述:
输出包括两个整数，为给定N个数中的最大值与最小值。
示例1
输入
5
1 2 3 4 5
3
3 7 8
输出
5 1
8 3
*/

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    while(cin >> n) {
        int cur;
        int max = -1000001;
        int min = 1000001;
        for (int i = 0; i < n; i++) {
            cin >> cur;
            if (cur > max)
                max = cur;
            if (cur < min)
                min = cur;
        }
        cout << max << " " << min << endl;
    }
}
