/*
放苹果

https://www.nowcoder.com/practice/4f0c1e21010e4d849bde5297148e81d9?tpId=40&tqId=21372&rp=2&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking&tPage=2

时间限制：1秒 空间限制：65536K 热度指数：2904

题目描述
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
输入描述:
每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
输出描述:
对输入的每组数据M和N，用一行输出相应的K。
示例1
输入
7 3
输出
8

思路：动态规划

*/

#include <iostream>
using namespace std;

int m, n;
int dp[11][11];

void initDp() {
    
    // 定义0个苹果为1种，0个盘子为0种。0个苹果0个盘子的情况不会出现
    for (int j = 1; j <= 10; j++) {
        dp[0][j] = 1;
        dp[1][j] = 1;
    }
    
    for (int i = 2; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (j > i) {
                // 盘子多余苹果时去掉多余盘子不影响结果
                dp[i][j] = dp[i][i];
            } else {
                // 两种情况
                // 至少有一个空盘子，去掉这个空盘子结果不变
                // 所有盘子都有苹果，从每个盘子中拿掉一个苹果结果不变
                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
            }
        }
    }
}

int main() {
    initDp();
    while (cin >> m >> n) {
        cout << dp[m][n] << endl;
    }
}
