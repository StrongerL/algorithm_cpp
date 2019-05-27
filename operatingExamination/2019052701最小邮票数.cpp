/*
https://www.nowcoder.com/practice/83800ae3292b4256b7349ded5f178dd1?tpId=40&tqId=21345&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

最小邮票数

时间限制：1秒 空间限制：65536K 热度指数：8965

题目描述
    有若干张邮票，要求从中选取最少的邮票张数凑成一个给定的总值。     如，有1分，3分，3分，3分，4分五张邮票，要求凑成10分，则使用3张邮票：3分、3分、4分即可。
输入描述:
    有多组数据，对于每组数据，首先是要求凑成的邮票总值M，M<100。然后是一个数N，N〈20，表示有N张邮票。接下来是N个正整数，分别表示这N张邮票的面值，且以升序排列。
输出描述:
      对于每组数据，能够凑成总值M的最少邮票张数。若无解，输出0。
示例1
输入
10
5
1 3 3 3 4
输出
3


思路：0-1背包简化版，dp[]数组存储组成面额所需最小邮票数量，无法组成则赋值为INF

*/

#include <iostream>
#include <algorithm>
using namespace std;

#define INF 20
int dp[101];
int stamp[21];
int M, N;

int main() {
    while (cin >> M >> N) {
        // 输入
        for (int i = 1; i <= N; i++) {
            cin >> stamp[i];
        }
        // 边界条件
        dp[0] = 0;
        for(int j = 1; j <= M; j++) {
            dp[j] = (stamp[1] == j) ? 1 : INF;
        }
        // 状态转移
        for (int i = 2; i <= N; i++) {
            for (int j = M; j >= stamp[i]; j--) {
                // min()函数头文件<algorithm>
                dp[j] = min(dp[j], dp[j - stamp[i]] + 1);
            }
        }
        // 输出
        if (dp[M] == INF)
            cout << 0 << endl;
        else
            cout << dp[M] << endl;
    }
}
