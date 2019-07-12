/*
https://acm.ecnu.edu.cn/contest/186/problem/B/

B. 整数划分
单点时限: 2.0 sec

内存限制: 512 MB

对于一个给定的正整数 n ，希望你能将它分成仅由数字 1 或 2 或 3 组成的和的形式，问有多少种划分方法。

举个例子： 4 可以被划分成 1+1+1+1 或 2+2 或 3+1 或 2+1+1 这 4 种形式，注意 1+3 和 3+1 视为同一种划分方法。
输入格式
有多组输入，每组输入由一行一个正整数 n 组成，题目保证 1≤n≤32767 ，保证数据组数不超过 200 组。

输出格式
对于每一个 n ，输出题目种所求的划分方法数，一行一个结果。

样例
input
4
5
output
4
5
input
2934
12553
output
718831
13137761


思路：划分中至少有一个1或者划分中没有1

 */

#include <iostream>
using namespace std;

int ans[32770];

int main()
{
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;


    for (int i = 4; i <= 32767; i++) {
        int count = 0;
        for (int j = 0; j * 3 <= i; j++) {
            if (!((i - j * 3) & 1))
                count ++;
        }
        ans[i] = ans[i - 1] + count;
    }

    int n;
    while (cin >> n) {
        cout << ans[n] << endl;
    }

}
