/*
https://www.nowcoder.com/practice/df219d60a7af4171a981ef56bd597f7b?tpId=40&tqId=21353&tPage=2&rp=2&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

最大序列和

时间限制：1秒 空间限制：65536K 热度指数：7381

题目描述
给出一个整数序列S，其中有N个数，定义其中一个非空连续子序列T中所有数的和为T的“序列和”。 对于S的所有非空连续子序列T，求最大的序列和。 变量条件：N为正整数，N≤1000000，结果序列和在范围（-2^63,2^63-1）以内。
输入描述:
第一行为一个正整数N，第二行为N个整数，表示序列中的数。
输出描述:
输入可能包括多组数据，对于每一组输入数据，
仅输出一个数，表示最大序列和。
示例1
输入
5
1 5 -3 2 4

6
1 -2 3 4 -10 6

4
-3 -1 -2 -5
输出
9
7
-1

思路：不断累加并于当前最大和比较，如果当前的和为负数，将其置为0

*/

#include <iostream>
using namespace std;
long long num[1000010];
int N;
int main() {
    while (cin >> N) {
        for (int i = 0; i < N; i++) {
            cin >> num[i];
        }
        long long maxSum = num[0];
        long long curSum = 0;
        for (int i = 0; i < N; i++) {
            curSum += num[i];
            if (curSum > maxSum)
                maxSum = curSum;
            if (curSum <= 0)
                curSum = 0;
        }
        cout << maxSum << endl;
    }
}
